#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>


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

#define stop_pwm  100
namespace m {

enum motor_dir{
     stop    =  0x3a,
     forward =  0x3b,
     reverse =  0x3c
};
}

namespace MOTOR {


enum movementMotor_dir_state
{
    forward,
    reverse,
    left,
    right,
    softForwardLeft,
    softForwardRight,
    softReverseLeft,
    softReverseRight,
    stop
};
}


class motor : public QObject
{
    Q_OBJECT
public:
    explicit motor(QObject *parent = 0);
    static QByteArray movement_motor(MOTOR::movementMotor_dir_state state ,uint16_t pwm,uint8_t pwm_start=150,uint8_t pwm_end=255,int16_t defult_stop_state=0);

signals:

public slots:


};


#endif // MOTOR_H
