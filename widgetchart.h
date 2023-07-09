#ifndef WIDGETCHART_H
#define WIDGETCHART_H

#include "database.h"

#include <QWidget>
#include <QChart>
#include <QLineSeries>

namespace Ui {
class WidgetChart;
}

class WidgetChart : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetChart(dataBase*db, QWidget *parent = nullptr);
    ~WidgetChart();

private:
    Ui::WidgetChart *ui;
    QChart *chart;
    QGraphicsScene *scene;
    dataBase *db;
    QLineSeries ls;
    QLineSeries maximum;
    QLineSeries mediane;

    void makeChart();
public slots:
    void updateChart();
};

#endif // WIDGETCHART_H
