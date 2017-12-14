TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\SFML-2.3.2\lib"
LIBS += -L"..\SFML-2.3.2\bin"

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.3.2\include"
DEPENDPATH += "..\SFML-2.3.2\include"

#MAC
#INCLUDEPATH += "/usr/local/include"
#DEPENDPATH += "/usr/local/include"

HEADERS += \
    test_fcns.h \
    binary_fcns.h \
    doubles.h \
    token.h \
    unary_fcns.h \
    free_fcns.h \
    linked_list_struct.h \
    list_class.h \
    my_library.h \
    queue.h \
    stack.h \
    shunting_yard.h \
    variable.h \
    special.h \
    rpn.h \
    animate.h \
    system.h \
    random.h \
    constants.h \
    translate.h \
    graph.h

SOURCES += \
    test_fcns.cpp \
    binary_fcns.cpp \
    doubles.cpp \
    token.cpp \
    unary_fcns.cpp \
    variable.cpp \
    my_library.cpp \
    main.cpp \
    shunting_yard.cpp \
    special.cpp \
    rpn.cpp \
    animate.cpp \
    system.cpp \
    random.cpp \
    translate.cpp \
    graph.cpp
