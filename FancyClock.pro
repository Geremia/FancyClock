#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T15:25:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FancyClock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    preference.cpp

HEADERS  += mainwindow.h \
    preference.h

FORMS    += mainwindow.ui \
    preference.ui

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
