#include "artistdashboard.h"
#include "ui_artistdashboard.h"
#include "editaccountwindow.h"
#include "editsongdialog.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <iostream>

ArtistDashboard::ArtistDashboard(int artistId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArtistDashboard)
    , currentArtistId(artistId)
    , selectedAlbumId(-1)
    , selectedSongId(-1)
{
    ui->setupUi(this);
    loadAlbums();

    connect(ui->logoutBtn, &QPushButton::clicked, this, &ArtistDashboard::onLogoutClicked);
    connect(ui->createAlbumBtn, &QPushButton::clicked, this, &ArtistDashboard::onCreateAlbumClicked);
    connect(ui->createSongBtn, &QPushButton::clicked, this, &ArtistDashboard::onCreateSongClicked);
    connect(ui->deleteAlbumBtn, &QPushButton::clicked, this, &ArtistDashboard::onDeleteAlbumClicked);
    connect(ui->albumsList, &QListWidget::itemClicked, this, &ArtistDashboard::onAlbumSelected);
    connect(ui->editAccountBtn, &QPushButton::clicked, this, &ArtistDashboard::onEditAccountClicked);
    connect(ui->editSongBtn, &QPushButton::clicked, this, &ArtistDashboard::onEditSongClicked);
    connect(ui->deleteSongBtn, &QPushButton::clicked, this, &ArtistDashboard::onDeleteSongClicked);
    connect(ui->songsList, &QListWidget::itemClicked, this, &ArtistDashboard::onSongItemClicked);

    ui->deleteAlbumBtn->setEnabled(false);
    ui->editSongBtn->setEnabled(false);
    ui->deleteSongBtn->setEnabled(false);
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
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(album.getName()));
            item->setData(Qt::UserRole, album.getId());
            ui->albumsList->addItem(item);
            std::cout << "Added album: " << album.getName() << " ID: " << album.getId() << std::endl;
        }
        QListWidgetItem* singlesItem = new QListWidgetItem("🎵 Singles");
        singlesItem->setData(Qt::UserRole, 0);
        ui->albumsList->addItem(singlesItem);
        std::cout << "Added Singles item" << std::endl;
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ArtistDashboard::loadSongs(int albumId)
{
    ui->songsList->clear();
    selectedSongId = -1;
    ui->editSongBtn->setEnabled(false);
    ui->deleteSongBtn->setEnabled(false);

    std::cout << "\n========== LOAD SONGS ==========" << std::endl;
    std::cout << "Album ID: " << albumId << std::endl;

    try {
        std::vector<Song> songs;
        if (albumId == 0) {
            songs = artistService.fetchSingles(currentArtistId);
            std::cout << "Fetching singles, found " << songs.size() << " songs" << std::endl;
        } else {
            songs = artistService.fetchSongsByAlbum(albumId);
            std::cout << "Fetching songs by album, found " << songs.size() << " songs" << std::endl;
        }
        for (const auto& song : songs) {
            QString display = QString::fromStdString(song.getTitle()) + " (" +
                              QString::number(song.getDuration()) + "s)";
            if (!song.getFilePath().empty()) {
                display += " 📁";
            }
            QListWidgetItem* item = new QListWidgetItem(display);
            item->setData(Qt::UserRole, song.getId());
            ui->songsList->addItem(item);
            std::cout << "  Added song: " << song.getTitle() << " ID: " << song.getId() << std::endl;
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
    std::cout << "========== LOAD SONGS COMPLETE ==========\n" << std::endl;
}

void ArtistDashboard::refreshCurrentView()
{
    if (selectedAlbumId != -1) {
        loadSongs(selectedAlbumId);
    }
}

void ArtistDashboard::onLogoutClicked()
{
    this->close();
}

void ArtistDashboard::onEditAccountClicked()
{
    auto artist = artistService.fetchArtist(currentArtistId);
    if (artist) {
        EditAccountWindow* editWindow = new EditAccountWindow(
            currentArtistId,
            QString::fromStdString(artist->getUsername()),
            QString::fromStdString(artist->getFullName()),
            QString::fromStdString(artist->getBio()),
            this
            );
        editWindow->show();
    }
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
            int albumId = artistService.addNewAlbum(currentArtistId, albumName.toStdString());
            if (albumId != -1) {
                artistService.reloadAllData();
                loadAlbums();
                refreshCurrentView();
                QMessageBox::information(this, "Success", "Album created successfully!");
            } else {
                showError("Failed to create album");
            }
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

    // Ask for audio file
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Select Audio File",
        "",
        "Audio Files (*.mp3 *.wav *.flac *.m4a *.aac *.ogg *.wma);;All Files (*)"
        );

    try {
        int songId = artistService.addNewSong(
            currentArtistId,
            title.toStdString(),
            genre.toStdString(),
            year,
            duration,
            albumId,
            filePath.toStdString()
            );
        if (songId != -1) {
            artistService.reloadAllData();
            loadAlbums();
            refreshCurrentView();
            QMessageBox::information(this, "Success", "Song created successfully!");
        } else {
            showError("Failed to create song");
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ArtistDashboard::onDeleteAlbumClicked()
{
    if (selectedAlbumId == -1 || selectedAlbumId == 0) {
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Album",
                                  "Are you sure you want to delete this album and all its songs?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        try {
            if (artistService.deleteAlbum(selectedAlbumId)) {
                artistService.reloadAllData();
                loadAlbums();
                ui->songsList->clear();
                ui->deleteAlbumBtn->setEnabled(false);
                selectedAlbumId = -1;
                selectedSongId = -1;
                ui->editSongBtn->setEnabled(false);
                ui->deleteSongBtn->setEnabled(false);
                QMessageBox::information(this, "Success", "Album deleted successfully!");
            } else {
                showError("Failed to delete album");
            }
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ArtistDashboard::onAlbumSelected(QListWidgetItem* item)
{
    if (!item) {
        return;
    }

    int albumId = item->data(Qt::UserRole).toInt();
    selectedAlbumId = albumId;

    std::cout << "\n========== ALBUM SELECTED ==========" << std::endl;
    std::cout << "Album ID: " << albumId << std::endl;
    std::cout << "Item text: " << item->text().toStdString() << std::endl;

    if (albumId != 0) {
        ui->deleteAlbumBtn->setEnabled(true);
    } else {
        ui->deleteAlbumBtn->setEnabled(false);
    }

    loadSongs(albumId);
    std::cout << "========== ALBUM SELECTED COMPLETE ==========\n" << std::endl;
}

void ArtistDashboard::onSongItemClicked(QListWidgetItem* item)
{
    std::cout << "\n========== SONG ITEM CLICKED ==========" << std::endl;

    if (!item) {
        std::cout << "Item is NULL" << std::endl;
        ui->editSongBtn->setEnabled(false);
        ui->deleteSongBtn->setEnabled(false);
        selectedSongId = -1;
        std::cout << "========== SONG ITEM CLICKED COMPLETE ==========\n" << std::endl;
        return;
    }

    std::cout << "Item text: " << item->text().toStdString() << std::endl;
    std::cout << "Item data (UserRole): " << item->data(Qt::UserRole).toInt() << std::endl;

    selectedSongId = item->data(Qt::UserRole).toInt();
    std::cout << "SELECTED SONG ID: " << selectedSongId << std::endl;

    ui->editSongBtn->setEnabled(true);
    ui->deleteSongBtn->setEnabled(true);

    std::cout << "========== SONG ITEM CLICKED COMPLETE ==========\n" << std::endl;
}

void ArtistDashboard::onEditSongClicked()
{
    std::cout << "\n========== EDIT SONG CLICKED ==========" << std::endl;
    std::cout << "Current selectedSongId: " << selectedSongId << std::endl;

    if (selectedSongId == -1) {
        std::cout << "ERROR: No song selected (selectedSongId = -1)" << std::endl;
        QMessageBox::warning(this, "No Song Selected", "Please select a song from the list first!");
        std::cout << "========== EDIT SONG CLICKED COMPLETE ==========\n" << std::endl;
        return;
    }

    std::cout << "Opening EditSongDialog with song ID: " << selectedSongId << std::endl;
    EditSongDialog dialog(currentArtistId, selectedSongId, this);
    if (dialog.exec() == QDialog::Accepted) {
        std::cout << "Dialog accepted - updating..." << std::endl;
        artistService.reloadAllData();
        loadAlbums();
        refreshCurrentView();
        selectedSongId = -1;
        ui->editSongBtn->setEnabled(false);
        ui->deleteSongBtn->setEnabled(false);
        QMessageBox::information(this, "Success", "Song updated successfully!");
        std::cout << "Update complete!" << std::endl;
    } else {
        std::cout << "Dialog rejected/cancelled" << std::endl;
    }
    std::cout << "========== EDIT SONG CLICKED COMPLETE ==========\n" << std::endl;
}

void ArtistDashboard::onDeleteSongClicked()
{
    std::cout << "\n========== DELETE SONG CLICKED ==========" << std::endl;
    std::cout << "Current selectedSongId: " << selectedSongId << std::endl;

    if (selectedSongId == -1) {
        std::cout << "ERROR: No song selected (selectedSongId = -1)" << std::endl;
        QMessageBox::warning(this, "No Song Selected", "Please select a song from the list first!");
        std::cout << "========== DELETE SONG CLICKED COMPLETE ==========\n" << std::endl;
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Song",
                                  "Are you sure you want to delete this song?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        try {
            std::cout << "Deleting song ID: " << selectedSongId << std::endl;
            if (artistService.deleteSong(selectedSongId)) {
                artistService.reloadAllData();
                loadAlbums();
                refreshCurrentView();
                selectedSongId = -1;
                ui->editSongBtn->setEnabled(false);
                ui->deleteSongBtn->setEnabled(false);
                QMessageBox::information(this, "Success", "Song deleted successfully!");
                std::cout << "Delete successful!" << std::endl;
            } else {
                showError("Failed to delete song");
                std::cout << "Delete failed!" << std::endl;
            }
        } catch (const std::exception& e) {
            showError(e.what());
            std::cout << "Exception: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Delete cancelled by user" << std::endl;
    }
    std::cout << "========== DELETE SONG CLICKED COMPLETE ==========\n" << std::endl;
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