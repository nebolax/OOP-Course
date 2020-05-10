QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    tartefact.cpp \
    tearthgamecell.cpp \
    tearthperson.cpp \
    tenemy.cpp \
    tfinishgamecell.cpp \
    tfiregamecell.cpp \
    tfireperson.cpp \
    tfirstartefact.cpp \
    tfirstenemy.cpp \
    tgamecell.cpp \
    tgamemech.cpp \
    tperson.cpp \
    tsecondartefact.cpp \
    tsecondenemy.cpp \
    twatergamecell.cpp \
    twaterperson.cpp

HEADERS += \
    tartefact.h \
    tearthgamecell.h \
    tearthperson.h \
    tenemy.h \
    tfinishgamecell.h \
    tfiregamecell.h \
    tfireperson.h \
    tfirstartefact.h \
    tfirstenemy.h \
    tgamecell.h \
    tgamemech.h \
    tmagicreserve.h \
    tperson.h \
    tsecondartefact.h \
    tsecondenemy.h \
    twatergamecell.h \
    twaterperson.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    pictures.qrc
