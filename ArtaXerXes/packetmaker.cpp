#include "packetmaker.h"

PacketMaker::PacketMaker(QObject *parent) : QObject(parent)
{
    servoHeadPitch=90;
    servoHeadYaw=90;
    ledHeadLight=turnon;
    lastLedHeadLight=false;

}
QByteArray PacketMaker::PWM_paketMaker(int halfAxis_stat[], bool btn_stat[],int mode_,bool thermal,bool cameraMode)
{


    QByteArray robotData;
    QByteArray movement_motor;
    movement_motor.resize(4);
    robotData.resize(35);
    for(int s=0;s<35;s++)
    {
        robotData[s]=0;
    }
    for(int s=0;s<4;s++)
    {
       movement_motor[s]=0;
    }

    if(mode_==forward_mode )
    {

        if(cameraMode)
        {
            robotData[26]=Packetmaker::camera_mod::forward_GTA;
        }
        else
        {
            robotData[26]=Packetmaker::camera_mod::forward_F_camera;
        }
        if (btn_stat[TOCHPAD_btn]==false && btn_stat[PS_btn]==false)
        {
            //**************************************
            //FF
            robotData[FF_PWM]=FF_PWM_data;
            if(btn_stat[R1_btn])
            {
                robotData[FF_dir]=forward_;
            }
            else if(btn_stat[R2_btn])
            {
                robotData[FF_dir]=revers_;
            }
            else
            {
                robotData[FF_dir]=Stop_;
            }
            //************************************
            //BF
            robotData[BF_PWM]=BF_PWM_data;
            if(btn_stat[L1_btn])
            {
                robotData[BF_dir]=forward_;
            }
            else if(btn_stat[L2_btn])
            {
                robotData[BF_dir]=revers_;
            }
            else
            {
                robotData[BF_dir]=Stop_;
            }
            //*************************************
            if(halfAxis_stat[_LL]<low_limit && halfAxis_stat[_LR]<low_limit)
            {
                if(halfAxis_stat[_RU]>low_limit)
                {
                    movement_motor=  motor::movement_motor(MOTOR::movementMotor_dir_state::forward,halfAxis_stat[_RU]*10);
                }
                else if(halfAxis_stat[_RD]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::reverse,halfAxis_stat[_RD]*10);
                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,0);
                }
            }
            else if(halfAxis_stat[_RU]<low_limit && halfAxis_stat[_RD]< low_limit)
            {
                if(halfAxis_stat[_LL]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::left,halfAxis_stat[_LL]*10);

                }
                else if(halfAxis_stat[_LR]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::right,halfAxis_stat[_LR]*10);

                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,0);
                }
            }
            else if(halfAxis_stat[_RU]>low_limit &&  (halfAxis_stat[_LR]>low_limit || halfAxis_stat[_LL]>low_limit ))
            {
                if(halfAxis_stat[_LR]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softForwardRight,halfAxis_stat[_LR]*10);

                }
                else  if(halfAxis_stat[_LL]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softForwardLeft,halfAxis_stat[_LL]*10);
                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,0);
                }
            }
            else if(halfAxis_stat[_RD]>low_limit &&  (halfAxis_stat[_LR]>low_limit || halfAxis_stat[_LL]>low_limit ))
            {
                if(halfAxis_stat[_LR]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softReverseRight,halfAxis_stat[_LR]*10);

                }
                else  if(halfAxis_stat[_LL]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softReverseLeft,halfAxis_stat[_LL]*10);
                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,halfAxis_stat[_LR]*10);
                }
            }
        }
    }
    else if(mode_==revrese_mode)
    {
        if(cameraMode)
        {
        robotData[26]=Packetmaker::camera_mod::reverse_GTA;
        }
        else
        {
            robotData[26]=Packetmaker::camera_mod::reverse_B_camera;
        }
        if (btn_stat[TOCHPAD_btn]==false && btn_stat[PS_btn]==false)
        {
            //**************************************
            //FF
            robotData[FF_PWM]=FF_PWM_data;
            if(btn_stat[R1_btn])
            {
                robotData[BF_dir]=forward_;
            }
            else if(btn_stat[R2_btn])
            {
                robotData[BF_dir]=revers_;
            }
            else
            {
                robotData[BF_dir]=Stop_;
            }
            //************************************
            //BF
            robotData[BF_PWM]=BF_PWM_data;
            if(btn_stat[L1_btn])
            {
                robotData[FF_dir]=forward_;
            }
            else if(btn_stat[L2_btn])
            {
                robotData[FF_dir]=revers_;
            }
            else
            {
                robotData[FF_dir]=Stop_;
            }
            //*************************************
            if(halfAxis_stat[_LL]<low_limit && halfAxis_stat[_LR]<low_limit)
            {
                if(halfAxis_stat[_RU]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::reverse,halfAxis_stat[_RU]*10);
                }
                else if(halfAxis_stat[_RD]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::forward,halfAxis_stat[_RD]*10);
                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,0);
                }
            }
            else if(halfAxis_stat[_RU]<low_limit && halfAxis_stat[_RD]< low_limit)
            {
                if(halfAxis_stat[_LL]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::left,halfAxis_stat[_LL]*10);

                }
                else if(halfAxis_stat[_LR]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::right,halfAxis_stat[_LR]*10);

                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,0);
                }
            }
            else if(halfAxis_stat[_RU]>low_limit &&  (halfAxis_stat[_LR]>low_limit || halfAxis_stat[_LL]>low_limit ))
            {
                if(halfAxis_stat[_LR]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softReverseRight,halfAxis_stat[_LR]*10);

                }
                else  if(halfAxis_stat[_LL]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softReverseLeft,halfAxis_stat[_LL]*10);
                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,0);
                }
            }
            else if(halfAxis_stat[_RD]>low_limit &&  (halfAxis_stat[_LR]>low_limit || halfAxis_stat[_LL]>low_limit ))
            {
                if(halfAxis_stat[_LR]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softForwardRight,halfAxis_stat[_LR]*10);

                }
                else  if(halfAxis_stat[_LL]>low_limit)
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::softForwardLeft,halfAxis_stat[_LL]*10);
                }
                else
                {
                    movement_motor= motor::movement_motor(MOTOR::movementMotor_dir_state::stop,halfAxis_stat[_LR]*10);
                }
            }
        }

    }
    else
    {
        if(cameraMode)
        {
        robotData[26]=Packetmaker::camera_mod::manipulator_GTA;
        }
        else
        {
            robotData[26]=Packetmaker::camera_mod::manipulator_Head;
        }
        //            if(controlMode==1)
        //            {

        //            }
        //            else
        {
            if (btn_stat[TOCHPAD_btn]==false && btn_stat[PS_btn]==false)
            {

                //Arm0
                if(halfAxis_stat[_RR]>low_limit)
                {
                    //            if(R3joy_right>200)
                    //            robotData[21]=200;
                    //            else
                    robotData[9]=dastane_daste+halfAxis_stat[_RR];

                    robotData[8]=forward_;
                }
                else if (halfAxis_stat[_RL]>low_limit)
                {
                    //            if(R3joy_left>200)
                    //            robotData[21]=200;
                    //            else
                    robotData[9]=dastane_daste+halfAxis_stat[_RL];
                    robotData[8]=revers_;
                }
                else
                {
                    robotData[9]=100;
                    robotData[8]=Stop_;
                }
                //Arm1
                if(halfAxis_stat[_RU]>low_limit)
                {

                    robotData[11]=dastane_daste+halfAxis_stat[_RU];
                    robotData[10]=forward_;
                }
                else if(halfAxis_stat[_RD]>low_limit)
                {
                    robotData[11]=dastane_daste+halfAxis_stat[_RD];
                    robotData[10]=revers_;
                }
                else
                {
                    robotData[11]=100;
                    robotData[10]=Stop_;
                }

                //Arm2
                if(halfAxis_stat[_LU]>low_limit)
                {
                    robotData[13]=dastane_daste+halfAxis_stat[_LU];
                    robotData[12]=forward_;
                }
                else if(halfAxis_stat[_LD]>low_limit)
                {
                    robotData[13]=dastane_daste+halfAxis_stat[_LD];
                    robotData[12]=revers_;
                }
                else
                {
                    robotData[13]=100;
                    robotData[12]=Stop_;
                }
                //pr
                robotData[15]=Pr_PWM_data;
                if(btn_stat[UP_btn]&&!btn_stat[Y_btn])
                {
                    robotData[14]=revers_;
                }
                else if(btn_stat[DOWN_btn]&&!btn_stat[Y_btn])
                {
                    robotData[14]=forward_;
                }
                else
                {
                    robotData[14]=Stop_;
                }

                //roll
                if(btn_stat[RIGHT_btn])
                {
                    robotData[17]=revers_;
                }
                else if(btn_stat[LEFT_btn])
                {
                    robotData[17]=forward_;
                }
                else
                {
                    robotData[17]=Stop_;
                }
                //pitch
                if(btn_stat[R2_btn])
                {
                    robotData[16]=revers_;
                }
                else if(btn_stat[R1_btn])
                {
                    robotData[16]=forward_;
                }
                else
                {
                    robotData[16]=Stop_;
                }
            }
            //Gr
            if(btn_stat[L1_btn])
            {
                robotData[19]=revers_;
                robotData[20]=turnon;
            }
            else if(btn_stat[L2_btn])
            {
                robotData[19]=forward_;
                robotData[20]=turnon;
            }
            else
            {
                robotData[19]=Stop_;
                robotData[20]=turnoff;
            }


        }
    }
    if(btn_stat[TOCHPAD_btn]==true)
    {
        if(btn_stat[A_btn])
        {
            servoHeadPitch=90;
            servoHeadYaw=90;
        }
        if(btn_stat[Y_btn] && !lastLedHeadLight==btn_stat[Y_btn])
        {
            if(ledHeadLight==turnon)
            {
                ledHeadLight=turnoff;
            }
            else
            {
                ledHeadLight=turnon;
            }


        }


        lastLedHeadLight=btn_stat[Y_btn];
//        qDebug()<<ledHeadLight<<lastLedHeadLight<<btn_stat[Y_btn];
    }
    else
    {
        if(btn_stat[Y_btn])
        {
            servoHeadPitch++;
            if(servoHeadPitch > 160)
                servoHeadPitch = 160;
        }
        else if(btn_stat[A_btn])
        {
            servoHeadPitch--;
            if(servoHeadPitch < 10)
                servoHeadPitch = 10;
        }
        else
        {

        }
        if(btn_stat[X_btn])
        {
            servoHeadYaw++;
            if(servoHeadYaw > 190)
                servoHeadYaw = 190;
        }
        else if(btn_stat[B_btn])
        {
            servoHeadYaw--;
            if(servoHeadYaw < 5)
                servoHeadYaw = 5;
        }
        else
        {

        }

    }


    robotData[0]=movement_motor[0];
    robotData[1]=movement_motor[1];
    robotData[2]=movement_motor[2];
    robotData[3]=movement_motor[3];

    robotData[21]=servoHeadYaw;
    robotData[22]=servoHeadPitch;
    robotData[23]=ledHeadLight;
    if(thermal)
        robotData[24]=turnon;
    else
        robotData[24]=turnoff;

    //qDebug()<<robotData[24];
    //    robotData[24]=0;//yejadigepormishe
    //    robotData[25]=LED_body;
    return robotData;
}

