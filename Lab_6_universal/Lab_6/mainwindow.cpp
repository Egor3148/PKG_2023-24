
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPainter>

#include<QFileDialog>
#include<QFile>
#include<QMessageBox>

#include <cmath>

#include <iostream>


/*--------------------- MainWindow--------------------*/


MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //getting the addresses of the input spinboxes
    arg1 = ui->argSpinbox1;
    arg2 = ui->argSpinbox2;
    arg3 = ui->argSpinbox3;

    //input spinboxes range setting
    arg1->setRange(-200.0, 200.0);
    arg2->setRange(-200.0, 200.0);
    arg3->setRange(-200.0, 200.0);

    //viewport initializing
    ui->viewportWidget->clear();
    viewPtr = new Viewport();
    viewPtr->updatesEnabled();
    ui->viewportWidget->addTab(viewPtr, "Viewport");

    //coordinates issues initializing (defines the (0; 0) position and the scale value)
    viewPtr->zeroX = ui->viewportWidget->width() / 2.0;
    viewPtr->zeroY =  ui->viewportWidget->height() / 2.0;
    viewPtr->scaleValue =  ui->viewportWidget->width() / 100.0;


    //interactive elements connection
    connect(ui->processingButton, SIGNAL(clicked()), this, SLOT(processButtonClicked()));
    connect(ui->movingOptButton, SIGNAL(clicked()), this, SLOT(movingOptButtonClicked()));
    connect(ui->rotatingOptButton, SIGNAL(clicked()), this, SLOT(rotatingOptButtonClicked()));
    connect(ui->scalingOptButton, SIGNAL(clicked()), this, SLOT(scalingOptButtonClicked()));

}

MainWindow::~MainWindow()
{
    delete viewPtr;
    delete ui;
}


/*--------------------Object3D---------------------*/


Object3D::Object3D()
{
    transformMatrix = new double*[3];
    for(int i = 0; i < 3; ++i)
    {
        transformMatrix[i] = new double[3];
    }

    QFile file("test.3dc");
    //file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!file.isOpen())
    {
        //QMessageBox::critical("ERROR", "Error while opening the file.\nCheck if the file exists");
        exit(1);
    }
    QTextStream fin(&file);

    double tempX, tempY, tempZ;

    //gets center coordinates
    fin >> tempX >> tempY >> tempZ;
    centerPoint.setAll(tempX, tempY, tempZ);

    fin >> pointsAmount;

    //gets carcass points and their projections ("Z=0" by default)
    carcassPoints = new Point3D[pointsAmount];
    projectionCarcassPoints = new Point2D[pointsAmount];

    for(int i = 0; i < pointsAmount; ++i)
    {
        fin >> tempX >> tempY >> tempZ;

        carcassPoints[i].setAll(tempX, tempY, tempZ);
        projectionCarcassPoints[i].getFromPoint3D(carcassPoints[i]);
    }

    //gets ribs matrix
    ribsMatrix = new int*[pointsAmount];
    for(int i = 0; i < pointsAmount; ++i)
    {
        ribsMatrix[i] = new int[pointsAmount];
        for(int j = 0; j < pointsAmount; ++j)
        {
            fin << ribsMatrix[i][j];
        }
    }

    file.close();
}

Object3D::~Object3D()
{
    for(int i = 0; i < 3; ++i)
    {
        delete[] transformMatrix[i];
    }
    delete[] transformMatrix;

    for(int i = 0; i < pointsAmount; ++i)
    {
        delete[] ribsMatrix[i];
    }
    delete[] ribsMatrix;

    delete[] carcassPoints;
    delete[] projectionCarcassPoints;
}


void Object3D::draw(QPainter* painter, double x0, double y0, double scale)
{
    for(int i = 0; i < pointsAmount; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(ribsMatrix[i][j] == 1)
            {
                painter->drawLine(((projectionCarcassPoints[i].x()) * scale) + x0,
                                  ((projectionCarcassPoints[i].y()) * scale) - y0,
                                  ((projectionCarcassPoints[j].x()) * scale) + x0,
                                  ((projectionCarcassPoints[j].y()) * scale) - y0);
            }
        }
    }
}


