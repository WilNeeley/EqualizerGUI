#ifndef SOUNDACQUIRER_H
#define SOUNDACQUIRER_H

//#include <QObject>
#include <QThread>
#include <QVector>
#include <QTimer>
#include <QElapsedTimer>

#define VECSIZE 251
#define FREQ 50

class SoundAcquirer : public QObject
{
    Q_OBJECT
public:
    explicit SoundAcquirer(QObject *parent = 0);
    ~SoundAcquirer();

    //void run() Q_DECL_OVERRIDE;

private:
    QElapsedTimer* etimer;
    QTimer* timer;
    QVector<double> value;
    QVector<double> time;

signals:
    void dataReady(QVector<double> v, QVector<double> t);

public slots:
    void getNewPoint();
};

#endif // SOUNDACQUIRER_H
