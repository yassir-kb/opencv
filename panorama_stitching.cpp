#include "opencv2/imgcodecs.hpp"
#include "opencv2/stitching.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <QStringList>
#include "panorama_stitching.h"

using namespace std;
using namespace cv;


bool divide_images = false;
Stitcher::Mode mode = Stitcher::PANORAMA;
vector<Mat> firstimgs;
vector<Mat> imgs;
Mat pano;

void PanoramaStitching(QStringList path) {
    for (int i = 0; i < path.length(); i++) {
        firstimgs.push_back(imread(samples::findFile(path[i].toStdString(), IMREAD_COLOR)));
    }
    namedWindow("Panorama Stitching Demo", WINDOW_AUTOSIZE);
    moveWindow("Panorama Stitching Demo", pano.cols, 0);
    PanoramaStitchingProcess();
    waitKey(0);
}


void PanoramaStitchingProcess() {
    for (int i = 0; i < firstimgs.size(); i++) {
        if (divide_images) {
            Rect rect(0, 0, firstimgs[i].cols / 2, firstimgs[i].rows);
            imgs.push_back(firstimgs[i](rect).clone());
            rect.x = firstimgs[i].cols / 3;
            imgs.push_back(firstimgs[i](rect).clone());
            rect.x = firstimgs[i].cols / 2;
            imgs.push_back(firstimgs[i](rect).clone());
        } else {
            imgs.push_back(firstimgs[i]);
        }
    }
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(imgs, pano);
    if (status != Stitcher::OK) {
        cout << "Can't stitch images, error code = " << int(status) << endl;
    }
    imshow("Resized Up image by defining height and width", pano);
    waitKey();

    destroyAllWindows();
}