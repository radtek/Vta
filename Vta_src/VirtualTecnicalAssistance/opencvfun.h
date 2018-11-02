#ifndef OPENCVFUN_H
#define OPENCVFUN_H

#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv/cv.h>
#include <sstream>
#include <QtGui>

using namespace cv;
using namespace std;

class OpenCvFun
{
public:
    OpenCvFun();
 static  QPoint MatchImage(const QString& img,const QString& tmp);
 static QImage   MatToQImage(const Mat& mat);

};

#endif // OPENCVFUN_H
