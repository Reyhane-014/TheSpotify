#include "listenerdashboard.h"
#include "ui_listenerdashboard.h"
#include "editaccountwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QStringList>
#include <set>

ListenerDashboard::ListenerDashboard(int listenerId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ListenerDashboard)
    , currentListenerId(listenerId)
    , selectedPlaylistId(-1)
    , selectedSongId(-1)
{
    ui->setupUi(this);
    loadPlaylists();

    ui->genreFilterCombo->addItem("All Genres", "");
    ui->yearFilterCombo->addItem("All Years", -1);

    loadAllSongs();

    connect(ui->logoutBtn, &QPushButton::clicked, this, &ListenerDashboard::onLogoutClicked);
    connect(ui->createPlaylistBtn, &QPushButton::clicked, this, &ListenerDashboard::onCreatePlaylistClicked);
    connect(ui->deletePlaylistBtn, &QPushButton::clicked, this, &ListenerDashboard::onDeletePlaylistClicked);
    connect(ui->playlistsList, &QListWidget::itemClicked, this, &ListenerDashboard::onPlaylistSelected);
    connect(ui->addSongsBtn, &QPushButton::clicked, this, &ListenerDashboard::onAddSongsClicked);
    connect(ui->viewArtistsBtn, &QPushButton::clicked, this, &ListenerDashboard::onViewArtistsClicked);
    connect(ui->editAccountBtn, &QPushButton::clicked, this, &ListenerDashboard::onEditAccountClicked);
    connect(ui->updatePlaylistBtn, &QPushButton::clicked, this, &ListenerDashboard::onUpdatePlaylistClicked);
    connect(ui->removeSongBtn, &QPushButton::clicked, this, &ListenerDashboard::onRemoveSongClicked);
    connect(ui->songsList, &QListWidget::itemClicked, this, &ListenerDashboard::onSongInPlaylistSelected);
    connect(ui->allSongsList, &QListWidget::itemClicked, this, &ListenerDashboard::onAllSongsItemClicked);

    connect(ui->searchEdit, &QLineEdit::textChanged, this, &ListenerDashboard::onSearchTextChanged);
    connect(ui->genreFilterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ListenerDashboard::onGenreFilterChanged);
    connect(ui->yearFilterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ListenerDashboard::onYearFilterChanged);
    connect(ui->clearFilterBtn, &QPushButton::clicked, this, &ListenerDashboard::onClearFilterClicked);

    ui->deletePlaylistBtn->setEnabled(false);
    ui->updatePlaylistBtn->setEnabled(false);
    ui->removeSongBtn->setEnabled(false);
    ui->songsList->clear();
}

ListenerDashboard::~ListenerDashboard()
{
    delete ui;
}

void ListenerDashboard::loadGenresAndYears()
{
    QString currentGenre = ui->genreFilterCombo->currentData().toString();
    int currentYear = ui->yearFilterCombo->currentData().toInt();

    ui->genreFilterCombo->clear();
    ui->yearFilterCombo->clear();

    ui->genreFilterCombo->addItem("All Genres", "");
    ui->yearFilterCombo->addItem("All Years", -1);

    std::set<std::string> genres;
    std::set<int> years;

    for (const auto& song : allSongsCache) {
        genres.insert(song.getGenre());
        years.insert(song.getReleaseYear());
    }

    for (const auto& genre : genres) {
        ui->genreFilterCombo->addItem(QString::fromStdString(genre), QString::fromStdString(genre));
    }

    for (int year : years) {
        ui->yearFilterCombo->addItem(QString::number(year), year);
    }

    int foundGenreIndex = ui->genreFilterCombo->findData(currentGenre);
    if (foundGenreIndex != -1) {
        ui->genreFilterCombo->setCurrentIndex(foundGenreIndex);
    } else {
        ui->genreFilterCombo->setCurrentIndex(0);
    }

    int foundYearIndex = ui->yearFilterCombo->findData(currentYear);
    if (foundYearIndex != -1) {
        ui->yearFilterCombo->setCurrentIndex(foundYearIndex);
    } else {
        ui->yearFilterCombo->setCurrentIndex(0);
    }
}

