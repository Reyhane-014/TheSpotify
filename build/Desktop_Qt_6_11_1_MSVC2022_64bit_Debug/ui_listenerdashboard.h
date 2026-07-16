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
    QPushButton *addSongsBtn;
    QPushButton *deletePlaylistBtn;
    QSpacerItem *toolbarSpacer;
    QGroupBox *playlistsGroup;
    QHBoxLayout *playlistsLayout;
    QListWidget *playlistsList;
    QGroupBox *songsGroup;
    QHBoxLayout *songsLayout;
    QListWidget *songsList;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListenerDashboard)
    {
        if (ListenerDashboard->objectName().isEmpty())
            ListenerDashboard->setObjectName("ListenerDashboard");
        ListenerDashboard->resize(800, 600);
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

        addSongsBtn = new QPushButton(centralwidget);
        addSongsBtn->setObjectName("addSongsBtn");
        addSongsBtn->setStyleSheet(QString::fromUtf8("\n"
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

        toolbarLayout->addWidget(addSongsBtn);

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

        toolbarSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        toolbarLayout->addItem(toolbarSpacer);


        verticalLayout->addLayout(toolbarLayout);

        playlistsGroup = new QGroupBox(centralwidget);
        playlistsGroup->setObjectName("playlistsGroup");
        playlistsGroup->setStyleSheet(QString::fromUtf8("\n"
"        QGroupBox {\n"
"            font-family: \"Segoe UI\", sans-serif;\n"
"            font-size: 14px;\n"
"            font-weight: 600;\n"
"            color: #1A1A2E;\n"
"            border: 2px solid #D0D0D0;\n"
"            border-radius: 12px;\n"
"            margin-top: 12px;\n"
"            padding-top: 8px;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 16px;\n"
"            padding: 0 8px;\n"
"            background-color: #F8F9FA;\n"
"        }\n"
"       "));
        playlistsLayout = new QHBoxLayout(playlistsGroup);
        playlistsLayout->setObjectName("playlistsLayout");
        playlistsList = new QListWidget(playlistsGroup);
        playlistsList->setObjectName("playlistsList");
        playlistsList->setStyleSheet(QString::fromUtf8("\n"
"           QListWidget {\n"
"               background-color: #FFFFFF;\n"
"               border: none;\n"
"               border-radius: 8px;\n"
"               color: #1A1A2E;\n"
"               font-size: 14px;\n"
"               font-family: \"Segoe UI\", sans-serif;\n"
"               padding: 8px;\n"
"               min-height: 180px;\n"
"           }\n"
"           QListWidget::item {\n"
"               padding: 12px 16px;\n"
"               border-radius: 8px;\n"
"               margin: 2px 0;\n"
"           }\n"
"           QListWidget::item:selected {\n"
"               background-color: #0F3460;\n"
"               color: #FFFFFF;\n"
"           }\n"
"           QListWidget::item:hover:!selected {\n"
"               background-color: #E8EDF2;\n"
"           }\n"
"          "));

        playlistsLayout->addWidget(playlistsList);


        verticalLayout->addWidget(playlistsGroup);

        songsGroup = new QGroupBox(centralwidget);
        songsGroup->setObjectName("songsGroup");
        songsGroup->setStyleSheet(QString::fromUtf8("\n"
"        QGroupBox {\n"
"            font-family: \"Segoe UI\", sans-serif;\n"
"            font-size: 14px;\n"
"            font-weight: 600;\n"
"            color: #1A1A2E;\n"
"            border: 2px solid #D0D0D0;\n"
"            border-radius: 12px;\n"
"            margin-top: 12px;\n"
"            padding-top: 8px;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 16px;\n"
"            padding: 0 8px;\n"
"            background-color: #F8F9FA;\n"
"        }\n"
"       "));
        songsLayout = new QHBoxLayout(songsGroup);
        songsLayout->setObjectName("songsLayout");
        songsList = new QListWidget(songsGroup);
        songsList->setObjectName("songsList");
        songsList->setStyleSheet(QString::fromUtf8("\n"
"           QListWidget {\n"
"               background-color: #FFFFFF;\n"
"               border: none;\n"
"               border-radius: 8px;\n"
"               color: #1A1A2E;\n"
"               font-size: 13px;\n"
"               font-family: \"Segoe UI\", sans-serif;\n"
"               padding: 8px;\n"
"               min-height: 120px;\n"
"           }\n"
"           QListWidget::item {\n"
"               padding: 10px 16px;\n"
"               border-radius: 8px;\n"
"               margin: 1px 0;\n"
"           }\n"
"           QListWidget::item:selected {\n"
"               background-color: #0F3460;\n"
"               color: #FFFFFF;\n"
"           }\n"
"           QListWidget::item:hover:!selected {\n"
"               background-color: #E8EDF2;\n"
"           }\n"
"          "));

        songsLayout->addWidget(songsList);


        verticalLayout->addWidget(songsGroup);

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
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        addSongsBtn->setText(QCoreApplication::translate("ListenerDashboard", "\360\237\216\265 Browse Songs", nullptr));
        deletePlaylistBtn->setText(QCoreApplication::translate("ListenerDashboard", "\360\237\227\221\357\270\217 Delete", nullptr));
        playlistsGroup->setTitle(QCoreApplication::translate("ListenerDashboard", "\360\237\223\213 Your Playlists", nullptr));
        songsGroup->setTitle(QCoreApplication::translate("ListenerDashboard", "\360\237\216\266 Songs in Playlist", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ListenerDashboard: public Ui_ListenerDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTENERDASHBOARD_H
