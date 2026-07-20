#include "playercontrol.h"
#include "ui_playercontrol.h"
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QUrl>

PlayerControl::PlayerControl(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerControl)
    , currentSongIndex(-1)
    , currentSongId(-1)
    , isPlaying(false)
    , isPaused(false)
    , isUserSeeking(false)
{
    ui->setupUi(this);
    setupPlayer();

    connect(ui->playBtn, &QPushButton::clicked, this, &PlayerControl::onPlayBtnClicked);
    connect(ui->nextBtn, &QPushButton::clicked, this, &PlayerControl::onNextBtnClicked);
    connect(ui->prevBtn, &QPushButton::clicked, this, &PlayerControl::onPrevBtnClicked);
    connect(ui->stopBtn, &QPushButton::clicked, this, &PlayerControl::onStopBtnClicked);
    connect(ui->volumeBtn, &QPushButton::clicked, this, &PlayerControl::onVolumeBtnClicked);
    connect(ui->positionSlider, &QSlider::sliderMoved, this, &PlayerControl::onPositionSliderMoved);
    connect(ui->volumeSlider, &QSlider::sliderMoved, this, &PlayerControl::onVolumeChanged);

    ui->playBtn->setEnabled(false);
    ui->nextBtn->setEnabled(false);
    ui->prevBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    ui->positionSlider->setEnabled(false);
    ui->volumeSlider->setValue(80);
    ui->currentSongLabel->setText("No song playing");
    ui->playBtn->setText("▶");
    ui->songInfoLabel->setText("");
    ui->statusIndicator->setText("⏹");
    ui->positionSlider->setRange(0, 0);
    ui->timeLabel->setText("00:00 / 00:00");
    updateVolumeIcon();
}

PlayerControl::~PlayerControl()
{
    delete ui;
}

void PlayerControl::setupPlayer()
{
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.8);

    connect(player, &QMediaPlayer::positionChanged, this, &PlayerControl::onPositionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &PlayerControl::onDurationChanged);
    connect(player, &QMediaPlayer::mediaStatusChanged, this, &PlayerControl::onMediaStatusChanged);
}

void PlayerControl::setPlaylist(const std::vector<Song>& songs, int startIndex)
{
    currentSongList = songs;

    if (!currentSongList.empty() && startIndex >= 0 && startIndex < (int)currentSongList.size()) {
        currentSongIndex = startIndex;
        updateSongInfo(startIndex);
        ui->playBtn->setEnabled(true);
        ui->nextBtn->setEnabled(true);
        ui->prevBtn->setEnabled(true);
        ui->stopBtn->setEnabled(true);
        ui->positionSlider->setEnabled(true);
        ui->playBtn->setText("▶");
        isPlaying = false;
        isPaused = false;
        ui->statusIndicator->setText("⏹");
        player->stop();
    } else if (!currentSongList.empty()) {
        currentSongIndex = 0;
        updateSongInfo(0);
        ui->playBtn->setEnabled(true);
        ui->nextBtn->setEnabled(true);
        ui->prevBtn->setEnabled(true);
        ui->stopBtn->setEnabled(true);
        ui->positionSlider->setEnabled(true);
        ui->playBtn->setText("▶");
        isPlaying = false;
        isPaused = false;
        ui->statusIndicator->setText("⏹");
        player->stop();
    } else {
        clearPlaylist();
    }
}

void PlayerControl::addToPlaylist(const Song& song)
{
    if (song.getFilePath().empty()) {
        return;
    }

    currentSongList.push_back(song);

    if (currentSongList.size() == 1) {
        currentSongIndex = 0;
        updateSongInfo(0);
        ui->playBtn->setEnabled(true);
        ui->nextBtn->setEnabled(true);
        ui->prevBtn->setEnabled(true);
        ui->stopBtn->setEnabled(true);
        ui->positionSlider->setEnabled(true);
        ui->playBtn->setText("▶");
        isPlaying = false;
        isPaused = false;
        ui->statusIndicator->setText("⏹");
        player->stop();
    }
}

void PlayerControl::clearPlaylist()
{
    currentSongList.clear();
    currentSongIndex = -1;
    currentSongId = -1;
    isPlaying = false;
    isPaused = false;
    player->stop();
    ui->currentSongLabel->setText("No song playing");
    ui->songInfoLabel->setText("");
    ui->playBtn->setEnabled(false);
    ui->nextBtn->setEnabled(false);
    ui->prevBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    ui->positionSlider->setEnabled(false);
    ui->playBtn->setText("▶");
    ui->statusIndicator->setText("⏹");
    ui->positionSlider->setRange(0, 0);
    ui->timeLabel->setText("00:00 / 00:00");
}

void PlayerControl::playSong(int songId)
{
    for (int i = 0; i < (int)currentSongList.size(); i++) {
        if (currentSongList[i].getId() == songId) {
            playSongByIndex(i);
            return;
        }
    }
}

void PlayerControl::playSongByIndex(int index)
{
    if (index >= 0 && index < (int)currentSongList.size()) {
        currentSongIndex = index;
        updateSongInfo(index);
        onPlayBtnClicked();
    }
}

