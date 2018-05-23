#include "loby.h"

Loby::Loby(QObject *parent) : QObject(parent)
{
    w.showMaximized();
    joy.moveToThread(&gamepad_thr);
    gamepad_thr.start();

    robot_mode=forward_mode;

    for(int i=0;i<4;i++)
    {
        cam[i].moveToThread(&cam_thr[i]);
        cam_thr[i].start(QThread::HighestPriority);
    }
    d.moveToThread(&deck_thr);
    deck_thr.start(QThread::HighestPriority);
    //    PM.moveToThread(&send_data_timer_thr);
    //    send_data_timer_thr.start();

    cam[0].openCam("rtsp://root:roboticplanet@192.168.1.90/axis-media/media.amp?camera=1&videocodec=jpeg&fps=15");
    cam[1].openCam("rtsp://root:roboticplanet@192.168.1.90/axis-media/media.amp?camera=2&videocodec=jpeg&fps=15");
    cam[2].openCam("rtsp://root:roboticplanet@192.168.1.90/axis-media/media.amp?camera=3&videocodec=jpeg&fps=15");
    cam[3].openCam("rtsp://root:roboticplanet@192.168.1.90/axis-media/media.amp?camera=4&videocodec=jpeg&fps=15");
    //    cam[0].openCam(0);
    //    cam[2].openCam(1);
    //    cam[1].openCam(2);
    //    cam[3].openCam(3);
    connect(&cam[0],SIGNAL(imageReady(Mat)),&w,SLOT(quadeViweUpdate1(Mat)),Qt::DirectConnection);
    connect(&cam[1],SIGNAL(imageReady(Mat)),&w,SLOT(quadeViweUpdate2(Mat)),Qt::DirectConnection);
    connect(&cam[2],SIGNAL(imageReady(Mat)),&w,SLOT(quadeViweUpdate3(Mat)),Qt::DirectConnection);
    connect(&cam[3],SIGNAL(imageReady(Mat)),&w,SLOT(quadeViweUpdate4(Mat)),Qt::DirectConnection);

    //-------------------------------------------------------------------------------//
    //-------------------------Processing viwe --------------------------------------//
    connect(&cam[0],SIGNAL(imageReady(Mat)),this,SLOT(getMat1(Mat)),Qt::DirectConnection);
    connect(&cam[1],SIGNAL(imageReady(Mat)),this,SLOT(getMat2(Mat)),Qt::DirectConnection);
    connect(&cam[2],SIGNAL(imageReady(Mat)),this,SLOT(getMat3(Mat)),Qt::DirectConnection);
    connect(&cam[3],SIGNAL(imageReady(Mat)),this,SLOT(getMat4(Mat)),Qt::DirectConnection);

    connect(&QR_Timer,SIGNAL(timeout()),this,SLOT(QrProcessing()),Qt::DirectConnection);
    connect(&QR_,SIGNAL(QRDetection(Mat,QString)),&w,SLOT(updateQrImg(Mat,QString)),Qt::DirectConnection);

    QR_Timer.start(100);

    connect(&motion_Timer[0],SIGNAL(timeout()),this,SLOT(MotionProcessing()),Qt::DirectConnection);
    connect(&QR_,SIGNAL(motionDetection(Mat,int)),&w,SLOT(updateMotionImg(Mat,int)),Qt::DirectConnection);
    motion_Timer[0].start(50);
    //---------------------------------------------------------------------------------//
    //    send_data_timer.moveToThread(&send_data_timer_thr);
    //    send_data_timer_thr.start(QThread::HighestPriority);
//    connect(&send_data_timer,SIGNAL(timeout()),this,SLOT(data_sender()));
//    send_data_timer.start(30);

    connect(this,SIGNAL(tabChanged(bool)),&w,SLOT(changeTap(bool)),Qt::DirectConnection);
    connect(&joy,SIGNAL(BTN_Change(int,bool)),this,SLOT(getGamepadState(int,bool)),Qt::DirectConnection);
    connect(this,SIGNAL(robotmode_signal(int)),&w,SLOT(set_robot_mode_show(int)));
    connect(this,SIGNAL(thresholdSetting(int,int)),&w,SLOT(set_thersholdValue(int,int)));

    connect(&joy,SIGNAL(connection(bool)),&w,SLOT(set_gamepadConnectionViwe(bool)));

    connect(&K,SIGNAL(keyPressed(int)),this,SLOT(getKeboardState(int)));


    connect(&d,SIGNAL(thermalImIsReady(Mat))        ,&w,SLOT(updateThearmalImg(Mat)));
    connect(&d,SIGNAL(MapImageIsReady(Mat))         ,&w ,SLOT(updateMapImg(Mat)));
    connect(&d,SIGNAL(mainDataIsReady()), this,SLOT(main_feedback_is_ready()));

}

