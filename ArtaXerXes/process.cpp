#include "process.h"




// various tracking parameters (in seconds)
const double MHI_DURATION = 1;
const double MAX_TIME_DELTA = 0.5;
const double MIN_TIME_DELTA = 0.05;
// number of cyclic frame buffer used for motion detection
// (should, probably, depend on FPS)
const int N = 4;


// ring image buffer
vector<Mat> buf(N);
int last=0;

Mat mhi; // MHI



int  update_mhi( const Mat im, Mat& dst, int diff_threshold )
{
    int number=0;
    Mat img;
//    im.copyTo(img);

    blur(im,img,cv::Size( 3, 3 ));

    resize(img,img,cv::Size(300,300));
    double timestamp = (double)clock()/CLOCKS_PER_SEC; // get current time in seconds
    int idx1 = last, idx2;
    Mat silh, orient, mask, segmask;

    cvtColor( img, buf[last], CV_BGR2GRAY ); // convert frame to grayscale

    idx2 = (last + 1) % N; // index of (last - (N-1))th frame
    last = idx2;

    if( buf[idx1].size() != buf[idx2].size() )
        silh = Mat::ones(img.size(), CV_8U)*255;
    else
        absdiff(buf[idx1], buf[idx2], silh); // get difference between frames

    threshold( silh, silh, diff_threshold, 1, CV_THRESH_BINARY ); // and threshold it
    if( mhi.empty() )
        mhi = Mat::zeros(silh.size(), CV_32F);
    updateMotionHistory( silh, mhi, timestamp, MHI_DURATION ); // update MHI

    // convert MHI to blue 8u image
    mhi.convertTo(mask, CV_8U, 255./MHI_DURATION,
                (MHI_DURATION - timestamp)*255./MHI_DURATION);
    dst = Mat::zeros(mask.size(), CV_8UC3);
    insertChannel(mask, dst, 0);

    // calculate motion gradient orientation and valid orientation mask
    calcMotionGradient( mhi, mask, orient, MAX_TIME_DELTA, MIN_TIME_DELTA, 3 );

    // segment motion: get sequence of motion components
    // segmask is marked motion components map. It is not used further
    vector<Rect> brects;
    segmentMotion(mhi, segmask, brects, timestamp, MAX_TIME_DELTA );

    // iterate through the motion components,
    // One more iteration (i == -1) corresponds to the whole image (global motion)
    for( int i = -1; i < (int)brects.size(); i++ ) {
        Rect roi; Scalar color; double magnitude;
        Mat maski = mask;
        if( i < 0 ) { // case of the whole image
            roi = Rect(0, 0, img.cols, img.rows);
            color = Scalar::all(255);
            magnitude = 100;
        }
        else { // i-th motion component
            roi = brects[i];
            if( roi.area() < 200 )
            {
                // reject very smal..............l components
                continue;
            }
            number++;

            color = Scalar(0, 255, 255);
            magnitude = 30;
            maski = mask(roi);
        }

        // calculate orientation
        double angle = calcGlobalOrientation( orient(roi), maski, mhi(roi), timestamp, MHI_DURATION);
        angle = 360.0 - angle;  // adjust for images with top-left origin

        int count = norm( silh, NORM_L1 ); // calculate number of points within silhouette ROI
        // check for the case of little motion
        if( count < roi.area() * 0.05 )
            continue;

        // draw a clock with arrow indicating the direction
        Point center( roi.x + roi.width/2, roi.y + roi.height/2 );
        rectangle( img, roi,  color, 3, CV_AA, 0 );
        line( img, center, Point( cvRound( center.x + magnitude*cos(angle*CV_PI/180)),
                cvRound( center.y - magnitude*sin(angle*CV_PI/180))), color, 3, CV_AA, 0 );
    }

    img.copyTo(dst);
    return number;
}






Process::Process(QObject *parent) : QObject(parent)
{

    connect(this,SIGNAL(HazmatDetected(Mat,int,int,int,int)),this,SLOT(prossesTaki(Mat,int,int,int,int)));
    connect(this,SIGNAL(HazmatStart()),this,SLOT(prosses()));

    connect(this,SIGNAL(motionStart()),this,SLOT(motion()));
    connect(this,SIGNAL(QRStart()),this,SLOT(QR_scan()));
    temp=1;

}



