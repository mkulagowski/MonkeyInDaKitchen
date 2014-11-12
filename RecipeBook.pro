#-------------------------------------------------
#
# Project created by QtCreator 2014-10-31T01:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RecipeBook
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Recipe.cpp \
    RecipeBook.cpp \
    recipespanel.cpp \
    addrecipepanel.cpp \
    addrecipeingredients.cpp \
    addrecipetxt.cpp \
    addrecipephoto.cpp \
    removerecipepanel.cpp \
    findrecipepanel.cpp

HEADERS  += mainwindow.h \
    RecipeBook.h \
    Recipe.h \
    recipespanel.h \
    recipespanel.h \
    addrecipepanel.h \
    addrecipeingredients.h \
    addrecipetxt.h \
    addrecipephoto.h \
    removerecipepanel.h \
    findrecipepanel.h

FORMS    += mainwindow.ui \
    recipespanel.ui \
    recipespanel.ui \
    addrecipepanel.ui \
    addrecipeingredients.ui \
    addrecipetxt.ui \
    addrecipephoto.ui \
    removerecipepanel.ui \
    findrecipepanel.ui
CONFIG += c++11
