/********************************************************************************
** Form generated from reading UI file 'editaccountwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITACCOUNTWINDOW_H
#define UI_EDITACCOUNTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAccountWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QLabel *fullNameLabel;
    QLineEdit *fullNameEdit;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *bioLabel;
    QTextEdit *bioEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *saveBtn;
    QHBoxLayout *buttonLayout;
    QPushButton *cancelBtn;
    QPushButton *deleteAccountBtn;
    QLabel *errorLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EditAccountWindow)
    {
        if (EditAccountWindow->objectName().isEmpty())
            EditAccountWindow->setObjectName("EditAccountWindow");
        EditAccountWindow->resize(500, 600);
        EditAccountWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background: qlineargradient(\n"
"            x1: 0, y1: 0,\n"
"            x2: 1, y2: 1,\n"
"            stop: 0 #F5F5F5,\n"
"            stop: 1 #E0E0E0\n"
"        );\n"
"    }\n"
"   "));
        centralwidget = new QWidget(EditAccountWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 40, 50, 40);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignLeft);
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #333333;\n"
"        font-size: 28px;\n"
"        font-weight: 300;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"        letter-spacing: 2px;\n"
"       "));

        verticalLayout->addWidget(titleLabel);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        fullNameLabel = new QLabel(centralwidget);
        fullNameLabel->setObjectName("fullNameLabel");
        fullNameLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #555555;\n"
"        font-size: 12px;\n"
"        font-weight: 600;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(fullNameLabel);

        fullNameEdit = new QLineEdit(centralwidget);
        fullNameEdit->setObjectName("fullNameEdit");
        fullNameEdit->setStyleSheet(QString::fromUtf8("\n"
"        QLineEdit {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #D0D0D0;\n"
"            border-radius: 25px;\n"
"            color: #333333;\n"
"            font-size: 14px;\n"
"            padding: 14px 20px;\n"
"            font-family: \"Helvetica Neue\", sans-serif;\n"
"        }\n"
"        QLineEdit:focus {\n"
"            border-color: #007AFF;\n"
"        }\n"
"       "));

        verticalLayout->addWidget(fullNameEdit);

        usernameLabel = new QLabel(centralwidget);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #555555;\n"
"        font-size: 12px;\n"
"        font-weight: 600;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(centralwidget);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setStyleSheet(QString::fromUtf8("\n"
"        QLineEdit {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #D0D0D0;\n"
"            border-radius: 25px;\n"
"            color: #333333;\n"
"            font-size: 14px;\n"
"            padding: 14px 20px;\n"
"            font-family: \"Helvetica Neue\", sans-serif;\n"
"        }\n"
"        QLineEdit:focus {\n"
"            border-color: #007AFF;\n"
"        }\n"
"       "));

        verticalLayout->addWidget(usernameEdit);

        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #555555;\n"
"        font-size: 12px;\n"
"        font-weight: 600;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setStyleSheet(QString::fromUtf8("\n"
"        QLineEdit {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #D0D0D0;\n"
"            border-radius: 25px;\n"
"            color: #333333;\n"
"            font-size: 14px;\n"
"            padding: 14px 20px;\n"
"            font-family: \"Helvetica Neue\", sans-serif;\n"
"        }\n"
"        QLineEdit:focus {\n"
"            border-color: #007AFF;\n"
"        }\n"
"       "));

        verticalLayout->addWidget(passwordEdit);

        bioLabel = new QLabel(centralwidget);
        bioLabel->setObjectName("bioLabel");
        bioLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #555555;\n"
"        font-size: 12px;\n"
"        font-weight: 600;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(bioLabel);

        bioEdit = new QTextEdit(centralwidget);
        bioEdit->setObjectName("bioEdit");
        bioEdit->setStyleSheet(QString::fromUtf8("\n"
"        QTextEdit {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #D0D0D0;\n"
"            border-radius: 15px;\n"
"            color: #333333;\n"
"            font-size: 14px;\n"
"            padding: 14px 20px;\n"
"            font-family: \"Helvetica Neue\", sans-serif;\n"
"            min-height: 80px;\n"
"        }\n"
"        QTextEdit:focus {\n"
"            border-color: #007AFF;\n"
"        }\n"
"       "));

        verticalLayout->addWidget(bioEdit);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        saveBtn = new QPushButton(centralwidget);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setStyleSheet(QString::fromUtf8("\n"
"        QPushButton {\n"
"            background-color: #007AFF;\n"
"            border: none;\n"
"            border-radius: 25px;\n"
"            color: #FFFFFF;\n"
"            font-family: \"Helvetica Neue\", sans-serif;\n"
"            font-size: 16px;\n"
"            font-weight: 600;\n"
"            padding: 14px 30px;\n"
"            min-height: 50px;\n"
"        }\n"
"        QPushButton:hover {\n"
"            background-color: #0055CC;\n"
"        }\n"
"        QPushButton:pressed {\n"
"            background-color: #003399;\n"
"        }\n"
"       "));

        verticalLayout->addWidget(saveBtn);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        cancelBtn = new QPushButton(centralwidget);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: transparent;\n"
"              border: none;\n"
"              color: #007AFF;\n"
"              font-family: \"Helvetica Neue\", sans-serif;\n"
"              font-size: 14px;\n"
"              font-weight: 500;\n"
"              padding: 10px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              text-decoration: underline;\n"
"          }\n"
"         "));

        buttonLayout->addWidget(cancelBtn);

        deleteAccountBtn = new QPushButton(centralwidget);
        deleteAccountBtn->setObjectName("deleteAccountBtn");
        deleteAccountBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #E94560;\n"
"              border: none;\n"
"              border-radius: 25px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Helvetica Neue\", sans-serif;\n"
"              font-size: 14px;\n"
"              font-weight: 600;\n"
"              padding: 14px 20px;\n"
"              min-height: 50px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #C73E54;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #A03245;\n"
"          }\n"
"         "));

        buttonLayout->addWidget(deleteAccountBtn);


        verticalLayout->addLayout(buttonLayout);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setVisible(false);
        errorLabel->setAlignment(Qt::AlignCenter);
        errorLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #FF3B30;\n"
"        font-size: 13px;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(errorLabel);

        EditAccountWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EditAccountWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 22));
        EditAccountWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EditAccountWindow);
        statusbar->setObjectName("statusbar");
        EditAccountWindow->setStatusBar(statusbar);

        retranslateUi(EditAccountWindow);

        QMetaObject::connectSlotsByName(EditAccountWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EditAccountWindow)
    {
        EditAccountWindow->setWindowTitle(QCoreApplication::translate("EditAccountWindow", "Edit Account", nullptr));
        titleLabel->setText(QCoreApplication::translate("EditAccountWindow", "Edit Account", nullptr));
        fullNameLabel->setText(QCoreApplication::translate("EditAccountWindow", "Full Name", nullptr));
        fullNameEdit->setPlaceholderText(QCoreApplication::translate("EditAccountWindow", "Enter your full name", nullptr));
        usernameLabel->setText(QCoreApplication::translate("EditAccountWindow", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("EditAccountWindow", "Choose a username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("EditAccountWindow", "New Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("EditAccountWindow", "Enter new password", nullptr));
        bioLabel->setText(QCoreApplication::translate("EditAccountWindow", "Bio", nullptr));
        bioEdit->setPlaceholderText(QCoreApplication::translate("EditAccountWindow", "Tell us about yourself...", nullptr));
        saveBtn->setText(QCoreApplication::translate("EditAccountWindow", "SAVE CHANGES", nullptr));
        cancelBtn->setText(QCoreApplication::translate("EditAccountWindow", "Cancel", nullptr));
        deleteAccountBtn->setText(QCoreApplication::translate("EditAccountWindow", "DELETE ACCOUNT", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EditAccountWindow: public Ui_EditAccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITACCOUNTWINDOW_H
