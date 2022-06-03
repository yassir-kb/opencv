/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *etiquetaResultado;
    QPushButton *buttonErosion;
    QPushButton *buttonResizing;
    QPushButton *buttonLightenDarken;
    QPushButton *buttonPaSti;
    QPushButton *buttonDilatation;
    QPushButton *buttonCaEdge;
    QLabel *etiquetaResultado_3;
    QPushButton *pushButton;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(612, 571);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        etiquetaResultado = new QLabel(centralwidget);
        etiquetaResultado->setObjectName(QString::fromUtf8("etiquetaResultado"));
        etiquetaResultado->setGeometry(QRect(160, 20, 291, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        etiquetaResultado->setPalette(palette1);
        QFont font;
        font.setPointSize(16);
        etiquetaResultado->setFont(font);
        buttonErosion = new QPushButton(centralwidget);
        buttonErosion->setObjectName(QString::fromUtf8("buttonErosion"));
        buttonErosion->setGeometry(QRect(430, 440, 88, 41));
        buttonResizing = new QPushButton(centralwidget);
        buttonResizing->setObjectName(QString::fromUtf8("buttonResizing"));
        buttonResizing->setGeometry(QRect(100, 490, 81, 41));
        buttonLightenDarken = new QPushButton(centralwidget);
        buttonLightenDarken->setObjectName(QString::fromUtf8("buttonLightenDarken"));
        buttonLightenDarken->setGeometry(QRect(240, 440, 135, 41));
        buttonPaSti = new QPushButton(centralwidget);
        buttonPaSti->setObjectName(QString::fromUtf8("buttonPaSti"));
        buttonPaSti->setGeometry(QRect(240, 490, 135, 41));
        buttonDilatation = new QPushButton(centralwidget);
        buttonDilatation->setObjectName(QString::fromUtf8("buttonDilatation"));
        buttonDilatation->setGeometry(QRect(100, 440, 81, 41));
        buttonCaEdge = new QPushButton(centralwidget);
        buttonCaEdge->setObjectName(QString::fromUtf8("buttonCaEdge"));
        buttonCaEdge->setGeometry(QRect(430, 490, 88, 41));
        etiquetaResultado_3 = new QLabel(centralwidget);
        etiquetaResultado_3->setObjectName(QString::fromUtf8("etiquetaResultado_3"));
        etiquetaResultado_3->setGeometry(QRect(160, 400, 291, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        etiquetaResultado_3->setPalette(palette2);
        QFont font1;
        font1.setPointSize(12);
        etiquetaResultado_3->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 60, 221, 31));
        QFont font2;
        font2.setPointSize(10);
        pushButton->setFont(font2);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 120, 481, 261));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        label->setPalette(palette3);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        etiquetaResultado->setText(QCoreApplication::translate("MainWindow", "Welcome to the Image Editor", nullptr));
        buttonErosion->setText(QCoreApplication::translate("MainWindow", "Erosion", nullptr));
        buttonResizing->setText(QCoreApplication::translate("MainWindow", "Resizing", nullptr));
        buttonLightenDarken->setText(QCoreApplication::translate("MainWindow", "Lighten / Darken", nullptr));
        buttonPaSti->setText(QCoreApplication::translate("MainWindow", "Panorama / Stitching", nullptr));
        buttonDilatation->setText(QCoreApplication::translate("MainWindow", "Dilatation", nullptr));
        buttonCaEdge->setText(QCoreApplication::translate("MainWindow", "Canny edge\n"
"detection", nullptr));
        etiquetaResultado_3->setText(QCoreApplication::translate("MainWindow", "Select an action to apply on the image:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Select an image to modify", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
