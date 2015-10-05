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
}

MainWindow::~MainWindow()
{
    delete ui;
}
