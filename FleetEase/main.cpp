#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "mainwindow.h"
#include "Models/loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Splash screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png")); // imagine sau simplu text
    splash->show();
    a.processEvents();

    // După 2-3 secunde, închidem splash screen-ul și afișăm fereastra de login
    QTimer::singleShot(2500, splash, &QWidget::close);

    LoginWindow loginWindow;
    QObject::connect(&loginWindow, &LoginWindow::loginSuccessful, [&](){
        // După login cu succes, afișăm fereastra principală
        MainWindow *w = new MainWindow(loginWindow.getUsername());
        w->show();
        loginWindow.close();
    });

    // Așteptăm încheierea splash screen-ului înainte de a afișa fereastra de login
    QTimer::singleShot(2500, [&](){
        loginWindow.show();
    });

    return a.exec();
}
