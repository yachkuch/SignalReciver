/********************************************************************************
** Form generated from reading UI file 'widgetchart.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCHART_H
#define UI_WIDGETCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetChart
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *WidgetChart)
    {
        if (WidgetChart->objectName().isEmpty())
            WidgetChart->setObjectName("WidgetChart");
        WidgetChart->resize(640, 480);
        verticalLayout_2 = new QVBoxLayout(WidgetChart);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(WidgetChart);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(WidgetChart);

        QMetaObject::connectSlotsByName(WidgetChart);
    } // setupUi

    void retranslateUi(QWidget *WidgetChart)
    {
        WidgetChart->setWindowTitle(QCoreApplication::translate("WidgetChart", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetChart: public Ui_WidgetChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCHART_H
