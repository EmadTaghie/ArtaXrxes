#ifndef LOBY_H
#define LOBY_H

#include <QObject>
#include <QThread>
#include <gamepad.h>
#include "mainwindow.h"
#include "cam.h"
#include "process.h"
#include "deck.h"
#include "packetmaker.h"
#include "keyboard.h"
#include "kinematic.h"
#include <thread>
#include <mutex>
using namespace cv;
//mutex muxet;
class Loby : public QObject
{
    Q_OBJECT
public:
    explicit Loby(QObject *parent = 0);
    void data_sender();

signals:
    void robotmode_signal(int mode);
    void tabChanged(bool s);
    void thresholdSetting(int T, int value);

public slots:

private slots:
    //    void combineUpboardData(QString *qr_string, short unsigned *hazmat_type);
        void getMat1(Mat a);
        void getMat2(Mat a);
        void getMat3(Mat a);
        void getMat4(Mat a);

        void MotionProcessing();
        void QrProcessing();
        void getGamepadState(int btn_number,bool status);
        void getKeboardState(int k);
        void main_feedback_is_ready();

private:

    QByteArray PWM_paketMaker(int halfAxis_stat[], bool btn_stat[], bool mode);



    QThread gamepad_thr;
    gamepad joy;
    MainWindow w;
    Deck d;
    PacketMaker PM;
    _Keyboard K;
    kinematic manipullator;

    Cam cam[4];
    QThread cam_thr[4];
    QThread deck_thr;
    Mat cam_mat[4];
    Mat motion_buf[4];
    QTimer motion_Timer[4];

    Process QR_;
    QThread QR_thr;
    QTimer QR_Timer;
    QTimer send_data_timer;
    QThread send_data_timer_thr;

    int robot_mode;


};

#endif // LOBY_H
