#include "editsongdialog.h"
#include "ui_editsongdialog.h"
#include <QMessageBox>
#include <iostream>

EditSongDialog::EditSongDialog(int artistId, int songId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditSongDialog)
    , currentArtistId(artistId)
    , currentSongId(songId)
{
    std::cout << "\n========== EDIT SONG DIALOG CONSTRUCTOR ==========" << std::endl;
    std::cout << "Artist ID: " << artistId << std::endl;
    std::cout << "Song ID received: " << songId << std::endl;

    ui->setupUi(this);
    loadAlbums();
    loadSongData();

    connect(ui->saveBtn, &QPushButton::clicked, this, &EditSongDialog::onSaveClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &EditSongDialog::onCancelClicked);

    std::cout << "========== EDIT SONG DIALOG CONSTRUCTOR COMPLETE ==========\n" << std::endl;
}

EditSongDialog::~EditSongDialog()
{
    delete ui;
}

void EditSongDialog::loadAlbums()
{
    ui->albumCombo->clear();
    ui->albumCombo->addItem("Single (No Album)", 0);

    auto albums = artistService.fetchArtistAlbums(currentArtistId);
    for (const auto& album : albums) {
        ui->albumCombo->addItem(QString::fromStdString(album.getName()), album.getId());
    }
}

void EditSongDialog::loadSongData()
{
    std::cout << "\n========== LOAD SONG DATA ==========" << std::endl;
    std::cout << "Looking for song ID: " << currentSongId << std::endl;

    auto songPtr = artistService.fetchSong(currentSongId);
    if (songPtr) {
        currentSong = *songPtr;
        std::cout << "Found song: " << currentSong.getTitle() << std::endl;
        std::cout << "Genre: " << currentSong.getGenre() << std::endl;
        std::cout << "Year: " << currentSong.getReleaseYear() << std::endl;
        std::cout << "Duration: " << currentSong.getDuration() << std::endl;
        std::cout << "Album ID: " << currentSong.getAlbumId() << std::endl;

        ui->titleEdit->setText(QString::fromStdString(currentSong.getTitle()));
        ui->genreEdit->setText(QString::fromStdString(currentSong.getGenre()));
        ui->yearSpin->setValue(currentSong.getReleaseYear());
        ui->durationSpin->setValue(currentSong.getDuration());

        int albumId = currentSong.getAlbumId();
        for (int i = 0; i < ui->albumCombo->count(); ++i) {
            if (ui->albumCombo->itemData(i).toInt() == albumId) {
                ui->albumCombo->setCurrentIndex(i);
                std::cout << "Set album combo to index: " << i << " (Album ID: " << albumId << ")" << std::endl;
                break;
            }
        }
    } else {
        std::cout << "ERROR: Song NOT found! ID: " << currentSongId << std::endl;
    }
    std::cout << "========== LOAD SONG DATA COMPLETE ==========\n" << std::endl;
}

void EditSongDialog::onSaveClicked()
{
    std::cout << "\n========== SAVE SONG CLICKED ==========" << std::endl;
    std::cout << "Song ID: " << currentSongId << std::endl;

    QString title = ui->titleEdit->text().trimmed();
    QString genre = ui->genreEdit->text().trimmed();
    int year = ui->yearSpin->value();
    int duration = ui->durationSpin->value();
    int albumId = ui->albumCombo->currentData().toInt();

    std::cout << "Title: " << title.toStdString() << std::endl;
    std::cout << "Genre: " << genre.toStdString() << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Duration: " << duration << std::endl;
    std::cout << "Album ID: " << albumId << std::endl;

    if (title.isEmpty()) {
        std::cout << "ERROR: Title is empty!" << std::endl;
        QMessageBox::warning(this, "Error", "Please enter a song title!");
        std::cout << "========== SAVE SONG COMPLETE ==========\n" << std::endl;
        return;
    }

    std::cout << "Calling artistService.updateSong()..." << std::endl;
    if (artistService.updateSong(currentSongId, title.toStdString(), genre.toStdString(), year, duration, albumId)) {
        std::cout << "Update successful!" << std::endl;
        QMessageBox::information(this, "Success", "Song updated successfully!");
        accept();
    } else {
        std::cout << "Update FAILED!" << std::endl;
        QMessageBox::warning(this, "Error", "Failed to update song!");
    }
    std::cout << "========== SAVE SONG COMPLETE ==========\n" << std::endl;
}

void EditSongDialog::onCancelClicked()
{
    std::cout << "\n========== CANCEL SONG CLICKED ==========" << std::endl;
    reject();
    std::cout << "========== CANCEL SONG COMPLETE ==========\n" << std::endl;
}