#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include <QWidget>
#include <vector>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "../Sources/entities/song.h"

namespace Ui { class PlayerControl; }

class PlayerControl : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerControl(QWidget *parent = nullptr);
    ~PlayerControl();

    void setPlaylist(const std::vector<Song>& songs, int startIndex = 0);
    void addToPlaylist(const Song& song);
    void clearPlaylist();
    void playSong(int songId);
    void playSongByIndex(int index);
    void stop();
    void pause();
    void resume();

signals:
    void songChanged(const Song& song);
    void playbackStarted();
    void playbackStopped();

private slots:
    void onPlayBtnClicked();
    void onNextBtnClicked();
    void onPrevBtnClicked();
    void onStopBtnClicked();
    void onVolumeBtnClicked();
    void onPositionSliderMoved(int value);
    void onPositionChanged(qint64 position);
    void onDurationChanged(qint64 duration);
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void onVolumeChanged(int volume);

private:
    Ui::PlayerControl *ui;
    QMediaPlayer* player;
    QAudioOutput* audioOutput;
    std::vector<Song> currentSongList;
    int currentSongIndex;
    int currentSongId;
    bool isPlaying;
    bool isPaused;
    bool isUserSeeking;

    void updateSongInfo(int index);
    void updatePlayPauseButton();
    void updateVolumeIcon();
    QString formatTime(qint64 milliseconds);
    void setupPlayer();
};

#endif