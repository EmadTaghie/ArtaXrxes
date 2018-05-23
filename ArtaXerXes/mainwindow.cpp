#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    controlMode_flg=false;
    ui->setupUi(this);
    connect(&viweTimer,SIGNAL(timeout()),this,SLOT(tabUpdate()));
    viweTimer.start(100);
    tab_thr.start(QThread::HighestPriority);
    ui->nonControlMod->setChecked(true);
    controlMode_flg=Ui::PWMSetpoint;
    filterX=0;
    filterY=0;
    filterZ=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeProcessCamera(bool flg)
{
    if(flg)
    {
        if(ui->cam1_radioButton->isChecked())
        {
            ui->cam2_radioButton->setChecked(true);
        }
        else if(ui->cam2_radioButton->isChecked())
        {
            ui->cam3_radioButton->setChecked(true);
        }
        else if(ui->cam3_radioButton->isChecked())
        {
            ui->cam4_radioButton->setChecked(true);
        }
        else if(ui->cam4_radioButton->isChecked())
        {
            ui->noncam_radioButton_2->setChecked(true);
        }
    }
    else
    {
        if(ui->noncam_radioButton_2->isChecked())
        {
            ui->cam4_radioButton->setChecked(true);
        }
        else if(ui->cam4_radioButton->isChecked())
        {
            ui->cam3_radioButton->setChecked(true);
        }
        else if(ui->cam3_radioButton->isChecked())
        {
            ui->cam2_radioButton->setChecked(true);
        }
        else if(ui->cam2_radioButton->isChecked())
        {
            ui->cam1_radioButton->setChecked(true);
        }
    }

}

void MainWindow::tabUpdate()
{
    Mat m2;
    QImage Qframe;
    for(int i=0;i<4;i++)
    {
        QuadViweDisconnect_[i]++;
    }
    ///------------------------------------------------------------------------------------------///
    //show quade view...
    if(ui->tabWidget->currentIndex()==0)
    {
        if(!Quadview[0].empty())
        {
            cvtColor(Quadview[0],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));

            ui->quadViwe_1->setPixmap(QPixmap::fromImage(Qframe));
        }
        if(!Quadview[1].empty())
        {
            cvtColor(Quadview[1],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));

            ui->quadViwe_2->setPixmap(QPixmap::fromImage(Qframe));
        }
        if(!Quadview[2].empty())
        {
            cvtColor(Quadview[2],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));

            ui->quadViwe_3->setPixmap(QPixmap::fromImage(Qframe));
        }
        if(!Quadview[3].empty())
        {
            cvtColor(Quadview[3],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));

            ui->quadViwe_4->setPixmap(QPixmap::fromImage(Qframe));
        }
    }
    ///---------------------------------------------------------------------------------------///
    //show process viwe...
    else if(ui->tabWidget->currentIndex()==1)
    {

        if(!processview[0].empty())
        {
            cvtColor(processview[0],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));
            ui->processViwe_1->setPixmap(QPixmap::fromImage(Qframe));
        }
        if(!processview[1].empty())
        {
            cvtColor(processview[1],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));
            ui->processViwe_2->setPixmap(QPixmap::fromImage(Qframe));
        }
        if(!processview[2].empty())
        {
            cvtColor(processview[2],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));
            ui->processViwe_3->setPixmap(QPixmap::fromImage(Qframe));
        }
        if(!processview[3].empty())
        {
            cvtColor(processview[3],m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width()/2,ui->tabWidget->height()/2));
            ui->processViwe_4->setPixmap(QPixmap::fromImage(Qframe));
        }
    }


    else if(ui->tabWidget->currentIndex()==3)
    {

        if(!MapMat.empty())
        {
            qDebug()<<"zahremar";

            cvtColor(MapMat,m2,CV_BGR2BGR555);
            Qframe= QImage((uchar*)m2.data, m2.cols, m2.rows, m2.step, QImage::Format_RGB555);
            Qframe=Qframe.scaled(QSize(ui->tabWidget->width(),ui->tabWidget->height()));
            ui->Map_image_show->setPixmap(QPixmap::fromImage(Qframe));

        }
    }


    ///----------------------------------------------------------------------------------------///
    manip_setpoin_status.theta0=ui->doubleSpinBox_ARM_0->value();
    manip_setpoin_status.theta1=ui->doubleSpinBox_ARM_1->value();
    manip_setpoin_status.theta2=ui->doubleSpinBox_ARM_2->value();
    manip_setpoin_status.theta3=ui->doubleSpinBox_ARM_3->value();
    manip_setpoin_status.xdat=ui->doubleSpinBox_X_speed->value()*100;
    manip_setpoin_status.ydat=ui->doubleSpinBox_Y_speed->value()*100;
    manip_setpoin_status.zdat=ui->doubleSpinBox_Z_speed->value()*100;
    manip_setpoin_status.theta0dat=ui->doubleSpinBox_AS_ARM_0->value();
    manip_setpoin_status.theta1dat=ui->doubleSpinBox_AS_ARM_1->value();
    manip_setpoin_status.theta2dat=ui->doubleSpinBox_AS_ARM_2->value();




}

