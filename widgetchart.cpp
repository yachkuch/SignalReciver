#include "widgetchart.h"
#include "ui_widgetchart.h"

WidgetChart::WidgetChart(dataBase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetChart)
{
    ui->setupUi(this);
    this->db = db;
    chart = new QChart;
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->addItem(chart);
    chart->setMinimumHeight(500);
    chart->setMinimumWidth(1500);
    mediane.setColor(Qt::red);
    mediane.setMarkerSize(20);
    maximum.setColor(Qt::green);
    maximum.setMarkerSize(20);

}

WidgetChart::~WidgetChart()
{
    delete ui;
}

void WidgetChart::makeChart()
{

    //updateChart();
}

void WidgetChart::updateChart()
{
    chart->removeSeries(&ls);
    chart->removeSeries(&maximum);
    chart->removeSeries(&mediane);
    ls.clear();
    mediane.clear();
    maximum.clear();
    ls.append(db->getPoints());
    mediane.append(db->getPointMedian());
    maximum.append(db->getMax());
    chart->addSeries(&ls);
    chart->addSeries(&mediane);
    chart->addSeries(&maximum);
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0,4096);
    chart->axes(Qt::Horizontal).first()->setTitleText("№ discrets");
    chart->axes(Qt::Vertical).first()->setTitleText("Amplitude");
    chart->axes(Qt::Vertical).first()->setRange(*db->getPairMinMax().first-1000,*db->getPairMinMax().second+1000);
    chart->setTitle("Сигнал");

}
