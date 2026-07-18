#ifndef ARTISTDASHBOARD_H
#define ARTISTDASHBOARD_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "../Sources/services/artisthandler.h"

namespace Ui { class ArtistDashboard; }

class ArtistDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit ArtistDashboard(int artistId, QWidget *parent = nullptr);
    ~ArtistDashboard();

private slots:
    void onLogoutClicked();
    void onCreateAlbumClicked();
    void onCreateSongClicked();
    void onDeleteAlbumClicked();
    void onAlbumSelected(QListWidgetItem* item);
    void onSongItemClicked(QListWidgetItem* item);
    void onEditAccountClicked();
    void onEditSongClicked();
    void onDeleteSongClicked();

private:
    Ui::ArtistDashboard *ui;
    ArtistHandler artistService;
    int currentArtistId;
    int selectedAlbumId;
    int selectedSongId;
    void loadAlbums();
    void loadSongs(int albumId);
    void refreshCurrentView();
    void showError(const QString& msg);
    void clearError();
};

#endif