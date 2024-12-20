QT += quick
QT += core gui
QT += widgets
#QT += quickcontrols2

SOURCES += \
        main.cpp \
        maincontroller.cpp \
        megamillionsthread.cpp \
        meganumcheckthread.cpp \
        numbercheckthread.cpp \
        powerballthread.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources \
    images.qrc \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    maincontroller.h \
    megamillionsthread.h \
    meganumcheckthread.h \
    numbercheckthread.h \
    powerballthread.h
