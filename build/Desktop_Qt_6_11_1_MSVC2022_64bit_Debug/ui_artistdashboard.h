/********************************************************************************
** Form generated from reading UI file 'artistdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTISTDASHBOARD_H
#define UI_ARTISTDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArtistDashboard
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *headerLayout;
    QLabel *titleLabel;
    QSpacerItem *headerSpacer;
    QPushButton *logoutBtn;
    QHBoxLayout *toolbarLayout;
    QPushButton *createAlbumBtn;
    QPushButton *createSongBtn;
    QPushButton *deleteAlbumBtn;
    QPushButton *editSongBtn;
    QPushButton *deleteSongBtn;
    QPushButton *editAccountBtn;
    QSpacerItem *toolbarSpacer;
    QHBoxLayout *mainLayout;
    QGroupBox *albumsGroup;
    QVBoxLayout *albumsLayout;
    QListWidget *albumsList;
    QGroupBox *songsGroup;
    QVBoxLayout *songsLayout;
    QListWidget *songsList;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ArtistDashboard)
    {
        if (ArtistDashboard->objectName().isEmpty())
            ArtistDashboard->setObjectName("ArtistDashboard");
        ArtistDashboard->resize(900, 600);
        ArtistDashboard->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #F8F9FA;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(ArtistDashboard);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 10, 20, 20);
        headerLayout = new QHBoxLayout();
        headerLayout->setObjectName("headerLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"          color: #1A1A2E;\n"
"          font-size: 28px;\n"
"          font-weight: 700;\n"
"          font-family: \"Segoe UI\", sans-serif;\n"
"         "));

        headerLayout->addWidget(titleLabel);

        headerSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);

        logoutBtn = new QPushButton(centralwidget);
        logoutBtn->setObjectName("logoutBtn");
        logoutBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #E94560;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 14px;\n"
"              font-weight: 600;\n"
"              padding: 8px 20px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #C73E54;\n"
"          }\n"
"         "));

        headerLayout->addWidget(logoutBtn);


        verticalLayout->addLayout(headerLayout);

        toolbarLayout = new QHBoxLayout();
        toolbarLayout->setObjectName("toolbarLayout");
        createAlbumBtn = new QPushButton(centralwidget);
        createAlbumBtn->setObjectName("createAlbumBtn");
        createAlbumBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #0F3460;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #16213E;\n"
"          }\n"
"         "));

        toolbarLayout->addWidget(createAlbumBtn);

        createSongBtn = new QPushButton(centralwidget);
        createSongBtn->setObjectName("createSongBtn");
        createSongBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #0F3460;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #16213E;\n"
"          }\n"
"         "));

        toolbarLayout->addWidget(createSongBtn);

        deleteAlbumBtn = new QPushButton(centralwidget);
        deleteAlbumBtn->setObjectName("deleteAlbumBtn");
        deleteAlbumBtn->setEnabled(false);
        deleteAlbumBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #E94560;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #C73E54;\n"
"          }\n"
"         "));

        toolbarLayout->addWidget(deleteAlbumBtn);

        editSongBtn = new QPushButton(centralwidget);
        editSongBtn->setObjectName("editSongBtn");
        editSongBtn->setEnabled(false);
        editSongBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #0F3460;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #16213E;\n"
"          }\n"
"         "));

        toolbarLayout->addWidget(editSongBtn);

        deleteSongBtn = new QPushButton(centralwidget);
        deleteSongBtn->setObjectName("deleteSongBtn");
        deleteSongBtn->setEnabled(false);
        deleteSongBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #E94560;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #C73E54;\n"
"          }\n"
"         "));

        toolbarLayout->addWidget(deleteSongBtn);

        editAccountBtn = new QPushButton(centralwidget);
        editAccountBtn->setObjectName("editAccountBtn");
        editAccountBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #0F3460;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #16213E;\n"
"          }\n"
"         "));

        toolbarLayout->addWidget(editAccountBtn);

        toolbarSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        toolbarLayout->addItem(toolbarSpacer);


        verticalLayout->addLayout(toolbarLayout);

        mainLayout = new QHBoxLayout();
        mainLayout->setObjectName("mainLayout");
        albumsGroup = new QGroupBox(centralwidget);
        albumsGroup->setObjectName("albumsGroup");
        albumsGroup->setStyleSheet(QString::fromUtf8("\n"
"          QGroupBox {\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 14px;\n"
"              font-weight: 600;\n"
"              color: #1A1A2E;\n"
"              border: 2px solid #D0D0D0;\n"
"              border-radius: 12px;\n"
"              margin-top: 12px;\n"
"              padding-top: 8px;\n"
"          }\n"
"          QGroupBox::title {\n"
"              subcontrol-origin: margin;\n"
"              subcontrol-position: top left;\n"
"              left: 16px;\n"
"              padding: 0 8px;\n"
"              background-color: #F8F9FA;\n"
"          }\n"
"         "));
        albumsLayout = new QVBoxLayout(albumsGroup);
        albumsLayout->setObjectName("albumsLayout");
        albumsList = new QListWidget(albumsGroup);
        albumsList->setObjectName("albumsList");
        albumsList->setStyleSheet(QString::fromUtf8("\n"
"             QListWidget {\n"
"                 background-color: #FFFFFF;\n"
"                 border: none;\n"
"                 border-radius: 8px;\n"
"                 color: #1A1A2E;\n"
"                 font-size: 14px;\n"
"                 font-family: \"Segoe UI\", sans-serif;\n"
"                 padding: 8px;\n"
"                 min-height: 250px;\n"
"                 max-height: 350px;\n"
"             }\n"
"             QListWidget::item {\n"
"                 padding: 12px 16px;\n"
"                 border-radius: 8px;\n"
"                 margin: 2px 0;\n"
"             }\n"
"             QListWidget::item:selected {\n"
"                 background-color: #0F3460;\n"
"                 color: #FFFFFF;\n"
"             }\n"
"             QListWidget::item:hover:!selected {\n"
"                 background-color: #E8EDF2;\n"
"             }\n"
"            "));

        albumsLayout->addWidget(albumsList);


        mainLayout->addWidget(albumsGroup);

        songsGroup = new QGroupBox(centralwidget);
        songsGroup->setObjectName("songsGroup");
        songsGroup->setStyleSheet(QString::fromUtf8("\n"
"          QGroupBox {\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 14px;\n"
"              font-weight: 600;\n"
"              color: #1A1A2E;\n"
"              border: 2px solid #D0D0D0;\n"
"              border-radius: 12px;\n"
"              margin-top: 12px;\n"
"              padding-top: 8px;\n"
"          }\n"
"          QGroupBox::title {\n"
"              subcontrol-origin: margin;\n"
"              subcontrol-position: top left;\n"
"              left: 16px;\n"
"              padding: 0 8px;\n"
"              background-color: #F8F9FA;\n"
"          }\n"
"         "));
        songsLayout = new QVBoxLayout(songsGroup);
        songsLayout->setObjectName("songsLayout");
        songsList = new QListWidget(songsGroup);
        songsList->setObjectName("songsList");
        songsList->setStyleSheet(QString::fromUtf8("\n"
"             QListWidget {\n"
"                 background-color: #FFFFFF;\n"
"                 border: none;\n"
"                 border-radius: 8px;\n"
"                 color: #1A1A2E;\n"
"                 font-size: 13px;\n"
"                 font-family: \"Segoe UI\", sans-serif;\n"
"                 padding: 8px;\n"
"                 min-height: 250px;\n"
"                 max-height: 350px;\n"
"             }\n"
"             QListWidget::item {\n"
"                 padding: 10px 16px;\n"
"                 border-radius: 8px;\n"
"                 margin: 1px 0;\n"
"             }\n"
"             QListWidget::item:selected {\n"
"                 background-color: #0F3460;\n"
"                 color: #FFFFFF;\n"
"             }\n"
"             QListWidget::item:hover:!selected {\n"
"                 background-color: #E8EDF2;\n"
"             }\n"
"            "));

        songsLayout->addWidget(songsList);


        mainLayout->addWidget(songsGroup);


        verticalLayout->addLayout(mainLayout);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setVisible(false);
        errorLabel->setAlignment(Qt::AlignCenter);
        errorLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #E94560;\n"
"        font-size: 13px;\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(errorLabel);

        ArtistDashboard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ArtistDashboard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 22));
        ArtistDashboard->setMenuBar(menubar);
        statusbar = new QStatusBar(ArtistDashboard);
        statusbar->setObjectName("statusbar");
        ArtistDashboard->setStatusBar(statusbar);

        retranslateUi(ArtistDashboard);

        QMetaObject::connectSlotsByName(ArtistDashboard);
    } // setupUi

    void retranslateUi(QMainWindow *ArtistDashboard)
    {
        ArtistDashboard->setWindowTitle(QCoreApplication::translate("ArtistDashboard", "Artist Panel", nullptr));
        titleLabel->setText(QCoreApplication::translate("ArtistDashboard", "\360\237\216\265 My Music", nullptr));
        logoutBtn->setText(QCoreApplication::translate("ArtistDashboard", "\360\237\232\252 Exit", nullptr));
        createAlbumBtn->setText(QCoreApplication::translate("ArtistDashboard", "\342\236\225 New Album", nullptr));
        createSongBtn->setText(QCoreApplication::translate("ArtistDashboard", "\360\237\216\265 New Song", nullptr));
        deleteAlbumBtn->setText(QCoreApplication::translate("ArtistDashboard", "\360\237\227\221\357\270\217 Delete Album", nullptr));
        editSongBtn->setText(QCoreApplication::translate("ArtistDashboard", "\342\234\217\357\270\217 Edit Song", nullptr));
        deleteSongBtn->setText(QCoreApplication::translate("ArtistDashboard", "\360\237\227\221\357\270\217 Delete Song", nullptr));
        editAccountBtn->setText(QCoreApplication::translate("ArtistDashboard", "\342\232\231\357\270\217 Edit Account", nullptr));
        albumsGroup->setTitle(QCoreApplication::translate("ArtistDashboard", "\360\237\223\200 Your Albums", nullptr));
        songsGroup->setTitle(QCoreApplication::translate("ArtistDashboard", "\360\237\216\266 Songs", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ArtistDashboard: public Ui_ArtistDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTISTDASHBOARD_H
