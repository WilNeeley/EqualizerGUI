#include "soundacquirer.h"
#include <math.h>

SoundAcquirer::SoundAcquirer(QObject *parent) : QObject(parent)
{
    // Reserves sufficient memory for the vectors such that pops and pushes don't take too long
    value.reserve(VECSIZE);
    time.reserve(VECSIZE);

    // Sets up the vector sizes
    value.resize(VECSIZE);
    time.resize(VECSIZE);

    // Initializes the vector values
    for(int i = 0; i < VECSIZE; i++)
    {
        value[i] = 0;
        time[i] = (- VECSIZE + 1.0 + i)/FREQ;
    }

    // Sets up the timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getNewPoint()));
    timer->start(1000.0/FREQ);

    // Sets up the etimer
    etimer = new QElapsedTimer;
    etimer->start();
}


SoundAcquirer::~SoundAcquirer()
{
    delete etimer;
    delete timer;
}


// *****  SIGNALS  ***** //

//void SoundAcquirer::dataReady(QVector<double> t, QVector<double> v) {}


// *****   SLOTS   ***** //

void SoundAcquirer::getNewPoint()
{
    // Keeps track of the run time
    //static double currTime = 0;
    //currTime += 1.0/FREQ;
    double currTime = 0.001 * etimer->elapsed();

    // Removes values from the beginning
    value.remove(0);
    time.remove(0);

    // Adds values to the end
    value.append( sin(currTime) );
    time.append( currTime);

    emit dataReady(value, time);
}
