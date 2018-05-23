#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <QTimer>

#define Add_            0
#define Subtract_       1
#define Left_           2
#define Right_          3



struct key_state
{
    bool now_state;
    bool last_state;
    key_state()
    {
        now_state=false;
        last_state=false;
    }
};

class _Keyboard : public QObject
{
    Q_OBJECT
public:
    explicit _Keyboard(QObject *parent = 0);

signals:
    void keyPressed(int k);

public slots:
    void read_keyboard();
private:
    key_state key[10];
    QTimer updateTimer;


};

#endif // KEYBOARD_H
