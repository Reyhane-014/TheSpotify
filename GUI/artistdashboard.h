#ifndef ARTISTDASHBOARD_H
#define ARTISTDASHBOARD_H

#include <QMainWindow>
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
    void onAlbumSelected();

private:
    Ui::ArtistDashboard *ui;
    ArtistHandler artistService;
    int currentArtistId;
    int selectedAlbumId;
    void loadAlbums();
    void loadSongs(int albumId);
    void showError(const QString& msg);
    void clearError();
};

#endif