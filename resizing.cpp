#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "resizing.h"
#include "QString"

using namespace std;
using namespace cv;

Mat src2;
int down_width = 300;
int down_height = 200;
Mat resized_down;
int up_width = 600;
int up_height = 400;
Mat resized_up;

void ResizingProcess() {
    //resize down
    resize(src2, resized_down, Size(down_width, down_height), INTER_LINEAR);
    //resize up
    resize(src2, resized_up, Size(up_width, up_height), INTER_LINEAR);

    imshow("Resized Down by defining height and width", resized_down);
    waitKey();
    imshow("Resized Up image by defining height and width", resized_up);
    waitKey();

    destroyAllWindows();
};


void Resizing(QString path) {
    src2 = imread(samples::findFile(path.toStdString(), IMREAD_COLOR));
    namedWindow("Resizing Demo", WINDOW_AUTOSIZE);
    moveWindow("Resizing Demo", src2.cols, 0);
    ResizingProcess();
    waitKey(0);
}
