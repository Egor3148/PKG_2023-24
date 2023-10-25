#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>          //for opening the file from dialog
#include <QDir>                 //for file system navigation
#include <QFileSystemModel>
#include <QModelIndex>

#include <QGridLayout>
#include <QListView>
#include <QImageWriter>
#include <QTableWidget>
#include <QHeaderView>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    bool line_changed=false;

    QGridLayout* backgr;

    QFileSystemModel* model;    //a widget for displaying file system
    QListView* listView;
    QTableWidget* twInfo=nullptr;

    int* sortCols = new int[5];



public slots:
    void onListViewDoubleClicked(const QModelIndex& index);
    void twInfoSelected(int logicalIndex);

private slots:
    void dialogClose();
    void onMultiChoiceClicked();
    void onLineEditFinished(const QModelIndex &index);
};
#endif // WIDGET_H
