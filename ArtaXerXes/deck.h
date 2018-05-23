#ifndef DECK_H
#define DECK_H

#include <QObject>
#include "xnetwork.h"
#include <QThread>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <QImage>
#include <QTimer>
#include <QDataStream>
#include <QByteArray>
#include <iostream>

#define main_RX_packet_size 60



using namespace std;
using namespace cv;

struct motorDataPkg
{
    __uint8_t data[4];
};

struct driversPkg
{
  motorDataPkg motor[3];
};

struct HeadPkg
{
    __uint8_t gas_data;
};

enum driveID
{
    slave1 =0 ,//right motor , front filipper
    slave2 =1 ,//left motor ,  back  filiper
    slave3 =2 ,//arm0 , arm1, arm2
    slave4 =3 ,//pr , roll ,pitch
};

enum ARMID
{
    ARM0 =0 ,
    ARM1 =1 ,
    ARM2 =2 ,
};


class Deck : public QObject
{
    Q_OBJECT
public:
    explicit Deck(QObject *parent = 0);

    void set_main_data(QByteArray m, char header[]);
    void send_hazmat_thresh(uint8_t thr);
    float get_arms_angle(__uint8_t namber);
    __uint8_t get_gas_data();
signals:
    void thermalImIsReady(Mat m);
    void mainDataIsReady();
    void MapImageIsReady(Mat m);
    void mainDataReadyForSend();

public slots:

private slots:
    void thermalreadyRead();
    void mapreadyRead();
    void mainreadyRead();
    void MainDatasend();
private:
    XNetwork main_;
    XNetwork thermal;
    XNetwork map;
    XNetwork Hazmat;
    QImage Thermal_Image;
    QByteArray thermal_data_Rx;
    QByteArray main_data_Rx;
    QByteArray map_data_Rx;
    driversPkg Motorfeedback[4];
    HeadPkg headfeedback;
    Mat Map_image;
    QByteArray main_data_Tx;

};

#endif // DECK_H
