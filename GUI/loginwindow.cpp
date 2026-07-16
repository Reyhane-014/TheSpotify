#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "artistdashboard.h"
#include "listenerdashboard.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    connect(ui->loginBtn, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(ui->registerBtn, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onLoginClicked()
{
    clearError();

    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        showError("Please enter both username and password!");
        return;
    }

    auto account = authManager.loginUser(username.toStdString(), password.toStdString());

    if (account == nullptr) {
        showError("Invalid username or password!");
        return;
    }

    if (account->getRole() == Role::Artist) {
        ArtistDashboard *dashboard = new ArtistDashboard(account->getId(), this);
        dashboard->show();
        this->hide();
    } else {
        ListenerDashboard *dashboard = new ListenerDashboard(account->getId(), this);
        dashboard->show();
        this->hide();
    }
}

void LoginWindow::onRegisterClicked()
{
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

void LoginWindow::showError(const QString& msg)
{
    ui->errorLabel->setText(msg);
    ui->errorLabel->setVisible(true);
}

void LoginWindow::clearError()
{
    ui->errorLabel->setVisible(false);
}