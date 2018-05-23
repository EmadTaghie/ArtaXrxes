#ifndef CAM_H
#define CAM_H

#include <QObject>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QThread>
#include <QDebug>
using namespace cv;
using namespace std;
class Cam : public QObject
{
    Q_OBJECT
public:
    explicit Cam(QObject *parent = 0);
    void openCam(const string camera);
    void openCam(int camera);
signals:
    void imageReady(Mat a);
    void imageReady(QImage i);
public slots:


private slots:
    void update_frame();

private:
    QTimer frame_timer;
    Mat frame;
    VideoCapture cap;
};

#endif // CAM_H
