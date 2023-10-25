/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListView *fileTreeView;
    QLabel *Label_1;
    QLabel *Label_5;
    QLabel *Label_3;
    QLabel *Label_4;
    QLabel *Label_2;
    QLabel *FileName;
    QLineEdit *lineEdit;
    QLabel *Contraction;
    QLabel *Resolution;
    QLabel *Color_depth;
    QLabel *Size;
    QPushButton *multiChoice;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(454, 500);
        Widget->setMinimumSize(QSize(454, 500));
        Widget->setMaximumSize(QSize(454, 500));
        fileTreeView = new QListView(Widget);
        fileTreeView->setObjectName("fileTreeView");
        fileTreeView->setGeometry(QRect(20, 80, 231, 391));
        Label_1 = new QLabel(Widget);
        Label_1->setObjectName("Label_1");
        Label_1->setGeometry(QRect(260, 110, 81, 41));
        Label_1->setFrameShape(QFrame::WinPanel);
        Label_1->setFrameShadow(QFrame::Raised);
        Label_5 = new QLabel(Widget);
        Label_5->setObjectName("Label_5");
        Label_5->setGeometry(QRect(260, 430, 81, 41));
        Label_5->setFrameShape(QFrame::WinPanel);
        Label_5->setFrameShadow(QFrame::Raised);
        Label_3 = new QLabel(Widget);
        Label_3->setObjectName("Label_3");
        Label_3->setGeometry(QRect(260, 270, 81, 41));
        Label_3->setFrameShape(QFrame::WinPanel);
        Label_3->setFrameShadow(QFrame::Raised);
        Label_4 = new QLabel(Widget);
        Label_4->setObjectName("Label_4");
        Label_4->setGeometry(QRect(260, 350, 81, 41));
        Label_4->setFrameShape(QFrame::WinPanel);
        Label_4->setFrameShadow(QFrame::Raised);
        Label_2 = new QLabel(Widget);
        Label_2->setObjectName("Label_2");
        Label_2->setGeometry(QRect(260, 190, 81, 41));
        Label_2->setFrameShape(QFrame::WinPanel);
        Label_2->setFrameShadow(QFrame::Raised);
        FileName = new QLabel(Widget);
        FileName->setObjectName("FileName");
        FileName->setGeometry(QRect(600, 90, 141, 21));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 20, 231, 21));
        Contraction = new QLabel(Widget);
        Contraction->setObjectName("Contraction");
        Contraction->setGeometry(QRect(600, 170, 181, 31));
        Resolution = new QLabel(Widget);
        Resolution->setObjectName("Resolution");
        Resolution->setGeometry(QRect(600, 260, 181, 31));
        Color_depth = new QLabel(Widget);
        Color_depth->setObjectName("Color_depth");
        Color_depth->setGeometry(QRect(600, 350, 181, 31));
        Size = new QLabel(Widget);
        Size->setObjectName("Size");
        Size->setGeometry(QRect(600, 430, 181, 31));
        multiChoice = new QPushButton(Widget);
        multiChoice->setObjectName("multiChoice");
        multiChoice->setGeometry(QRect(260, 20, 81, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Label_1->setText(QCoreApplication::translate("Widget", "File name:", nullptr));
        Label_5->setText(QCoreApplication::translate("Widget", "Size:", nullptr));
        Label_3->setText(QCoreApplication::translate("Widget", "Resolution:", nullptr));
        Label_4->setText(QCoreApplication::translate("Widget", "Color depth:", nullptr));
        Label_2->setText(QCoreApplication::translate("Widget", "Compression:", nullptr));
        FileName->setText(QString());
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("Widget", "Enter the file path", nullptr));
#endif // QT_CONFIG(tooltip)
        Contraction->setText(QString());
        Resolution->setText(QString());
        Color_depth->setText(QString());
        Size->setText(QString());
        multiChoice->setText(QCoreApplication::translate("Widget", "Open...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
