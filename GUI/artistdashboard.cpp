#include "artistdashboard.h"
#include "ui_artistdashboard.h"
#include <QMessageBox>
#include <QInputDialog>

ArtistDashboard::ArtistDashboard(int artistId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArtistDashboard)
    , currentArtistId(artistId)
    , selectedAlbumId(-1)
{
    ui->setupUi(this);
    loadAlbums();

    connect(ui->logoutBtn, &QPushButton::clicked, this, &ArtistDashboard::onLogoutClicked);
    connect(ui->createAlbumBtn, &QPushButton::clicked, this, &ArtistDashboard::onCreateAlbumClicked);
    connect(ui->createSongBtn, &QPushButton::clicked, this, &ArtistDashboard::onCreateSongClicked);
    connect(ui->deleteAlbumBtn, &QPushButton::clicked, this, &ArtistDashboard::onDeleteAlbumClicked);
    connect(ui->albumsList, &QListWidget::itemClicked, this, &ArtistDashboard::onAlbumSelected);

    ui->deleteAlbumBtn->setEnabled(false);
    ui->songsList->clear();
}

ArtistDashboard::~ArtistDashboard()
{
    delete ui;
}

void ArtistDashboard::loadAlbums()
{
    ui->albumsList->clear();
    try {
        auto albums = artistService.fetchArtistAlbums(currentArtistId);
        for (const auto& album : albums) {
            ui->albumsList->addItem(QString::fromStdString(album.getName()));
        }
        ui->albumsList->addItem("🎵 Singles");
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ArtistDashboard::loadSongs(int albumId)
{
    ui->songsList->clear();
    try {
        auto songs = artistService.fetchSongsByAlbum(albumId);
        for (const auto& song : songs) {
            QString display = QString::fromStdString(song.getTitle()) + " (" + QString::number(song.getDuration()) + "s)";
            ui->songsList->addItem(display);
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ArtistDashboard::onLogoutClicked()
{
    this->close();
}

void ArtistDashboard::onCreateAlbumClicked()
{
    bool ok;
    QString albumName = QInputDialog::getText(this, "Create Album",
                                              "Enter album name:",
                                              QLineEdit::Normal,
                                              "", &ok);
    if (ok && !albumName.isEmpty()) {
        try {
            artistService.addNewAlbum(currentArtistId, albumName.toStdString());
            loadAlbums();
            QMessageBox::information(this, "Success", "Album created successfully!");
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ArtistDashboard::onCreateSongClicked()
{
    bool ok;

    QString title = QInputDialog::getText(this, "Create Song",
                                          "Enter song title:",
                                          QLineEdit::Normal,
                                          "", &ok);
    if (!ok || title.isEmpty()) {
        return;
    }

    QString genre = QInputDialog::getText(this, "Create Song",
                                          "Enter genre:",
                                          QLineEdit::Normal,
                                          "Pop", &ok);
    if (!ok) {
        return;
    }

    int year = QInputDialog::getInt(this, "Create Song",
                                    "Enter release year:",
                                    2024, 1900, 2030, 1, &ok);
    if (!ok) {
        return;
    }

    int duration = QInputDialog::getInt(this, "Create Song",
                                        "Enter duration (seconds):",
                                        180, 10, 600, 5, &ok);
    if (!ok) {
        return;
    }

    auto albums = artistService.fetchArtistAlbums(currentArtistId);
    QStringList albumNames;
    albumNames << "Single (No Album)";
    for (const auto& album : albums) {
        albumNames << QString::fromStdString(album.getName());
    }

    QString albumName = QInputDialog::getItem(this, "Create Song",
                                              "Select album:",
                                              albumNames, 0, false, &ok);
    if (!ok) {
        return;
    }

    int albumId = 0;
    if (albumName != "Single (No Album)") {
        for (const auto& album : albums) {
            if (QString::fromStdString(album.getName()) == albumName) {
                albumId = album.getId();
                break;
            }
        }
    }

    try {
        artistService.addNewSong(currentArtistId,
                                 title.toStdString(),
                                 genre.toStdString(),
                                 year,
                                 duration,
                                 albumId);
        loadAlbums();
        loadSongs(albumId);
        QMessageBox::information(this, "Success", "Song created successfully!");
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ArtistDashboard::onDeleteAlbumClicked()
{
    if (selectedAlbumId == -1) {
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Album",
                                  "Are you sure you want to delete this album?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        try {
            artistService.deleteAlbum(selectedAlbumId);
            loadAlbums();
            ui->songsList->clear();
            ui->deleteAlbumBtn->setEnabled(false);
            selectedAlbumId = -1;
            QMessageBox::information(this, "Success", "Album deleted successfully!");
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ArtistDashboard::onAlbumSelected()
{
    ui->deleteAlbumBtn->setEnabled(true);
    selectedAlbumId = 1;
    loadSongs(selectedAlbumId);
}

void ArtistDashboard::showError(const QString& msg)
{
    ui->errorLabel->setText(msg);
    ui->errorLabel->setVisible(true);
}

void ArtistDashboard::clearError()
{
    ui->errorLabel->setVisible(false);
}