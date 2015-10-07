#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "soundacquirer.h"
#include "soundprocessor.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SoundProcessor *sp;
    SoundAcquirer  *sa;
    QCPBars   *newbars;

    QVector<double> barindices;
    //QVector<int>  colvals;
    //QVector<double> xvals;
    //QVector<double> yvals;

public slots:
    //void getBarValues();
    //void getPlotValues();
    void updateBars(QVector<int> vals);
    void updateBarPlot(QVector<int> vals);
    void updatePlot(QVector<double> x, QVector<double> y);
};

#endif // MAINWINDOW_H