//-------------------------------qaud viwe-------------------------------------//
void MainWindow::quadeViweUpdate1(Mat im)
{

    if(robot_mode== manipulator_mod)
    {
        im.copyTo(Quadview[0]);
    }
    else
    {
        if(ui->camera_mode->isChecked())
        {
            flip(im,Quadview[0],1);
            //im.copyTo(Quadview[0]);
        }
        else
        {
            im.copyTo(Quadview[0]);
        }
    }
    QuadViweDisconnect_[0]=0;
}
void MainWindow::quadeViweUpdate2(Mat im)
{
    //    if(mode_== manipulator_mod)
    //    {
    //    Mat rot_mat = cv::getRotationMatrix2D(Point(im.cols/2,im.rows/2),180, 1);
    //    cv::warpAffine(im, Quadview[1], rot_mat, im.size(), cv::INTER_CUBIC);
    //    }
    //    else {
    im.copyTo(Quadview[1]);
    //    }
    QuadViweDisconnect_[1]=0;
}
void MainWindow::quadeViweUpdate3(Mat im)
{
    flip(im,Quadview[2],1);

    //    im.copyTo(Quadview[2]);
    if(robot_mode== manipulator_mod)
    {
        cv::line(Quadview[2],Point(Quadview[2].cols/2,0),Point(Quadview[2].cols/2,Quadview[2].rows) , cv::Scalar(0,255,0),3);
    }

    QuadViweDisconnect_[2]=0;
}
void MainWindow::quadeViweUpdate4(Mat im)
{
    im.copyTo(Quadview[3]);
    QuadViweDisconnect_[3]=0;
}

void MainWindow::changeTap(bool status)
{
    if( status==true)
    {
        if(ui->tabWidget->currentIndex()!=3)
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    }
    else
    {
        if(ui->tabWidget->currentIndex()!=0)
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
    }
}
//----------------------------------------------------------------------------//

void MainWindow::updateMotionImg(Mat im,int number)
{
    //  numberOfMotion=number;
    im.copyTo(processview[3]);
}
void MainWindow::updateQrImg(Mat im,QString string)
{
    im.copyTo(processview[1]);
    QrString=string;
}

void MainWindow::set_robot_mode_show(int mode)
{
    qDebug()<<mode;
    if(mode==forward_mode)
    {
        ui->robotmode_state->setText("Forward Mode");
        ui->robotmode_state->setStyleSheet("background-color : rgb(0,120,250)");
        robot_mode=forward_mode;
    }
    else if (mode==revrese_mode)
    {
        ui->robotmode_state->setText("Revers Mode");
        ui->robotmode_state->setStyleSheet("background-color : rgb(250,85,0)");
        robot_mode=revrese_mode;
    }
    else if(mode==manipulator_mod)
    {
        ui->robotmode_state->setText("Manipulator");
        ui->robotmode_state->setStyleSheet("background-color : rgb(255,255,0)");
        robot_mode=manipulator_mod;
    }
}

