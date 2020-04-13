QT       += core gui \
            xml \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjlib\include \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjmedia\include \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjlib-util\include \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjnath\include \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjsip\include \
    C:\Users\ssafarov\Downloads\pjproject-2.10TEST\pjproject-2.10\pjsip-apps\src\pjsua\include \
    C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\include \
    C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjmedia\include \
    C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib-util\include \
    C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjnath\include \
    C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjsip\include \
    C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjsip-apps\src\pjsua\include \




# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


LIBS += \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\libpjproject-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjlib-util-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjlib-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjmedia-audiodev-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjmedia-codec-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjmedia-videodev-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjmedia-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjnath-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjsip-core-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjsip-simple-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjsip-ua-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjsua2-lib-x86_64-x64-vc14-Release-Dynamic.lib \
    #C:\Users\ssafarov\Downloads\pjprojectX64\pjproject-2.10\pjlib\lib\pjsua-lib-x86_64-x64-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjlib\lib\pjlib-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjmedia\lib\pjmedia-audiodev-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjmedia\lib\pjmedia-codec-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjmedia\lib\pjmedia-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjmedia\lib\pjmedia-videodev-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjlib-util\lib\pjlib-util-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\third_party\lib\libspeex-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\third_party\lib\libsrtp-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjsip\lib\pjsua2-lib-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjsip\lib\pjsua-lib-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjsip\lib\pjsip-simple-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjsip\lib\pjsip-core-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjlib\lib\pjnath-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v2\pjproject-2.10\pjlib\lib\libpjproject-i386-Win32-vc14-Release-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjlib\lib\pjlib-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjlib-util\lib\pjlib-util-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjmedia\lib\pjmedia-audiodev-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjmedia\lib\pjmedia-codec-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjmedia\lib\pjmedia-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjmedia\lib\pjmedia-videodev-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjnath\lib\pjnath-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjsip\lib\pjsip-core-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjsip\lib\pjsip-simple-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjsip\lib\pjsip-ua-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjsip\lib\pjsua2-lib-i386-Win32-vc14-Debug-Dynamic.lib \
    C:\Users\ssafarov\Downloads\pjproject-2.10v3\pjproject-2.10\pjsip\lib\pjsua-lib-i386-Win32-vc14-Debug-Dynamic.lib \
    -lWs2_32 \
    -lOle32 \




# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    PjSipadaptr.cpp \
    addcontact.cpp \
    dialog.cpp \
    dialogcontact.cpp \
    main.cpp \
    mainwindow.cpp \
    readXmlFile.cpp

HEADERS += \
    PjSipadptr.h \
    addcontact.h \
    app_config.h \
    dialog.h \
    dialogcontact.h \
    mainwindow.h \
    readXmlFile.h

FORMS += \
    addcontact.ui \
    dialog.ui \
    dialogcontact.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
