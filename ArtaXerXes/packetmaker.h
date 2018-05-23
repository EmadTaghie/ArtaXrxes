#ifndef MACKETMAKER_H
#define MACKETMAKER_H

#include <QObject>
#include <gamepad.h>
#include <kinematic.h>
#include <motor.h>
#include <QThread>
#include <mutex>
// 20 -> 160 pitch
//-10 -> 190 yaw
typedef __uint8_t       Byte;

#define forward_mode         0
#define revrese_mode         1
#define manipulator_mod      2
#define omni_mode            3

#define Stop_      0x3a
#define forward_   0x3b
#define revers_    0x3c

#define turnon      29
#define turnoff     129

#define lamasab    1
#define dastane_daste ((2.55-lamasab)*100+1)
#define BLUETOOTH 0

#define data_size 30

#define BF_PWM_data 255
#define FF_PWM_data 255
#define Pr_PWM_data 255



#define Rm_dir          0
#define Rm_PWM          1
#define Lm_dir          2
#define Lm_PWM          3
#define FF_dir          4
#define FF_PWM          5
#define BF_dir          6
#define BF_PWM          7
#define ARM0_dir        8
#define ARM0_PWM        9
#define ARM1_dir        10
#define ARM1_PWM        11
#define ARM2_dir        12
#define ARM2_PWM        13
#define PR_dir          14
#define PR_PWM          15
#define PITCH_dir       16
#define ROLL_dir        17
#define YAW_dir         18
#define GR_dir          19
#define GR_ON_OFF       20
#define HeadYawAngle    21
#define HeadPitchAngle  22
#define HeadLED         23
#define Thermal_ON_OFF  24
#define Main_IO         25
//..........................

#define ARM0_hp        8
#define ARM0_lp        9
#define ARM1_hp        10
#define ARM1_lp        11
#define ARM2_hp        12
#define ARM2_lp        13
#define ARM3_hp        27
#define ARM3_lp        28


namespace Packetmaker {
enum camera_mod{
forward_GTA= 115,
reverse_GTA= 120,
manipulator_GTA= 125,
forward_F_camera =100,
reverse_B_camera = 105,
manipulator_Head =110,
};

}



class PacketMaker : public QObject
{
    Q_OBJECT
public:
    explicit PacketMaker(QObject *parent = 0);

    QByteArray PWM_paketMaker(int halfAxis_stat[], bool btn_stat[], int mode_, bool thermal, bool cameraMode);
    QByteArray CNT_manip_pos_packetMaker(float ARM0, float ARM1, float ARM2, float ARM3);
    QByteArray CNT_manip_angularSpeed_paketMaker(manip_ setpoint);
    QByteArray CNT_manip_linearSpeed_paketMaker(manip_ setpoint);
    QByteArray CNT_manip_allways_paketMaker(manip_ setpoint);

    bool get_led_light();
signals:

    void mohasebat();
public slots:

private  slots:
    void mohasebat_slot();
private:
    __uint8_t servoHeadPitch;
    __uint8_t servoHeadYaw;
    __uint8_t ledHeadLight;
    bool lastLedHeadLight;
    int halfAxis_stat_[8];
    bool btn_stat_[14];
    int mode__;
};

#endif // MACKETMAKER_H

//***************************************************************************************************
//-----  Mode  ---->|    PWM        |   CONTROL  |
//***************************************************************************************************
// 0->     rm       |    dir        |      //    |
//---------------------------------------------------------------------------------------------------
// 1->     rm       |    speed      |      //    |
//---------------------------------------------------------------------------------------------------
// 2->     lm       |    dir        |      //    |
//---------------------------------------------------------------------------------------------------
// 3->     lm       |    speed      |      //    |
//---------------------------------------------------------------------------------------------------
// 4->     FF       |    dir        |      //    |
//----------------------------------------------------------------------------------------------------
// 5->     FF       |    speed      |      //    |
//----------------------------------------------------------------------------------------------------
// 6->     BF       |    dir        |      //    |
//----------------------------------------------------------------------------------------------------
// 7->     BF       |    speed      |      //    |
//----------------------------------------------------------------------------------------------------
// 8->     ARM0     |    dir        |   POS_high |
//-----------------------------------------------------------------------------------------------------
// 9->     ARM0     |    speed      |   POS_low  |
//-----------------------------------------------------------------------------------------------------
// 10->    ARM1     |    dir        |   POS_high |
//-----------------------------------------------------------------------------------------------------
// 11->    ARM1     |    speed      |   POS_low  |
//------------------------------------------------------------------------------------------------------
// 12->    ARM2     |    dir        |   POS_high |
//------------------------------------------------------------------------------------------------------
// 13->    ARM2     |    speed      |   POS_low  |
//--------------------------------------------------------------------------------------------------------
// 14->    Pr       |    dir        |      //    |
//-------------------------------------------------------------------------------------------------------
// 15->    Pr       |    speed      |      //    |
//--------------------------------------------------------------------------------------------------------
// 16->    Pitch    |    dir        |      //    |
//--------------------------------------------------------------------------------------------------------
// 17->    Roll     |    dir        |      //    |
//-------------------------------------------------------------------------------------------------------
// 18->    Yaw      |    dir        |      //    |
//--------------------------------------------------------------------------------------------------------
// 19->    Gr       |    dir        |      //    |
//--------------------------------------------------------------------------------------------------------
// 20->    Gr       |    on_off     |      //    |
//--------------------------------------------------------------------------------------------------------
// 21->    Head     |    servo yaw  |      //    |
//--------------------------------------------------------------------------------------------------------
// 22->    Head     |  servo pitch  |      //    |
//-------------------------------------------------------------------------------------------------------
// 23->    Head     |    LED        |      //    |
//-------------------------------------------------------------------------------------------------------
// 24->    Thermal  |    on_off     |      //    |
//-------------------------------------------------------------------------------------------------------
// 25->    Main     |    IO         |      //    |
//-------------------------------------------------------------------------------------------------------
// 26->    camera   |     SW        |            |
//--------------------------------------------------------------------------------------------------------
// 27->    pitch    |               |  POS_high  |
//--------------------------------------------------------------------------------------------------------
// 28->    Null     |               |  POS_low   |
//--------------------------------------------------------------------------------------------------------
// 29->    Null     |               |            |
//**********************************************************************************************************


