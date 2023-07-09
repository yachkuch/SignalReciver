#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QPointF>
#include <QVector>
#include <QDebug>

#include <numeric>
#include <iostream>
#include <utility>

class dataBase : public QObject
{
    Q_OBJECT
public:
    explicit dataBase(QObject *parent = nullptr);
    std::pair<__int16 *, __int16 *> getPairMinMax();
    QList <QPointF> getPoints();
    QPointF getPointMedian();
    QPointF getMax();

signals:
public slots:
    void setInformation(__int16 points[]);
private:
    std::pair<__int16*, __int16*> MinMaxValue;
    QList <QPointF> points;
    QPointF pointMedian;
    QPointF Max;

};

#endif // DATABASE_H
