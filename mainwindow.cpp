#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB = new dataBase;
    thread = new QThread;
    net = new network(DB);
    net->moveToThread(thread);
    thread->start();

    chart = new WidgetChart(DB);
    wAbout = new widgetAbout;

    connect(net,SIGNAL(update1()),chart,SLOT(updateChart()));

    auto *MenuBar = new QMenuBar();
    ui->toolBar->addWidget(MenuBar);
    auto *Menu = new QMenu("Меню");
    MenuBar->addMenu(Menu);
    actWalve = new QAction("Tool");
    actWalve2 = new QAction("About");
    Menu->addAction(actWalve);
    Menu->addAction(actWalve2);

    connect(actWalve, SIGNAL(triggered(bool)), this , SLOT(ruleWidgets(bool)));
    connect(actWalve2, SIGNAL(triggered(bool)), this , SLOT(ruleWidgets(bool)));


    chart->show();
    wAbout->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateChart()
{
    chart->updateChart();
}

void MainWindow::ruleWidgets(bool)
{
   QAction *Buff = static_cast<QAction *>(sender());
    if(Buff == actWalve){
       chart->show();
       wAbout->hide();
   } else if (Buff == actWalve2){
       chart->hide();
       wAbout->show();
    }
}

