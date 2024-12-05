#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = nullptr);

    QString getUsername() const { return usernameEdit->text(); }

signals:
    void loginSuccessful();

private slots:
    void attemptLogin();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QLabel *statusLabel;

    // Puteți modifica aceste date după preferințe sau le puteți lua dintr-o bază de date.
    QString validUsername = "admin";
    QString validPassword = "1234";
};

#endif // LOGINWINDOW_H
