TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        barre.cpp \
        barrecarre.cpp \
        barreronde.cpp \
        catalogue.cpp \
        main.cpp \
        menu.cpp

HEADERS += \
    barre.h \
    barrecarre.h \
    barreronde.h \
    catalogue.h \
    menu.h

DISTFILES += \
    barre.txt
