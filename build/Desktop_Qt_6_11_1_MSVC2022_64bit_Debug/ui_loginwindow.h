/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *buttonLayout;
    QPushButton *loginBtn;
    QPushButton *registerBtn;
    QLabel *errorLabel;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(500, 400);
        LoginWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background: qlineargradient(\n"
"            x1: 0, y1: 0,\n"
"            x2: 1, y2: 1,\n"
"            stop: 0 #F5F5F5,\n"
"            stop: 1 #E0E0E0\n"
"        );\n"
"    }\n"
"   "));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(50, 50, 50, 50);
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignLeft);
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"        color: #333333;\n"
"        font-size: 32px;\n"
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

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

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

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        loginBtn = new QPushButton(centralwidget);
        loginBtn->setObjectName("loginBtn");
        loginBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: #007AFF;\n"
"              border: none;\n"
"              border-radius: 25px;\n"
"              color: #FFFFFF;\n"
"              font-family: \"Helvetica Neue\", sans-serif;\n"
"              font-size: 16px;\n"
"              font-weight: 600;\n"
"              padding: 14px 30px;\n"
"              min-width: 150px;\n"
"              min-height: 50px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              background-color: #0055CC;\n"
"          }\n"
"          QPushButton:pressed {\n"
"              background-color: #003399;\n"
"          }\n"
"         "));

        buttonLayout->addWidget(loginBtn);

        registerBtn = new QPushButton(centralwidget);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setStyleSheet(QString::fromUtf8("\n"
"          QPushButton {\n"
"              background-color: transparent;\n"
"              border: none;\n"
"              color: #007AFF;\n"
"              font-family: \"Helvetica Neue\", sans-serif;\n"
"              font-size: 14px;\n"
"              font-weight: 500;\n"
"              padding: 14px 20px;\n"
"              min-width: 150px;\n"
"              min-height: 50px;\n"
"          }\n"
"          QPushButton:hover {\n"
"              text-decoration: underline;\n"
"          }\n"
"         "));

        buttonLayout->addWidget(registerBtn);


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

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 22));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Music Player", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginWindow", "\360\237\216\266 Music Player", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("LoginWindow", "Sign in to continue", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Username or email", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginWindow", "Sign In", nullptr));
        registerBtn->setText(QCoreApplication::translate("LoginWindow", "Create Account", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
