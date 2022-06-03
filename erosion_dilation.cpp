#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <QString>
#include "erosion_dilation.h"

using namespace cv;
using namespace std;


Mat src, erosion_dst, dilation_dst;
int erosion_elem = 0;
int erosion_size = 0;
int dilation_elem = 0;
int dilation_size = 0;
int const max_elem = 2;
int const max_kernel_size = 21;


void Dilation(QString path) {
    src = imread(samples::findFile(path.toStdString(), IMREAD_COLOR));

    namedWindow("Dilation Demo", WINDOW_AUTOSIZE);
    moveWindow("Dilation Demo", src.cols, 0);
    DilationProcess(0, 0);
    waitKey(0);
}

void DilationProcess(int dilation_size, void *) {
    int dilation_type = 0;
    if (dilation_elem == 0) { dilation_type = MORPH_RECT; }
    else if (dilation_elem == 1) { dilation_type = MORPH_CROSS; }
    else if (dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Dilation Demo",
                   NULL, max_elem,
                   DilationProcess);
    createTrackbar("Kernel size:\n 2n +1", "Dilation Demo",
                   NULL, max_kernel_size,
                   DilationProcess);

    Mat element = getStructuringElement(dilation_type,
                                        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
                                        Point(dilation_size, dilation_size));
    dilate(src, dilation_dst, element);
    imshow("Dilation Demo", dilation_dst);
    waitKey();

    destroyAllWindows();
}

void Erosion(QString path) {
    src = imread(samples::findFile(path.toStdString(), IMREAD_COLOR));

    namedWindow("Erosion Demo", WINDOW_AUTOSIZE);
    moveWindow("Erosion Demo", src.cols, 0);
    ErosionProcess(0, 0);
    waitKey(0);
}

void ErosionProcess(int erosion_size, void *) {
    int erosion_type = 0;
    if (erosion_elem == 0) { erosion_type = MORPH_RECT; }
    else if (erosion_elem == 1) { erosion_type = MORPH_CROSS; }
    else if (erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }

    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", "Erosion Demo",
                   NULL, max_elem,
                   ErosionProcess);
    createTrackbar("Kernel size:\n 2n +1", "Erosion Demo",
                   NULL, max_kernel_size,
                   ErosionProcess);

    Mat element = getStructuringElement(erosion_type,
                                        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                                        Point(erosion_size, erosion_size));
    erode(src, erosion_dst, element);
    imshow("Erosion Demo", erosion_dst);
    waitKey();

    destroyAllWindows();
}
