#include "editaccountwindow.h"
#include "ui_editaccountwindow.h"
#include <QMessageBox>

EditAccountWindow::EditAccountWindow(int accountId, const QString& username, const QString& fullName, const QString& bio, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditAccountWindow)
    , currentAccountId(accountId)
{
    ui->setupUi(this);

    ui->usernameEdit->setText(username);
    ui->fullNameEdit->setText(fullName);
    ui->bioEdit->setText(bio);

    connect(ui->saveBtn, &QPushButton::clicked, this, &EditAccountWindow::onSaveClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &EditAccountWindow::onCancelClicked);
    connect(ui->deleteAccountBtn, &QPushButton::clicked, this, &EditAccountWindow::onDeleteAccountClicked);
}

EditAccountWindow::~EditAccountWindow()
{
    delete ui;
}

void EditAccountWindow::onSaveClicked()
{
    clearError();

    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString fullName = ui->fullNameEdit->text();
    QString bio = ui->bioEdit->toPlainText();

    if (username.isEmpty() || password.isEmpty() || fullName.isEmpty()) {
        showError("Please fill in all required fields!");
        return;
    }

    if (authManager.updateAccount(currentAccountId, username.toStdString(), password.toStdString(), fullName.toStdString(), bio.toStdString())) {
        QMessageBox::information(this, "Success", "Account updated successfully!");
        this->close();
    } else {
        showError("Failed to update account. Username may already exist!");
    }
}

void EditAccountWindow::onCancelClicked()
{
    this->close();
}

void EditAccountWindow::onDeleteAccountClicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Account",
                                  "Are you sure you want to delete your account? This action cannot be undone!",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (authManager.deleteAccount(currentAccountId)) {
            QMessageBox::information(this, "Success", "Account deleted successfully!");
            this->close();
            QApplication::quit();
        } else {
            showError("Failed to delete account!");
        }
    }
}

void EditAccountWindow::showError(const QString& msg)
{
    ui->errorLabel->setText(msg);
    ui->errorLabel->setVisible(true);
}

void EditAccountWindow::clearError()
{
    ui->errorLabel->setVisible(false);
}