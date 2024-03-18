TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
#CONFIG -= qt


SOURCES += \
        main.cpp

INCLUDEPATH += "C:\Users\juani\OneDrive\Escritorio\POO\Clase 3\Ej2Lib"

LIBS += -L"C:\Users\juani\OneDrive\Escritorio\POO\Clase 3\build-Ej2Lib-Desktop_Qt_6_6_2_MinGW_64_bit-Debug\debug"

LIBS += -lEj2Lib
