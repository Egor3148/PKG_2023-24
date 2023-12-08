
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPainter>

#include <cmath>

#include <iostream>


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



Viewport::Viewport(QWidget *parent) : QWidget(parent)
{
    //viewPtr = this;

    //transform matrix
    transformMatrix = new double*[3];
    //tempMatrix = new double*[3];

    for(int i = 0; i < 3; ++i)
    {
        transformMatrix[i] = new double[3];

        //tempMatrix[i] = new double[3] {0};
        //tempMatrix[i][i] = 1;
    }

    //center point initialization
    centerPoint.setAll(0, 0, 11);

    //basic carcass points initialization
    carcassPoints = new Point3D[22];
    projectionCarcassPoints = new Point2D[22];

    carcassPoints[0].setAll(-1, -4, 10);
    projectionCarcassPoints[0].setAll(-1, -4);

    carcassPoints[1].setAll(-1, 4, 10);
    projectionCarcassPoints[1].setAll(-1, 4);

    carcassPoints[2].setAll(0, 4, 10);
    projectionCarcassPoints[2].setAll(0, 4);

    carcassPoints[3].setAll(0, 1, 10);
    projectionCarcassPoints[3].setAll(0, 1);

    carcassPoints[4].setAll(3, 4, 10);
    projectionCarcassPoints[4].setAll(3, 4);

    carcassPoints[5].setAll(4, 3, 10);
    projectionCarcassPoints[5].setAll(4, 3);

    carcassPoints[6].setAll(1, 0, 10);
    projectionCarcassPoints[6].setAll(1, 0);

    carcassPoints[7].setAll(4, -3, 10);
    projectionCarcassPoints[7].setAll(4, -3);

    carcassPoints[8].setAll(3, -4, 10);
    projectionCarcassPoints[8].setAll(3, -4);

    carcassPoints[9].setAll(0, -1, 10);
    projectionCarcassPoints[9].setAll(0, -1);

    carcassPoints[10].setAll(0, -4, 10);
    projectionCarcassPoints[10].setAll(0, -4);



    carcassPoints[11].setAll(-1, -4, 12);
    projectionCarcassPoints[11].setAll(-1, -4);

    carcassPoints[12].setAll(-1, 4, 12);
    projectionCarcassPoints[12].setAll(-1, 4);

    carcassPoints[13].setAll(0, 4, 12);
    projectionCarcassPoints[13].setAll(0, 4);

    carcassPoints[14].setAll(0, 1, 12);
    projectionCarcassPoints[14].setAll(0, 1);

    carcassPoints[15].setAll(3, 4, 12);
    projectionCarcassPoints[15].setAll(3, 4);

    carcassPoints[16].setAll(4, 3, 12);
    projectionCarcassPoints[16].setAll(4, 3);

    carcassPoints[17].setAll(1, 0, 12);
    projectionCarcassPoints[17].setAll(1, 0);

    carcassPoints[18].setAll(4, -3, 12);
    projectionCarcassPoints[18].setAll(4, -3);

    carcassPoints[19].setAll(3, -4, 12);
    projectionCarcassPoints[19].setAll(3, -4);

    carcassPoints[20].setAll(0, -1, 12);
    projectionCarcassPoints[20].setAll(0, -1);

    carcassPoints[21].setAll(0, -4, 12);
    projectionCarcassPoints[21].setAll(0, -4);
}

Viewport::~Viewport()
{
    for(int i = 0; i < 3; ++i)
    {
        delete[] transformMatrix[i];
        //delete[] tempMatrix[i];
    }
    delete[] transformMatrix;
    //delete[] tempMatrix;

    delete[] carcassPoints;
    delete[] projectionCarcassPoints;
}

void Viewport::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(0, 0, this->width(), this->height());
    painter.setPen(Qt::black);

    for(int i = 0; i < 10; ++i)
    {
        painter.drawLine(zeroX + (projectionCarcassPoints[i].x() * scaleValue),
                         zeroY - (projectionCarcassPoints[i].y() * scaleValue),
                         zeroX + (projectionCarcassPoints[i+1].x() * scaleValue),
                         zeroY - (projectionCarcassPoints[i+1].y() * scaleValue));

        painter.drawLine(zeroX + (projectionCarcassPoints[i + 11].x() * scaleValue),
                         zeroY - (projectionCarcassPoints[i + 11].y() * scaleValue),
                         zeroX + (projectionCarcassPoints[i+12].x() * scaleValue),
                         zeroY - (projectionCarcassPoints[i+12].y() * scaleValue));

        painter.drawLine(zeroX + (projectionCarcassPoints[i + 11].x() * scaleValue),
                         zeroY - (projectionCarcassPoints[i + 11].y() * scaleValue),
                         zeroX + (projectionCarcassPoints[i].x() * scaleValue),
                         zeroY - (projectionCarcassPoints[i].y() * scaleValue));
    }
    painter.drawLine(zeroX + (projectionCarcassPoints[0].x() * scaleValue),
                     zeroY - (projectionCarcassPoints[0].y() * scaleValue),
                     zeroX + (projectionCarcassPoints[10].x() * scaleValue),
                     zeroY - (projectionCarcassPoints[10].y() * scaleValue));

    painter.drawLine(zeroX + (projectionCarcassPoints[11].x() * scaleValue),
                     zeroY - (projectionCarcassPoints[11].y() * scaleValue),
                     zeroX + (projectionCarcassPoints[21].x() * scaleValue),
                     zeroY - (projectionCarcassPoints[21].y() * scaleValue));

    painter.drawLine(zeroX + (projectionCarcassPoints[10].x() * scaleValue),
                     zeroY - (projectionCarcassPoints[10].y() * scaleValue),
                     zeroX + (projectionCarcassPoints[21].x() * scaleValue),
                     zeroY - (projectionCarcassPoints[21].y() * scaleValue));
}



