#ifndef EDITSONGDIALOG_H
#define EDITSONGDIALOG_H

#include <QDialog>
#include "../Sources/entities/song.h"
#include "../Sources/services/artisthandler.h"

namespace Ui { class EditSongDialog; }

class EditSongDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditSongDialog(int artistId, int songId, QWidget *parent = nullptr);
    ~EditSongDialog();

private slots:
    void onSaveClicked();
    void onCancelClicked();

private:
    Ui::EditSongDialog *ui;
    ArtistHandler artistService;
    int currentArtistId;
    int currentSongId;
    Song currentSong;
    void loadSongData();
    void loadAlbums();
};

#endif