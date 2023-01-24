TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        circle.cpp \
        main.cpp \
        square.cpp

HEADERS += \
    circle.h \
    ellipse.h \
    rectangle.h \
    shape.h \
    square.h \
    triangle.h
