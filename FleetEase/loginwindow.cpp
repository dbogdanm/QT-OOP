#include "Models/loginwindow.h".h"
#include <QVBoxLayout>
#include <QFormLayout>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password); // Parola ascunsă

    formLayout->addRow("Username:", usernameEdit);
    formLayout->addRow("Password:", passwordEdit);

    loginButton = new QPushButton("Login", this);
    statusLabel = new QLabel(this);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(loginButton);
    mainLayout->addWidget(statusLabel);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::attemptLogin);
}

void LoginWindow::attemptLogin()
{
    QString enteredUsername = usernameEdit->text();
    QString enteredPassword = passwordEdit->text();

    if (enteredUsername == validUsername && enteredPassword == validPassword) {
        // Autentificare reușită
        emit loginSuccessful();
    } else {
        // Autentificare eșuată
        statusLabel->setText("Username sau parolă incorecte!");
    }
}
