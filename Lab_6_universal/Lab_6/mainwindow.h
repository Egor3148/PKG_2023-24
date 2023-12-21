#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>

//#include<iostream>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


/*------------------POINTS CLASSES---------------------*/

//this class stores and transforms the points
class Point3D
{
    //Point coordinates will be stored there
    double* coordinates;

public:
    //constructors (default and by coordinates)
    Point3D()
    {
        coordinates = new double[3];
    }
    Point3D(double x, double y, double z)
    {
        coordinates = new double[3];

        coordinates[0] = x;
        coordinates[1] = y;
        coordinates[2] = z;
    }
    Point3D(Point3D& otherPoint)
    {
        this->coordinates = new double[3];
        for(int i = 0; i < 3; ++i)
        {
            this->coordinates[i] = otherPoint.coordinates[i];
        }
    }

    ~Point3D() {delete[] coordinates;}

    //setters
    void setX(double x)
    {
        coordinates[0] = x;
    }
    void setY(double y)
    {
        coordinates[1] = y;
    }
    void setZ(double z)
    {
        coordinates[2] = z;
    }

    void setAll(double x, double y, double z)
    {
        coordinates[0] = x;
        coordinates[1] = y;
        coordinates[2] = z;
    }

    //getters
    double x() {return coordinates[0];}
    double y() {return coordinates[1];}
    double z() {return coordinates[2];}

    //multiplies the point on transformation matrix to get its new value
    void transform(double** transformMatrix/*, int rows, int cols*/)    //by default its size is 3
    {
        double* tempV = new double[3];
        double temp;

        /*for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                std::cout << transformMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }*/

        for(int i = 0; i < 3; ++i)
        {
            temp = 0;
            for(int j = 0; j < 3; ++j)
            {
                temp += coordinates[j] * transformMatrix[i][j];
            }
            tempV[i] = temp;
        }

        for(int i = 0; i < 3; ++i)
        {
            coordinates[i] = tempV[i];
        }
        delete[] tempV;

    }
};

class Point2D
{
    //Point coordinates will be stored there
    double* coordinates;

public:
    //constructors (default and by coordinates)
    Point2D()
    {
        coordinates = new double[2];
    }
    Point2D(double x, double y)
    {
        coordinates = new double[2];

        coordinates[0] = x;
        coordinates[1] = y;
    }
    ~Point2D() {delete[] coordinates;}

    //setters
    void setX(double x)
    {
        coordinates[0] = x;
    }
    void setY(double y)
    {
        coordinates[1] = y;
    }

    void setAll(double x, double y)
    {
        coordinates[0] = x;
        coordinates[1] = y;
    }



    //getters
    double x() {return coordinates[0];}
    double y() {return coordinates[1];}

    //gets a projection of a 3D point (the default plane is "Z=0")
    void getFromPoint3D (Point3D point)
    {
        coordinates[0] = point.x();
        coordinates[1] = point.y();
    }
};


/*-------------------BASIC OBJECT CLASS-----------------*/

//this class represents a single object
class Object3D
{
private:

public:

    Point3D centerPoint;    //information about the center of the point
    Point3D* carcassPoints;   //basic points to draw lines between them to get the figure
    Point2D* projectionCarcassPoints; //the projections of basic points

    //ribs data
    int pointsAmount;
    int** ribsMatrix;

    //transformation matrix
    double** transformMatrix;

    //--------methods-----

    //draws an object
    void draw(QPainter& painter, double x0, double y0, double scale);

    Object3D();
    ~Object3D();

    friend class Viewport;
};


/*------------------VIEWPORT CLASS----------------------*/

//this class prints out the image (the camera plane is "Z=0")
class Viewport : public QWidget
{
private:

    //coordinates issues
    double zeroX, zeroY;
    double scaleValue;

    //models to display
    Object3D* modelPtr;

    //a drawing method
    void paintEvent(QPaintEvent*);

public:

    /*
    //transformation matrix
    double** transformMatrix;
    //double** tempMatrix;

    Point3D centerPoint;    //information about the center of the point
    Point3D* carcassPoints;   //basic points to draw lines between them to get the figure
    Point2D* projectionCarcassPoints; //the projections of basic points will be there
*/

    Viewport(QWidget *parent = nullptr);
    ~Viewport();

    friend class MainWindow;

};


/*------------------------MAIN APP CLASS----------------------*/

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:

    Viewport* viewPtr;

    //arguments input addresses
    QDoubleSpinBox* arg1;
    QDoubleSpinBox* arg2;
    QDoubleSpinBox* arg3;

    //transformation flags
    bool move = true;
    bool rotate = false;
    bool scale = false;

    MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void processButtonClicked();

    void movingOptButtonClicked();
    void rotatingOptButtonClicked();
    void scalingOptButtonClicked();
};


#endif // MAINWINDOW_H