QByteArray PacketMaker::CNT_manip_pos_packetMaker(float ARM0, float ARM1, float ARM2,float ARM3)
{
    QByteArray robotData;
    robotData.resize(35);
    for(int s=0;s<35;s++)
    {
        robotData[s]=0;
    }
    robotData[ARM0_hp]=(Byte)((ARM0*10.0)/256);
    robotData[ARM0_lp]=(Byte)((int)(ARM0*10.0)%256);
    robotData[ARM1_hp]=(Byte)((ARM1*10.0)/256);
    robotData[ARM1_lp]=(Byte)((int)(ARM1*10.0)%256);
    robotData[ARM2_hp]=(Byte)((ARM2*10.0)/256);
    robotData[ARM2_lp]=(Byte)((int)(ARM2*10.0)%256);
    robotData[ARM3_hp]=(Byte)((ARM3*10.0)/256);
    robotData[ARM3_lp]=(Byte)((int)(ARM3*10.0)%256);

    if(ARM3<130)
    {
    robotData[ARM3_hp]=(Byte)((ARM3*10.0)/256);
    robotData[ARM3_lp]=(Byte)((int)(ARM3*10.0)%256);
    }
    else
    {
        robotData[ARM3_hp]=(Byte)((1300)/256);
        robotData[ARM3_lp]=(Byte)((1300)%256);
    }


   // qDebug()<< "dastan"<<(int)(float)((ARM0)*10)<<"**hp="<<(uint8_t)robotData[ARM0_hp]<< "**lp="<<(uint8_t)robotData[ARM0_lp];



    robotData[21]=servoHeadYaw;
    robotData[22]=servoHeadPitch;
    robotData[23]=ledHeadLight;
    return robotData;

}

