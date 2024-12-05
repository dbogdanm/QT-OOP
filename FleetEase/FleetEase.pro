QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    driver.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Exceptions/DriverNotFoundException.h \
    Exceptions/FleetException.h \
    Exceptions/RouteNotFoundException.h \
    Exceptions/VehicleNotFoundException.h \
    Models/Bus.h \
    Models/Driver.h \
    Models/FleetManager.h \
    Models/Helper.h \
    Models/Motorcycle.h \
    Models/Route.h \
    Models/Truck.h \
    Models/Vehicle.h \
    Models/loginwindow.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += resources.qrc \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
