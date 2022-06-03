#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <QString>
#include "lighten_darken.h"

using std::cin;
using std::cout;
using std::endl;
using namespace cv;

Mat image;
Mat new_image;
int alpha;
int beta;
int const max_element = 3;
int const max_kernel_size = 100;

void LightenDarken(QString path) {
    image = imread(samples::findFile(path.toStdString(), IMREAD_COLOR));
    if (image.empty()) {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << image << " <Input image>" << endl;
    }
    new_image = Mat::zeros(image.size(), image.type());
    namedWindow("Lighten Darken Demo", WINDOW_AUTOSIZE);
    moveWindow("Lighten Darken Demo", new_image.cols, 0);
    createTrackbar("Light or Dark :", "Lighten Darken Demo",
                   &alpha, max_element, LightenDarkenProcess);
    createTrackbar("Lightness degree :", "Lighten Darken Demo",
                   &beta, max_kernel_size, LightenDarkenProcess);
    LightenDarkenProcess(1.0, 0);
    waitKey(0);
}

void LightenDarkenProcess(int, void *) {

    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < image.channels(); c++) {
                new_image.at<Vec3b>(y, x)[c] =
                        saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
            }
        }
    }
    imshow("Lighten Darken Demo", new_image);
    waitKey();

    destroyAllWindows();
}