void MainWindow::set_gamepadConnectionViwe(bool flg)
{
    if(flg==true)
    {
        ui->gamepad_connection_viwe->setText("Gamepad Connected");
        ui->gamepad_connection_viwe->setStyleSheet("color : rgb(10,200,10)");
    }

    else

    {
        ui->gamepad_connection_viwe->setText("Gamepad is not Connect");
        ui->gamepad_connection_viwe->setStyleSheet("color : rgb(200,10,10)");
    }




}

void MainWindow::set_thersholdValue(int t, int value)
{
    switch (t) {
    case Ui::thresholdSettingValue::motion:
        ui->motionThrsh->setValue(value);
        break;
    case Ui::thresholdSettingValue::Hazmat:
        ui->hazmatTresh->setValue(value);
        break;
    default:
        break;
    }

}

void MainWindow::set_led_light(bool led)
{
    ui->LEDLightProgressBar->setValue(100*led);
}


int MainWindow::get_camera_selected()
{
    if(ui->cam1_radioButton->isChecked())
    {
        return 0;
    }
    else if(ui->cam2_radioButton->isChecked())
    {
        return 1;
    }
    else if(ui->cam3_radioButton->isChecked())
    {
        return 2;
    }
    else if(ui->cam4_radioButton->isChecked())
    {
        return 3;
    }
    else if(ui->noncam_radioButton_2->isChecked())
    {
        return 4;
    }
}

int MainWindow::get_thersholdValue(Ui::thresholdSettingValue t)
{
    switch (t) {
    case Ui::thresholdSettingValue::motion:
        return ui->motionThrsh->value();
        break;
    case Ui::thresholdSettingValue::Hazmat:
        return ui->hazmatTresh->value();
        break;
    default:
        break;
    }
}

void MainWindow::set_arm_angle_just_for_show(__uint8_t ID,float angle)
{
    if(ID==0)
    {
        ui->doubleSpinBox_point_ARM_0->setValue((double)angle);
    }
    else if(ID==1)
    {
        ui->doubleSpinBox_point_ARM_1->setValue((double)angle);
    }
    else if(ID==2)
    {
        ui->doubleSpinBox_point_ARM_2->setValue((double)angle);
    }
    else if(ID==3)
    {
        ui->doubleSpinBox_point_ARM_3->setValue((double)angle);
    }
}

void MainWindow::set_gas_data_just_for_show(__uint8_t data)
{
    ui->GasProgressBar->setValue(data);
}

uint8_t MainWindow::get_control_mode_flg()
{
    return controlMode_flg;
}

bool MainWindow::get_thermal_ONOF()
{
    if(ui->tabWidget->currentIndex()==1)
    {
        return true;
    }
    else return false;


}

bool MainWindow::get_GTA_camera_mode()
{
    return ui->camera_mode->isChecked();
}

