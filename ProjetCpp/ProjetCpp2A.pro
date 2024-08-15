#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql multimedia widgets serialport charts printsupport network texttospeech multimediawidgets
CONFIG += console stl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

OPENSSL_LIBS='-L/opt/ssl/lib -lssl -lcrypto' ./configure -openssl-linked
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    droitacces.cpp \
    fournisseur.cpp \
    login.cpp \
    main.cpp \
    connection.cpp \
    statfadwa.cpp \
    notification.cpp \
    qcustomplot.cpp \
    statstock.cpp \
    statplat.cpp \
    utilisateur.cpp \
    commande.cpp \
    commandefournisseur.cpp \
    evaluation.cpp \
    statevaluation.cpp \
    menu.cpp \
    offrefournisseur.cpp \
    plat.cpp \
    smtp.cpp \
    stock.cpp\
    produit.cpp\
    mainwindow.cpp \
    table.cpp \
    transaction.cpp \
    stat.cpp \
    stat_evaluation_fedi.cpp

HEADERS += \
    arduino.h \
    qcustomplot.h \
    statevaluation.h \
    droitacces.h \
    fournisseur.h \
    connection.h \
    statplat.h \
    login.h \
    statfadwa.h \
    notification.h \
    statstock.h \
    utilisateur.h \
    commande.h \
    commandefournisseur.h \
    evaluation.h \
    menu.h \
    offrefournisseur.h \
    plat.h \
    smtp.h \
    stock.h\
    produit.h\
    mainwindow.h \
    table.h \
    transaction.h \
    stat.h \
    stat_evaluation_fedi.h

FORMS += \
        mainwindow.ui\
        login.ui \
    statevaluation.ui \
    stat.ui \
    statfadwa.ui \
    statstock.ui \
    statplat.ui \
    stat_evaluation_fedi.ui


RC_ICONS = hat.ico

QMAKE_CXXFLAGS += -std=gnu++11
QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    ../Calque 0.png \
    ../Photos/hhhhhh.png