/*-------------------Viewport-----------------------*/


Viewport::Viewport(QWidget *parent) : QWidget(parent)
{
    zeroX = this->width() / 2.0;
    zeroY = this->height() / 2.0;
    scaleValue = zeroX / 20.0;

    modelPtr = new Object3D;
}

Viewport::~Viewport()
{
    delete modelPtr;
}

void Viewport::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    /*for(int i = 0; i < modelPtr->pointsAmount; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(modelPtr->ribsMatrix[i][j] == 1)
            {
                painter.drawLine(modelPtr);
            }
        }
    }*/

    modelPtr->draw(&painter, zeroX, zeroY, scaleValue);
}


/*----------------------SLOTS-----------------------*/


void MainWindow::movingOptButtonClicked()
{
    move = true;
    rotate = false;
    scale = false;

    arg1->setValue(0);
    arg2->setValue(0);
    arg3->setValue(0);
}

void MainWindow::rotatingOptButtonClicked()
{
    move = false;
    rotate = true;
    scale = false;

    arg1->setValue(0);
    arg2->setValue(0);
    arg3->setValue(0);
}

void MainWindow::scalingOptButtonClicked()
{
    move = false;
    rotate = false;
    scale = true;

    arg1->setValue(1);
    arg2->setValue(1);
    arg3->setValue(1);
}



