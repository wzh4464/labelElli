#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

using cv::Mat;
using namespace cv;

using tracker = void (*)(int, void*);

class Labeler
{
private:
    const char * window = "Labeler";
    const char* trackx = "x";
    const char* tracky = "y";
    const char* tracka = "a";
    const char* trackb = "b";
    const char* trackth = "th";
    int phi; // phi = th + 180, to make th can be minus
public:
    int x,y,a,b,th; // a,b are semi ones
    
    Labeler(/* args */);
    ~Labeler();
    Labeler(Mat src);
    Mat src;
    static void onChangeTrackBar (int,void* ptr);
    void label();
    void save();

};

