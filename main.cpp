/**
 * @Author: WU Zihan
 * @Date:   2022-04-21 13:09:10
 * @Last Modified by:   WU Zihan
 * @Last Modified time: 2022-05-01 02:21:58
 */
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include "Labeler.hpp"
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    cout << "Built with OpenCV " << CV_VERSION << endl;
#if defined(_WIN64)
    CommandLineParser parser(argc, argv, "{@input | ../../cookie.jpg | input image}");
#else
    CommandLineParser parser(argc, argv, "{@input | ../cookie.jpg | input image}");
#endif
    string filename;
    filename = parser.get<String>("@input");
    Mat src = imread(samples::findFile(parser.get<String>("@input")), IMREAD_COLOR);
    Labeler labeler(src);
    labeler.label();
    return 0;
}
