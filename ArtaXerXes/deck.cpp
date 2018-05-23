#include "deck.h"

Deck::Deck(QObject *parent) : QObject(parent)
{
    //tanzimate IP addres haye hame gesmat ha:
    //set main IP addres:
    main_.Set_clientIP("192.168.1.8", 8585);
    main_.Set_serverIP("192.168.1.152",8234);
    //set raspberry pi IP addres:
    thermal.Set_clientIP("192.168.1.41",2222);
    thermal.Set_serverIP("192.168.1.152",1111);
    //set uppoard Map IP addres
    map.Set_clientIP("192,168,1,91",3434);
    map.Set_serverIP("192.168.1.152",3434);
    //set hazmat IP
    Hazmat.Set_clientIP("192,168,1,30",7887);
    Hazmat.Set_serverIP("192.168.1.152",7887);


    connect(&thermal,SIGNAL(reseived_data()),this,SLOT(thermalreadyRead()),Qt::DirectConnection);
    connect(&main_,SIGNAL(reseived_data()),this,SLOT(mainreadyRead()),Qt::DirectConnection);
    connect(&map,SIGNAL(reseived_data()),this,SLOT(mapreadyRead()),Qt::DirectConnection);
    connect(this,SIGNAL(mainDataReadyForSend()),this,SLOT(MainDatasend()),Qt::DirectConnection);

}

void Deck::send_hazmat_thresh(uint8_t thr)
{
    QByteArray temp;
    temp.resize(1);
    temp[0]=thr;
    Hazmat.Send(temp);
    qDebug()<<"dastan";
}

void Deck::set_main_data(QByteArray m ,char header[])
{
    int cs=0;
    main_data_Tx.resize(35);

    main_data_Tx[0]=header[0];
    main_data_Tx[1]=header[1];
    main_data_Tx[2]=header[2];
    for(int k=0;k<35-5;k++)
    {
        main_data_Tx[k+3]=m[k];
        cs+=m[k];
    }
    main_data_Tx[33]=cs%256;
    main_data_Tx[34]='\r';
    //   main_.Send(main_data_Tx);
    emit mainDataReadyForSend();
    Hazmat.Send(main_data_Tx);
 //   send_hazmat_thresh(85);

}

float Deck::get_arms_angle(__uint8_t namber)
{
    float temp;

    if(namber<=2)
    {
        temp=((Motorfeedback[2].motor[namber].data[1]*256+Motorfeedback[2].motor[namber].data[2])/10.0);
    }
    else
    {
        temp=((Motorfeedback[3].motor[2].data[1]*256+Motorfeedback[3].motor[2].data[2])/10.0);
    }
    //qDebug()<<temp;
    return temp;
}

__uint8_t Deck::get_gas_data()
{
    return headfeedback.gas_data;
}


void Deck::thermalreadyRead()
{


    thermal_data_Rx.resize(thermal.Get_data_size());
    thermal_data_Rx = thermal.Get_data();


    if(thermal_data_Rx.size())
    {

        Mat thermal_img = Mat(120, 160, CV_8UC3);
        {
            for (int y = 0; y < 240; ++y){
                for (int x = 0; x < 80; ++x){
                    thermal_img.at<Vec3b>(Point(x+80*(y%2),y/2))[2] = thermal_data_Rx[(x + (y)*80)*3];
                    thermal_img.at<Vec3b>(Point(x+80*(y%2),y/2))[1] = thermal_data_Rx[(x + (y)*80)*3 + 1];
                    thermal_img.at<Vec3b>(Point(x+80*(y%2),y/2))[0] = thermal_data_Rx[(x + (y)*80)*3 + 2];
                }
            }
        }
        emit thermalImIsReady(thermal_img);
        //        imshow("dastan",thermal_img);
    }
}

void Deck::mapreadyRead()
{
    map_data_Rx.resize(map.Get_data_size());
    map_data_Rx=map.Get_data();
    std::vector<uchar> bufferToCompress(map_data_Rx.begin(), map_data_Rx.end());
    Map_image=imdecode(bufferToCompress,CV_LOAD_IMAGE_COLOR); //be un var begu color befreste
    //    Map_image.resize(bufferToCompress.size());
    //    for(int i=0;i<bufferToCompress.size();i++)
    //    {
    //        Map_image.at<uchar>(i)=bufferToCompress.at(i);
    //    }

    emit MapImageIsReady(Map_image);
    //imshow("map",Map_image);
    //waitKey(10);

    map_data_Rx.clear();
}


void Deck::mainreadyRead()
{

    if(main_.Get_data_size()==main_RX_packet_size)
    {
        main_data_Rx.resize(main_.Get_data_size());
        main_data_Rx.clear();
        main_data_Rx= main_.Get_data();
        if(main_data_Rx[0]=='F')
            if(main_data_Rx[1]=='D')
                if(main_data_Rx[2]=='B')
                    if(main_data_Rx[main_RX_packet_size-1]=='\r')
                    {   int temp=3;
                        for(int s=0;s<4;s++)
                        {
                            for(int k=0;k<3;k++)
                            {
                                for(int w=0;w<4;w++)
                                {
                                    Motorfeedback[s].motor[k].data[w]=(__uint8_t)main_data_Rx[temp++];

                                }
                            }
                        }
//                        cout<<temp<<"="<<(uint8_t)Motorfeedback[s].motor[k].data[w]<<"*";
//                        cout<<'\r'<<endl;

                        headfeedback.gas_data=(uint8_t)main_data_Rx[temp++];
                        emit mainDataIsReady();
                    }

    }

    //   main_res_flg=true;
}

void Deck::MainDatasend()
{
    main_.Send(main_data_Tx);
}
