/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer;
    QLabel *fullNameLabel;
    QLineEdit *fullNameEdit;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QLabel *roleLabel;
    QComboBox *roleCombo;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *buttonLayout;
    QPushButton *registerBtn;
    QPushButton *backBtn;
    QLabel *errorLabel;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(500, 550);
        RegisterWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background: qlineargradient(\n"
"            x1: 0, y1: 0,\n"
"            x2: 1, y2: 1,\n"
"            stop: 0 #F5F5F5,\n"
"            stop: 1 #E0E0E0\n"
"        );\n"
"    }\n"
"   "));
        centralwidget = new QWidget(RegisterWindow);
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

        subtitleLabel = new QLabel(centralwidget);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setAlignment(Qt::AlignLeft);
        subtitleLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #888888;\n"
"        font-size: 14px;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(subtitleLabel);

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

        roleLabel = new QLabel(centralwidget);
        roleLabel->setObjectName("roleLabel");
        roleLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #555555;\n"
"        font-size: 12px;\n"
"        font-weight: 600;\n"
"        font-family: \"Helvetica Neue\", sans-serif;\n"
"       "));

        verticalLayout->addWidget(roleLabel);

        roleCombo = new QComboBox(centralwidget);
        roleCombo->addItem(QString());
        roleCombo->addItem(QString());
        roleCombo->setObjectName("roleCombo");
        roleCombo->setStyleSheet(QString::fromUtf8("\n"
"        QComboBox {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #D0D0D0;\n"
"            border-radius: 25px;\n"
"            color: #333333;\n"
"            font-size: 14px;\n"
"            padding: 12px 20px;\n"
"            font-family: \"Helvetica Neue\", sans-serif;\n"
"        }\n"
"        QComboBox:focus {\n"
"            border-color: #007AFF;\n"
"        }\n"
"        QComboBox::drop-down {\n"
"            border: none;\n"
"        }\n"
"        QComboBox QAbstractItemView {\n"
"            background-color: #FFFFFF;\n"
"            border: 1px solid #D0D0D0;\n"
"            border-radius: 10px;\n"
"            color: #333333;\n"
"            selection-background-color: #007AFF;\n"
"            selection-color: #FFFFFF;\n"
"        }\n"
"       "));

        verticalLayout->addWidget(roleCombo);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonLayout = new QVBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        registerBtn = new QPushButton(centralwidget);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #007AFF;\n"
"              border: none;\n"
"              border-radius: 25px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Helvetica Neue\", sans-serif;\n"
"              font-size: 16px;\n"
"              font-weight: 600;\n"
"              padding: 14px 30px;\n"
"              min-width: 200px;\n"
"              min-height: 50px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #0055CC;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #003399;\n"
"          }\n"
"         "));

        buttonLayout->addWidget(registerBtn);

        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName("backBtn");
        backBtn->setStyleSheet(QString::fromUtf8("\n"
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

        buttonLayout->addWidget(backBtn);


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

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 22));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName("statusbar");
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Create Account", nullptr));
        titleLabel->setText(QCoreApplication::translate("RegisterWindow", "\360\237\216\266 Create Account", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("RegisterWindow", "Create your account to get started", nullptr));
        fullNameLabel->setText(QCoreApplication::translate("RegisterWindow", "Full Name", nullptr));
        fullNameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Enter your full name", nullptr));
        usernameLabel->setText(QCoreApplication::translate("RegisterWindow", "Username", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Choose a username", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Create a password", nullptr));
        roleLabel->setText(QCoreApplication::translate("RegisterWindow", "I am a...", nullptr));
        roleCombo->setItemText(0, QCoreApplication::translate("RegisterWindow", "Artist", nullptr));
        roleCombo->setItemText(1, QCoreApplication::translate("RegisterWindow", "Listener", nullptr));

        registerBtn->setText(QCoreApplication::translate("RegisterWindow", "CREATE ACCOUNT", nullptr));
        backBtn->setText(QCoreApplication::translate("RegisterWindow", "Back to Login", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
