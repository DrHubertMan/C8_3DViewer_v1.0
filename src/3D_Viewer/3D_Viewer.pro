QT += core gui printsupport charts opengl

macx {
  LIBS += -framework OpenGL
}
unix:!macx {
  LIBS += -lGLU -lGL
}

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

SOURCES += \
        main.cc \
        mainwidget.cc \
        mybutton.cc \
        draw.cc\
        gif.cc\
        c-function/core/core.c\
        c-function/core/pars.c\
        c-function/support/support_function.c

HEADERS += \
    mainwidget.h \
    mybutton.h \
    draw.h\
    gif.h\
    c-function/core/core.h\
    c-function/core/pars.h\
    c-function/support/support_function.h
