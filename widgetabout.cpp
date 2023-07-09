#include "widgetabout.h"
#include "ui_widgetabout.h"

#include<QTextDocument>
#include<QTextCharFormat>
#include<QTextCursor>
#include<QFont>
#include<QMessageBox>

widgetAbout::widgetAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetAbout)
{
    ui->setupUi(this);
    formInf();
}

widgetAbout::~widgetAbout()
{
    delete ui;
}

void widgetAbout::formInf()
{
    QTextCursor cursor(&td);
    cursor.movePosition(QTextCursor::Start);
    QTextCharFormat textTitl;
    QFont fontTitle("Arial", 12);
    textTitl.setFont(fontTitle);

    QFile file("C:/Projects/TestWork/Config/about.txt");
    QTextStream strean(&file);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen()){
        while (!strean.atEnd()) {
            cursor.insertText(strean.readLine());
            cursor.insertBlock();
        }
    } else {
        QMessageBox MB;
        MB.setText("Отсутствует информация");
        MB.exec();
    }
    file.close();
    ui->textEdit->setDocument(&td);
}
