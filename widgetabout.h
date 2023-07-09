#ifndef WIDGETABOUT_H
#define WIDGETABOUT_H

#include<QTextDocument>
#include <QWidget>
#include <QFile>

namespace Ui {
class widgetAbout;
}

class widgetAbout : public QWidget
{
    Q_OBJECT

public:
    explicit widgetAbout(QWidget *parent = nullptr);
    ~widgetAbout();

private:
    Ui::widgetAbout *ui;
    /**
     * @brief formInf формирует текстовую информачию
     */
    void formInf();
    QTextDocument td;
};

#endif // WIDGETABOUT_H
