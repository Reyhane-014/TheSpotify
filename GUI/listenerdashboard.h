#ifndef LISTENERDASHBOARD_H
#define LISTENERDASHBOARD_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "../Sources/services/listenerhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ListenerDashboard; }
QT_END_NAMESPACE

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

private:
    Ui::ListenerDashboard *ui;
    ListenerHandler listenerService;
    int currentListenerId;
    int selectedPlaylistId;
    int selectedSongId;
    std::vector<Song> allSongsCache;
    void loadPlaylists();
    void loadSongsInPlaylist(int playlistId);
    void loadAllSongs();
    void applyFilters();
    void loadGenresAndYears();
    void showError(const QString& msg);
    void clearError();
};

#endif