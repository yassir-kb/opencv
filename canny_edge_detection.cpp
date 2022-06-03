#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <QString>
#include "canny_edge_detection.h"

using namespace cv;
Mat src4, src_gray;
Mat dst, detected_edges;
int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char *window_name = "Edge Map";

static void CannyThresholdProcess(int, void *) {
    blur(src_gray, detected_edges, Size(3, 3));
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);
    dst = Scalar::all(0);
    src4.copyTo(dst, detected_edges);
    imshow(window_name, dst);
}


void CannyThreshold(QString path) {

    src4 = imread(samples::findFile(path.toStdString(), IMREAD_COLOR));
    if (src4.empty()) {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << src4 << " <Input image>" << std::endl;
    }
    dst.create(src4.size(), src4.type());
    cvtColor(src4, src_gray, COLOR_BGR2GRAY);
    namedWindow(window_name, WINDOW_AUTOSIZE);
    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThresholdProcess);
    CannyThresholdProcess(0, 0);
    waitKey(0);

    destroyAllWindows();
}