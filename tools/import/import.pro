######################################################################
# Automatically generated by qmake (2.01a) Fri Jun 27 12:07:18 2008
######################################################################

include( ../../version.pri )

RESOURCES = import.qrc

TEMPLATE = app

DEPENDPATH += .

QT += xml

CONFIG += release

TARGET = drishtiimport

DESTDIR = ../../bin

win32 {

INCLUDEPATH += c:\drishtilib\netcdf\include \

QMAKE_LIBDIR += c:\drishtilib\netcdf\lib	   

LIBS += netcdf.lib
}

unix {
!macx {

INCLUDEPATH += . \
	16bit \
        /usr/include/netcdf-3

QMAKE_LFLAGS += -Xlinker -rpath -Xlinker \'\$\$ORIGIN/sharedlibs\' 
QMAKE_LFLAGS += -Xlinker -rpath -Xlinker \'\$\$ORIGIN/ITK\' 

QMAKE_LIBDIR += /usr/lib /usr/lib/x86_64-linux-gnu

LIBS += -lnetcdf_c++ \
        -lnetcdf \
}
}


macx {

INCLUDEPATH += . \
	/usr/local/include
	
QMAKE_LIBDIR += . \
	/usr/local/lib

LIBS += \
	-lnetcdf \
	-lnetcdf_c++
}

FORMS += remapwidget.ui \
	 savepvldialog.ui \
	 drishtiimport.ui \
	 fileslistdialog.ui

# Input
HEADERS += global.h \
	   common.h \
	   staticfunctions.h \
	   fileslistdialog.h \
	   remapwidget.h \
           remaphistogramline.h \
           remaphistogramwidget.h \
	   remapimage.h \
	   gradienteditor.h \
	   gradienteditorwidget.h \
	   dcolordialog.h \
	   dcolorwheel.h \
	   drishtiimport.h \
	   myslider.h \
	   raw2pvl.h \
	   savepvldialog.h \
	   volumefilemanager.h \
	   volumedata.h \
	   volinterface.h \
	   lookuptable.h marchingcubes.h ply.h

SOURCES += global.cpp \
	   staticfunctions.cpp \
	   fileslistdialog.cpp \
	   main.cpp \
           remapwidget.cpp \
           remaphistogramline.cpp \
           remaphistogramwidget.cpp \
	   remapimage.cpp \
	   gradienteditor.cpp \
	   gradienteditorwidget.cpp \
	   dcolordialog.cpp \
	   dcolorwheel.cpp \
	   drishtiimport.cpp \
	   myslider.cpp \
	   raw2pvl.cpp \
	   savepvldialog.cpp \
	   volumedata.cpp \
	   volumefilemanager.cpp \
	   marchingcubes.cpp ply.c