void PlayerControl::stop()
{
    player->stop();
    isPlaying = false;
    isPaused = false;
    ui->playBtn->setText("▶");
    ui->statusIndicator->setText("⏹");
    ui->positionSlider->setValue(0);
    ui->timeLabel->setText("00:00 / 00:00");
    emit playbackStopped();
}

void PlayerControl::pause()
{
    if (isPlaying) {
        player->pause();
        isPaused = true;
        isPlaying = false;
        ui->playBtn->setText("▶");
        ui->statusIndicator->setText("⏸");
        emit playbackStopped();
    }
}

void PlayerControl::resume()
{
    if (isPaused) {
        player->play();
        isPaused = false;
        isPlaying = true;
        ui->playBtn->setText("⏸");
        ui->statusIndicator->setText("▶");
        emit playbackStarted();
    }
}

void PlayerControl::onPlayBtnClicked()
{
    if (currentSongIndex < 0 || currentSongIndex >= (int)currentSongList.size()) {
        return;
    }

    if (isPlaying) {
        pause();
        return;
    }

    if (isPaused) {
        resume();
        return;
    }

    const Song& song = currentSongList[currentSongIndex];
    QString filePath = QString::fromStdString(song.getFilePath());

    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "No File", "This song has no audio file attached!");
        return;
    }

    QUrl fileUrl = QUrl::fromLocalFile(filePath);
    player->setSource(fileUrl);
    player->play();

    currentSongId = song.getId();
    isPlaying = true;
    isPaused = false;
    ui->playBtn->setText("⏸");
    ui->statusIndicator->setText("▶");
    ui->currentSongLabel->setText(QString::fromStdString(song.getTitle()));
    emit playbackStarted();
}

void PlayerControl::onNextBtnClicked()
{
    if (currentSongList.empty()) {
        return;
    }

    player->stop();
    isPlaying = false;
    isPaused = false;
    ui->playBtn->setText("▶");
    ui->statusIndicator->setText("⏹");

    currentSongIndex = (currentSongIndex + 1) % (int)currentSongList.size();
    updateSongInfo(currentSongIndex);
    onPlayBtnClicked();
}

void PlayerControl::onPrevBtnClicked()
{
    if (currentSongList.empty()) {
        return;
    }

    player->stop();
    isPlaying = false;
    isPaused = false;
    ui->playBtn->setText("▶");
    ui->statusIndicator->setText("⏹");

    currentSongIndex = (currentSongIndex - 1 + (int)currentSongList.size()) % (int)currentSongList.size();
    updateSongInfo(currentSongIndex);
    onPlayBtnClicked();
}

void PlayerControl::onStopBtnClicked()
{
    stop();
}

void PlayerControl::onVolumeBtnClicked()
{
    int currentVolume = ui->volumeSlider->value();
    if (currentVolume > 0) {
        ui->volumeSlider->setValue(0);
    } else {
        ui->volumeSlider->setValue(80);
    }
}

void PlayerControl::onVolumeChanged(int volume)
{
    audioOutput->setVolume(volume / 100.0);
    updateVolumeIcon();
}

void PlayerControl::updateVolumeIcon()
{
    int volume = ui->volumeSlider->value();
    if (volume == 0) {
        ui->volumeBtn->setText("🔇");
    } else if (volume < 40) {
        ui->volumeBtn->setText("🔈");
    } else if (volume < 70) {
        ui->volumeBtn->setText("🔉");
    } else {
        ui->volumeBtn->setText("🔊");
    }
}

void PlayerControl::onPositionSliderMoved(int value)
{
    isUserSeeking = true;
    qint64 position = (qint64)value * player->duration() / 100;
    player->setPosition(position);
    isUserSeeking = false;
}

void PlayerControl::onPositionChanged(qint64 position)
{
    if (!isUserSeeking) {
        qint64 duration = player->duration();
        if (duration > 0) {
            int progress = (int)(position * 100 / duration);
            ui->positionSlider->setValue(progress);
        }
    }
    ui->timeLabel->setText(formatTime(position) + " / " + formatTime(player->duration()));
}

void PlayerControl::onDurationChanged(qint64 duration)
{
    ui->positionSlider->setRange(0, 100);
    ui->timeLabel->setText("00:00 / " + formatTime(duration));
}

void PlayerControl::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia) {
        onNextBtnClicked();
    } else if (status == QMediaPlayer::InvalidMedia) {
        QMessageBox::warning(this, "Error", "Cannot play this file!");
        stop();
    }
}

void PlayerControl::updateSongInfo(int index)
{
    if (index >= 0 && index < (int)currentSongList.size()) {
        const Song& song = currentSongList[index];
        currentSongId = song.getId();
        ui->currentSongLabel->setText(QString::fromStdString(song.getTitle()));
        ui->songInfoLabel->setText(
            QString::fromStdString(song.getGenre()) + " | " +
            QString::number(song.getDuration()) + "s"
            );
        ui->positionSlider->setValue(0);
        ui->timeLabel->setText("00:00 / 00:00");
        emit songChanged(song);
    }
}

QString PlayerControl::formatTime(qint64 milliseconds)
{
    int seconds = milliseconds / 1000;
    int minutes = seconds / 60;
    seconds = seconds % 60;
    return QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));
}

void PlayerControl::updatePlayPauseButton()
{
    if (isPlaying) {
        ui->playBtn->setText("⏸");
    } else {
        ui->playBtn->setText("▶");
    }
}