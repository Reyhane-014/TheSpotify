#ifndef LISTENERDASHBOARD_H
#define LISTENERDASHBOARD_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QDockWidget>
#include "../Sources/services/listenerhandler.h"
#include "playercontrol.h"

namespace Ui { class ListenerDashboard; }

class ListenerDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListenerDashboard(int listenerId, QWidget *parent = nullptr);
    ~ListenerDashboard();

private slots:
    void onLogoutClicked();
    void onCreatePlaylistClicked();
    void onDeletePlaylistClicked();
    void onPlaylistSelected(QListWidgetItem* item);
    void onAddSongsClicked();
    void onViewArtistsClicked();
    void onEditAccountClicked();
    void onUpdatePlaylistClicked();
    void onRemoveSongClicked();
    void onSongInPlaylistSelected(QListWidgetItem* item);
    void onAllSongsItemClicked(QListWidgetItem* item);
    void onSearchTextChanged(const QString& text);
    void onGenreFilterChanged(int index);
    void onYearFilterChanged(int index);
    void onClearFilterClicked();
    void onSongDoubleClicked(QListWidgetItem* item);

private:
    Ui::ListenerDashboard *ui;
    ListenerHandler listenerService;
    PlayerControl* playerControl;
    int currentListenerId;
    int selectedPlaylistId;
    int selectedSongId;
    std::vector<Song> allSongsCache;
    std::vector<Song> currentPlaylistSongs;
    void loadPlaylists();
    void loadSongsInPlaylist(int playlistId);
    void loadAllSongs();
    void applyFilters();
    void loadGenresAndYears();
    void showError(const QString& msg);
    void clearError();
    void setupPlayerDock();
};

#endif