QByteArray PacketMaker::CNT_manip_angularSpeed_paketMaker(manip_ setpoint)
{
    QByteArray robotData;
    robotData.resize(35);
    for(int s=0;s<35;s++)
    {
        robotData[s]=0;
    }

    if(setpoint.theta0dat>=0)
    {

        robotData[ARM0_hp]=forward_ | 0xC0;
        robotData[ARM0_lp]=(Byte)(setpoint.theta0dat*10.0);

    }
    else
    {

        robotData[ARM0_hp]=revers_ | 0xC0;
        robotData[ARM0_lp]=(Byte)-1*(Byte)(setpoint.theta0dat*10.0);
    }
    if(setpoint.theta1dat>=0)
    {

        robotData[ARM1_hp]=forward_ | 0xC0;
        robotData[ARM1_lp]=(Byte)(setpoint.theta1dat*10.0);

    }
    else
    {

        robotData[ARM1_hp]=revers_ | 0xC0;
        robotData[ARM1_lp]=(Byte)-1*(Byte)(setpoint.theta1dat*10.0);
    }
    if(setpoint.theta2dat>=0)
    {

        robotData[ARM2_hp]=forward_ | 0xC0;
        robotData[ARM2_lp]=(Byte)(setpoint.theta2dat*10.0);

    }
    else
    {

        robotData[ARM2_hp]=revers_ | 0xC0;
        robotData[ARM2_lp]=(Byte)-1*(Byte)(setpoint.theta2dat*10.0);
    }
 double AH_angle;
    if(setpoint.theta2-setpoint.theta1>0)
    {
         AH_angle=(90-fabs(setpoint.theta2-setpoint.theta1)+setpoint.theta3)*10;
    }
    else
    {
         AH_angle=(90+(setpoint.theta1-setpoint.theta2)+setpoint.theta3)*10;
    }


    qDebug()<<AH_angle;
    if(AH_angle<1300)
    {
    robotData[ARM3_hp]=(Byte)((AH_angle)/256);
    robotData[ARM3_lp]=(Byte)((int)(AH_angle)%256);
    }
    else
    {
        robotData[ARM3_hp]=(Byte)((1300)/256);
        robotData[ARM3_lp]=(Byte)((1300)%256);
    }


    //    robotData[ARM0_lp]=(Byte)((int)(ARM0*10.0)%256);
    //    robotData[ARM1_hp]=(Byte)((ARM1*10.0)/256);
    //    robotData[ARM1_lp]=(Byte)((int)(ARM1*10.0)%256);
    //    robotData[ARM2_hp]=(Byte)((ARM2*10.0)/256);
    //    robotData[ARM2_lp]=(Byte)((int)(ARM2*10.0)%256);
    robotData[21]=servoHeadYaw;
    robotData[22]=servoHeadPitch;
    robotData[23]=ledHeadLight;
    return  robotData;
}

