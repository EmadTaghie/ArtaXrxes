#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QMainWindow>
#include <stdio.h>
#include <QDebug>
#include "iostream"
#include <QThread>
#include <QMutex>
#include <linux/joystick.h>

//#include "C:\Qt\ZBar\include\zbar.h"
#include "zbar-0.10/include/zbar.h"


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/nonfree/features2d.hpp"


#define Quad_hazmat_      10
#define Single_hazmat_    20
#define Non_hazmat_       30

using namespace cv;
using namespace std;
using namespace zbar;

class Process : public QObject
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = 0);
    void QR_scan(Mat a, QString *S);
    void motion(Mat m1, Mat m2, int thrsh);
    void prosses(Mat input, int thrsh, int mode);

    int detect(Mat img_1, Mat img_2);
    int filter_color(Mat m, int code);
    string hazmat_name(int a);
signals:
    void HazmatStart();
    void HazmatTakiStart();

    void HazmatDetected(Mat a,int x,int b ,int c, int d);
    void HazmattakiDetected(Mat a,int x,int b ,int c,int d,int e);
    void QRStart();
    void QRDetection(Mat a,QString b);
    void motionStart();
    void motionDetection(Mat a,int b);

public slots:
    void prosses();
    void prossesTaki(Mat a,int x,int b ,int c, int d);
    void QR_scan();
    void motion();
private:
    QString QrString_buff;
    ImageScanner scanner;
    Mat Hazmat;
    Mat motion1;
    Mat motion2;
    Mat QR;
    Mat QR_buff;
    int hazmatthrsh;
    int motionthrsh;
    int temp;

    int hazmat_mode;
};


#endif // PROCESS_H