void MainWindow::set_manipulator_linear_speed(int halfAxis_stat[], bool btn_stat[], int mode_)
{
    QByteArray robotData;
    robotData.resize(35);

    double X,Y,Z;

    for(int s=0;s<35;s++)
    {
        robotData[s]=0;
    }
    if(halfAxis_stat[_RR]>low_limit)
    {
        //            if(R3joy_right>200)
        //            robotData[21]=200;
        //            else
        Y=halfAxis_stat[_RR];

        //   ui->doubleSpinBox_Y_speed->setValue(halfAxis_stat[_RR]);
    }
    else if (halfAxis_stat[_RL]>low_limit)
    {
        Y=-1*halfAxis_stat[_RL];
        // ui->doubleSpinBox_Y_speed->setValue(-1*halfAxis_stat[_RL]);
    }
    else
    {
        Y=0;
        //ui->doubleSpinBox_Y_speed->setValue(0);
    }
    //Arm1
    if(halfAxis_stat[_RU]>low_limit)
    {
        X=halfAxis_stat[_RU];
        //ui->doubleSpinBox_X_speed->setValue(halfAxis_stat[_RU]);
    }
    else if(halfAxis_stat[_RD]>low_limit)
    {
        X=-1*halfAxis_stat[_RD];
        //ui->doubleSpinBox_X_speed->setValue(-1*halfAxis_stat[_RD]);
    }
    else
    {
        X=0;
        //ui->doubleSpinBox_X_speed->setValue(0);
    }

    //Arm2
    if(halfAxis_stat[_LU]>low_limit)
    {
        Z=halfAxis_stat[_LU];
        //ui->doubleSpinBox_Z_speed->setValue(halfAxis_stat[_LU]);
    }
    else if(halfAxis_stat[_LD]>low_limit)
    {
        Z=-1*halfAxis_stat[_LD];
        //ui->doubleSpinBox_Z_speed->setValue(-1*halfAxis_stat[_LD]);
    }
    else
    {
        Z=0;
        //ui->doubleSpinBox_Z_speed->setValue(0);
    }

    filterX=1*X;//+1*filterX;
    filterY=1*Y;//+1*filterY;
    filterZ=1*Z;//+1*filterZ;

    ui->doubleSpinBox_X_speed->setValue(filterX);
    ui->doubleSpinBox_Y_speed->setValue(filterY);
    ui->doubleSpinBox_Z_speed->setValue(filterZ);




}

void MainWindow::updateThearmalImg(Mat im)
{
    im.copyTo(processview[0]);

}

void MainWindow::updateMapImg(Mat m)
{
    //    imshow("map",map);


    m.copyTo(MapMat);

}
void MainWindow::on_controlMod_AP_toggled(bool checked)
{
    //    if(checked=true)
    //    {
    //        controlMode_flg=Ui::angleSetpoint;
    //        ui->controlMod_AS->setChecked(false);
    //        ui->controlMod_LS->setChecked(false);
    //        ui->nonControlMod->setChecked(false);
    //    }
}

void MainWindow::on_controlMod_LS_toggled(bool checked)
{
    //    if(checked=true)
    //    {
    //        controlMode_flg=Ui::linearSpeedSetpoint;
    //        ui->controlMod_AP->setChecked(false);
    //        ui->controlMod_AS->setChecked(false);
    //        ui->nonControlMod->setChecked(false);
    //    }
}

void MainWindow::on_controlMod_AS_toggled(bool checked)
{
    //    if(checked=true)
    //    {
    //        controlMode_flg=Ui::angularSpeedSetpoint;
    //        ui->controlMod_AP->setChecked(false);
    //        ui->controlMod_LS->setChecked(false);
    //        ui->nonControlMod->setChecked(false);
    //    }
}

void MainWindow::on_nonControlMod_toggled(bool checked)
{
    //    if(checked=true)
    //    {
    //        controlMode_flg=Ui::PWMSetpoint;
    //        ui->controlMod_AP->setChecked(false);
    //        ui->controlMod_LS->setChecked(false);
    //        ui->controlMod_AS->setChecked(false);
    //    }
}

void MainWindow::on_controlMod_AS_clicked()
{
    controlMode_flg=Ui::angularSpeedSetpoint;

}

void MainWindow::on_controlMod_LS_clicked()
{
    controlMode_flg=Ui::linearSpeedSetpoint;
}

void MainWindow::on_controlMod_AP_clicked()
{
    controlMode_flg=Ui::angleSetpoint;
}

void MainWindow::on_nonControlMod_clicked()
{
    controlMode_flg=Ui::PWMSetpoint;
}
