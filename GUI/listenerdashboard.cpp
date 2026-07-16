#include "listenerdashboard.h"
#include "ui_listenerdashboard.h"
#include <QMessageBox>
#include <QInputDialog>

ListenerDashboard::ListenerDashboard(int listenerId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListenerDashboard)
    , currentListenerId(listenerId)
    , selectedPlaylistId(-1)
{
    ui->setupUi(this);
    loadPlaylists();

    connect(ui->logoutBtn, &QPushButton::clicked, this, &ListenerDashboard::onLogoutClicked);
    connect(ui->createPlaylistBtn, &QPushButton::clicked, this, &ListenerDashboard::onCreatePlaylistClicked);
    connect(ui->deletePlaylistBtn, &QPushButton::clicked, this, &ListenerDashboard::onDeletePlaylistClicked);
    connect(ui->playlistsList, &QListWidget::itemClicked, this, &ListenerDashboard::onPlaylistSelected);
    connect(ui->addSongsBtn, &QPushButton::clicked, this, &ListenerDashboard::onAddSongsClicked);

    ui->deletePlaylistBtn->setEnabled(false);
    ui->songsList->clear();
}

ListenerDashboard::~ListenerDashboard()
{
    delete ui;
}

void ListenerDashboard::loadPlaylists()
{
    ui->playlistsList->clear();
    try {
        auto playlists = listenerService.fetchListenerPlaylists(currentListenerId);
        for (const auto& playlist : playlists) {
            QString name = QString::fromStdString(playlist.getName());
            if (playlist.getIsFavorite()) {
                name = "❤️ " + name;
            }
            ui->playlistsList->addItem(name);
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ListenerDashboard::loadSongsInPlaylist(int playlistId)
{
    ui->songsList->clear();
    try {
        auto playlist = listenerService.getPlaylist(playlistId);
        if (playlist) {
            const std::vector<int>& songIds = playlist->getSongIds();
            for (int songId : songIds) {
                auto song = listenerService.fetchSong(songId);
                if (song) {
                    QString display = QString::fromStdString(song->getTitle()) + " (" + QString::number(song->getDuration()) + "s)";
                    ui->songsList->addItem(display);
                }
            }
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ListenerDashboard::onLogoutClicked()
{
    this->close();
}

void ListenerDashboard::onCreatePlaylistClicked()
{
    bool ok;
    QString playlistName = QInputDialog::getText(this, "Create Playlist",
                                                 "Enter playlist name:",
                                                 QLineEdit::Normal,
                                                 "", &ok);
    if (ok && !playlistName.isEmpty()) {
        try {
            listenerService.createNewPlaylist(currentListenerId, playlistName.toStdString());
            loadPlaylists();
            QMessageBox::information(this, "Success", "Playlist created successfully!");
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ListenerDashboard::onDeletePlaylistClicked()
{
    if (selectedPlaylistId == -1) {
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Playlist",
                                  "Are you sure you want to delete this playlist?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        try {
            listenerService.deletePlaylist(selectedPlaylistId);
            loadPlaylists();
            ui->songsList->clear();
            ui->deletePlaylistBtn->setEnabled(false);
            selectedPlaylistId = -1;
            QMessageBox::information(this, "Success", "Playlist deleted successfully!");
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ListenerDashboard::onPlaylistSelected()
{
    ui->deletePlaylistBtn->setEnabled(true);
    selectedPlaylistId = 1;
    loadSongsInPlaylist(selectedPlaylistId);
}

void ListenerDashboard::onAddSongsClicked()
{
    QMessageBox::information(this, "Browse Songs", "Browse Songs dialog coming soon!");
}

void ListenerDashboard::showError(const QString& msg)
{
    ui->errorLabel->setText(msg);
    ui->errorLabel->setVisible(true);
}

void ListenerDashboard::clearError()
{
    ui->errorLabel->setVisible(false);
}