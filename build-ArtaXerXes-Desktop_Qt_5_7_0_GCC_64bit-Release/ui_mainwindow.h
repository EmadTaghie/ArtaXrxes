/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *Hazmat_mode_;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *Single_hazmat;
    QRadioButton *Quad_hazmat;
    QRadioButton *Non_hazmat;
    QGroupBox *Selectprocesscam;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *cam1_radioButton;
    QRadioButton *cam2_radioButton;
    QRadioButton *cam3_radioButton;
    QRadioButton *cam4_radioButton;
    QRadioButton *noncam_radioButton_2;
    QPushButton *robotmode_state;
    QHBoxLayout *horizontalLayout_5;
    QSlider *hazmatTresh;
    QSlider *motionThrsh;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *gamepad_connection_viwe;
    QProgressBar *LEDLightProgressBar;
    QProgressBar *GasProgressBar;
    QGridLayout *gridLayout_12;
    QLabel *Hazmat2;
    QLabel *hazmat1Data;
    QLabel *Hazmat4;
    QLabel *Hazmat1;
    QLabel *Qr;
    QLabel *hazmat2Data;
    QLabel *hazmat3Data;
    QLabel *Qr_data;
    QLabel *hazmat4Data;
    QLabel *Hazmat3;
    QLabel *Single_Hazmat4;
    QLabel *hazmatSingleData_;
    QSpacerItem *verticalSpacer;
    QCheckBox *camera_mode;
    QFrame *line_2;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QLabel *extraViwe;
    QTabWidget *tabWidget;
    QWidget *quadViwe;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *quadViwe_1;
    QLabel *quadViwe_2;
    QLabel *quadViwe_3;
    QLabel *quadViwe_4;
    QWidget *processViwe;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QLabel *processViwe_1;
    QLabel *processViwe_2;
    QLabel *processViwe_4;
    QLabel *processViwe_3;
    QWidget *tab;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_7;
    QDoubleSpinBox *doubleSpinBox_point_ARM_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *txt_angular_speed_arm_2;
    QFrame *line_4;
    QFrame *line_3;
    QLabel *label4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *doubleSpinBox_AS_ARM_2;
    QLabel *txt_z;
    QLabel *txt_arm_0;
    QDoubleSpinBox *doubleSpinBox_point_ARM_1;
    QLabel *txt_arm_2;
    QLabel *txt_x;
    QLabel *txt_angular_speed_arm_1;
    QFrame *line_5;
    QDoubleSpinBox *doubleSpinBox_point_ARM_0;
    QDoubleSpinBox *doubleSpinBox_AS_ARM_1;
    QLabel *txt_y;
    QLabel *label3;
    QLabel *label1;
    QDoubleSpinBox *doubleSpinBox_ARM_0;
    QLabel *label2;
    QLabel *txt_angular_speed_arm_0;
    QDoubleSpinBox *doubleSpinBox_AS_ARM_0;
    QDoubleSpinBox *doubleSpinBox_X_speed;
    QDoubleSpinBox *doubleSpinBox_Z_speed;
    QDoubleSpinBox *doubleSpinBox_Y_speed;
    QDoubleSpinBox *doubleSpinBox_ARM_2;
    QFrame *line_6;
    QFrame *line_11;
    QLabel *txt_arm_1;
    QDoubleSpinBox *doubleSpinBox_ARM_1;
    QRadioButton *controlMod_AP;
    QRadioButton *controlMod_LS;
    QRadioButton *controlMod_AS;
    QRadioButton *nonControlMod;
    QDoubleSpinBox *doubleSpinBox_point_ARM_3;
    QDoubleSpinBox *doubleSpinBox_ARM_3;
    QLabel *txt_arm_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_11;
    QLabel *Map_image_show;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1274, 762);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(86, 86, 86)"));
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Hazmat_mode_ = new QGroupBox(centralWidget);
        Hazmat_mode_->setObjectName(QStringLiteral("Hazmat_mode_"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(86, 86, 86, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Hazmat_mode_->setPalette(palette);
        gridLayout_9 = new QGridLayout(Hazmat_mode_);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        Single_hazmat = new QRadioButton(Hazmat_mode_);
        Single_hazmat->setObjectName(QStringLiteral("Single_hazmat"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Single_hazmat->setPalette(palette1);

        verticalLayout_10->addWidget(Single_hazmat);

        Quad_hazmat = new QRadioButton(Hazmat_mode_);
        Quad_hazmat->setObjectName(QStringLiteral("Quad_hazmat"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Quad_hazmat->setPalette(palette2);

        verticalLayout_10->addWidget(Quad_hazmat);

        Non_hazmat = new QRadioButton(Hazmat_mode_);
        Non_hazmat->setObjectName(QStringLiteral("Non_hazmat"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Non_hazmat->setPalette(palette3);
        Non_hazmat->setChecked(true);

        verticalLayout_10->addWidget(Non_hazmat);


        gridLayout_9->addLayout(verticalLayout_10, 0, 0, 1, 1);


        verticalLayout->addWidget(Hazmat_mode_);

        Selectprocesscam = new QGroupBox(centralWidget);
        Selectprocesscam->setObjectName(QStringLiteral("Selectprocesscam"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        Selectprocesscam->setPalette(palette4);
        gridLayout_8 = new QGridLayout(Selectprocesscam);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        cam1_radioButton = new QRadioButton(Selectprocesscam);
        cam1_radioButton->setObjectName(QStringLiteral("cam1_radioButton"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        cam1_radioButton->setPalette(palette5);

        verticalLayout_9->addWidget(cam1_radioButton);

        cam2_radioButton = new QRadioButton(Selectprocesscam);
        cam2_radioButton->setObjectName(QStringLiteral("cam2_radioButton"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        cam2_radioButton->setPalette(palette6);
        cam2_radioButton->setChecked(true);

        verticalLayout_9->addWidget(cam2_radioButton);

        cam3_radioButton = new QRadioButton(Selectprocesscam);
        cam3_radioButton->setObjectName(QStringLiteral("cam3_radioButton"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        cam3_radioButton->setPalette(palette7);

        verticalLayout_9->addWidget(cam3_radioButton);

        cam4_radioButton = new QRadioButton(Selectprocesscam);
        cam4_radioButton->setObjectName(QStringLiteral("cam4_radioButton"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        cam4_radioButton->setPalette(palette8);
        cam4_radioButton->setChecked(false);

        verticalLayout_9->addWidget(cam4_radioButton);

        noncam_radioButton_2 = new QRadioButton(Selectprocesscam);
        noncam_radioButton_2->setObjectName(QStringLiteral("noncam_radioButton_2"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        noncam_radioButton_2->setPalette(palette9);
        noncam_radioButton_2->setChecked(false);

        verticalLayout_9->addWidget(noncam_radioButton_2);


        gridLayout_8->addLayout(verticalLayout_9, 1, 0, 1, 1);


        verticalLayout->addWidget(Selectprocesscam);

        robotmode_state = new QPushButton(centralWidget);
        robotmode_state->setObjectName(QStringLiteral("robotmode_state"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(robotmode_state->sizePolicy().hasHeightForWidth());
        robotmode_state->setSizePolicy(sizePolicy);
        robotmode_state->setMinimumSize(QSize(0, 100));
        robotmode_state->setMaximumSize(QSize(400, 16777215));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush4(QColor(255, 250, 203, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush4);
        QBrush brush5(QColor(253, 241, 141, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        QBrush brush6(QColor(126, 116, 39, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush6);
        QBrush brush7(QColor(168, 155, 52, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush7);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush3);
        QBrush brush8(QColor(253, 244, 167, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush3);
        QBrush brush10(QColor(252, 233, 79, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        robotmode_state->setPalette(palette10);
        QFont font;
        font.setFamily(QStringLiteral("Abyssinica SIL"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        robotmode_state->setFont(font);
        robotmode_state->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 255)"));

        verticalLayout->addWidget(robotmode_state);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        hazmatTresh = new QSlider(centralWidget);
        hazmatTresh->setObjectName(QStringLiteral("hazmatTresh"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush11(QColor(237, 212, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush11);
        QBrush brush12(QColor(190, 190, 190, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush11);
        hazmatTresh->setPalette(palette11);
        hazmatTresh->setMaximum(30);
        hazmatTresh->setSingleStep(2);
        hazmatTresh->setValue(11);
        hazmatTresh->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(hazmatTresh);

        motionThrsh = new QSlider(centralWidget);
        motionThrsh->setObjectName(QStringLiteral("motionThrsh"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush11);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush10);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush11);
        motionThrsh->setPalette(palette12);
        motionThrsh->setMinimum(0);
        motionThrsh->setMaximum(50);
        motionThrsh->setValue(10);
        motionThrsh->setOrientation(Qt::Vertical);

        horizontalLayout_5->addWidget(motionThrsh);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gamepad_connection_viwe = new QLabel(centralWidget);
        gamepad_connection_viwe->setObjectName(QStringLiteral("gamepad_connection_viwe"));
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        gamepad_connection_viwe->setFont(font1);
        gamepad_connection_viwe->setStyleSheet(QLatin1String("color : rgb(200,10,10);\n"
"text-align: center;"));
        gamepad_connection_viwe->setTextFormat(Qt::AutoText);
        gamepad_connection_viwe->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(gamepad_connection_viwe);

        LEDLightProgressBar = new QProgressBar(centralWidget);
        LEDLightProgressBar->setObjectName(QStringLiteral("LEDLightProgressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LEDLightProgressBar->sizePolicy().hasHeightForWidth());
        LEDLightProgressBar->setSizePolicy(sizePolicy1);
        LEDLightProgressBar->setMaximumSize(QSize(300, 25));
        QPalette palette13;
        QBrush brush13(QColor(85, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush13);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush13);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush13);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush13);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        LEDLightProgressBar->setPalette(palette13);
        QFont font2;
        font2.setFamily(QStringLiteral("Purisa"));
        font2.setPointSize(17);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        LEDLightProgressBar->setFont(font2);
        LEDLightProgressBar->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"    width: 10px;\n"
"    margin: 0.5px;\n"
"}\n"
"QProgressBar {\n"
"	color : rgb(85, 0, 0);\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #05B8CC;\n"
"    width: 20px;\n"
"\n"
"}"));
        LEDLightProgressBar->setMaximum(100);
        LEDLightProgressBar->setValue(0);
        LEDLightProgressBar->setInvertedAppearance(false);
        LEDLightProgressBar->setTextDirection(QProgressBar::BottomToTop);

        verticalLayout_2->addWidget(LEDLightProgressBar);

        GasProgressBar = new QProgressBar(centralWidget);
        GasProgressBar->setObjectName(QStringLiteral("GasProgressBar"));
        sizePolicy1.setHeightForWidth(GasProgressBar->sizePolicy().hasHeightForWidth());
        GasProgressBar->setSizePolicy(sizePolicy1);
        GasProgressBar->setMaximumSize(QSize(300, 25));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush13);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush13);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        GasProgressBar->setPalette(palette14);
        QFont font3;
        font3.setFamily(QStringLiteral("Purisa"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::NoAntialias);
        GasProgressBar->setFont(font3);
        GasProgressBar->setAcceptDrops(false);
        GasProgressBar->setAutoFillBackground(false);
        GasProgressBar->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"    width: 10px;\n"
"    margin: 0.5px;\n"
"}\n"
"QProgressBar {\n"
"	color : rgb(85, 0, 0);\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #05B8CC;\n"
"    width: 5\n"
"px;\n"
"\n"
"}"));
        GasProgressBar->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        GasProgressBar->setMaximum(255);
        GasProgressBar->setValue(85);

        verticalLayout_2->addWidget(GasProgressBar);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        Hazmat2 = new QLabel(centralWidget);
        Hazmat2->setObjectName(QStringLiteral("Hazmat2"));
        QFont font4;
        font4.setFamily(QStringLiteral("Century Schoolbook L"));
        Hazmat2->setFont(font4);

        gridLayout_12->addWidget(Hazmat2, 3, 0, 1, 1);

        hazmat1Data = new QLabel(centralWidget);
        hazmat1Data->setObjectName(QStringLiteral("hazmat1Data"));
        hazmat1Data->setMaximumSize(QSize(300, 16777215));
        hazmat1Data->setFont(font4);

        gridLayout_12->addWidget(hazmat1Data, 2, 2, 1, 1);

        Hazmat4 = new QLabel(centralWidget);
        Hazmat4->setObjectName(QStringLiteral("Hazmat4"));
        Hazmat4->setFont(font4);

        gridLayout_12->addWidget(Hazmat4, 5, 0, 1, 1);

        Hazmat1 = new QLabel(centralWidget);
        Hazmat1->setObjectName(QStringLiteral("Hazmat1"));
        Hazmat1->setMaximumSize(QSize(16777215, 25));
        Hazmat1->setFont(font4);

        gridLayout_12->addWidget(Hazmat1, 2, 0, 1, 1);

        Qr = new QLabel(centralWidget);
        Qr->setObjectName(QStringLiteral("Qr"));
        Qr->setMaximumSize(QSize(16777215, 25));
        Qr->setFont(font4);

        gridLayout_12->addWidget(Qr, 1, 0, 1, 1);

        hazmat2Data = new QLabel(centralWidget);
        hazmat2Data->setObjectName(QStringLiteral("hazmat2Data"));
        hazmat2Data->setMaximumSize(QSize(300, 25));
        hazmat2Data->setFont(font4);

        gridLayout_12->addWidget(hazmat2Data, 3, 2, 1, 1);

        hazmat3Data = new QLabel(centralWidget);
        hazmat3Data->setObjectName(QStringLiteral("hazmat3Data"));
        hazmat3Data->setMaximumSize(QSize(300, 25));
        hazmat3Data->setFont(font4);

        gridLayout_12->addWidget(hazmat3Data, 4, 2, 1, 1);

        Qr_data = new QLabel(centralWidget);
        Qr_data->setObjectName(QStringLiteral("Qr_data"));
        Qr_data->setMaximumSize(QSize(300, 16777215));
        Qr_data->setFont(font4);

        gridLayout_12->addWidget(Qr_data, 1, 2, 1, 1);

        hazmat4Data = new QLabel(centralWidget);
        hazmat4Data->setObjectName(QStringLiteral("hazmat4Data"));
        hazmat4Data->setMaximumSize(QSize(300, 25));
        hazmat4Data->setFont(font4);

        gridLayout_12->addWidget(hazmat4Data, 5, 2, 1, 1);

        Hazmat3 = new QLabel(centralWidget);
        Hazmat3->setObjectName(QStringLiteral("Hazmat3"));
        Hazmat3->setFont(font4);

        gridLayout_12->addWidget(Hazmat3, 4, 0, 1, 1);

        Single_Hazmat4 = new QLabel(centralWidget);
        Single_Hazmat4->setObjectName(QStringLiteral("Single_Hazmat4"));
        Single_Hazmat4->setMaximumSize(QSize(100, 20));
        Single_Hazmat4->setFont(font4);

        gridLayout_12->addWidget(Single_Hazmat4, 6, 0, 1, 1);

        hazmatSingleData_ = new QLabel(centralWidget);
        hazmatSingleData_->setObjectName(QStringLiteral("hazmatSingleData_"));
        hazmatSingleData_->setMaximumSize(QSize(300, 25));
        hazmatSingleData_->setFont(font4);

        gridLayout_12->addWidget(hazmatSingleData_, 6, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer, 7, 2, 1, 1);

        camera_mode = new QCheckBox(centralWidget);
        camera_mode->setObjectName(QStringLiteral("camera_mode"));
        camera_mode->setChecked(true);

        gridLayout_12->addWidget(camera_mode, 7, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_12);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(59, 300));
        widget->setMaximumSize(QSize(460, 320));
        widget->setStyleSheet(QLatin1String("background-color: rgb(40, 0, 0);\n"
"border-style:outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"    font: bold 10px;\n"
"    min-width: 5em;\n"
"border-color :rgb(100, 150, 200);  \n"
" color:rgb(17, 85, 255);"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        extraViwe = new QLabel(widget);
        extraViwe->setObjectName(QStringLiteral("extraViwe"));
        extraViwe->setStyleSheet(QStringLiteral("color : blue"));
        extraViwe->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(extraViwe, 0, 0, 1, 1);


        verticalLayout_3->addWidget(widget);


        gridLayout_3->addLayout(verticalLayout_3, 0, 2, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(1400, 1000));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(40, 0, 0);\n"
"border-style:outset;\n"
"    border-width: 2px;\n"
"    border-color: beige;\n"
"    font: bold 10px;\n"
"    min-width: 5em;\n"
"border-color :rgb(100, 150, 200);  \n"
" color:rgb(17, 85, 255);"));
        tabWidget->setTabBarAutoHide(false);
        quadViwe = new QWidget();
        quadViwe->setObjectName(QStringLiteral("quadViwe"));
        QFont font5;
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        quadViwe->setFont(font5);
        quadViwe->setAutoFillBackground(false);
        quadViwe->setInputMethodHints(Qt::ImhNone);
        gridLayout_2 = new QGridLayout(quadViwe);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        quadViwe_1 = new QLabel(quadViwe);
        quadViwe_1->setObjectName(QStringLiteral("quadViwe_1"));
        quadViwe_1->setStyleSheet(QStringLiteral(""));
        quadViwe_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(quadViwe_1, 1, 0, 1, 1);

        quadViwe_2 = new QLabel(quadViwe);
        quadViwe_2->setObjectName(QStringLiteral("quadViwe_2"));
        quadViwe_2->setStyleSheet(QStringLiteral(""));
        quadViwe_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(quadViwe_2, 1, 1, 1, 1);

        quadViwe_3 = new QLabel(quadViwe);
        quadViwe_3->setObjectName(QStringLiteral("quadViwe_3"));
        quadViwe_3->setStyleSheet(QStringLiteral(""));
        quadViwe_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(quadViwe_3, 2, 0, 1, 1);

        quadViwe_4 = new QLabel(quadViwe);
        quadViwe_4->setObjectName(QStringLiteral("quadViwe_4"));
        quadViwe_4->setStyleSheet(QStringLiteral(""));
        quadViwe_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(quadViwe_4, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(quadViwe, QString());
        processViwe = new QWidget();
        processViwe->setObjectName(QStringLiteral("processViwe"));
        gridLayout_6 = new QGridLayout(processViwe);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        processViwe_1 = new QLabel(processViwe);
        processViwe_1->setObjectName(QStringLiteral("processViwe_1"));
        processViwe_1->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(processViwe_1, 0, 0, 1, 1);

        processViwe_2 = new QLabel(processViwe);
        processViwe_2->setObjectName(QStringLiteral("processViwe_2"));
        processViwe_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(processViwe_2, 0, 1, 1, 1);

        processViwe_4 = new QLabel(processViwe);
        processViwe_4->setObjectName(QStringLiteral("processViwe_4"));
        processViwe_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(processViwe_4, 1, 1, 1, 1);

        processViwe_3 = new QLabel(processViwe);
        processViwe_3->setObjectName(QStringLiteral("processViwe_3"));
        processViwe_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(processViwe_3, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(processViwe, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_10 = new QGridLayout(tab);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        doubleSpinBox_point_ARM_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_point_ARM_2->setObjectName(QStringLiteral("doubleSpinBox_point_ARM_2"));
        doubleSpinBox_point_ARM_2->setMinimumSize(QSize(59, 40));
        doubleSpinBox_point_ARM_2->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_point_ARM_2->setMinimum(-90);
        doubleSpinBox_point_ARM_2->setMaximum(180);

        gridLayout_7->addWidget(doubleSpinBox_point_ARM_2, 4, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 16, 0, 1, 1);

        txt_angular_speed_arm_2 = new QLabel(tab);
        txt_angular_speed_arm_2->setObjectName(QStringLiteral("txt_angular_speed_arm_2"));
        txt_angular_speed_arm_2->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_angular_speed_arm_2, 15, 0, 1, 1);

        line_4 = new QFrame(tab);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_4, 6, 1, 1, 1);

        line_3 = new QFrame(tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_3, 6, 0, 1, 1);

        label4 = new QLabel(tab);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(label4, 7, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 16, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_2, 16, 2, 1, 1);

        doubleSpinBox_AS_ARM_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_AS_ARM_2->setObjectName(QStringLiteral("doubleSpinBox_AS_ARM_2"));
        doubleSpinBox_AS_ARM_2->setMinimumSize(QSize(59, 40));
        doubleSpinBox_AS_ARM_2->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_AS_ARM_2->setMinimum(-90);
        doubleSpinBox_AS_ARM_2->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_AS_ARM_2, 15, 1, 1, 1);

        txt_z = new QLabel(tab);
        txt_z->setObjectName(QStringLiteral("txt_z"));
        txt_z->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_z, 10, 0, 1, 1);

        txt_arm_0 = new QLabel(tab);
        txt_arm_0->setObjectName(QStringLiteral("txt_arm_0"));
        txt_arm_0->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_arm_0, 1, 0, 1, 1);

        doubleSpinBox_point_ARM_1 = new QDoubleSpinBox(tab);
        doubleSpinBox_point_ARM_1->setObjectName(QStringLiteral("doubleSpinBox_point_ARM_1"));
        doubleSpinBox_point_ARM_1->setMinimumSize(QSize(59, 40));
        doubleSpinBox_point_ARM_1->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_point_ARM_1->setMinimum(-90);
        doubleSpinBox_point_ARM_1->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_point_ARM_1, 3, 2, 1, 1);

        txt_arm_2 = new QLabel(tab);
        txt_arm_2->setObjectName(QStringLiteral("txt_arm_2"));
        txt_arm_2->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_arm_2, 4, 0, 1, 1);

        txt_x = new QLabel(tab);
        txt_x->setObjectName(QStringLiteral("txt_x"));
        txt_x->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_x, 8, 0, 1, 1);

        txt_angular_speed_arm_1 = new QLabel(tab);
        txt_angular_speed_arm_1->setObjectName(QStringLiteral("txt_angular_speed_arm_1"));
        txt_angular_speed_arm_1->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_angular_speed_arm_1, 14, 0, 1, 1);

        line_5 = new QFrame(tab);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_5, 6, 2, 1, 1);

        doubleSpinBox_point_ARM_0 = new QDoubleSpinBox(tab);
        doubleSpinBox_point_ARM_0->setObjectName(QStringLiteral("doubleSpinBox_point_ARM_0"));
        doubleSpinBox_point_ARM_0->setMinimumSize(QSize(59, 40));
        doubleSpinBox_point_ARM_0->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_point_ARM_0->setMinimum(-90);
        doubleSpinBox_point_ARM_0->setMaximum(180);

        gridLayout_7->addWidget(doubleSpinBox_point_ARM_0, 1, 2, 1, 1);

        doubleSpinBox_AS_ARM_1 = new QDoubleSpinBox(tab);
        doubleSpinBox_AS_ARM_1->setObjectName(QStringLiteral("doubleSpinBox_AS_ARM_1"));
        doubleSpinBox_AS_ARM_1->setMinimumSize(QSize(59, 40));
        doubleSpinBox_AS_ARM_1->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_AS_ARM_1->setMinimum(-90);
        doubleSpinBox_AS_ARM_1->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_AS_ARM_1, 14, 1, 1, 1);

        txt_y = new QLabel(tab);
        txt_y->setObjectName(QStringLiteral("txt_y"));
        txt_y->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_y, 9, 0, 1, 1);

        label3 = new QLabel(tab);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(label3, 12, 1, 1, 1);

        label1 = new QLabel(tab);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(label1, 0, 2, 1, 1);

        doubleSpinBox_ARM_0 = new QDoubleSpinBox(tab);
        doubleSpinBox_ARM_0->setObjectName(QStringLiteral("doubleSpinBox_ARM_0"));
        doubleSpinBox_ARM_0->setMinimumSize(QSize(59, 40));
        doubleSpinBox_ARM_0->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_ARM_0->setMinimum(-90);
        doubleSpinBox_ARM_0->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_ARM_0, 1, 1, 1, 1);

        label2 = new QLabel(tab);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(label2, 0, 1, 1, 1);

        txt_angular_speed_arm_0 = new QLabel(tab);
        txt_angular_speed_arm_0->setObjectName(QStringLiteral("txt_angular_speed_arm_0"));
        txt_angular_speed_arm_0->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_angular_speed_arm_0, 13, 0, 1, 1);

        doubleSpinBox_AS_ARM_0 = new QDoubleSpinBox(tab);
        doubleSpinBox_AS_ARM_0->setObjectName(QStringLiteral("doubleSpinBox_AS_ARM_0"));
        doubleSpinBox_AS_ARM_0->setMinimumSize(QSize(59, 40));
        doubleSpinBox_AS_ARM_0->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_AS_ARM_0->setMinimum(-90);
        doubleSpinBox_AS_ARM_0->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_AS_ARM_0, 13, 1, 1, 1);

        doubleSpinBox_X_speed = new QDoubleSpinBox(tab);
        doubleSpinBox_X_speed->setObjectName(QStringLiteral("doubleSpinBox_X_speed"));
        doubleSpinBox_X_speed->setMinimumSize(QSize(59, 40));
        doubleSpinBox_X_speed->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_X_speed->setMinimum(-90);
        doubleSpinBox_X_speed->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_X_speed, 8, 1, 1, 1);

        doubleSpinBox_Z_speed = new QDoubleSpinBox(tab);
        doubleSpinBox_Z_speed->setObjectName(QStringLiteral("doubleSpinBox_Z_speed"));
        doubleSpinBox_Z_speed->setMinimumSize(QSize(59, 40));
        doubleSpinBox_Z_speed->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_Z_speed->setMinimum(-90);
        doubleSpinBox_Z_speed->setMaximum(90);
        doubleSpinBox_Z_speed->setSingleStep(0.1);

        gridLayout_7->addWidget(doubleSpinBox_Z_speed, 10, 1, 1, 1);

        doubleSpinBox_Y_speed = new QDoubleSpinBox(tab);
        doubleSpinBox_Y_speed->setObjectName(QStringLiteral("doubleSpinBox_Y_speed"));
        doubleSpinBox_Y_speed->setMinimumSize(QSize(59, 40));
        doubleSpinBox_Y_speed->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_Y_speed->setMinimum(-90);
        doubleSpinBox_Y_speed->setMaximum(90);

        gridLayout_7->addWidget(doubleSpinBox_Y_speed, 9, 1, 1, 1);

        doubleSpinBox_ARM_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_ARM_2->setObjectName(QStringLiteral("doubleSpinBox_ARM_2"));
        doubleSpinBox_ARM_2->setMinimumSize(QSize(59, 40));
        doubleSpinBox_ARM_2->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_ARM_2->setMinimum(-180);
        doubleSpinBox_ARM_2->setMaximum(180);
        doubleSpinBox_ARM_2->setSingleStep(0.3);

        gridLayout_7->addWidget(doubleSpinBox_ARM_2, 4, 1, 1, 1);

        line_6 = new QFrame(tab);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_6, 11, 0, 1, 1);

        line_11 = new QFrame(tab);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_11, 11, 1, 1, 1);

        txt_arm_1 = new QLabel(tab);
        txt_arm_1->setObjectName(QStringLiteral("txt_arm_1"));
        txt_arm_1->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_arm_1, 3, 0, 1, 1);

        doubleSpinBox_ARM_1 = new QDoubleSpinBox(tab);
        doubleSpinBox_ARM_1->setObjectName(QStringLiteral("doubleSpinBox_ARM_1"));
        doubleSpinBox_ARM_1->setMinimumSize(QSize(59, 40));
        doubleSpinBox_ARM_1->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_ARM_1->setMinimum(-180);
        doubleSpinBox_ARM_1->setMaximum(180);
        doubleSpinBox_ARM_1->setSingleStep(0.3);

        gridLayout_7->addWidget(doubleSpinBox_ARM_1, 3, 1, 1, 1);

        controlMod_AP = new QRadioButton(tab);
        controlMod_AP->setObjectName(QStringLiteral("controlMod_AP"));
        controlMod_AP->setMinimumSize(QSize(59, 50));
        controlMod_AP->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(controlMod_AP, 0, 0, 1, 1);

        controlMod_LS = new QRadioButton(tab);
        controlMod_LS->setObjectName(QStringLiteral("controlMod_LS"));
        controlMod_LS->setMinimumSize(QSize(59, 50));
        controlMod_LS->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(controlMod_LS, 7, 0, 1, 1);

        controlMod_AS = new QRadioButton(tab);
        controlMod_AS->setObjectName(QStringLiteral("controlMod_AS"));
        controlMod_AS->setMinimumSize(QSize(59, 50));
        controlMod_AS->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(controlMod_AS, 12, 0, 1, 1);

        nonControlMod = new QRadioButton(tab);
        nonControlMod->setObjectName(QStringLiteral("nonControlMod"));
        nonControlMod->setMinimumSize(QSize(59, 50));
        nonControlMod->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(nonControlMod, 7, 2, 1, 1);

        doubleSpinBox_point_ARM_3 = new QDoubleSpinBox(tab);
        doubleSpinBox_point_ARM_3->setObjectName(QStringLiteral("doubleSpinBox_point_ARM_3"));
        doubleSpinBox_point_ARM_3->setMinimumSize(QSize(59, 40));
        doubleSpinBox_point_ARM_3->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_point_ARM_3->setMinimum(-90);
        doubleSpinBox_point_ARM_3->setMaximum(180);

        gridLayout_7->addWidget(doubleSpinBox_point_ARM_3, 5, 2, 1, 1);

        doubleSpinBox_ARM_3 = new QDoubleSpinBox(tab);
        doubleSpinBox_ARM_3->setObjectName(QStringLiteral("doubleSpinBox_ARM_3"));
        doubleSpinBox_ARM_3->setMinimumSize(QSize(59, 40));
        doubleSpinBox_ARM_3->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));
        doubleSpinBox_ARM_3->setMinimum(-180);
        doubleSpinBox_ARM_3->setMaximum(180);
        doubleSpinBox_ARM_3->setSingleStep(0.3);

        gridLayout_7->addWidget(doubleSpinBox_ARM_3, 5, 1, 1, 1);

        txt_arm_3 = new QLabel(tab);
        txt_arm_3->setObjectName(QStringLiteral("txt_arm_3"));
        txt_arm_3->setStyleSheet(QStringLiteral("background-color :rgb(250,250,250)"));

        gridLayout_7->addWidget(txt_arm_3, 5, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_7, 0, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_11 = new QGridLayout(tab_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        Map_image_show = new QLabel(tab_2);
        Map_image_show->setObjectName(QStringLiteral("Map_image_show"));

        gridLayout_11->addWidget(Map_image_show, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Hazmat_mode_->setTitle(QApplication::translate("MainWindow", "Hazmat mode", 0));
        Single_hazmat->setText(QApplication::translate("MainWindow", "Single_hazmat", 0));
        Quad_hazmat->setText(QApplication::translate("MainWindow", "Quad_hazmat", 0));
        Non_hazmat->setText(QApplication::translate("MainWindow", "Non_hazmat", 0));
        Selectprocesscam->setTitle(QApplication::translate("MainWindow", "Select Camera", 0));
        cam1_radioButton->setText(QApplication::translate("MainWindow", "camera 1", 0));
        cam2_radioButton->setText(QApplication::translate("MainWindow", "camera 2", 0));
        cam3_radioButton->setText(QApplication::translate("MainWindow", "camera 3", 0));
        cam4_radioButton->setText(QApplication::translate("MainWindow", "camera 4", 0));
        noncam_radioButton_2->setText(QApplication::translate("MainWindow", "Non prosecc", 0));
#ifndef QT_NO_ACCESSIBILITY
        robotmode_state->setAccessibleName(QApplication::translate("MainWindow", "jnjjijoi", 0));
#endif // QT_NO_ACCESSIBILITY
        robotmode_state->setText(QApplication::translate("MainWindow", "Move Mode", 0));
        gamepad_connection_viwe->setText(QApplication::translate("MainWindow", "gamepad is not connect", 0));
        LEDLightProgressBar->setFormat(QApplication::translate("MainWindow", "LED", 0));
        GasProgressBar->setFormat(QApplication::translate("MainWindow", "Gas data", 0));
        Hazmat2->setText(QApplication::translate("MainWindow", "Hazmat2:", 0));
        hazmat1Data->setText(QString());
        Hazmat4->setText(QApplication::translate("MainWindow", "Hazmat4:", 0));
        Hazmat1->setText(QApplication::translate("MainWindow", "Hazmat1:", 0));
        Qr->setText(QApplication::translate("MainWindow", "QR Code:", 0));
        hazmat2Data->setText(QString());
        hazmat3Data->setText(QString());
        Qr_data->setText(QString());
        hazmat4Data->setText(QString());
        Hazmat3->setText(QApplication::translate("MainWindow", "Hazmat3:", 0));
        Single_Hazmat4->setText(QApplication::translate("MainWindow", "Single Hazmat:", 0));
        hazmatSingleData_->setText(QString());
        camera_mode->setText(QApplication::translate("MainWindow", "Camera GTA mode", 0));
        extraViwe->setText(QApplication::translate("MainWindow", "camera 1", 0));
        quadViwe_1->setText(QApplication::translate("MainWindow", "camera 1", 0));
        quadViwe_2->setText(QApplication::translate("MainWindow", "camera 2", 0));
        quadViwe_3->setText(QApplication::translate("MainWindow", "camera 3", 0));
        quadViwe_4->setText(QApplication::translate("MainWindow", "camera 4", 0));
        tabWidget->setTabText(tabWidget->indexOf(quadViwe), QApplication::translate("MainWindow", "Quad viwe", 0));
        processViwe_1->setText(QApplication::translate("MainWindow", "process1", 0));
        processViwe_2->setText(QApplication::translate("MainWindow", "process2", 0));
        processViwe_4->setText(QApplication::translate("MainWindow", "process4", 0));
        processViwe_3->setText(QApplication::translate("MainWindow", "process3", 0));
        tabWidget->setTabText(tabWidget->indexOf(processViwe), QApplication::translate("MainWindow", "Process Viwe", 0));
        txt_angular_speed_arm_2->setText(QApplication::translate("MainWindow", "ARM 2 A.S", 0));
        label4->setText(QApplication::translate("MainWindow", "Linear speed Set Point", 0));
        txt_z->setText(QApplication::translate("MainWindow", "Z", 0));
        txt_arm_0->setText(QApplication::translate("MainWindow", "ARM 0", 0));
        txt_arm_2->setText(QApplication::translate("MainWindow", "ARM 2", 0));
        txt_x->setText(QApplication::translate("MainWindow", "X", 0));
        txt_angular_speed_arm_1->setText(QApplication::translate("MainWindow", "ARM 1 A.S", 0));
        txt_y->setText(QApplication::translate("MainWindow", "Y", 0));
        label3->setText(QApplication::translate("MainWindow", "Angular speed Set Point", 0));
        label1->setText(QApplication::translate("MainWindow", "Point", 0));
        label2->setText(QApplication::translate("MainWindow", "Set Point", 0));
        txt_angular_speed_arm_0->setText(QApplication::translate("MainWindow", "ARM 0 A.S", 0));
        txt_arm_1->setText(QApplication::translate("MainWindow", "ARM 1", 0));
        controlMod_AP->setText(QApplication::translate("MainWindow", " A P Control", 0));
        controlMod_LS->setText(QApplication::translate("MainWindow", "L S control", 0));
        controlMod_AS->setText(QApplication::translate("MainWindow", "A S", 0));
        nonControlMod->setText(QApplication::translate("MainWindow", "PWM mode", 0));
        txt_arm_3->setText(QApplication::translate("MainWindow", "ARM 3", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Control", 0));
        Map_image_show->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Map", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
