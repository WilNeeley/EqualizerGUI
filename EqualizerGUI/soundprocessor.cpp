#include "soundprocessor.h"

SoundProcessor::SoundProcessor(QObject *parent) : QObject(parent)
{
    // Size the QVectors
    colvals.resize(COLS);
    xvals.resize(DATAPOINTS);
    yvals.resize(DATAPOINTS);
}


SoundProcessor::~SoundProcessor()
{

}


/*QVector<int> SoundProcessor::getBarValues()
{
    return colvals;
}

QVector<double> SoundProcessor::getXValues()
{
    return xvals;
}

QVector<double> SoundProcessor::getYValues()
{
    return yvals;
}*/



// *****  SIGNALS  ***** //

//void barsReady(QVector<int> cols) {}
//void plotReady(QVector<double> x, QVector<double> y) {}


// *****   SLOTS   ***** //

void SoundProcessor::processAudio(QVector<double> value, QVector<double> time)
{
    // Copies things over
    for(int i = 0; i < DATAPOINTS; i++)
    {
        xvals[i] = time[i];
        yvals[i] = value[i];
    }

    // Emit that the plot is ready to go
    emit plotReady(xvals, yvals);

    // Creates a cycling pattern on the bars
    static int cycle = 79;
    cycle++;
    if(cycle > 100)
        cycle = 0;

    colvals[COLS-1] = cycle;

    for(int i = COLS-1; i > 0; i--)
    {
        colvals[i-1] = colvals[i] - 5;
        if(colvals[i-1] < 0)
            colvals[i-1] += 100;
    }

    // Emit that the bars are ready to go
    emit barsReady(colvals);
}