// SLOTS

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


        viewPtr->centerPoint.setAll((viewPtr->centerPoint).x() + (arg1->text().toFloat()),
                                    (viewPtr->centerPoint).y() + (arg2->text().toFloat()),
                                    (viewPtr->centerPoint).z() + (arg3->text().toFloat()));
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].setAll((viewPtr->carcassPoints[i]).x() + (arg1->text().toFloat()),
                                             (viewPtr->carcassPoints[i]).y() + (arg2->text().toFloat()),
                                             (viewPtr->carcassPoints[i]).z() + (arg3->text().toFloat()));

            viewPtr->projectionCarcassPoints[i].getFromPoint3D(viewPtr->carcassPoints[i]);

            //DEBUG ONLY
            //std::cout << (viewPtr->projectionCarcassPoints[i]).x() << " " << (viewPtr->projectionCarcassPoints[i]).y() << " ";
        }
        //viewPtr->update();
        //return;
    }
    else if(rotate)
    {

        //move to the center to rotate the whole object properly
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].setAll((viewPtr->carcassPoints[i]).x() - viewPtr->centerPoint.x(),
                                             (viewPtr->carcassPoints[i]).y() - viewPtr->centerPoint.y(),
                                             (viewPtr->carcassPoints[i]).z() - viewPtr->centerPoint.z());
        }


        //rotate around X axis
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->transformMatrix[1][1] = cos(arg1->text().toFloat());
        viewPtr->transformMatrix[2][1] = sin(arg1->text().toFloat());
        viewPtr->transformMatrix[1][2] = viewPtr->transformMatrix[2][1] * -1.0;
        viewPtr->transformMatrix[2][2] = viewPtr->transformMatrix[1][1];
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].transform(viewPtr->transformMatrix);
        }


        //rotate around Y axis
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->transformMatrix[0][0] = cos(arg2->text().toFloat());
        viewPtr->transformMatrix[0][2] = sin(arg2->text().toFloat());
        viewPtr->transformMatrix[2][0] = viewPtr->transformMatrix[0][2] * -1.0;
        viewPtr->transformMatrix[2][2] = viewPtr->transformMatrix[0][0];
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].transform(viewPtr->transformMatrix);
        }


        //rotate around Z axis
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->transformMatrix[0][0] = cos(arg3->text().toFloat());
        viewPtr->transformMatrix[1][0] = sin(arg3->text().toFloat());
        viewPtr->transformMatrix[0][1] = viewPtr->transformMatrix[1][0] * -1.0;
        viewPtr->transformMatrix[1][1] = viewPtr->transformMatrix[0][0];
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].transform(viewPtr->transformMatrix);
        }


        //move back to the true object position
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].setAll((viewPtr->carcassPoints[i]).x() + viewPtr->centerPoint.x(),
                                             (viewPtr->carcassPoints[i]).y() + viewPtr->centerPoint.y(),
                                             (viewPtr->carcassPoints[i]).z() + viewPtr->centerPoint.z());
            viewPtr->projectionCarcassPoints[i].getFromPoint3D((viewPtr->carcassPoints[i]));
        }
    }
    else if(scale)
    {
        //move to the center to rotate the whole object properly
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].setAll((viewPtr->carcassPoints[i]).x() - viewPtr->centerPoint.x(),
                                             (viewPtr->carcassPoints[i]).y() - viewPtr->centerPoint.y(),
                                             (viewPtr->carcassPoints[i]).z() - viewPtr->centerPoint.z());
        }


        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                viewPtr->transformMatrix[i][j] = 0;
            }
            viewPtr->transformMatrix[i][i] = 1;
        }
        viewPtr->transformMatrix[0][0] = (arg1->text().toFloat())/* / 100.0*/;
        viewPtr->transformMatrix[1][1] = (arg2->text().toFloat())/* / 100.0*/;
        viewPtr->transformMatrix[2][2] = (arg3->text().toFloat())/* / 100.0*/;
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].transform(viewPtr->transformMatrix);
        }


        //move back to the true object position
        for(int i = 0; i < 22; ++i)
        {
            viewPtr->carcassPoints[i].setAll((viewPtr->carcassPoints[i]).x() + viewPtr->centerPoint.x(),
                                             (viewPtr->carcassPoints[i]).y() + viewPtr->centerPoint.y(),
                                             (viewPtr->carcassPoints[i]).z() + viewPtr->centerPoint.z());
            viewPtr->projectionCarcassPoints[i].getFromPoint3D((viewPtr->carcassPoints[i]));
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
