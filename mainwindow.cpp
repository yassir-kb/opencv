#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "erosion_dilation.h"
#include "resizing.h"
#include "panorama_stitching.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <iostream>

QStringList fileNames;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Create dynamic objects to handle all interface components.
// For each object a pointer is created for handling, with the same identifier as
// was used in the graphical interface designer.

//-------------We will relate the interaction with the buutons with funtions------------

    connect(ui->buttonDilatation, SIGNAL(released()), this, SLOT(buttonDilatationClick()));
    connect(ui->buttonErosion, SIGNAL(released()), this, SLOT(buttonErosionClick()));
    connect(ui->buttonResizing, SIGNAL(released()), this, SLOT(buttonResizingClick()));
    connect(ui->buttonLightenDarken, SIGNAL(released()), this, SLOT(buttonLightenDarkenClick()));
    connect(ui->buttonPaSti, SIGNAL(released()), this, SLOT(buttonPaStiClick()));
    connect(ui->buttonCaEdge, SIGNAL(released()), this, SLOT(buttonCaEdgeClick()));

}

MainWindow::~MainWindow() { // Destroyer
    delete ui;
}

//-----------Functions that will be trigger after pressing the button-----------


void MainWindow::buttonDilatationClick() {
    for (int i = 0; i < fileNames.length(); i++) {
        Dilation(5, fileNames[i]);
    }
}

void MainWindow::buttonErosionClick() {
    for (int i = 0; i < fileNames.length(); i++) {
        Erosion(5, fileNames[i]);
    }
}


void MainWindow::buttonResizingClick() {
    for (int i = 0; i < fileNames.length(); i++) {
        Resizing(fileNames[i]);
    }
}

void MainWindow::buttonLightenDarkenClick() {

}

void MainWindow::buttonPaStiClick() {
    PanoramaStitching(fileNames);
}

void MainWindow::buttonCaEdgeClick() {

}

void MainWindow::on_pushButton_clicked() {

// Obtain the route of the files

    QString fileName = QFileDialog::getOpenFileName(this, tr("Excel file"), "./",
                                                    tr("Files (* .csv) ;; Text (. txt) ;; Image (. jpg * .bmp * .png)"));

    if (!fileName.isEmpty()) {
        // Obtain information related with the file
        QFileInfo info(fileName);
        QString file_suffix = info.suffix(); // Obtain the extension of the file
//qDebug()<<"file_suffix="<<file_suffix;

        // Open after analyze the type of file
        QStringList stringList;
        stringList << "csv" << "txt" << "jpg" << "bmp" << "png";
//0:csv 1:txt 2:jpg 3:bmp 4:png
        if (stringList.indexOf(file_suffix) == 0) {
            qDebug() << "Format = csv";
            ui->label->clear();
            QString result = QString::asprintf("Please select a format valid of image, only jpg");
            ui->label->setText(result);
        }

        if (stringList.indexOf(file_suffix) == 1) {
            qDebug() << "Format = txt";
            ui->label->clear();
            QString result = QString::asprintf("Please select a format valid of image, only jpg");
            ui->label->setText(result);
        }

        if (stringList.indexOf(file_suffix) == 2) {
            qDebug() << "Format = jpg";
            fileNames.append(fileName);
            openImage();
        }
        if (stringList.indexOf(file_suffix) == 3) {
            qDebug() << "Format = bmp";
            fileNames.append(fileName);
            openImage();
        }
        if (stringList.indexOf(file_suffix) == 4) {
            qDebug() << "Format = png";
            fileNames.append(fileName);
            openImage();
        }
    }
}

// Open image (* .jpg *.bmp *.png)
void MainWindow::openImage() {
    ui->label->clear(); // Delete the content of the label first
    for (int i = 0; i < fileNames.length(); i++) {
        QImage img(fileNames[i]);
        if (!img.isNull()) {
            // Qt :: KeepAspectRatio adaptative size, without deformation
            img = img.scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio);
            ui->label->setPixmap(QPixmap::fromImage(img));
        }
    }
}