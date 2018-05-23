#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <QObject>
#include <math.h>
#include <QDebug>

struct manip_
{
    float x;
    float y;
    float z;
    float theta0;
    float theta1;
    float theta2;
    float theta3;
    int xdat;
    int ydat;
    int zdat;
    float theta0dat;
    float theta1dat;
    float theta2dat;
};

struct ARMangularspeeds
{
    float t0dat;
    float t1dat;
    float t2dat;
};

class kinematic : public QObject
{
    Q_OBJECT
public:
    explicit kinematic(QObject *parent = 0);
 //manip_ now_pos;
 manip_ forwardKinematic(float t0 , float t1 , float t2);
 manip_ inverseKinematic(float x , float y , float z);
 ARMangularspeeds make_angular_speed(float nowt0pos,float nowt1pos,float nowt2pos,int Vx,int Vy,int Vz);
signals:

public slots:

private:

    float c0;
    float c12;
    float s0;
    float s12;
    float c1;
    float s1;
    float LArm1;
    float Pr;
    float d2;
    float a1;
    float d1;


};

#endif // KINEMATIC_H
