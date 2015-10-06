#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bar00->setValue( 5);
    ui->bar01->setValue(10);
    ui->bar02->setValue(15);
    ui->bar03->setValue(20);
    ui->bar04->setValue(25);
    ui->bar05->setValue(30);
    ui->bar06->setValue(35);
    ui->bar07->setValue(40);
    ui->bar08->setValue(45);
    ui->bar09->setValue(50);
    ui->bar10->setValue(55);
    ui->bar11->setValue(60);
    ui->bar12->setValue(65);
    ui->bar13->setValue(70);
    ui->bar14->setValue(75);
    ui->bar15->setValue(80);

    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = cos(x[i]); // let's plot a quadratic function
    }

    // Set up the graph
    ui->plot->addGraph();
    updatePlot(x,y);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePlot(QVector<double> x, QVector<double> y)
{
    // Sets the data for the plot
    ui->plot->graph(0)->setData(x, y);

    // Sets up the axis labels
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");

    // Sets the axes ranges
    ui->plot->xAxis->setRange(-1, 1);
    ui->plot->yAxis->setRange( 0, 1);
    ui->plot->replot();
}
