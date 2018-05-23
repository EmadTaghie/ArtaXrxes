#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <QObject>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <QTimer>
#include <QDebug>





//********************************************************************//
//           | L2 |                                   | R2 |          //
//           | L1 |                                   | R1 |          //
//           ******                                   ******          //
//         *       ***********************************      *         //
//        *     ^         share           option       Y     *        //
//        *     |                                            *        //
//        *  <-   ->            touchpad           X       B *        //
//        *     |                                            *        //
//        *     v                 start                A     *        //
//        *            *   L3    *******   R3   *            *        //
//        *           *   *   *           *  *   *           *        //
//        *          *                            *          *        //
//        *         *                              *         *        //
//         *       *                                *       *         //
//            *  *                                    *  *            //
//                                                                    //
//********************************************************************//







#define joy_ip 0
#define X_          sf::Joystick::isButtonPressed(joy_ip,0)
#define A_          sf::Joystick::isButtonPressed(joy_ip,1)
#define B_          sf::Joystick::isButtonPressed(joy_ip,2)
#define Y_          sf::Joystick::isButtonPressed(joy_ip,3)
#define L1_         sf::Joystick::isButtonPressed(joy_ip,4)
#define R1_         sf::Joystick::isButtonPressed(joy_ip,5)
#define L2_         sf::Joystick::isButtonPressed(joy_ip,6)
#define R2_         sf::Joystick::isButtonPressed(joy_ip,7)
#define SHARE       sf::Joystick::isButtonPressed(joy_ip,8)
#define OPTIONS     sf::Joystick::isButtonPressed(joy_ip,9)
#define L3_         sf::Joystick::isButtonPressed(joy_ip,10)
#define R3_         sf::Joystick::isButtonPressed(joy_ip,11)
#define PS          sf::Joystick::isButtonPressed(joy_ip,12)
#define TOUCHPAD    sf::Joystick::isButtonPressed(joy_ip,13)
#define DPADX       sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::PovX)
#define DPADY       -sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::PovY)
#define LJOYX       sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::X)
#define LJOYY       sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::Y)
#define RJOYX       sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::Z)
#define RJOYY       sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::R)
#define L2_a        sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::U)
#define R2_a        sf::Joystick::getAxisPosition(joy_ip,sf::Joystick::V)
//number of btn!!!
#define X_btn           0
#define A_btn           1
#define B_btn           2
#define Y_btn           3
#define L1_btn          4
#define R1_btn          5
#define L2_btn          6
#define R2_btn          7
#define SHARE_btn       8
#define OPTION_btn      9
#define L3_btn          10
#define R3_btn          11
#define PS_btn          12
#define TOCHPAD_btn     13
#define UP_btn          14
#define DOWN_btn        15
#define RIGHT_btn       16
#define LEFT_btn        17
//half axis -- faghat vase rahati dar edame barname!!!
#define _LD 0
#define _LU 1
#define _LR 2
#define _LL 3
#define _RD 4
#define _RU 5
#define _RR 6
#define _RL 7
//axis -- vase datahaye joystikaaaa!!!
#define LY 0
#define LX 1
#define RY 2
#define RX 3

#define low_limit           20
#define high_limit          210

using namespace sf;
class gamepad : public QObject
{
    Q_OBJECT
public:
    explicit gamepad(QObject *parent = 0);
    bool getBtnStatus(int btn_number);
    int getHalfAxisStatus(int HalfAxis);
    int getAxisStatus(int Axis);


signals:
    void BTN_Change(int a,bool status);
    void connection(bool flg);


public slots:


private slots:
    void _update();

private:
    bool gamepadConnection,gamepadLastConnection;
    QTimer *update_timer;
    bool lastBtn[18];
    bool nowBtn[18];
    int  axis[4];
    int  halfAxis[8];

};

#endif // GAMEPAD_H
