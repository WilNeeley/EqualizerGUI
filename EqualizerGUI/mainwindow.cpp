#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Sets up the UI
    ui->setupUi(this);
    ui->plot->addGraph();

    // Sets up the bar plot
    newbars = new QCPBars(ui->barplot->xAxis, ui->barplot->yAxis);
    ui->barplot->addPlottable(newbars);
    newbars->setName("Bars");

    barindices.empty();
    for(int i = 0; i < 16; i++)
        barindices.append(i + 0.5);

    // Sets up the Sound Processor and Sound Acquirer
    sa = new SoundAcquirer(this);
    sp = new SoundProcessor(this);


    // generate some data:
    /*QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = cos(x[i]); // let's plot a quadratic function
    }
    updatePlot(x,y);*/

    QObject::connect(sp, SIGNAL( barsReady(QVector<int>)),
                     this, SLOT(updateBars(QVector<int>)));
    QObject::connect(sp, SIGNAL(    barsReady(QVector<int>)),
                     this, SLOT(updateBarPlot(QVector<int>)));
    QObject::connect(sp, SIGNAL( plotReady(QVector<double>,QVector<double>)),
                     this, SLOT(updatePlot(QVector<double>,QVector<double>)));
    QObject::connect(sa, SIGNAL(   dataReady(QVector<double>,QVector<double>)),
                     sp,   SLOT(processAudio(QVector<double>,QVector<double>)));

}


MainWindow::~MainWindow()
{
    delete ui;
    delete sp;
}



// *****   SLOTS   ***** //


void MainWindow::updateBars(QVector<int> vals)
{
    ui->bar00->setValue(vals[ 0]);
    ui->bar01->setValue(vals[ 1]);
    ui->bar02->setValue(vals[ 2]);
    ui->bar03->setValue(vals[ 3]);
    ui->bar04->setValue(vals[ 4]);
    ui->bar05->setValue(vals[ 5]);
    ui->bar06->setValue(vals[ 6]);
    ui->bar07->setValue(vals[ 7]);
    ui->bar08->setValue(vals[ 8]);
    ui->bar09->setValue(vals[ 9]);
    ui->bar10->setValue(vals[10]);
    ui->bar11->setValue(vals[11]);
    ui->bar12->setValue(vals[12]);
    ui->bar13->setValue(vals[13]);
    ui->bar14->setValue(vals[14]);
    ui->bar15->setValue(vals[15]);
}


void MainWindow::updateBarPlot(QVector<int> vals)
{
    QVector<double> temp;
    for(int i = 0; i < vals.size(); i++)
        temp.append(vals[i]);

    newbars->setData(barindices, temp);

    // Axis scaling
    ui->barplot->xAxis->setRange( 0, 16);
    ui->barplot->yAxis->setRange( 0,100);
    ui->barplot->replot();
}


void MainWindow::updatePlot(QVector<double> x, QVector<double> y)
{
    // Sets the data for the plot
    ui->plot->graph(0)->setData(x, y);

    // Sets up the axis labels
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");

    // Finds the min and max values for the X axis
    double xmin = x[0];
    double xmax = x[x.size() - 1];


    // Sets the axes ranges
    ui->plot->xAxis->setRange( xmin, xmax);
    ui->plot->yAxis->setRange( -1, 1);
    ui->plot->replot();
}




