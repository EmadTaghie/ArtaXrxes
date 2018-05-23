#include "kinematic.h"

kinematic::kinematic(QObject *parent) : QObject(parent)
{
    LArm1=550;
    Pr=540;
    a1=73.43;
    d1=101;
    d2=0;

}

manip_ kinematic::inverseKinematic(float x, float y, float z)
{
    manip_ next_pos;
    float r;
    z=z-d1;

    if ((x)<0)
    r=-1*(sqrt(x*x+y*y)-a1);
    else
    r=(sqrt(x*x+y*y)-a1);

    float c2=((r*r+z*z)-(LArm1*LArm1 + Pr*Pr))/(2*LArm1*Pr);
    float s2=-sqrt(1-c2*c2);
    next_pos.theta2=180+atan2(s2,c2)*180/3.1415;
    float k1=LArm1+Pr*c2;
    float k2=Pr*s2;
    next_pos.theta1=180-(atan2(z,r)- atan2(k2,k1))*180/3.1415;
    next_pos.theta0=atan(y/x)*180/3.1415;
//    qDebug()<<"teta1= "   << next_pos.theta1<<"  teta2="  <<  next_pos.theta2;
    return next_pos;
}

ARMangularspeeds kinematic::make_angular_speed(float nowt0pos, float nowt1pos, float nowt2pos, int Vx, int Vy, int Vz)
{
    ARMangularspeeds out;
   // nowt0pos=0;
    float time=.5;
    manip_ now_point,next_point,temp,kooft;
    now_point= forwardKinematic(nowt0pos,nowt1pos,nowt2pos);
    kooft=inverseKinematic(now_point.x,now_point.y,now_point.z);
    next_point.x=Vx/100.0*time+now_point.x;
    next_point.y=Vy/100.0*time+now_point.y;
    next_point.z=Vz/100.0*time+now_point.z;
    temp=inverseKinematic(next_point.x,next_point.y,next_point.z);
    out.t0dat=(temp.theta0-nowt0pos)/time;
    out.t1dat=(temp.theta1-nowt1pos)/time;
    out.t2dat=(temp.theta2-(nowt2pos))/time;
    qDebug()<<"now angle"<<nowt0pos<<"..."<<nowt1pos<<"..."<<nowt2pos;
    qDebug()<<"next angle"<<temp.theta0<<"..."<<temp.theta1<<"..."<<temp.theta2;
    qDebug()<<"now_point"<<now_point.x<<"..."<<now_point.y<<"..."<<now_point.z;
    qDebug()<<"next_point"<<next_point.x<<"..."<<next_point.y<<"..."<<next_point.z;
    qDebug()<<"sorat zavieii"<<out.t0dat<<"..."<<out.t1dat<<"..."<<out.t2dat;
    qDebug()<<"koofr"<< kooft.theta0<<"..."<<kooft.theta1<<"..."<<kooft.theta2;
    return out;
}

manip_ kinematic::forwardKinematic(float t0, float t1, float t2)
{

    manip_ now_pos;
    now_pos.theta0=t0;
    now_pos.theta1=t1;
    now_pos.theta2=180-t2;
    c0=cos(now_pos.theta0*3.14159265/180);
    c12=cos((now_pos.theta1+now_pos.theta2)*3.14159265/180);
    s0=sin(now_pos.theta0*3.14159265/180);
    s12=sin((now_pos.theta1+now_pos.theta2)*3.14159265/180);
    c1=cos(now_pos.theta1*3.14159265/180);
    s1=sin(now_pos.theta1*3.14159265/180);
    now_pos.x= a1*c0 + d2*s0 - Pr*(c0*c12)-LArm1*c1*c0;
    now_pos.y= a1*s0 + d2*c0 + Pr*(s0*c12)+LArm1*s0*c1;
    now_pos.z= d1+Pr*s12 + LArm1*s1;
//    qDebug()<<"x=" <<now_pos.x <<"y="<<now_pos.y <<"z= " <<  now_pos.z;
    return now_pos;
}
