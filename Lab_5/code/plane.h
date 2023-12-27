#ifndef PLANE_H
#define PLANE_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <iostream>

enum type{
    Cirus,
    Central
};

class plane : public QWidget
{
public:
    plane(type, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent*)
    {
        QPainter painter1(this);
        double h = this->height();
        double w = this->width();
        h/=2;
        w/=2;
        double hScale = 20;
        double wScale = 20;
        painter1.translate(w,h);
        QPainterPath text;
        QFont f ("Times", 8);
        f.setStyleStrategy(QFont::ForceOutline);
        painter1.setPen(QPen(Qt::black, 1));

        painter1.drawLine(-(this->width() >> 1), 0, this->width() >> 1, 0);
        painter1.drawLine(0, -(this->height() >> 1), 0, this->height() >> 1);

        painter1.setPen(QPen(Qt::black, 3));
        text.addText(0, 0, f, QString::number(0));
        for(int i = 1; i < this->width()/(wScale*2); ++i)
        {
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(i*wScale, 0);
            text.addText(i*wScale, 12, f, QString::number(i));
            painter1.drawPoint(-i*wScale, 0);
            text.addText(-i*wScale, 12, f, QString::number(-i));

            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-i*wScale, -(this->height() >> 1), -i*wScale, this->height() >> 1);
            painter1.drawLine(i*wScale, -(this->height() >> 1), i*wScale, this->height() >> 1);
        }
        for(int i = 1; i < this->height()/(hScale*2); ++i)
        {
            painter1.setPen(QPen(Qt::black, 3));
            painter1.drawPoint(0, i*hScale);
            text.addText(0, -i*hScale, f, QString::number(i));
            painter1.drawPoint(0, -i*hScale);
            text.addText(0, i*hScale, f, QString::number(-i));
            painter1.setPen(QPen(Qt::black, 1));
            painter1.drawLine(-(this->width() >> 1), -i*hScale, this->width() >> 1, -i*hScale);
            painter1.drawLine(-(this->width() >> 1), i*hScale, this->width() >> 1, i*hScale);
        }
        painter1.setPen(QPen(Qt::red, 3));
        painter1.setBrush(Qt::NoBrush);
        for(int i = 0; i<segments.size(); ++i)
        {
            painter1.drawLine(segments[i].first.x()*20, -segments[i].first.y()*20, segments[i].second.x()*20, -segments[i].second.y()*20);
        }
        painter1.setPen(QPen(Qt::blue, 4));
        if(t == type::Central)
        {
            painter1.drawLine(xMax*20, -yMax*20, xMax*20, -yMin*20);
            painter1.drawLine(xMax*20, -yMax*20, xMin*20, -yMax*20);
            painter1.drawLine(xMin*20, -yMin*20, xMax*20, -yMin*20);
            painter1.drawLine(xMin*20, -yMin*20, xMin*20, -yMax*20);
        }else
        {
            for(int i = 0; i<cropper.size();++i)
            {
                painter1.drawLine(cropper[i].first.x()*20,-cropper[i].first.y()*20,cropper[i].second.x()*20,-cropper[i].second.y()*20);
            }
        }
        painter1.setPen(QPen(Qt::darkGreen, 4));
        for(int i = 0; i<clippedSegments.size(); ++i)
        {
            painter1.drawLine(clippedSegments[i].first.x()*20, -clippedSegments[i].first.y()*20, clippedSegments[i].second.x()*20, -clippedSegments[i].second.y()*20);
        }
        painter1.setPen(QPen(Qt::black, 1));
        painter1.setBrush(QBrush(Qt::black));
        painter1.drawPath(text);
    }
private:
    void clipSegments();
    void Cirus();
    void ClipByCirus(QPair<QPointF,QPointF>);

    float getT(QPair<QPointF,QPointF>,QPair<QPointF,QPointF>, bool*);
    int getCode(QPointF);
    QPointF intersectionPoint(QPointF,QPointF);

    QVector<QPair<QPointF,QPointF>> segments;
    QVector<QPair<QPointF,QPointF>> clippedSegments;
    QVector<QPointF> CirusSegment;
    QVector<QPair<QPointF, QPointF>> cropper;
    int xMin, xMax, yMin, yMax;
    type t;
    float t_1, t_2;
};

#endif // PLANE_H
