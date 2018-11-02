#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T07:30:28
#
#-------------------------------------------------

QT       += core gui xml network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VirtualTecnicalAssistance
TEMPLATE = app


SOURCES += main.cpp\
        vta.cpp \
    vtatask.cpp \
    convertor.cpp \
    VtaAiml/vtaaiml.cpp \
    VtaAiml/aimlparser.cpp \
    VtaSpeak/vtaspeak.cpp \
    VtaSpeak/vtaspeakrecognize.cpp \
    vtasetting.cpp \
    opencvfun.cpp \
    windowsfuncations.cpp \
    CaptureImage/imagecropper.cpp

HEADERS  += vta.h \
    vtatask.h \
    convertor.h \
    VtaAiml/vtaaiml.h \
    VtaAiml/aimlparser.h \
    VtaSpeak/vtaspeak.h \
    VtaSpeak/vtaspeakrecognize.h \
    vtasetting.h \
    opencvfun.h \
    windowsfuncations.h \
    CaptureImage/imagecropper.h \
    CaptureImage/imagecropper_e.h \
    CaptureImage/imagecropper_p.h

FORMS    += vta.ui \
    vtasetting.ui


RESOURCES +=

INCLUDEPATH += C:\\opencv\\include


LIBS += -LC:\\opencv\\x86\mingw\\lib\
-lopencv_calib3d310.dll \
-lopencv_core310.dll \
-lopencv_features2d310.dll \
-lopencv_flann310.dll \
-lopencv_highgui310.dll \
-lopencv_imgproc310.dll \
-lopencv_ml310.dll \
-lopencv_objdetect310.dll \
-lopencv_photo310.dll \
-lopencv_stitching310.dll \
-lopencv_superres310.dll \
-lopencv_videoio310.dll \
-lopencv_video310.dll \
-lopencv_videostab310.dll \
-lopencv_flann310.dll \
-lopencv_imgcodecs310.dll \
-lopencv_shape310.dll \
-lopencv_ts310

unix|win32: LIBS += -lQt5Test

unix|win32: LIBS += -lQt5Core
