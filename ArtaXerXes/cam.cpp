#include "cam.h"

Cam::Cam(QObject *parent) : QObject(parent)
{
}

void Cam::openCam(const string camera)
{
    cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('H', '2', '6', '4'));
    cap.open(camera);
    cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('H', '2', '6', '4'));
    cap >> frame;
    connect(&frame_timer,SIGNAL(timeout()),this,SLOT(update_frame()));
    frame_timer.start(25);
}

void Cam::openCam(int camera)
{
    cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('H', '2', '6', '4'));
    cap.open(camera);
    cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('H', '2', '6', '4'));
    cap>> frame;
    connect(&frame_timer,SIGNAL(timeout()),this,SLOT(update_frame()));
    frame_timer.start(25);
}

void Cam::update_frame()
{
    if(cap.isOpened())
    {
        cap>>frame;
        emit imageReady(frame);
    }
}





