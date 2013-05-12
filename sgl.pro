TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    filereader.cpp \
    shader.cpp

QMAKE_CXXFLAGS += -std=c++11
LIBS += -lGL
LIBS += -lglfw
LIBS += -lglloadD
LIBS += -lglut


LIBS += -lboost_system

HEADERS += \
    shader.h \
    filereader.h

OTHER_FILES += \
    pos.vert \
    color.frag
