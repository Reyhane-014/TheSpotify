#ifndef LISTENERDASHBOARD_H
#define LISTENERDASHBOARD_H

#include <QMainWindow>
#include "../Sources/services/listenerhandler.h"

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
    void onPlaylistSelected();
    void onAddSongsClicked();

private:
    Ui::ListenerDashboard *ui;
    ListenerHandler listenerService;
    int currentListenerId;
    int selectedPlaylistId;
    void loadPlaylists();
    void loadSongsInPlaylist(int playlistId);
    void showError(const QString& msg);
    void clearError();
};

#endif