void ListenerDashboard::loadPlaylists()
{
    ui->playlistsList->clear();
    try {
        auto playlists = listenerService.fetchListenerPlaylists(currentListenerId);
        for (const auto& playlist : playlists) {
            QString name = QString::fromStdString(playlist.getName());
            QListWidgetItem* item = new QListWidgetItem(name);
            item->setData(Qt::UserRole, playlist.getId());
            ui->playlistsList->addItem(item);
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ListenerDashboard::loadSongsInPlaylist(int playlistId)
{
    ui->songsList->clear();
    selectedSongId = -1;
    ui->removeSongBtn->setEnabled(false);

    try {
        auto playlist = listenerService.getPlaylist(playlistId);
        if (playlist) {
            const std::vector<int>& songIds = playlist->getSongIds();
            for (size_t i = 0; i < songIds.size(); ++i) {
                int songId = songIds[i];
                auto songPtr = listenerService.fetchSong(songId);
                if (songPtr) {
                    QString display = QString::fromStdString(songPtr->getTitle()) + " (" +
                                      QString::number(songPtr->getDuration()) + "s)";
                    QListWidgetItem* item = new QListWidgetItem(display);
                    item->setData(Qt::UserRole, songId);
                    ui->songsList->addItem(item);
                }
            }
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ListenerDashboard::loadAllSongs()
{
    try {
        allSongsCache = listenerService.fetchAllSongs();
        loadGenresAndYears();
        applyFilters();
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ListenerDashboard::applyFilters()
{
    ui->allSongsList->clear();

    if (allSongsCache.empty()) {
        return;
    }

    QString searchText = ui->searchEdit->text().trimmed().toLower();
    QString selectedGenre = ui->genreFilterCombo->currentData().toString();
    int selectedYear = ui->yearFilterCombo->currentData().toInt();

    std::vector<Song> filteredSongs;

    for (const auto& song : allSongsCache) {
        bool match = true;

        if (!searchText.isEmpty()) {
            QString title = QString::fromStdString(song.getTitle()).toLower();
            if (!title.contains(searchText)) {
                match = false;
            }
        }

        if (match && !selectedGenre.isEmpty()) {
            if (QString::fromStdString(song.getGenre()) != selectedGenre) {
                match = false;
            }
        }

        if (match && selectedYear != -1) {
            if (song.getReleaseYear() != selectedYear) {
                match = false;
            }
        }

        if (match) {
            filteredSongs.push_back(song);
        }
    }

    for (const auto& song : filteredSongs) {
        QString display = QString::fromStdString(song.getTitle()) + " - " +
                          QString::fromStdString(song.getGenre()) + " (" +
                          QString::number(song.getDuration()) + "s)";
        QListWidgetItem* item = new QListWidgetItem(display);
        item->setData(Qt::UserRole, song.getId());
        ui->allSongsList->addItem(item);
    }
}

void ListenerDashboard::onSearchTextChanged(const QString& text)
{
    Q_UNUSED(text);
    applyFilters();
}

void ListenerDashboard::onGenreFilterChanged(int index)
{
    Q_UNUSED(index);
    applyFilters();
}

void ListenerDashboard::onYearFilterChanged(int index)
{
    Q_UNUSED(index);
    applyFilters();
}

void ListenerDashboard::onClearFilterClicked()
{
    ui->searchEdit->clear();
    ui->genreFilterCombo->setCurrentIndex(0);
    ui->yearFilterCombo->setCurrentIndex(0);
    applyFilters();
}

void ListenerDashboard::onLogoutClicked()
{
    this->close();
}

void ListenerDashboard::onEditAccountClicked()
{
    auto listener = listenerService.fetchListener(currentListenerId);
    if (listener) {
        EditAccountWindow* editWindow = new EditAccountWindow(
            currentListenerId,
            QString::fromStdString(listener->getUsername()),
            QString::fromStdString(listener->getFullName()),
            QString::fromStdString(listener->getBio()),
            this
            );
        editWindow->show();
    }
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
            int playlistId = listenerService.createNewPlaylist(currentListenerId, playlistName.toStdString());
            if (playlistId != -1) {
                listenerService.saveAllData();
                listenerService.reloadAllData();
                loadPlaylists();
                loadAllSongs();
                QMessageBox::information(this, "Success", "Playlist created successfully!");
            } else {
                showError("Failed to create playlist");
            }
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ListenerDashboard::onUpdatePlaylistClicked()
{
    if (selectedPlaylistId == -1) {
        QMessageBox::warning(this, "No Playlist", "Please select a playlist first!");
        return;
    }

    bool ok;
    auto playlist = listenerService.getPlaylist(selectedPlaylistId);
    QString newName = QInputDialog::getText(this, "Update Playlist",
                                            "Enter new playlist name:",
                                            QLineEdit::Normal,
                                            QString::fromStdString(playlist->getName()), &ok);
    if (ok && !newName.isEmpty()) {
        try {
            if (listenerService.updatePlaylist(selectedPlaylistId, newName.toStdString())) {
                listenerService.saveAllData();
                listenerService.reloadAllData();
                loadPlaylists();
                QMessageBox::information(this, "Success", "Playlist updated successfully!");
            } else {
                showError("Failed to update playlist");
            }
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
            if (listenerService.deletePlaylist(selectedPlaylistId)) {
                listenerService.saveAllData();
                listenerService.reloadAllData();
                loadPlaylists();
                ui->songsList->clear();
                ui->deletePlaylistBtn->setEnabled(false);
                ui->updatePlaylistBtn->setEnabled(false);
                selectedPlaylistId = -1;
                QMessageBox::information(this, "Success", "Playlist deleted successfully!");
            } else {
                showError("Failed to delete playlist");
            }
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ListenerDashboard::onPlaylistSelected(QListWidgetItem* item)
{
    if (!item) {
        return;
    }

    selectedPlaylistId = item->data(Qt::UserRole).toInt();

    ui->deletePlaylistBtn->setEnabled(true);
    ui->updatePlaylistBtn->setEnabled(true);

    loadSongsInPlaylist(selectedPlaylistId);
}

void ListenerDashboard::onSongInPlaylistSelected(QListWidgetItem* item)
{
    if (!item) {
        ui->removeSongBtn->setEnabled(false);
        selectedSongId = -1;
        return;
    }

    selectedSongId = item->data(Qt::UserRole).toInt();
    ui->removeSongBtn->setEnabled(true);
}

void ListenerDashboard::onAllSongsItemClicked(QListWidgetItem* item)
{
    if (!item) {
        selectedSongId = -1;
        return;
    }
    selectedSongId = item->data(Qt::UserRole).toInt();
}

void ListenerDashboard::onAddSongsClicked()
{
    if (selectedSongId == -1) {
        QMessageBox::information(this, "Add Song", "Please select a song from the list first!");
        return;
    }

    if (selectedPlaylistId == -1) {
        QMessageBox::warning(this, "No Playlist", "Please select a playlist first!");
        return;
    }

    try {
        if (listenerService.addSongToPlaylist(selectedPlaylistId, selectedSongId)) {
            listenerService.saveAllData();
            listenerService.reloadAllData();
            loadSongsInPlaylist(selectedPlaylistId);
            loadPlaylists();
            QMessageBox::information(this, "Success", "Song added to playlist!");
        } else {
            showError("Failed to add song to playlist");
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
}

void ListenerDashboard::onRemoveSongClicked()
{
    if (selectedSongId == -1) {
        QMessageBox::warning(this, "No Song", "Please select a song from the playlist first!");
        return;
    }

    if (selectedPlaylistId == -1) {
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remove Song",
                                  "Are you sure you want to remove this song from the playlist?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        try {
            if (listenerService.removeSongFromPlaylist(selectedPlaylistId, selectedSongId)) {
                listenerService.saveAllData();
                listenerService.reloadAllData();
                loadSongsInPlaylist(selectedPlaylistId);
                selectedSongId = -1;
                ui->removeSongBtn->setEnabled(false);
                QMessageBox::information(this, "Success", "Song removed from playlist!");
            } else {
                showError("Failed to remove song");
            }
        } catch (const std::exception& e) {
            showError(e.what());
        }
    }
}

void ListenerDashboard::onViewArtistsClicked()
{
    try {
        auto artists = listenerService.fetchAllArtists();
        QStringList artistNames;
        for (const auto& artist : artists) {
            artistNames << QString::fromStdString(artist.getFullName()) + " (" +
                               QString::fromStdString(artist.getUsername()) + ")";
        }

        if (artistNames.isEmpty()) {
            QMessageBox::information(this, "Artists", "No artists found!");
            return;
        }

        bool ok;
        QString selected = QInputDialog::getItem(this, "View Artists",
                                                 "Select an artist to view their albums:",
                                                 artistNames, 0, false, &ok);
        if (ok && !selected.isEmpty()) {
            int idx = artistNames.indexOf(selected);
            if (idx >= 0 && idx < (int)artists.size()) {
                int artistId = artists[idx].getId();
                auto albums = listenerService.fetchArtistAlbums(artistId);
                QStringList albumNames;
                for (const auto& album : albums) {
                    albumNames << QString::fromStdString(album.getName());
                }
                if (albumNames.isEmpty()) {
                    QMessageBox::information(this, "Albums", "This artist has no albums yet!");
                } else {
                    QMessageBox::information(this, "Albums of " + selected,
                                             albumNames.join("\n"));
                }
            }
        }
    } catch (const std::exception& e) {
        showError(e.what());
    }
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