/********************************************************************************
** Form generated from reading UI file 'editsongdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSONGDIALOG_H
#define UI_EDITSONGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditSongDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *titleLabel2;
    QLineEdit *titleEdit;
    QLabel *genreLabel;
    QLineEdit *genreEdit;
    QHBoxLayout *yearDurationLayout;
    QLabel *yearLabel;
    QSpinBox *yearSpin;
    QLabel *durationLabel;
    QSpinBox *durationSpin;
    QLabel *albumLabel;
    QComboBox *albumCombo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *buttonLayout;
    QPushButton *cancelBtn;
    QPushButton *saveBtn;

    void setupUi(QDialog *EditSongDialog)
    {
        if (EditSongDialog->objectName().isEmpty())
            EditSongDialog->setObjectName("EditSongDialog");
        EditSongDialog->resize(450, 450);
        EditSongDialog->setStyleSheet(QString::fromUtf8("\n"
"    QDialog {\n"
"        background: qlineargradient(\n"
"            x1: 0, y1: 0,\n"
"            x2: 1, y2: 1,\n"
"            stop: 0 #F5F5F5,\n"
"            stop: 1 #E0E0E0\n"
"        );\n"
"    }\n"
"   "));
        verticalLayout = new QVBoxLayout(EditSongDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 30, 30, 30);
        titleLabel = new QLabel(EditSongDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"       color: #1A1A2E;\n"
"       font-size: 22px;\n"
"       font-weight: 700;\n"
"       font-family: \"Segoe UI\", sans-serif;\n"
"      "));

        verticalLayout->addWidget(titleLabel);

        titleLabel2 = new QLabel(EditSongDialog);
        titleLabel2->setObjectName("titleLabel2");
        titleLabel2->setStyleSheet(QString::fromUtf8("\n"
"       color: #555555;\n"
"       font-size: 12px;\n"
"       font-weight: 600;\n"
"       font-family: \"Segoe UI\", sans-serif;\n"
"       margin-top: 10px;\n"
"      "));

        verticalLayout->addWidget(titleLabel2);

        titleEdit = new QLineEdit(EditSongDialog);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setStyleSheet(QString::fromUtf8("\n"
"       QLineEdit {\n"
"           background-color: #FFFFFF;\n"
"           border: 1px solid #D0D0D0;\n"
"           border-radius: 10px;\n"
"           color: #333333;\n"
"           font-size: 14px;\n"
"           padding: 12px 16px;\n"
"           font-family: \"Segoe UI\", sans-serif;\n"
"       }\n"
"       QLineEdit:focus {\n"
"           border-color: #007AFF;\n"
"       }\n"
"      "));

        verticalLayout->addWidget(titleEdit);

        genreLabel = new QLabel(EditSongDialog);
        genreLabel->setObjectName("genreLabel");
        genreLabel->setStyleSheet(QString::fromUtf8("\n"
"       color: #555555;\n"
"       font-size: 12px;\n"
"       font-weight: 600;\n"
"       font-family: \"Segoe UI\", sans-serif;\n"
"       margin-top: 10px;\n"
"      "));

        verticalLayout->addWidget(genreLabel);

        genreEdit = new QLineEdit(EditSongDialog);
        genreEdit->setObjectName("genreEdit");
        genreEdit->setStyleSheet(QString::fromUtf8("\n"
"       QLineEdit {\n"
"           background-color: #FFFFFF;\n"
"           border: 1px solid #D0D0D0;\n"
"           border-radius: 10px;\n"
"           color: #333333;\n"
"           font-size: 14px;\n"
"           padding: 12px 16px;\n"
"           font-family: \"Segoe UI\", sans-serif;\n"
"       }\n"
"       QLineEdit:focus {\n"
"           border-color: #007AFF;\n"
"       }\n"
"      "));

        verticalLayout->addWidget(genreEdit);

        yearDurationLayout = new QHBoxLayout();
        yearDurationLayout->setObjectName("yearDurationLayout");
        yearLabel = new QLabel(EditSongDialog);
        yearLabel->setObjectName("yearLabel");
        yearLabel->setStyleSheet(QString::fromUtf8("\n"
"         color: #555555;\n"
"         font-size: 12px;\n"
"         font-weight: 600;\n"
"         font-family: \"Segoe UI\", sans-serif;\n"
"        "));

        yearDurationLayout->addWidget(yearLabel);

        yearSpin = new QSpinBox(EditSongDialog);
        yearSpin->setObjectName("yearSpin");
        yearSpin->setMinimum(1900);
        yearSpin->setMaximum(2030);
        yearSpin->setValue(2024);
        yearSpin->setStyleSheet(QString::fromUtf8("\n"
"         QSpinBox {\n"
"             background-color: #FFFFFF;\n"
"             border: 1px solid #D0D0D0;\n"
"             border-radius: 10px;\n"
"             color: #333333;\n"
"             font-size: 14px;\n"
"             padding: 8px 12px;\n"
"             font-family: \"Segoe UI\", sans-serif;\n"
"         }\n"
"         QSpinBox:focus {\n"
"             border-color: #007AFF;\n"
"         }\n"
"        "));

        yearDurationLayout->addWidget(yearSpin);

        durationLabel = new QLabel(EditSongDialog);
        durationLabel->setObjectName("durationLabel");
        durationLabel->setStyleSheet(QString::fromUtf8("\n"
"         color: #555555;\n"
"         font-size: 12px;\n"
"         font-weight: 600;\n"
"         font-family: \"Segoe UI\", sans-serif;\n"
"         margin-left: 20px;\n"
"        "));

        yearDurationLayout->addWidget(durationLabel);

        durationSpin = new QSpinBox(EditSongDialog);
        durationSpin->setObjectName("durationSpin");
        durationSpin->setMinimum(5);
        durationSpin->setMaximum(600);
        durationSpin->setValue(180);
        durationSpin->setStyleSheet(QString::fromUtf8("\n"
"         QSpinBox {\n"
"             background-color: #FFFFFF;\n"
"             border: 1px solid #D0D0D0;\n"
"             border-radius: 10px;\n"
"             color: #333333;\n"
"             font-size: 14px;\n"
"             padding: 8px 12px;\n"
"             font-family: \"Segoe UI\", sans-serif;\n"
"         }\n"
"         QSpinBox:focus {\n"
"             border-color: #007AFF;\n"
"         }\n"
"        "));

        yearDurationLayout->addWidget(durationSpin);


        verticalLayout->addLayout(yearDurationLayout);

        albumLabel = new QLabel(EditSongDialog);
        albumLabel->setObjectName("albumLabel");
        albumLabel->setStyleSheet(QString::fromUtf8("\n"
"       color: #555555;\n"
"       font-size: 12px;\n"
"       font-weight: 600;\n"
"       font-family: \"Segoe UI\", sans-serif;\n"
"       margin-top: 10px;\n"
"      "));

        verticalLayout->addWidget(albumLabel);

        albumCombo = new QComboBox(EditSongDialog);
        albumCombo->setObjectName("albumCombo");
        albumCombo->setStyleSheet(QString::fromUtf8("\n"
"       QComboBox {\n"
"           background-color: #FFFFFF;\n"
"           border: 1px solid #D0D0D0;\n"
"           border-radius: 10px;\n"
"           color: #333333;\n"
"           font-size: 14px;\n"
"           padding: 10px 16px;\n"
"           font-family: \"Segoe UI\", sans-serif;\n"
"       }\n"
"       QComboBox:focus {\n"
"           border-color: #007AFF;\n"
"       }\n"
"       QComboBox::drop-down {\n"
"           border: none;\n"
"       }\n"
"      "));

        verticalLayout->addWidget(albumCombo);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        cancelBtn = new QPushButton(EditSongDialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("\n"
"         QPushButton {\n"
"             background-color: transparent;\n"
"             border: none;\n"
"             color: #007AFF;\n"
"             font-family: \"Segoe UI\", sans-serif;\n"
"             font-size: 14px;\n"
"             font-weight: 500;\n"
"             padding: 10px 20px;\n"
"         }\n"
"         QPushButton:hover {\n"
"             text-decoration: underline;\n"
"         }\n"
"        "));

        buttonLayout->addWidget(cancelBtn);

        saveBtn = new QPushButton(EditSongDialog);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setStyleSheet(QString::fromUtf8("\n"
"         QPushButton {\n"
"             background-color: #007AFF;\n"
"             border: none;\n"
"             border-radius: 10px;\n"
"             color: #FFFFFF;\n"
"             font-family: \"Segoe UI\", sans-serif;\n"
"             font-size: 14px;\n"
"             font-weight: 600;\n"
"             padding: 12px 30px;\n"
"             min-width: 150px;\n"
"         }\n"
"         QPushButton:hover {\n"
"             background-color: #0055CC;\n"
"         }\n"
"         QPushButton:pressed {\n"
"             background-color: #003399;\n"
"         }\n"
"        "));

        buttonLayout->addWidget(saveBtn);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(EditSongDialog);

        QMetaObject::connectSlotsByName(EditSongDialog);
    } // setupUi

    void retranslateUi(QDialog *EditSongDialog)
    {
        EditSongDialog->setWindowTitle(QCoreApplication::translate("EditSongDialog", "Edit Song", nullptr));
        titleLabel->setText(QCoreApplication::translate("EditSongDialog", "\360\237\216\265 Edit Song", nullptr));
        titleLabel2->setText(QCoreApplication::translate("EditSongDialog", "Song Title", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("EditSongDialog", "Enter song title", nullptr));
        genreLabel->setText(QCoreApplication::translate("EditSongDialog", "Genre", nullptr));
        genreEdit->setPlaceholderText(QCoreApplication::translate("EditSongDialog", "Enter genre", nullptr));
        yearLabel->setText(QCoreApplication::translate("EditSongDialog", "Release Year", nullptr));
        durationLabel->setText(QCoreApplication::translate("EditSongDialog", "Duration (s)", nullptr));
        albumLabel->setText(QCoreApplication::translate("EditSongDialog", "Album", nullptr));
        cancelBtn->setText(QCoreApplication::translate("EditSongDialog", "Cancel", nullptr));
        saveBtn->setText(QCoreApplication::translate("EditSongDialog", "\360\237\222\276 Save Changes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditSongDialog: public Ui_EditSongDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSONGDIALOG_H
