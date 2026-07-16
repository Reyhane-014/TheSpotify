#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    ui->roleCombo->addItem("Artist");
    ui->roleCombo->addItem("Listener");

    connect(ui->registerBtn, &QPushButton::clicked, this, &RegisterWindow::onRegisterClicked);
    connect(ui->backBtn, &QPushButton::clicked, this, &RegisterWindow::onBackClicked);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::onRegisterClicked()
{
    clearError();

    QString fullName = ui->fullNameEdit->text();
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString role = ui->roleCombo->currentText();

    if (fullName.isEmpty() || username.isEmpty() || password.isEmpty()) {
        showError("Please fill in all required fields!");
        return;
    }

    bool success = authManager.registerUser(
        username.toStdString(),
        password.toStdString(),
        fullName.toStdString(),
        "",
        role.toStdString()
        );

    if (success) {
        QMessageBox::information(this, "Success", "Account created successfully!");
        onBackClicked();
    } else {
        showError("Username already exists or invalid input!");
    }
}

void RegisterWindow::onBackClicked()
{
    this->close();
}

void RegisterWindow::showError(const QString& msg)
{
    ui->errorLabel->setText(msg);
    ui->errorLabel->setVisible(true);
}

void RegisterWindow::clearError()
{
    ui->errorLabel->setVisible(false);
}