#include "keyboard.h"

_Keyboard::_Keyboard(QObject *parent) : QObject(parent)
{
    connect(&updateTimer,SIGNAL(timeout()),this,SLOT(read_keyboard()));
    updateTimer.start(50);
}

void _Keyboard::read_keyboard()
{
    key[Add_].now_state=sf::Keyboard::isKeyPressed(sf::Keyboard::Add);
    key[Subtract_].now_state=sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract);
    key[Left_].now_state=sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    key[Right_].now_state=sf::Keyboard::isKeyPressed(sf::Keyboard::Right);



    for(int i=0;i<10;i++)
    {
        if(key[i].now_state!=key[i].last_state)
        {
            key[i].last_state=key[i].now_state;
            if(key[i].now_state==true)
            {
                emit keyPressed(i);
            }
        }
    }
}
