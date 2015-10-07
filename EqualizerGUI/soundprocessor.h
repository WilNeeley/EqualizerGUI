#ifndef SOUNDPROCESSOR_H
#define SOUNDPROCESSOR_H

#define COLS 16
#define DATAPOINTS 251

#include <QObject>
#include <QVector>

//#include "mainwindow.h"

class SoundProcessor : public QObject
{
    Q_OBJECT
private:
    //QObject *parent;
    QVector<int>    colvals;
    QVector<double> xvals;
    QVector<double> yvals;

public:
    explicit SoundProcessor(QObject *parent = 0);
    ~SoundProcessor();
    void updateParentPlots();

    //QVector<int>  getBarValues();
    //QVector<double> getXValues();
    //QVector<double> getYValues();

signals:
    void barsReady(QVector<int> cols);
    void plotReady(QVector<double> x, QVector<double> y);

public slots:
    //void makeSineWave();
    void processAudio(QVector<double> value, QVector<double> time);
};

#endif // SOUNDPROCESSOR_H