///----------------------------------------------------------------------------------------------------------------------------------------///
// inja har frame jadidi ke az tarafe video encoder oomad ejra mishe
// kari ham ke mikone ye copy az tasvir too motion buffer negah midare vase clase prosses ye copy ham negah midare vase baghye prosses ha!!!!
void Loby::getMat1(Mat a)
{

    cam_mat[0].copyTo(motion_buf[0]);
    flip(a,cam_mat[0],1);

    a.copyTo(cam_mat[0]);
}
//camenta vase vaghtie ke bekhaim tahte sharayeti tasvir ro becharkhoonim
void Loby::getMat2(Mat a)
{
    cam_mat[1].copyTo(motion_buf[1]);
    //    Mat rot_mat = cv::getRotationMatrix2D(Point(a.cols/2,a.rows/2),180, 1);
    //    cv::warpAffine(a, cam_mat[1], rot_mat, a.size(), cv::INTER_CUBIC);
    a.copyTo(cam_mat[1]);

}
void Loby::getMat3(Mat a)
{
    cam_mat[2].copyTo(motion_buf[2]);
    a.copyTo(cam_mat[2]);
}
void Loby::getMat4(Mat a)
{
    cam_mat[3].copyTo(motion_buf[3]);
    a.copyTo(cam_mat[3]);
}
///----------------------------------------------------------------------------------------------------------------------------------------///
void Loby::QrProcessing()
{
    Mat temp;
    int camID;
    camID=w.get_camera_selected();
    if(camID!=4)
    {
        cam_mat[camID].copyTo(temp);
        QString s;
        QR_.QR_scan(temp,&s);

    }
}

void Loby::data_sender()
{
    while(1){
//        muxet.lock();
    QByteArray temp;
    int  halfAxis_temp[8];
    bool btn_temp[18];
    w.set_led_light(PM.get_led_light());
    for(int i=0;i<8;i++)
    {
        halfAxis_temp[i] = joy.getHalfAxisStatus(i);
    }

    for(int  i=0; i<18;i++)
    {
        btn_temp[i]=joy.getBtnStatus(i);
    }


    if(w.get_control_mode_flg()==Ui::PWMSetpoint)
    {
        d.set_main_data(PM.PWM_paketMaker(halfAxis_temp,btn_temp,robot_mode,w.get_thermal_ONOF(),w.get_GTA_camera_mode()),"PWM");
    }

    else
    {

        w.set_manipulator_linear_speed(halfAxis_temp,btn_temp,robot_mode);

        manip_ TEMP;
        TEMP=w.manip_setpoin_status;

        if(w.get_control_mode_flg()==Ui::angleSetpoint)
        {
            d.set_main_data(PM.CNT_manip_pos_packetMaker(TEMP.theta0,TEMP.theta1,TEMP.theta2,TEMP.theta3),"CNT");
        }
        else if(w.get_control_mode_flg()==Ui::linearSpeedSetpoint)
        {

            TEMP.theta0=d.get_arms_angle(0)-90;
            TEMP.theta1=d.get_arms_angle(1);
            TEMP.theta2=d.get_arms_angle(2);
            ARMangularspeeds TEMP_AS;




            TEMP_AS=manipullator.make_angular_speed(TEMP.theta0,TEMP.theta1,TEMP.theta2,TEMP.xdat,TEMP.ydat,TEMP.zdat);
            TEMP.theta0dat=TEMP_AS.t0dat;
            TEMP.theta1dat=TEMP_AS.t1dat;
            TEMP.theta2dat=TEMP_AS.t2dat;
            d.set_main_data(PM.CNT_manip_angularSpeed_paketMaker(TEMP),"CNT");

        }




        //  qDebug()<<TEMP.xdat<<"...."<<TEMP.ydat<<"...."<<TEMP.zdat<<"???????"<<TEMP.theta0dat<<"**"<<TEMP.theta1dat<<"**"<<TEMP.theta2dat<<"**";

        else if(w.get_control_mode_flg()==Ui::angularSpeedSetpoint)
        {
            d.set_main_data(PM.CNT_manip_angularSpeed_paketMaker(TEMP),"CNT");
            //        d.set_main_data(PM.CNT_manip_linearSpeed_paketMaker(TEMP),"CNT");
        }

    }
//    muxet.unlock();
    QThread::msleep(10);

}
}

