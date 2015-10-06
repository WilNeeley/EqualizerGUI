#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updatePlot(QVector<double> x, QVector<double> y);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
