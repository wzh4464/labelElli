/**
 * @Author: WU Zihan
 * @Date:   2022-04-21 13:16:10
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-04-21 15:14:12
 */
#include "Labeler.hpp"



Labeler::Labeler(/* args */)
{
}

Labeler::Labeler(Mat input)
{
    src = input.clone();
    x = src.cols / 2;
    y = src.rows / 2;
    a = x / 3;
    b = y / 4;
    th = 0;
    phi = 180;
}

Labeler::~Labeler()
{
}

void Labeler::label()
{
    char key;
    auto p = &onChangeTrackBar; // which must be a static one
    namedWindow( window, WINDOW_AUTOSIZE );
    createTrackbar (trackx,window,&x,src.cols,p,this);
    createTrackbar (tracky,window,&y,src.rows,p,this);
    createTrackbar (tracka,window,&a,src.cols,p,this);
    createTrackbar (trackb,window,&b,src.rows,p,this);
    createTrackbar (trackth,window,&phi,360,p,this);
    onChangeTrackBar(0,this); // pointer "this" is to make onchange can use members from the class
    while ((key = cv::waitKey(0)) != 'q')
    {
        if(key == 's')
        {
            save();
        }
    }
    return;
}

void Labeler::save()
{
    std::cout << x << '\t' << y << '\t' << a << '\t' << b << '\t' << th << std::endl;
}

void Labeler::onChangeTrackBar (int,void* ptr)
{
    Labeler *that = (Labeler*) ptr;
    Mat dist;
    dist = that->src.clone();
    that->th = that->phi - 180;
    ellipse(dist,Point(that->x,that->y),Size(that->a,that->b),that->th,0,360,Scalar(0,255,255),1,LINE_AA);
    imshow(that->window, dist);
}