QByteArray PacketMaker::CNT_manip_linearSpeed_paketMaker(manip_ setpoint)
{

}

QByteArray PacketMaker::CNT_manip_allways_paketMaker(manip_ setpoint)
{
    QByteArray robotData;
    robotData.resize(35);
    for(int s=0;s<35;s++)
    {
        robotData[s]=0;
    }
    robotData[ARM0_hp]=(Byte)((setpoint.theta0*10.0)/256);
    robotData[ARM0_lp]=(Byte)((int)(setpoint.theta0*10.0)%256);
    robotData[ARM1_hp]=(Byte)((setpoint.theta1*10.0)/256);
    robotData[ARM1_lp]=(Byte)((int)(setpoint.theta1*10.0)%256);
    robotData[ARM2_hp]=(Byte)((setpoint.theta2*10.0)/256);
    robotData[ARM2_lp]=(Byte)((int)(setpoint.theta2*10.0)%256);
    if(setpoint.theta3<130)
    {
    robotData[ARM3_hp]=(Byte)((setpoint.theta3*10.0)/256);
    robotData[ARM3_lp]=(Byte)((int)(setpoint.theta3*10.0)%256);
    }
    else
    {
        robotData[ARM3_hp]=(Byte)((1300)/256);
        robotData[ARM3_lp]=(Byte)((1300)%256);
    }

   // qDebug()<< "dastan"<<(int)(float)((ARM0)*10)<<"**hp="<<(uint8_t)robotData[ARM0_hp]<< "**lp="<<(uint8_t)robotData[ARM0_lp];



    robotData[21]=servoHeadYaw;
    robotData[22]=servoHeadPitch;
    robotData[23]=ledHeadLight;
    return robotData;
}

bool PacketMaker::get_led_light()
{
    if(ledHeadLight==turnoff)
        return false;
    else
        return true;
}

void PacketMaker::mohasebat_slot()
{

}