#define accuracy 0.3

int color_detector(Mat a)


{

    Mat m;
    a.copyTo(m);
    int result = 5;
    cvtColor(m, m, CV_RGB2HSV);
    Mat hsv,temp;
    Mat erode_element = getStructuringElement(MORPH_RECT, Size(2,2), Point(-1, -1));
    Mat dilate_element = getStructuringElement(MORPH_RECT, Size(2,2), Point(-1, -1));
    for(int i = 0; i < 5; i++)
    {
        //0 = red; 1 = orange; 2 = yellow; 3 = blue; 4 = green; 5 = other;
        switch (i)
        {
            case 0:
                inRange(m, cv::Scalar(110, 60, 0), cv::Scalar(150, 255, 255), hsv);
//                temp.copyTo(hsv);
//                inRange(m, cv::Scalar(0, 0, 0), cv::Scalar(20, 255, 255), temp);
//                hsv=hsv+temp;

                break;
            case 1:
                inRange(m, cv::Scalar(95, 50, 50), cv::Scalar(110, 255, 255), hsv);
                break;
            case 2:
                inRange(m, cv::Scalar(85, 20, 20), cv::Scalar(100, 255, 255), hsv);
                break;
            case 3:
                inRange(m, cv::Scalar(0, 50, 0), cv::Scalar(30, 255, 255), hsv);
                break;
            case 4:
                inRange(m, cv::Scalar(25, 50, 10), cv::Scalar(75, 255, 255), hsv);
                break;
        }
        cv::erode(hsv, hsv,erode_element, cv::Size(-1,-1), 5);
        cv::dilate(hsv, hsv,dilate_element, cv::Size(-1,-1), 3);
        if(countNonZero(hsv) > accuracy*(hsv.rows*hsv.cols))
        {
//            qDebug() << i;
            result = i;
            goto finish;
        }
    }
finish: return result;
}




