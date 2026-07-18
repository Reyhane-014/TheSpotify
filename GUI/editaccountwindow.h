#ifndef EDITACCOUNTWINDOW_H
#define EDITACCOUNTWINDOW_H

#include <QMainWindow>
#include "../Sources/services/authmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EditAccountWindow; }
QT_END_NAMESPACE

class EditAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditAccountWindow(int accountId, const QString& username, const QString& fullName, const QString& bio, QWidget *parent = nullptr);
    ~EditAccountWindow();

private slots:
    void onSaveClicked();
    void onCancelClicked();
    void onDeleteAccountClicked();

private:
    Ui::EditAccountWindow *ui;
    AuthManager authManager;
    int currentAccountId;
    void showError(const QString& msg);
    void clearError();
};

#endif