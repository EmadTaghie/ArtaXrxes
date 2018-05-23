#include "gamepad.h"

gamepad::gamepad(QObject *parent) : QObject(parent)
{
    update_timer=new QTimer();
    connect(update_timer,SIGNAL(timeout()),this,SLOT(_update()));
    update_timer->start(50);
}

bool gamepad::getBtnStatus(int btn_number)
{
    return nowBtn[btn_number];
}

int gamepad::getHalfAxisStatus(int HalfAxis)
{
    return halfAxis[HalfAxis];
}

int gamepad::getAxisStatus(int Axis)
{
    return axis[Axis];
}



void gamepad::_update()
{
    Joystick::update();
    gamepadConnection=     Joystick::isConnected(joy_ip);

    if(gamepadConnection!=gamepadLastConnection)
    {
        emit connection(gamepadConnection);
        gamepadLastConnection=gamepadConnection;
    }


    //---------------------------------------------------------------------------------------
    if( sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::PovX) >50)
    {
        nowBtn[RIGHT_btn]=true;
        nowBtn[LEFT_btn]=false;
    }
    else if( sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::PovX)<-50)
    {
        nowBtn[RIGHT_btn]=false;
        nowBtn[LEFT_btn]=true;
    }
    else
    {
        nowBtn[RIGHT_btn]=false;
        nowBtn[LEFT_btn]=false;
    }
    //----------------------------------------------------------------------------------------
    if( sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::PovY) <-50)
    {
        nowBtn[UP_btn]=true;
        nowBtn[DOWN_btn]=false;
    }
    else if( sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::PovY)>50)
    {
        nowBtn[UP_btn]=false;
        nowBtn[DOWN_btn]=true;
    }
    else
    {
        nowBtn[UP_btn]=false;
        nowBtn[DOWN_btn]=false;
    }
    //------------------------------------------------------------------------------------------
    for (int i = 0; i<14 ;i++)
    {
        nowBtn[i] =  sf::Joystick::isButtonPressed(joy_ip,i);
    }
    //----------------------------------------------------------------------------------------------
    for (int i = 0; i<18 ;i++)
    {
        if(lastBtn[i] != nowBtn[i])
            emit BTN_Change(i,nowBtn[i]);
        lastBtn[i] = nowBtn[i];
        //        qDebug()<<i <<" : "<<  nowBtn[i];
    }
    //--------------------------------------------------------------------------------------------------------
    axis[LY]=sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::Y);
    axis[LX]=sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::X);
    axis[RY]=sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::R);
    axis[RX]=sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::Z);

    for (int i=0;i<4;i++)
    {
        if(axis[i]>0)
        {
            halfAxis[i*2]=axis[i];
            halfAxis[i*2+1]=0;
        }
        else
        {
            halfAxis[i*2+1]=-axis[i];
            halfAxis[i*2]=0;
        }
        //        qDebug()<< i << "=" << halfAxis[i*2] << "***"  <<halfAxis[i*2+1];
    }
    //    qDebug()<<"gamepad connetion =" << gamepadConnection;
}
