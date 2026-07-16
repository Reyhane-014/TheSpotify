#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include "../Sources/services/authmanager.h"

namespace Ui { class RegisterWindow; }

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void onRegisterClicked();
    void onBackClicked();

private:
    Ui::RegisterWindow *ui;
    AuthManager authManager;
    void showError(const QString& msg);
    void clearError();
};

#endif