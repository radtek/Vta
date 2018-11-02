#include "opencvfun.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>


OpenCvFun::OpenCvFun()
{


}
QPoint OpenCvFun::MatchImage(const QString& img,const QString& tmp)
{

    QPoint p;
    QFileInfo fn(tmp);
    if(!fn.exists())
    {
        QMessageBox::critical(0,"Error !","File : VtaFile//"+tmp+"Not Find");
        return p;
    }
    IplImage* imgOriginal = cvLoadImage(img.toLatin1(), 0);
    IplImage* imgTemplate = cvLoadImage(tmp.toLatin1(), 0);

    IplImage* imgResult = cvCreateImage(cvSize(imgOriginal->width-imgTemplate->width+1, imgOriginal->height-imgTemplate->height+1), IPL_DEPTH_32F, 1);
     cvZero(imgResult);

       cvMatchTemplate(imgOriginal, imgTemplate, imgResult, CV_TM_CCORR_NORMED);


       double min_val=0, max_val=0;
          CvPoint min_loc, max_loc;
          cvMinMaxLoc(imgResult, &min_val, &max_val, &min_loc, &max_loc);
         cvRectangle(imgOriginal, max_loc, cvPoint(max_loc.x+imgTemplate->width, max_loc.y+imgTemplate->height), CV_RGB(253, 105, 55), 2);//cvScalar(0), 1);
           // printf(" max_val %f   : min_val   : %f   ", max_val,min_val);


       double fr = max_val;
       if(fr >= 0.999)
       {
           p.setX(max_loc.x);
           p.setY(max_loc.y);
       }
       else
       {
          //  qDebug()<<max_val;
          //  qDebug()<<min_val;
            p.setX(0);
            p.setY(0);


       }
   /*     cvNamedWindow("result");
       cvShowImage("result", imgOriginal);
   */
      return p;

}
QImage  OpenCvFun::MatToQImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type()==CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    else if(mat.type()==CV_8UC3)
    {
        // Copy input Mat
        const uchar *qImageBuffer = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        //qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}
