/********************************************************************************
** Form generated from reading UI file 'listenerdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTENERDASHBOARD_H
#define UI_LISTENERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListenerDashboard
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *headerLayout;
    QLabel *titleLabel;
    QSpacerItem *headerSpacer;
    QPushButton *logoutBtn;
    QHBoxLayout *toolbarLayout;
    QPushButton *createPlaylistBtn;
    QPushButton *updatePlaylistBtn;
    QPushButton *deletePlaylistBtn;
    QPushButton *removeSongBtn;
    QPushButton *viewArtistsBtn;
    QPushButton *editAccountBtn;
    QSpacerItem *toolbarSpacer;
    QHBoxLayout *mainLayout;
    QGroupBox *playlistsGroup;
    QVBoxLayout *playlistsLayout;
    QListWidget *playlistsList;
    QGroupBox *songsGroup;
    QVBoxLayout *songsLayout;
    QListWidget *songsList;
    QGroupBox *allSongsGroup;
    QVBoxLayout *allSongsLayout;
    QHBoxLayout *searchFilterLayout;
    QLineEdit *searchEdit;
    QComboBox *genreFilterCombo;
    QComboBox *yearFilterCombo;
    QPushButton *clearFilterBtn;
    QSpacerItem *searchFilterSpacer;
    QListWidget *allSongsList;
    QHBoxLayout *actionLayout;
    QPushButton *addSongsBtn;
    QSpacerItem *actionSpacer;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListenerDashboard)
    {
        if (ListenerDashboard->objectName().isEmpty())
            ListenerDashboard->setObjectName("ListenerDashboard");
        ListenerDashboard->resize(1100, 750);
        ListenerDashboard->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #F8F9FA;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(ListenerDashboard);
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
        createPlaylistBtn = new QPushButton(centralwidget);
        createPlaylistBtn->setObjectName("createPlaylistBtn");
        createPlaylistBtn->setStyleSheet(QString::fromUtf8("\n"
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

        toolbarLayout->addWidget(createPlaylistBtn);

        updatePlaylistBtn = new QPushButton(centralwidget);
        updatePlaylistBtn->setObjectName("updatePlaylistBtn");
        updatePlaylistBtn->setEnabled(false);
        updatePlaylistBtn->setStyleSheet(QString::fromUtf8("\n"
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

        toolbarLayout->addWidget(updatePlaylistBtn);

        deletePlaylistBtn = new QPushButton(centralwidget);
        deletePlaylistBtn->setObjectName("deletePlaylistBtn");
        deletePlaylistBtn->setEnabled(false);
        deletePlaylistBtn->setStyleSheet(QString::fromUtf8("\n"
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

        toolbarLayout->addWidget(deletePlaylistBtn);

        removeSongBtn = new QPushButton(centralwidget);
        removeSongBtn->setObjectName("removeSongBtn");
        removeSongBtn->setEnabled(false);
        removeSongBtn->setStyleSheet(QString::fromUtf8("\n"
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

        toolbarLayout->addWidget(removeSongBtn);

        viewArtistsBtn = new QPushButton(centralwidget);
        viewArtistsBtn->setObjectName("viewArtistsBtn");
        viewArtistsBtn->setStyleSheet(QString::fromUtf8("\n"
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

        toolbarLayout->addWidget(viewArtistsBtn);

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
        playlistsGroup = new QGroupBox(centralwidget);
        playlistsGroup->setObjectName("playlistsGroup");
        playlistsGroup->setStyleSheet(QString::fromUtf8("\n"
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
        playlistsLayout = new QVBoxLayout(playlistsGroup);
        playlistsLayout->setObjectName("playlistsLayout");
        playlistsList = new QListWidget(playlistsGroup);
        playlistsList->setObjectName("playlistsList");
        playlistsList->setStyleSheet(QString::fromUtf8("\n"
"             QListWidget {\n"
"                 background-color: #FFFFFF;\n"
"                 border: none;\n"
"                 border-radius: 8px;\n"
"                 color: #1A1A2E;\n"
"                 font-size: 14px;\n"
"                 font-family: \"Segoe UI\", sans-serif;\n"
"                 padding: 8px;\n"
"                 min-height: 200px;\n"
"                 max-height: 300px;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item {\n"
"                 padding: 12px 16px;\n"
"                 border-radius: 8px;\n"
"                 margin: 2px 0;\n"
"                 border: none;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item:selected {\n"
"                 background-color: #0F3460;\n"
"                 color: #FFFFFF;\n"
"                 border: none;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item:hover:!selected {\n"
"                 background-color: #E8EDF"
                        "2;\n"
"             }\n"
"            "));

        playlistsLayout->addWidget(playlistsList);


        mainLayout->addWidget(playlistsGroup);

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
"                 min-height: 200px;\n"
"                 max-height: 300px;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item {\n"
"                 padding: 10px 16px;\n"
"                 border-radius: 8px;\n"
"                 margin: 1px 0;\n"
"                 border: none;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item:selected {\n"
"                 background-color: #0F3460;\n"
"                 color: #FFFFFF;\n"
"                 border: none;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item:hover:!selected {\n"
"                 background-color: #E8EDF"
                        "2;\n"
"             }\n"
"            "));

        songsLayout->addWidget(songsList);


        mainLayout->addWidget(songsGroup);

        allSongsGroup = new QGroupBox(centralwidget);
        allSongsGroup->setObjectName("allSongsGroup");
        allSongsGroup->setStyleSheet(QString::fromUtf8("\n"
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
        allSongsLayout = new QVBoxLayout(allSongsGroup);
        allSongsLayout->setObjectName("allSongsLayout");
        searchFilterLayout = new QHBoxLayout();
        searchFilterLayout->setObjectName("searchFilterLayout");
        searchEdit = new QLineEdit(allSongsGroup);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setStyleSheet(QString::fromUtf8("\n"
"               QLineEdit {\n"
"                   background-color: #FFFFFF;\n"
"                   border: 1px solid #D0D0D0;\n"
"                   border-radius: 20px;\n"
"                   color: #333333;\n"
"                   font-size: 13px;\n"
"                   padding: 8px 16px;\n"
"                   font-family: \"Segoe UI\", sans-serif;\n"
"               }\n"
"               QLineEdit:focus {\n"
"                   border-color: #007AFF;\n"
"               }\n"
"              "));

        searchFilterLayout->addWidget(searchEdit);

        genreFilterCombo = new QComboBox(allSongsGroup);
        genreFilterCombo->setObjectName("genreFilterCombo");
        genreFilterCombo->setStyleSheet(QString::fromUtf8("\n"
"               QComboBox {\n"
"                   background-color: #FFFFFF;\n"
"                   border: 1px solid #D0D0D0;\n"
"                   border-radius: 20px;\n"
"                   color: #333333;\n"
"                   font-size: 13px;\n"
"                   padding: 8px 16px;\n"
"                   font-family: \"Segoe UI\", sans-serif;\n"
"                   min-width: 120px;\n"
"               }\n"
"               QComboBox:focus {\n"
"                   border-color: #007AFF;\n"
"               }\n"
"               QComboBox::drop-down {\n"
"                   border: none;\n"
"               }\n"
"              "));

        searchFilterLayout->addWidget(genreFilterCombo);

        yearFilterCombo = new QComboBox(allSongsGroup);
        yearFilterCombo->setObjectName("yearFilterCombo");
        yearFilterCombo->setStyleSheet(QString::fromUtf8("\n"
"               QComboBox {\n"
"                   background-color: #FFFFFF;\n"
"                   border: 1px solid #D0D0D0;\n"
"                   border-radius: 20px;\n"
"                   color: #333333;\n"
"                   font-size: 13px;\n"
"                   padding: 8px 16px;\n"
"                   font-family: \"Segoe UI\", sans-serif;\n"
"                   min-width: 100px;\n"
"               }\n"
"               QComboBox:focus {\n"
"                   border-color: #007AFF;\n"
"               }\n"
"               QComboBox::drop-down {\n"
"                   border: none;\n"
"               }\n"
"              "));

        searchFilterLayout->addWidget(yearFilterCombo);

        clearFilterBtn = new QPushButton(allSongsGroup);
        clearFilterBtn->setObjectName("clearFilterBtn");
        clearFilterBtn->setStyleSheet(QString::fromUtf8("\n"
"               QPushButton {\n"
"                   background-color: #6C757D;\n"
"                   border: none;\n"
"                   border-radius: 20px;\n"
"                   color: #FFFFFF;\n"
"                   font-family: \"Segoe UI\", sans-serif;\n"
"                   font-size: 13px;\n"
"                   font-weight: 600;\n"
"                   padding: 8px 16px;\n"
"               }\n"
"               QPushButton:hover {\n"
"                   background-color: #5A6268;\n"
"               }\n"
"              "));

        searchFilterLayout->addWidget(clearFilterBtn);

        searchFilterSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        searchFilterLayout->addItem(searchFilterSpacer);


        allSongsLayout->addLayout(searchFilterLayout);

        allSongsList = new QListWidget(allSongsGroup);
        allSongsList->setObjectName("allSongsList");
        allSongsList->setStyleSheet(QString::fromUtf8("\n"
"             QListWidget {\n"
"                 background-color: #FFFFFF;\n"
"                 border: none;\n"
"                 border-radius: 8px;\n"
"                 color: #1A1A2E;\n"
"                 font-size: 13px;\n"
"                 font-family: \"Segoe UI\", sans-serif;\n"
"                 padding: 8px;\n"
"                 min-height: 200px;\n"
"                 max-height: 300px;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item {\n"
"                 padding: 10px 16px;\n"
"                 border-radius: 8px;\n"
"                 margin: 1px 0;\n"
"                 border: none;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item:selected {\n"
"                 background-color: #0F3460;\n"
"                 color: #FFFFFF;\n"
"                 border: none;\n"
"                 outline: none;\n"
"             }\n"
"             QListWidget::item:hover:!selected {\n"
"                 background-color: #E8EDF"
                        "2;\n"
"             }\n"
"            "));

        allSongsLayout->addWidget(allSongsList);


        mainLayout->addWidget(allSongsGroup);


        verticalLayout->addLayout(mainLayout);

        actionLayout = new QHBoxLayout();
        actionLayout->setObjectName("actionLayout");
        addSongsBtn = new QPushButton(centralwidget);
        addSongsBtn->setObjectName("addSongsBtn");
        addSongsBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #28A745;\n"
"              border: none;\n"
"              border-radius: 8px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Segoe UI\", sans-serif;\n"
"              font-size: 13px;\n"
"              font-weight: 600;\n"
"              padding: 8px 16px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #218838;\n"
"          }\n"
"         "));

        actionLayout->addWidget(addSongsBtn);

        actionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionLayout->addItem(actionSpacer);


        verticalLayout->addLayout(actionLayout);

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

        ListenerDashboard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ListenerDashboard);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 22));
        ListenerDashboard->setMenuBar(menubar);
        statusbar = new QStatusBar(ListenerDashboard);
        statusbar->setObjectName("statusbar");
        ListenerDashboard->setStatusBar(statusbar);

        retranslateUi(ListenerDashboard);

        QMetaObject::connectSlotsByName(ListenerDashboard);
    } // setupUi

    void retranslateUi(QMainWindow *ListenerDashboard)
    {
        ListenerDashboard->setWindowTitle(QCoreApplication::translate("ListenerDashboard", "Listener Panel", nullptr));
        titleLabel->setText(QCoreApplication::translate("ListenerDashboard", "\360\237\216\265 My Library", nullptr));
        logoutBtn->setText(QCoreApplication::translate("ListenerDashboard", "\360\237\232\252 Exit", nullptr));
        createPlaylistBtn->setText(QCoreApplication::translate("ListenerDashboard", "\342\236\225 New Playlist", nullptr));
        updatePlaylistBtn->setText(QCoreApplication::translate("ListenerDashboard", "\342\234\217\357\270\217 Rename", nullptr));
        deletePlaylistBtn->setText(QCoreApplication::translate("ListenerDashboard", "\360\237\227\221\357\270\217 Delete", nullptr));
        removeSongBtn->setText(QCoreApplication::translate("ListenerDashboard", "\342\236\226 Remove Song", nullptr));
        viewArtistsBtn->setText(QCoreApplication::translate("ListenerDashboard", "\360\237\216\244 View Artists", nullptr));
        editAccountBtn->setText(QCoreApplication::translate("ListenerDashboard", "\342\232\231\357\270\217 Edit Account", nullptr));
        playlistsGroup->setTitle(QCoreApplication::translate("ListenerDashboard", "\360\237\223\213 Your Playlists", nullptr));
        songsGroup->setTitle(QCoreApplication::translate("ListenerDashboard", "\360\237\216\266 Songs in Playlist", nullptr));
        allSongsGroup->setTitle(QCoreApplication::translate("ListenerDashboard", "\360\237\216\265 All Songs", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("ListenerDashboard", "\360\237\224\215 Search songs by title...", nullptr));
        clearFilterBtn->setText(QCoreApplication::translate("ListenerDashboard", "\342\234\226 Clear", nullptr));
        addSongsBtn->setText(QCoreApplication::translate("ListenerDashboard", "\342\236\225 Add Selected Song to Playlist", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListenerDashboard: public Ui_ListenerDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTENERDASHBOARD_H