void Loby::getGamepadState(int btn_number, bool status)
{

    if(status==true)
    {
//        muxet.lock();
            if(btn_number==OPTION_btn )
            {
                if(robot_mode==forward_mode)
                {
                    robot_mode=revrese_mode;
                }
                else
                {
                    robot_mode=forward_mode;
                }
                emit robotmode_signal(robot_mode);

            }
            else if (btn_number==SHARE_btn )
            {
                if(robot_mode==manipulator_mod)
                {
                    robot_mode=forward_mode;
                }
                else
                {
                    robot_mode=manipulator_mod;
                }
                emit robotmode_signal(robot_mode);

            }

        //        else
        //        {
        //            if(btn_number==OPTION_btn )
        //            {
        //                if(robot_mode==forward_mode)
        //                {
        //                    robot_mode=revrese_mode;
        //                }
        //                else
        //                {
        //                    robot_mode=forward_mode;
        //                }
        //                emit robotmode_signal(robot_mode);

        //            }
        //            else if (btn_number==SHARE_btn )
        //            {
        //                if(robot_mode==manipulator_mod)
        //                {
        //                    robot_mode=forward_mode;
        //                }
        //                else
        //                {
        //                    robot_mode=manipulator_mod;
        //                }
        //                emit robotmode_signal(robot_mode);

        //            }
        //        }
        //---------------------------------------------------------------
        else if(btn_number==R3_btn )
        {
            emit tabChanged(true);
        }
        else if(btn_number==L3_btn )
        {
            emit tabChanged(false);
        }
        //--------------------------------------------------------------

        //------------------------------------------------------------
        if(joy.getBtnStatus(TOCHPAD_btn))
        {
            if(btn_number==R1_btn)
            {
                emit thresholdSetting(Ui::thresholdSettingValue::motion,w.get_thersholdValue(Ui::thresholdSettingValue::motion)+1);
            }
            else if(btn_number==R2_btn)
            {
                emit thresholdSetting(Ui::thresholdSettingValue::motion,w.get_thersholdValue(Ui::thresholdSettingValue::motion)-1);
            }

            if(btn_number==L1_btn)
            {
                emit thresholdSetting(Ui::thresholdSettingValue::Hazmat,w.get_thersholdValue(Ui::thresholdSettingValue::Hazmat)+1);
            }
            else if(btn_number==L2_btn)
            {
                emit thresholdSetting(Ui::thresholdSettingValue::Hazmat,w.get_thersholdValue(Ui::thresholdSettingValue::Hazmat)-1);
            }
        }
//        muxet.unlock();

    }

}

void Loby::getKeboardState(int k)
{

    switch (k) {
    case Add_:
        w.changeProcessCamera(true);
        break;
    case Subtract_:
        w.changeProcessCamera(false);
        break;
    case Left_:
        emit tabChanged(false);
        break;
    case Right_:
        emit tabChanged(true);
    default:
        break;
    }

}

void Loby::main_feedback_is_ready()
{
    for(int i=0;i<4;i++)
    {
        w.set_arm_angle_just_for_show(i,d.get_arms_angle(i));
    }
    w.set_gas_data_just_for_show(d.get_gas_data());
}



void Loby::MotionProcessing()
{
    Mat temp1;
    Mat temp2;
    int camID;
    camID=w.get_camera_selected();
    if(camID!=4)
    {
        cam_mat[camID].copyTo(temp1);
        motion_buf[camID].copyTo(temp2);
        if(!temp1.empty()&&!temp2.empty())
        {
            QR_.motion(temp1,temp2,w.get_thersholdValue(Ui::thresholdSettingValue::motion));
        }
    }
}

