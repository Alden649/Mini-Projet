QT += core
QT -= gui
QT += xml

CONFIG += c++11

TARGET = Test_Svg
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    PlateformeDOM.cpp \
    RapporteurErreur.cpp \
    TypeNoeudDOM.cpp \
    graphe.cpp \
    sommet.cpp

HEADERS += \
    PlateformeDOM.h \
    RapporteurErreur.h \
    TypeNoeudDOM.h \
    graphe.h \
    sommet.h
