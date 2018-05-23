#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMainWindow>
#include <stdio.h>
#include <QDebug>
#include "iostream"
#include "opencv2/opencv.hpp"
#include "gamepad.h"
#include <qglobal.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <stdlib.h>
#include <QPainter>
#include <QThread>
#include <QLabel>
#include <QMutex>
#include <QPushButton>
#include <QDataStream>
#include <QTime>
#include "packetmaker.h"
#include "kinematic.h"
using namespace cv;
namespace Ui {
class MainWindow;
enum thresholdSettingValue
{
    motion =0,
    Hazmat =1
};
enum control_mode
{
    angleSetpoint=0,
    linearSpeedSetpoint=1,
    angularSpeedSetpoint=2,
    PWMSetpoint=3
};
enum cameraMode
{
   GTA_mod,
   Manip_mode
};

}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeProcessCamera(bool flg);
    manip_ manip_setpoin_status;

    int get_camera_selected();
    int get_thersholdValue(Ui::thresholdSettingValue t);
    void set_arm_angle_just_for_show(__uint8_t ID, float angle);
    void set_gas_data_just_for_show(__uint8_t data);
    uint8_t get_control_mode_flg();
    bool get_thermal_ONOF();
    bool get_GTA_camera_mode();
    void set_manipulator_linear_speed(int halfAxis_stat[], bool btn_stat[],int mode_);
public slots:
    void quadeViweUpdate1(Mat im);
    void quadeViweUpdate2(Mat im);
    void quadeViweUpdate3(Mat im);
    void quadeViweUpdate4(Mat im);
    void changeTap(bool status);
    void updateMotionImg(Mat im, int number);
    void updateQrImg(Mat im, QString string);
    void set_robot_mode_show(int mode);
    void set_gamepadConnectionViwe(bool flg);
    void set_thersholdValue(int t,int  value);
    void set_led_light(bool led);
    void updateThearmalImg(Mat im);
    void updateMapImg(Mat m);

signals:
    void changeProcessCamera(int cam);


private slots:
    void tabUpdate();
    void on_controlMod_AP_toggled(bool checked);

    void on_controlMod_LS_toggled(bool checked);

    void on_controlMod_AS_toggled(bool checked);

    void on_nonControlMod_toggled(bool checked);

    void on_controlMod_AS_clicked();

    void on_controlMod_LS_clicked();

    void on_controlMod_AP_clicked();

    void on_nonControlMod_clicked();

private:
    Ui::MainWindow *ui;
    Mat Quadview[4];
    int QuadViweDisconnect_[4];
    QTimer viweTimer;
    Mat processview[4];
    Mat MapMat;
    QString QrString;
    uint8_t controlMode_flg;
    int robot_mode;
    QThread tab_thr;
    double filterX,filterY,filterZ;
};

#endif // MAINWINDOW_H
