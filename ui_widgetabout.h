/********************************************************************************
** Form generated from reading UI file 'widgetabout.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETABOUT_H
#define UI_WIDGETABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetAbout
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QWidget *widgetAbout)
    {
        if (widgetAbout->objectName().isEmpty())
            widgetAbout->setObjectName("widgetAbout");
        widgetAbout->resize(640, 480);
        verticalLayout_2 = new QVBoxLayout(widgetAbout);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(widgetAbout);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(widgetAbout);

        QMetaObject::connectSlotsByName(widgetAbout);
    } // setupUi

    void retranslateUi(QWidget *widgetAbout)
    {
        widgetAbout->setWindowTitle(QCoreApplication::translate("widgetAbout", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetAbout: public Ui_widgetAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETABOUT_H
