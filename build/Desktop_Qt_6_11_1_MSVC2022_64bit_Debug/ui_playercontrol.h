/********************************************************************************
** Form generated from reading UI file 'playercontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERCONTROL_H
#define UI_PLAYERCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerControl
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *songInfoLayout;
    QLabel *statusIndicator;
    QLabel *currentSongLabel;
    QSpacerItem *infoSpacer;
    QLabel *songInfoLabel;
    QHBoxLayout *positionLayout;
    QSlider *positionSlider;
    QLabel *timeLabel;
    QHBoxLayout *controlLayout;
    QSpacerItem *leftSpacer;
    QPushButton *prevBtn;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QPushButton *nextBtn;
    QPushButton *volumeBtn;
    QSlider *volumeSlider;
    QSpacerItem *rightSpacer;

    void setupUi(QWidget *PlayerControl)
    {
        if (PlayerControl->objectName().isEmpty())
            PlayerControl->setObjectName("PlayerControl");
        PlayerControl->resize(650, 110);
        PlayerControl->setMinimumSize(QSize(650, 110));
        PlayerControl->setMaximumSize(QSize(16777215, 110));
        PlayerControl->setStyleSheet(QString::fromUtf8("\n"
"    QWidget {\n"
"        background-color: #F8F9FA;\n"
"        border-top: 2px solid #E0E0E0;\n"
"    }\n"
"    QLabel {\n"
"        color: #1A1A2E;\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: transparent;\n"
"        border: none;\n"
"        color: #1A1A2E;\n"
"        font-family: \"Segoe UI\", sans-serif;\n"
"        padding: 8px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: rgba(0, 0, 0, 0.05);\n"
"        border-radius: 20px;\n"
"    }\n"
"    QSlider::groove:horizontal {\n"
"        background-color: #D0D0D0;\n"
"        height: 4px;\n"
"        border-radius: 2px;\n"
"    }\n"
"    QSlider::handle:horizontal {\n"
"        background-color: #007AFF;\n"
"        width: 12px;\n"
"        height: 12px;\n"
"        margin: -4px 0;\n"
"        border-radius: 6px;\n"
"    }\n"
"    QSlider::sub-page:horizontal {\n"
"        background-color: #007AFF;\n"
"        border-radius: 2px;\n"
"    }\n"
"    QSlider::gro"
                        "ove:vertical {\n"
"        background-color: #D0D0D0;\n"
"        width: 4px;\n"
"        border-radius: 2px;\n"
"    }\n"
"    QSlider::handle:vertical {\n"
"        background-color: #007AFF;\n"
"        width: 12px;\n"
"        height: 12px;\n"
"        margin: 0 -4px;\n"
"        border-radius: 6px;\n"
"    }\n"
"    QSlider::sub-page:vertical {\n"
"        background-color: #007AFF;\n"
"        border-radius: 2px;\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(PlayerControl);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 6, 10, 6);
        songInfoLayout = new QHBoxLayout();
        songInfoLayout->setObjectName("songInfoLayout");
        statusIndicator = new QLabel(PlayerControl);
        statusIndicator->setObjectName("statusIndicator");
        statusIndicator->setStyleSheet(QString::fromUtf8("color: #6C757D; font-size: 18px; font-weight: bold;"));

        songInfoLayout->addWidget(statusIndicator);

        currentSongLabel = new QLabel(PlayerControl);
        currentSongLabel->setObjectName("currentSongLabel");
        currentSongLabel->setStyleSheet(QString::fromUtf8("font-size: 13px; font-weight: 600; color: #1A1A2E;"));

        songInfoLayout->addWidget(currentSongLabel);

        infoSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        songInfoLayout->addItem(infoSpacer);

        songInfoLabel = new QLabel(PlayerControl);
        songInfoLabel->setObjectName("songInfoLabel");
        songInfoLabel->setStyleSheet(QString::fromUtf8("font-size: 12px; color: #6C757D;"));
        songInfoLabel->setAlignment(Qt::AlignRight);

        songInfoLayout->addWidget(songInfoLabel);


        verticalLayout->addLayout(songInfoLayout);

        positionLayout = new QHBoxLayout();
        positionLayout->setObjectName("positionLayout");
        positionSlider = new QSlider(PlayerControl);
        positionSlider->setObjectName("positionSlider");
        positionSlider->setOrientation(Qt::Horizontal);
        positionSlider->setEnabled(false);

        positionLayout->addWidget(positionSlider);

        timeLabel = new QLabel(PlayerControl);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setStyleSheet(QString::fromUtf8("font-size: 11px; color: #6C757D; min-width: 90px;"));
        timeLabel->setAlignment(Qt::AlignRight);

        positionLayout->addWidget(timeLabel);


        verticalLayout->addLayout(positionLayout);

        controlLayout = new QHBoxLayout();
        controlLayout->setObjectName("controlLayout");
        leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        controlLayout->addItem(leftSpacer);

        prevBtn = new QPushButton(PlayerControl);
        prevBtn->setObjectName("prevBtn");
        prevBtn->setEnabled(false);
        prevBtn->setStyleSheet(QString::fromUtf8("QPushButton { font-size: 20px; padding: 5px 10px; color: #0F3460; } QPushButton:hover { background-color: rgba(15, 52, 96, 0.1); border-radius: 20px; }"));

        controlLayout->addWidget(prevBtn);

        playBtn = new QPushButton(PlayerControl);
        playBtn->setObjectName("playBtn");
        playBtn->setEnabled(false);
        playBtn->setStyleSheet(QString::fromUtf8("QPushButton { font-size: 28px; padding: 5px 15px; background-color: #0F3460; border-radius: 25px; color: #FFFFFF; min-width: 60px; min-height: 45px; } QPushButton:hover { background-color: #1A1A4E; } QPushButton:disabled { background-color: #A0A0A0; }"));

        controlLayout->addWidget(playBtn);

        stopBtn = new QPushButton(PlayerControl);
        stopBtn->setObjectName("stopBtn");
        stopBtn->setEnabled(false);
        stopBtn->setStyleSheet(QString::fromUtf8("QPushButton { font-size: 20px; padding: 5px 10px; color: #E94560; } QPushButton:hover { background-color: rgba(233, 69, 96, 0.1); border-radius: 20px; }"));

        controlLayout->addWidget(stopBtn);

        nextBtn = new QPushButton(PlayerControl);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setEnabled(false);
        nextBtn->setStyleSheet(QString::fromUtf8("QPushButton { font-size: 20px; padding: 5px 10px; color: #0F3460; } QPushButton:hover { background-color: rgba(15, 52, 96, 0.1); border-radius: 20px; }"));

        controlLayout->addWidget(nextBtn);

        volumeBtn = new QPushButton(PlayerControl);
        volumeBtn->setObjectName("volumeBtn");
        volumeBtn->setStyleSheet(QString::fromUtf8("QPushButton { font-size: 16px; padding: 5px 8px; color: #0F3460; } QPushButton:hover { background-color: rgba(15, 52, 96, 0.1); border-radius: 20px; }"));

        controlLayout->addWidget(volumeBtn);

        volumeSlider = new QSlider(PlayerControl);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(80);
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal { background-color: #D0D0D0; height: 4px; border-radius: 2px; } QSlider::handle:horizontal { background-color: #0F3460; width: 10px; height: 10px; margin: -3px 0; border-radius: 5px; } QSlider::sub-page:horizontal { background-color: #0F3460; border-radius: 2px; }"));
        volumeSlider->setMaximumSize(QSize(80, 16777215));

        controlLayout->addWidget(volumeSlider);

        rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        controlLayout->addItem(rightSpacer);


        verticalLayout->addLayout(controlLayout);


        retranslateUi(PlayerControl);

        QMetaObject::connectSlotsByName(PlayerControl);
    } // setupUi

    void retranslateUi(QWidget *PlayerControl)
    {
        PlayerControl->setWindowTitle(QCoreApplication::translate("PlayerControl", "Player", nullptr));
        statusIndicator->setText(QCoreApplication::translate("PlayerControl", "\342\217\271", nullptr));
        currentSongLabel->setText(QCoreApplication::translate("PlayerControl", "No song playing", nullptr));
        songInfoLabel->setText(QString());
        timeLabel->setText(QCoreApplication::translate("PlayerControl", "00:00 / 00:00", nullptr));
        prevBtn->setText(QCoreApplication::translate("PlayerControl", "\342\217\256", nullptr));
#if QT_CONFIG(tooltip)
        prevBtn->setToolTip(QCoreApplication::translate("PlayerControl", "Previous", nullptr));
#endif // QT_CONFIG(tooltip)
        playBtn->setText(QCoreApplication::translate("PlayerControl", "\342\226\266", nullptr));
#if QT_CONFIG(tooltip)
        playBtn->setToolTip(QCoreApplication::translate("PlayerControl", "Play / Pause", nullptr));
#endif // QT_CONFIG(tooltip)
        stopBtn->setText(QCoreApplication::translate("PlayerControl", "\342\217\271", nullptr));
#if QT_CONFIG(tooltip)
        stopBtn->setToolTip(QCoreApplication::translate("PlayerControl", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
        nextBtn->setText(QCoreApplication::translate("PlayerControl", "\342\217\255", nullptr));
#if QT_CONFIG(tooltip)
        nextBtn->setToolTip(QCoreApplication::translate("PlayerControl", "Next", nullptr));
#endif // QT_CONFIG(tooltip)
        volumeBtn->setText(QCoreApplication::translate("PlayerControl", "\360\237\224\212", nullptr));
#if QT_CONFIG(tooltip)
        volumeBtn->setToolTip(QCoreApplication::translate("PlayerControl", "Mute", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class PlayerControl: public Ui_PlayerControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERCONTROL_H
