QT -= gui

QT += core network

CONFIG += c++17 console
QMAKE_CXXFLAGS += -std=c++17
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        server_adapter.cpp \
        command_receiver.cpp \
    movement_controller.cpp \
    system_tasks_handler.cpp \
    engine.cpp

LIBS += -lwiringPi -lpthread

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    engine_status.h \
    command_receiver.h \
    pin_state.h \
    movement_controller.h \
    rotation_direction.h \
    movement_direction.h \
    system_tasks_handler.h \
    server_adapter.h \
    drive_train.h \
    engine.h