int Process::detect(Mat img_1,Mat img_2){
    ///-- Step 1: Detect the keypoints using SURF Detector
    ///
    ///
    ///
    ///
    ///

    int color1=color_detector(img_1);
    int color2=color_detector(img_2);


//    if(color1==color2 )


    {



//        if(color1==0)
//            return 10000;
//        else if(color1==1)
//            return 999;
//        else if(color1==2)
//            return 998;
//        else if(color1==3)
//            return 997;
//        else if(color1==4)
//            return 996;
//        else if(color1==5)
//            return 995;
//        else if(color1==7)
//            return 994;







//        qDebug()<<color_detector(img_1);
         resize(img_1,img_1,Size(50,50));
          resize(img_2,img_2,Size(50,50));

//    SurfFeatureDetector detector;
//    SiftFeatureDetector detector;
//    OrbFeatureDetector detector;



    FastFeatureDetector detector;

    std::vector<KeyPoint> keypoints_1, keypoints_2;

    detector.detect( img_1, keypoints_1 );
    detector.detect( img_2, keypoints_2 );

    ///-- Step 2: Calculate descriptors (feature vectors)
//    SurfDescriptorExtractor extractor;
    SiftDescriptorExtractor extractor;  // Excellent Descriptor

    Mat descriptors_1, descriptors_2;

    extractor.compute( img_1, keypoints_1, descriptors_1 );
    extractor.compute( img_2, keypoints_2, descriptors_2 );

    ///-- Step 3: Matching descriptor vectors using FLANN matcher
    FlannBasedMatcher matcher;
//    BFMatcher matcher;       //  Brute Force Matcher

    std::vector< DMatch > matches;
    matcher.match( descriptors_1, descriptors_2, matches );

    double max_dist = 0; double min_dist = 100;

    ///-- Quick calculation of max and min distances between keypoints
    for( int i = 0; i < descriptors_1.rows; i++ )
    { double dist = matches[i].distance;
      if( dist < min_dist ) min_dist = dist;
      if( dist > max_dist ) max_dist = dist;
    }

    //printf("-- Max dist : %f \n", max_dist );
    //printf("-- Min dist : %f \n", min_dist );

    ///-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
    ///-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
    ///-- small)
    ///-- PS.- radiusMatch can also be used here.
    std::vector< DMatch > good_matches;

    for( int i = 0; i < descriptors_1.rows; i++ )
    { if( matches[i].distance <= max(2*min_dist, 0.02) )
      { good_matches.push_back( matches[i]); }
    }

    ///-- Draw only "good" matches
    Mat img_matches;
    drawMatches( img_1, keypoints_1, img_2, keypoints_2,
                 good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
                 vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

    ///-- Show detected matches
//    imshow( "Good Matches", img_matches );

    //qDebug() << "Num of good matches: " << good_matches.size();
    return good_matches.size();
    }
    return 0;

}


int Process::filter_color(Mat m, int code)
{
    //code: 0 = red, 1 = orange, 2 = yellow, 3 = green & blue
    Mat filter;
    m.copyTo(filter);
    cvtColor(filter, filter, cv::COLOR_RGB2HSV);
    switch (code) {
    case 0:

        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

string Process::hazmat_name(int a)
{
    string R;
    if(a==1)
    {
        R="FLAMMABLE SOLID";
    }
    else if(a==2)
    {
        R="ORGANIC PEROXIDE";
    }
    else if(a==3)
    {
        R="INHALATION HAZARD";
    }
    else if(a==4)
    {
        R="OXIDIZER";
    }
    else if(a==5)
    {
        R="DANGEROUS WHEN WET";
    }
    else if(a==6)
    {
        R="COMBUSTABLE";
    }
    else if(a==7)
    {
        R="FLAMMABLE LIQUID";
    }
    else if(a==8)
    {
        R="CORROSIVE";
    }
    else if(a==9)
    {
        R="EXPLOSIVE";
    }
    else if(a==10)
    {
        R="RADIOACTIVE";
    }
    else if(a==11)
    {

        R="INFECTIOUS SUBSTANCE";

    }
    else if(a==12)
    {
        R="NON-FLAMMABLE GAS";
    }

    return R;

}

void Process::prosses()
{
    Mat input,gray;

    cv::Mat rotated;
    cv::Mat mask;
    cv::Mat gray_d;

    cv::Mat erode_element = getStructuringElement(MORPH_RECT, Size(2,2), Point(-1, -1));
    cv::Mat dilate_element = getStructuringElement(MORPH_RECT, Size(2,2), Point(-1, -1));
    int detect_[4]={0,0,0,0};

 Hazmat.copyTo(input);
#if 1
 if(!Hazmat.empty()&& hazmat_mode==Quad_hazmat_)
{
    cv::cvtColor(input,gray, CV_BGR2GRAY);

    cv::GaussianBlur(gray,gray,cv::Size(5,5),5,5);
    cv::adaptiveThreshold(gray,gray,200,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY_INV, 11, hazmatthrsh /*this paramet need to calibr*/);

    cv::dilate(gray, gray,dilate_element, cv::Size(1, 1),4);
    cv::erode(gray, gray,erode_element, cv::Size(1, 1),2);
    cv::GaussianBlur(gray,gray,cv::Size(3,3),5,0);
    cv::blur(gray,gray,cv::Size(3,2));
    cv::threshold(gray, mask, 85, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(mask,contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);


    int biggestContourIdx = -1;
    float biggestContourArea = 0;
    cv::Mat drawing = cv::Mat::zeros( mask.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {


        float ctArea= cv::contourArea(contours[i]);
        if(ctArea > biggestContourArea)
        {
            biggestContourArea=ctArea;
            biggestContourIdx=i;
        }
    }






    for( int i = 0; i< contours.size(); i++ )
    {


        float ctArea= cv::contourArea(contours[i]);
        if(ctArea > biggestContourArea/10)
        {
            cv::Scalar color = cv::Scalar(0, 100, 0);
            drawContours( drawing, contours, i, color, -1, 8, hierarchy, 0, cv::Point(30,25) );
        }
    }

    cv::Mat dilate_element1 = getStructuringElement(MORPH_RECT, Size(5,5), Point(1, 1));
    cv::Mat erode_element1 = getStructuringElement(MORPH_RECT, Size(3,3), Point(0, 0));
    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 5);
    cv::erode(drawing, drawing,erode_element1, cv::Size(1, 1), 20);
    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 3);
    cv::erode(drawing, drawing,erode_element1, cv::Size(1, 1), 20);
    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 1);
    cv::erode(drawing, drawing,erode_element1, cv::Size(1, 1), 8);
    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 15);



    // one thing to remark: this will compute the OUTER boundary box, so maybe you have to erode/dilate if you want something between the ragged lines


    cvtColor(drawing,gray_d,COLOR_BGR2GRAY);
    cv::findContours(gray_d,contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);



    bool angle_falag = true;

    for( int ii = 0; ii< contours.size(); ii++ )
    {


    float ctArea= cv::contourArea(contours[ii]);

    if(ctArea > biggestContourArea/2)
    {

        cv::RotatedRect boundingBox = cv::minAreaRect(contours[ii]);
        cv::Point2f corners[4];
        cv::Point2f hazmat_corners[4][4];

        cv::Point2f cornersR[4];
        cv::Point2f hazmat_cornersR[4][4];

        cv::Mat rot_mat;

        boundingBox.points(corners);
    //        qDebug()<<boundingBox.angle;


        if(boundingBox.angle>-45)
        {
            rot_mat = cv::getRotationMatrix2D(boundingBox.center,boundingBox.angle, 1);
            angle_falag = false;
        }
        else
        {
            rot_mat = cv::getRotationMatrix2D(boundingBox.center,boundingBox.angle+90, 1);
            angle_falag= true;
        }


    cv::warpAffine(input, rotated, rot_mat, input.size(), cv::INTER_CUBIC);
                    for(int s=0 ; s<4 ;s++)
//                    if(name_mach>0 && s==1)
                    {

                        hazmat_corners[s][0]=corners[s];
                        hazmat_corners[s][1].x=(corners[s].x+corners[(s+1)%4].x)/2;
                        hazmat_corners[s][1].y=(corners[s].y+corners[(s+1)%4].y)/2;

                        hazmat_corners[s][2].x=(corners[s].x+corners[(s+2)%4].x)/2;
                        hazmat_corners[s][2].y= (corners[s].y+corners[(s+2)%4].y)/2;

                        hazmat_corners[s][3].x=(corners[s].x+corners[(s+3)%4].x)/2;
                        hazmat_corners[s][3].y=(corners[s].y+corners[(s+3)%4].y)/2;
}




    if(angle_falag)
        boundingBox.angle=90;
    else
        boundingBox.angle=0;


    boundingBox.points(cornersR);

    Rect box[4];
    Mat output;

    for(int s=0 ; s<4 ;s++)
    {

        hazmat_cornersR[s][0]=cornersR[s];
        hazmat_cornersR[s][1].x=(cornersR[s].x+cornersR[(s+1)%4].x)/2;
        hazmat_cornersR[s][1].y=(cornersR[s].y+cornersR[(s+1)%4].y)/2;

        hazmat_cornersR[s][2].x=(cornersR[s].x+cornersR[(s+2)%4].x)/2;
        hazmat_cornersR[s][2].y= (cornersR[s].y+cornersR[(s+2)%4].y)/2;

        hazmat_cornersR[s][3].x=(cornersR[s].x+cornersR[(s+3)%4].x)/2;
        hazmat_cornersR[s][3].y=(cornersR[s].y+cornersR[(s+3)%4].y)/2;





        if (angle_falag)
        {
            box[s]= Rect(hazmat_cornersR[s][0], hazmat_cornersR[s][2]);
        }
        else
        {
            box[(s+3)%4]= Rect(hazmat_cornersR[s][0], hazmat_cornersR[s][2]);

        }

        for(int k=0;k<4;k++)
            cv::line(rotated, hazmat_cornersR[s][k], hazmat_cornersR[s][(k+1)%4], cv::Scalar(0,255,0),3);

   }


//    imshow("rot_mat",rotated);
    for(int s=0 ; s<4 ;s++)
    {
        string name = QString :: number(s).toLatin1().data();
        if (0 <= box[s].x
            && 0 <= box[s].width
            && box[s].x + box[s].width <= input.cols
            && 0 <= box[s].y
            && 0 <= box[s].height
            && box[s].y + box[s].height <= input.rows)
        {

            output=rotated(box[s]);

            resize(output,output,Size(50,50));
//            rot_mat = cv::getRotationMatrix2D(Point(100,100),s*90, 1);
//            cv::warpAffine(output, output, rot_mat, output.size(), cv::INTER_CUBIC);

           // if(s==0)
                {
//                ax(output);
                int max_mach=0,dd;
                int name_mach=0;
                for(int l=0;l<3;l++)
                {
                    rot_mat = cv::getRotationMatrix2D(Point(25,25),l*90, 1);
                    cv::warpAffine(output, output, rot_mat, output.size(), cv::INTER_CUBIC);


                for(int i=0 ;i<12;i++)
                {

                    if(i!=1 && i!=9)
                    {


                    char ff[255];
                    if (i < 10)
                        sprintf(ff,"/home/sina/Desktop/data_set/%d0%d.pbm",0,i);
                    else
                        sprintf(ff,"/home/sina/Desktop/data_set/%d%d.pbm",0,i);

                    Mat temp =imread(ff);

                   dd= detect(output,temp);
                    if(dd>max_mach)
                    {
                        max_mach=dd;
                        name_mach=i+1;
                    }

                }
}
                }
//                    char aa[20];
//                    sprintf(aa,"hazmate %d",name_mach);
               // qDebug()<<"Hazmat"<< s << "=" <<name_mach;

                if(name_mach==5 || name_mach==7)
                {
                    int dastan;
                    dastan=color_detector(output);
                            if(dastan==0)
                               name_mach=7;
                           else if(dastan==3)
                               name_mach=5;
                            else
                                name_mach=0;
                }

                if(!angle_falag)

                for(int k=0;k<4;k++)
                    cv::line(input, hazmat_corners[(s+1)%4][k], hazmat_corners[(s+1)%4][(k+1)%4], cv::Scalar(255,0,0),3);
                else
                    for(int k=0;k<4;k++)
                    cv::line(input, hazmat_corners[(s+2)%4][k], hazmat_corners[(s+2)%4][(k+1)%4], cv::Scalar(255,0,0),3);


//                for(int s=0 ; s<4 ;s++)
                if(name_mach>0 )
                {

//                    hazmat_corners[s][0]=corners[s];
//                    hazmat_corners[s][1].x=(corners[s].x+corners[(s+1)%4].x)/2;
//                    hazmat_corners[s][1].y=(corners[s].y+corners[(s+1)%4].y)/2;

//                    hazmat_corners[s][2].x=(corners[s].x+corners[(s+2)%4].x)/2;
//                    hazmat_corners[s][2].y= (corners[s].y+corners[(s+2)%4].y)/2;

//                    hazmat_corners[s][3].x=(corners[s].x+corners[(s+3)%4].x)/2;
//                    hazmat_corners[s][3].y=(corners[s].y+corners[(s+3)%4].y)/2;






                    if(!angle_falag)

                    for(int k=0;k<4;k++)
                        cv::line(input, hazmat_corners[(s+1)%4][k], hazmat_corners[(s+1)%4][(k+1)%4], cv::Scalar(0,255,0),3);
                    else
                        for(int k=0;k<4;k++)
                        cv::line(input, hazmat_corners[(s+2)%4][k], hazmat_corners[(s+2)%4][(k+1)%4], cv::Scalar(0,255,0),3);



                putText(input, hazmat_name(name_mach), cvPoint(box[s].x,box[s].y+30), FONT_HERSHEY_COMPLEX_SMALL, 0.7, cvScalar(0,255,8), 1, CV_AA);
//                       imshow(name,output);
                    detect_[s]=name_mach;
                }

                    }
                }
            }

        }
    }

}



#endif
 if(!input.empty())

 emit HazmatDetected(input,detect_[0],detect_[1],detect_[2],detect_[3]);

}

void Process::prossesTaki(Mat a, int x, int b, int c, int d)
{
    Mat input,gray;

    cv::Mat rotated;
    cv::Mat mask;
    cv::Mat gray_d;

    cv::Mat erode_element = getStructuringElement(MORPH_RECT, Size(2,2), Point(-1, -1));
    cv::Mat dilate_element = getStructuringElement(MORPH_RECT, Size(2,2), Point(-1, -1));
    int detect_[4]={0,0,0,0};

 a.copyTo(input);
#if 1

 if(!Hazmat.empty()&& hazmat_mode==Single_hazmat_)

{
    cv::cvtColor(input,gray, CV_BGR2GRAY);

    cv::GaussianBlur(gray,gray,cv::Size(5,5),5,5);
    cv::adaptiveThreshold(gray,gray,200,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY_INV, 11, hazmatthrsh /*this paramet need to calibr*/);

    cv::dilate(gray, gray,dilate_element, cv::Size(1, 1),4);
    cv::erode(gray, gray,erode_element, cv::Size(1, 1),2);
    cv::GaussianBlur(gray,gray,cv::Size(3,3),5,0);
    cv::blur(gray,gray,cv::Size(3,2));
    cv::threshold(gray, mask, 85, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(mask,contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);


    int biggestContourIdx = -1;
    float biggestContourArea = 0;
    cv::Mat drawing = cv::Mat::zeros( mask.size(), CV_8UC3 );
    for( int i = 0; i< contours.size(); i++ )
    {


        float ctArea= cv::contourArea(contours[i]);
        if(ctArea > biggestContourArea)
        {
            biggestContourArea=ctArea;
            biggestContourIdx=i;
        }
    }






    for( int i = 0; i< contours.size(); i++ )
    {


        float ctArea= cv::contourArea(contours[i]);
        if(ctArea > biggestContourArea/10)
        {
            cv::Scalar color = cv::Scalar(0, 100, 0);
            drawContours( drawing, contours, i, color, -1, 8, hierarchy, 0, cv::Point(30,25) );
        }
    }

//    cv::Mat dilate_element1 = getStructuringElement(MORPH_RECT, Size(5,5), Point(1, 1));
//    cv::Mat erode_element1 = getStructuringElement(MORPH_RECT, Size(3,3), Point(0, 0));
//    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 5);
//    cv::erode(drawing, drawing,erode_element1, cv::Size(1, 1), 20);
//    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 3);
//    cv::erode(drawing, drawing,erode_element1, cv::Size(1, 1), 20);
//    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 1);
//    cv::erode(drawing, drawing,erode_element1, cv::Size(1, 1), 8);
//    cv::dilate(drawing, drawing,dilate_element1, cv::Size(1, 1), 15);



    // one thing to remark: this will compute the OUTER boundary box, so maybe you have to erode/dilate if you want something between the ragged lines


    cvtColor(drawing,gray_d,COLOR_BGR2GRAY);
    cv::findContours(gray_d,contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);



    bool angle_falag = true;

    for( int ii = 0; ii< contours.size(); ii++ )
    {


    float ctArea= cv::contourArea(contours[ii]);

    if(ctArea > biggestContourArea/2)
    {

        cv::RotatedRect boundingBox = cv::minAreaRect(contours[ii]);
        cv::Point2f corners[4];
        cv::Point2f hazmat_corners[4][4];

        cv::Point2f cornersR[4];
        cv::Point2f hazmat_cornersR[4][4];

        cv::Mat rot_mat;

        boundingBox.points(corners);
    //        qDebug()<<boundingBox.angle;


        if(boundingBox.angle>-45)
        {
            rot_mat = cv::getRotationMatrix2D(boundingBox.center,boundingBox.angle, 1);
            angle_falag = false;
        }
        else
        {
            rot_mat = cv::getRotationMatrix2D(boundingBox.center,boundingBox.angle+90, 1);
            angle_falag= true;
        }


    cv::warpAffine(input, rotated, rot_mat, input.size(), cv::INTER_CUBIC);
                    for(int s=0 ; s<4 ;s++)
//                    if(name_mach>0 && s==1)
                    {

                        hazmat_corners[s][0]=corners[s];
                        hazmat_corners[s][1].x=(corners[s].x+corners[(s+1)%4].x)/2;
                        hazmat_corners[s][1].y=(corners[s].y+corners[(s+1)%4].y)/2;

                        hazmat_corners[s][2].x=(corners[s].x+corners[(s+2)%4].x)/2;
                        hazmat_corners[s][2].y= (corners[s].y+corners[(s+2)%4].y)/2;

                        hazmat_corners[s][3].x=(corners[s].x+corners[(s+3)%4].x)/2;
                        hazmat_corners[s][3].y=(corners[s].y+corners[(s+3)%4].y)/2;
}




    if(angle_falag)
        boundingBox.angle=90;
    else
        boundingBox.angle=0;


    boundingBox.points(cornersR);

    Rect box[4];
    Mat output;

    for(int s=0 ; s<4 ;s++)
    {

        hazmat_cornersR[s][0]=cornersR[s];
        hazmat_cornersR[s][1].x=(cornersR[s].x+cornersR[(s+1)%4].x)/2;
        hazmat_cornersR[s][1].y=(cornersR[s].y+cornersR[(s+1)%4].y)/2;

        hazmat_cornersR[s][2].x=(cornersR[s].x+cornersR[(s+2)%4].x)/2;
        hazmat_cornersR[s][2].y= (cornersR[s].y+cornersR[(s+2)%4].y)/2;

        hazmat_cornersR[s][3].x=(cornersR[s].x+cornersR[(s+3)%4].x)/2;
        hazmat_cornersR[s][3].y=(cornersR[s].y+cornersR[(s+3)%4].y)/2;





        if (angle_falag)
        {
            box[s]= Rect(cornersR[0], cornersR[2]);
        }
        else
        {
            box[(s+3)%4]= Rect(cornersR[0], cornersR[2]);

        }

        for(int k=0;k<4;k++)
            cv::line(rotated, cornersR[k], cornersR[(k+1)%4], cv::Scalar(0,255,0),3);
   }


//    imshow("rot_mat",rotated);
    for(int s=0 ; s<4 ;s++)
    {
        string name = QString :: number(s).toLatin1().data();
        if (0 <= box[0].x
            && 0 <= box[0].width
            && box[0].x + box[0].width <= input.cols
            && 0 <= box[0].y
            && 0 <= box[0].height
            && box[0].y + box[0].height <= input.rows)
        {

            output=rotated(box[0]);

            resize(output,output,Size(200,200));
            rot_mat = cv::getRotationMatrix2D(Point(100,100),s*90, 1);
            cv::warpAffine(output, output, rot_mat, output.size(), cv::INTER_CUBIC);

           // if(s==0)
                {
//                ax(output);
                int max_mach=0,dd;
                int name_mach=0;
                for(int i=0 ;i<12;i++)
                {

                    char ff[255];
                    if (i < 10)
                        sprintf(ff,"/home/sina/Desktop/data_set/%d0%d.pbm",0,i);
                    else
                        sprintf(ff,"/home/sina/Desktop/data_set/%d%d.pbm",0,i);

                    Mat temp =imread(ff);

                   dd= detect(output,temp);
                    if(dd>max_mach)
                    {
                        max_mach=dd;
                        name_mach=i+1;
                    }

                }

//                    char aa[20];
//                    sprintf(aa,"hazmate %d",name_mach);
               // qDebug()<<"Hazmat"<< s << "=" <<name_mach;



//                for(int s=0 ; s<4 ;s++)
                if(name_mach>0 )
                {

//                    hazmat_corners[s][0]=corners[s];
//                    hazmat_corners[s][1].x=(corners[s].x+corners[(s+1)%4].x)/2;
//                    hazmat_corners[s][1].y=(corners[s].y+corners[(s+1)%4].y)/2;

//                    hazmat_corners[s][2].x=(corners[s].x+corners[(s+2)%4].x)/2;
//                    hazmat_corners[s][2].y= (corners[s].y+corners[(s+2)%4].y)/2;

//                    hazmat_corners[s][3].x=(corners[s].x+corners[(s+3)%4].x)/2;
//                    hazmat_corners[s][3].y=(corners[s].y+corners[(s+3)%4].y)/2;

                    if(!angle_falag)

                    for(int k=0;k<4;k++)
                        cv::line(input, corners[k], corners[(k+1)%4], cv::Scalar(0,255,0),3);
                    else
                        for(int k=0;k<4;k++)
                        cv::line(input, corners[k], corners[(k+1)%4], cv::Scalar(0,255,0),3);



                putText(input, hazmat_name(name_mach), cvPoint(box[s].x,box[s].y+30), FONT_HERSHEY_COMPLEX_SMALL, 0.7, cvScalar(0,25,85), 1, CV_AA);
//                       imshow(name,output);
                    detect_[s]=name_mach;
                }

                    }
                }
            }

        }
    }

}
#endif

 if(!input.empty())
 emit HazmattakiDetected(input,x,b,c,d,detect_[0]+detect_[1]+detect_[2]+detect_[3]);

}

void Process::QR_scan()
{
    Mat grey;
    QString S;



    if(!QR_buff.empty())

    {
        QR_buff.copyTo(QR);
    cvtColor(QR,grey,CV_BGR2GRAY);


    Image image(grey.cols, grey.rows, "Y800", grey.data, grey.cols * grey.rows);

    int n = scanner.scan(image);

    for(Image::SymbolIterator symbol = image.symbol_begin();
    symbol != image.symbol_end();
    ++symbol) {
        vector<Point> vp;


        S = QString::fromStdString(symbol->get_data());
    int n = symbol->get_location_size();
      for(int i=0;i<n;i++){
        vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
      }
      RotatedRect r = minAreaRect(vp);
      Point2f pts[4];
      r.points(pts);
      for(int i=0;i<4;i++){
        line(QR,pts[i],pts[(i+1)%4],Scalar(255,0,0),3);
      }


    }



    }

    putText(QR, S.toStdString(), Point(20,60), FONT_HERSHEY_COMPLEX_SMALL, 2.7, cvScalar(0,85,200), 1, CV_AA);

    if(S != QrString_buff)
    {
        QrString_buff=S;

        S="";
    }
    else
    QrString_buff=S;
//    qDebug()<<QrString_buff;

     if(!QR.empty())
     {
//         imshow("Qr",QR);

    emit QRDetection(QR,S);
     }
     temp=1;

}

void Process::motion()
{

    Mat grey1,grey2,bl1,bl2,dastan,dastan2,dastan3,dastan4,dastan5,dastan6;
    Rect bounding_rect;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    Mat temp;


    int number_of_motion_=0;

if(motion1.data && motion2.data)
{
//    cvtColor(motion1,grey1,CV_BGR2GRAY);
//    cvtColor(motion2,grey2,CV_BGR2GRAY);


//        {
//             blur(grey1,bl1, cv::Size( 5, 5 ) );
//             blur(grey2,bl2, cv::Size( 5, 5 ) );
//             dastan = bl1-bl2;
//             threshold(dastan,dastan2,motionthrsh/*this parametr*/,255,CV_THRESH_BINARY);
//             blur(dastan2,dastan4, cv::Size( 50, 50 ),cv::Point(-10,-10),cv::BORDER_DEFAULT);
//             threshold(dastan4,dastan3,50,250,CV_THRESH_BINARY);
//             blur(dastan3,dastan5, cv::Size( 100, 100 ),cv::Point(-10,-10),cv::BORDER_DEFAULT);
//             threshold(dastan5,dastan6,50,255,CV_THRESH_BINARY);
//    //-----------------------------------------------------------------
//            findContours( dastan6, contours, hierarchy,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_KCOS );
//            int j;
//            for(  j = 0; j< contours.size(); j++ )
//            {

//              if(j>10)  break;
//                  //  Find the area of contour
//                  double a=contourArea(contours[j],false);
//                  if(a>0&& a<200000)
//                  {
//                      // Find the bounding rectangle for biggest contour
//                      bounding_rect=boundingRect(contours[j]);
//                      cv::rectangle( motion1, bounding_rect ,cv::Scalar(0,255,0),10,1);
//                  }
//        }


//    }




  number_of_motion_ = update_mhi( motion1, temp, motionthrsh );

}







    if(!temp.empty())
    emit motionDetection(temp, number_of_motion_);
}




void Process::QR_scan(Mat a, QString *S)
{
    a.copyTo(QR_buff);
    if(temp==1)
    {
    temp=0;
    emit QRStart();
    }
}



void Process::motion(Mat m1, Mat m2,int thrsh)
{

    motionthrsh=thrsh;
    m1.copyTo(motion1);
    m2.copyTo(motion2);
    emit motionStart();


}





void Process::prosses(Mat inmat ,int thrsh, int mode)
{
    hazmat_mode=mode;
    hazmatthrsh=thrsh;
    inmat.copyTo(Hazmat);
    emit HazmatStart();


}
