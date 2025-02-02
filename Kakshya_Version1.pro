QT +=  widgets
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addedsuccessfully.cpp \
    addvaluestoroutine.cpp \
    bookclassroom.cpp \
    coordinatordash.cpp \
    crdash.cpp \
    crsearchclass.cpp \
    forgotpassword.cpp \
    loginpage.cpp \
    loginsuccessful.cpp \
    main.cpp \
    mainwindow.cpp \
    passwordchanged.cpp \
    selectcr.cpp \
    signupdialog.cpp \
    signupsuccessful.cpp \
    studentdash.cpp \
    teacherdash.cpp \
    teachersearch.cpp \
    uploadroutine.cpp

HEADERS += \
    addedsuccessfully.h \
    addvaluestoroutine.h \
    bookclassroom.h \
    coordinatordash.h \
    crdash.h \
    crsearchclass.h \
    forgotpassword.h \
    loginpage.h \
    loginsuccessful.h \
    mainwindow.h \
    passwordchanged.h \
    selectcr.h \
    signupdialog.h \
    signupsuccessful.h \
    studentdash.h \
    teacherdash.h \
    teachersearch.h \
    uploadroutine.h

FORMS += \
    addedsuccessfully.ui \
    addvaluestoroutine.ui \
    bookclassroom.ui \
    coordinatordash.ui \
    crdash.ui \
    crsearchclass.ui \
    forgotpassword.ui \
    loginpage.ui \
    loginsuccessful.ui \
    passwordchanged.ui \
    selectcr.ui \
    signupdialog.ui \
    signupsuccessful.ui \
    studentdash.ui \
    teacherdash.ui \
    teachersearch.ui \
    uploadroutine.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
