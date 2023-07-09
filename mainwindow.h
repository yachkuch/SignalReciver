#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QChart>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include "database.h"
#include "network.h"
#include "widgetchart.h"
#include "widgetabout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateChart();

private:
    Ui::MainWindow *ui;
    /**
     * @brief DB Хранилище приходящих точек
     */
    dataBase *DB;
    /**
     * @brief net прем посылаемых сообщений
     */
    network *net;
    /**
     * @brief thread
     */
    QThread *thread;
    /**
     * @brief chart Виджет графиков
     */
    WidgetChart *chart;
    /**
     * @brief actWalve кнопки переключения виджетами
     * @brief actWalve2 кнопки переключения виджетами
     */
    QAction *actWalve;
    QAction *actWalve2;
    /**
     * @brief wAbout Виджет с сопроводительной информацией
     */
    widgetAbout *wAbout;

private slots:
    /**
     * @brief ruleWidgets Функция управления виджетами
     */
    void ruleWidgets(bool);
signals:
    void update1();
};
#endif // MAINWINDOW_H
