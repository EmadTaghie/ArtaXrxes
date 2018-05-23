#include "motor.h"

motor::motor(QObject *parent) : QObject(parent)
{

}

QByteArray motor::movement_motor(MOTOR::movementMotor_dir_state state, uint16_t pwm, uint8_t pwm_start, uint8_t pwm_end, int16_t defult_stop_state)
{

    //meghdare pwm 0 ta 1000

    QByteArray temp;
    temp.resize(4);

    uint8_t final_pwm ;

    final_pwm=(pwm_end-pwm_start)*pwm/1000+pwm_start;





    if(state == MOTOR::movementMotor_dir_state::forward)
    {
        temp[Rm_dir]=m::motor_dir::forward;
        temp[Lm_dir]=m::motor_dir::forward;
        temp[Rm_PWM]=final_pwm;
        temp[Lm_PWM]=final_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::reverse)
    {
        temp[Rm_dir]=m::motor_dir::reverse;
        temp[Lm_dir]=m::motor_dir::reverse;
        temp[Rm_PWM]=final_pwm;
        temp[Lm_PWM]=final_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::left)
    {
        temp[Rm_dir]=m::motor_dir::forward;
        temp[Lm_dir]=m::motor_dir::reverse;
        temp[Rm_PWM]=final_pwm;
        temp[Lm_PWM]=final_pwm;

    }
    else if(state == MOTOR::movementMotor_dir_state::right)
    {
        temp[Rm_dir]=m::motor_dir::reverse;
        temp[Lm_dir]=m::motor_dir::forward;
        temp[Rm_PWM]=final_pwm;
        temp[Lm_PWM]=final_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::softForwardLeft)
    {
        temp[Rm_dir]=m::motor_dir::forward;
        temp[Lm_dir]=m::motor_dir::stop;
        temp[Rm_PWM]=final_pwm;
        temp[Lm_PWM]=stop_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::softForwardRight)
    {
        temp[Rm_dir]=m::motor_dir::stop;
        temp[Lm_dir]=m::motor_dir::forward;
        temp[Rm_PWM]=stop_pwm;
        temp[Lm_PWM]=final_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::softReverseLeft)
    {
        temp[Rm_dir]=m::motor_dir::stop;
        temp[Lm_dir]=m::motor_dir::reverse;
        temp[Rm_PWM]=stop_pwm;
        temp[Lm_PWM]=final_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::softReverseRight)
    {
        temp[Rm_dir]=m::motor_dir::reverse;
        temp[Lm_dir]=m::motor_dir::stop;
        temp[Rm_PWM]=final_pwm;
        temp[Lm_PWM]=stop_pwm;
    }
    else if(state == MOTOR::movementMotor_dir_state::stop)
    {

        if(defult_stop_state>0)
        {
            temp[Rm_dir]=m::motor_dir::forward;
            temp[Lm_dir]=m::motor_dir::forward;
            temp[Rm_PWM]=defult_stop_state;
            temp[Lm_PWM]=defult_stop_state;
        }
        else if(defult_stop_state<0)
        {
            temp[Rm_dir]=m::motor_dir::reverse;
            temp[Lm_dir]=m::motor_dir::reverse;
            temp[Rm_PWM]=-defult_stop_state;
            temp[Lm_PWM]=-defult_stop_state;
        }
        else
        {
            temp[Rm_dir]=m::motor_dir::stop;
            temp[Lm_dir]=m::motor_dir::stop;
            temp[Rm_PWM]=stop_pwm;
            temp[Lm_PWM]=stop_pwm;
        }

    }
    return temp;

}
