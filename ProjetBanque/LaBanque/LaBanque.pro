TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        comptebancaire.cpp \
        comptecilent.cpp \
        compteepargne.cpp \
        main.cpp \
        menu.cpp

HEADERS += \
    comptebancaire.h \
    comptecilent.h \
    compteepargne.h \
    menu.h

DISTFILES += \
    CompteBancaire.txt \
    compteEpargne.txt