void MainWindow::processButtonClicked()
{
    if(move)
    {
        /*for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                viewPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->transformMatrix[0][2] = arg1->text().toFloat();
        viewPtr->transformMatrix[1][2] = arg1->text().toFloat();
        viewPtr->transformMatrix[2][2] = arg1->text().toFloat();


        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].transform(viewPtr->transformMatrix);
            viewPtr->projectionCarcassPoints->getFromPoint3D((viewPtr->carcassPoints[i]));
        }*/


        viewPtr->modelPtr->centerPoint.setAll((viewPtr->modelPtr->centerPoint).x() + (arg1->text().toFloat()),
                                    (viewPtr->modelPtr->centerPoint).y() + (arg2->text().toFloat()),
                                    (viewPtr->modelPtr->centerPoint).z() + (arg3->text().toFloat()));
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].setAll((viewPtr->modelPtr->carcassPoints[i]).x() + (arg1->text().toFloat()),
                                             (viewPtr->modelPtr->carcassPoints[i]).y() + (arg2->text().toFloat()),
                                             (viewPtr->modelPtr->carcassPoints[i]).z() + (arg3->text().toFloat()));

            viewPtr->modelPtr->projectionCarcassPoints[i].getFromPoint3D(viewPtr->modelPtr->carcassPoints[i]);

            //DEBUG ONLY
            //std::cout << (viewPtr->projectionCarcassPoints[i]).x() << " " << (viewPtr->projectionCarcassPoints[i]).y() << " ";
        }
        //viewPtr->update();
        //return;
    }
    else if(rotate)
    {

        //move to the center to rotate the whole object properly
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].setAll((viewPtr->modelPtr->carcassPoints[i]).x() - viewPtr->modelPtr->centerPoint.x(),
                                                        (viewPtr->modelPtr->carcassPoints[i]).y() - viewPtr->modelPtr->centerPoint.y(),
                                                        (viewPtr->modelPtr->carcassPoints[i]).z() - viewPtr->modelPtr->centerPoint.z());
        }


        //rotate around X axis
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->modelPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->modelPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->modelPtr->transformMatrix[1][1] = cos(arg1->text().toFloat());
        viewPtr->modelPtr->transformMatrix[2][1] = sin(arg1->text().toFloat());
        viewPtr->modelPtr->transformMatrix[1][2] = viewPtr->modelPtr->transformMatrix[2][1] * -1.0;
        viewPtr->modelPtr->transformMatrix[2][2] = viewPtr->modelPtr->transformMatrix[1][1];
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].transform(viewPtr->modelPtr->transformMatrix);
        }


        //rotate around Y axis
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->modelPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->modelPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->modelPtr->transformMatrix[0][0] = cos(arg2->text().toFloat());
        viewPtr->modelPtr->transformMatrix[0][2] = sin(arg2->text().toFloat());
        viewPtr->modelPtr->transformMatrix[2][0] = viewPtr->modelPtr->transformMatrix[0][2] * -1.0;
        viewPtr->modelPtr->transformMatrix[2][2] = viewPtr->modelPtr->transformMatrix[0][0];
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].transform(viewPtr->modelPtr->transformMatrix);
        }


        //rotate around Z axis
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->modelPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->modelPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->modelPtr->transformMatrix[0][0] = cos(arg3->text().toFloat());
        viewPtr->modelPtr->transformMatrix[1][0] = sin(arg3->text().toFloat());
        viewPtr->modelPtr->transformMatrix[0][1] = viewPtr->modelPtr->transformMatrix[1][0] * -1.0;
        viewPtr->modelPtr->transformMatrix[1][1] = viewPtr->modelPtr->transformMatrix[0][0];
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].transform(viewPtr->modelPtr->transformMatrix);
        }


        //move back to the true object position
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].setAll((viewPtr->modelPtr->carcassPoints[i]).x() + viewPtr->modelPtr->centerPoint.x(),
                                             (viewPtr->modelPtr->carcassPoints[i]).y() + viewPtr->modelPtr->centerPoint.y(),
                                             (viewPtr->modelPtr->carcassPoints[i]).z() + viewPtr->modelPtr->centerPoint.z());
            viewPtr->modelPtr->projectionCarcassPoints[i].getFromPoint3D((viewPtr->modelPtr->carcassPoints[i]));
        }
    }
    else if(scale)
    {
        //move to the center to rotate the whole object properly
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].setAll((viewPtr->modelPtr->carcassPoints[i]).x() - viewPtr->modelPtr->centerPoint.x(),
                                             (viewPtr->modelPtr->carcassPoints[i]).y() - viewPtr->modelPtr->centerPoint.y(),
                                             (viewPtr->modelPtr->carcassPoints[i]).z() - viewPtr->modelPtr->centerPoint.z());
        }


        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->modelPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->modelPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->modelPtr->transformMatrix[0][0] = (arg1->text().toFloat())/* / 100.0*/;
        viewPtr->modelPtr->transformMatrix[1][1] = (arg2->text().toFloat())/* / 100.0*/;
        viewPtr->modelPtr->transformMatrix[2][2] = (arg3->text().toFloat())/* / 100.0*/;
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].transform(viewPtr->modelPtr->transformMatrix);
        }


        //move back to the true object position
        for(int i = 0; i < viewPtr->modelPtr->pointsAmount; ++i)
        {
            viewPtr->modelPtr->carcassPoints[i].setAll((viewPtr->modelPtr->carcassPoints[i]).x() + viewPtr->modelPtr->centerPoint.x(),
                                             (viewPtr->modelPtr->carcassPoints[i]).y() + viewPtr->modelPtr->centerPoint.y(),
                                             (viewPtr->modelPtr->carcassPoints[i]).z() + viewPtr->modelPtr->centerPoint.z());
            viewPtr->modelPtr->projectionCarcassPoints[i].getFromPoint3D((viewPtr->modelPtr->carcassPoints[i]));
        }
    }

    //DEBUG ONLY
    /*for(int i = 0; i < 22; ++i)
    {
        std::cout << viewPtr->projectionCarcassPoints[i].x() << " "
                  << viewPtr->projectionCarcassPoints[i].y() << " ";
    }*/
    //std::cout << "\n";

    viewPtr->update();
}
