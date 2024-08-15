#include "statevaluation.h"
#include "ui_statevaluation.h"
#include <QtSql>
#include<QMap>
#include <iostream>
#include <QString>
#include<time.h>
#include <QDialog>
#include <qdialog.h>
#include <ctime>
#include<vector>
#include <QLineEdit>
#include <cstring>
#include <QSharedPointer>
#include<QSharedDataPointer>
#include<qsharedpointer.h>
#include<qcustomplot.h>
statevaluation::statevaluation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statevaluation)
{
    ui->setupUi(this);
    QPixmap pix1("C:/QTP/ProjetCppA23G2/ProjetCpp/Calque 0.png");

    ui->label->setPixmap(pix1);


    // set dark background gradient:
               QLinearGradient gradient(111, 74, 147, 400);
               gradient.setColorAt(0, QColor(15, 30, 169));
               gradient.setColorAt(0.38, QColor(97, 118, 201));
               gradient.setColorAt(1, QColor(145, 21, 47));
               ui->widget->setBackground(QBrush(gradient));

               // create empty bar chart objects:
               QCPBars *regen = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

               regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders


               // set names and colors:

               regen->setName("Les Notes Des Clients");
               regen->setPen(QPen(QColor(133, 6, 6).lighter(180)));
               regen->setBrush(QColor(133, 6, 6));



               // prepare x axis with country labels:
               QVector<double> ticks;
               QVector<QString> labels;

               QVector<double> regenData;


               ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 ;
               QSqlQuery q;
               //q.prepare("select NOTE_CLIENT ,count(ID_NOTE) from EVALUATION  ORDER BY NOTE_CLIENT ");

               q.prepare("select NOTE_CLIENT ,count(ID_NOTE)as Note from EVALUATION group by NOTE_CLIENT ");


               if(q.exec()){
               while (q.next()) {


                labels << q.value(0).toString();

                regenData   << q.value(1).toDouble();

               }}
               QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
               textTicker->addTicks(ticks, labels);

               ui->widget->xAxis->setTicker(textTicker);
               ui->widget->xAxis->setTickLabelRotation(60);
               ui->widget->xAxis->setTickLength(0, 5);
               ui->widget->xAxis->setRange(0, 9);
               ui->widget->xAxis->setLabel("Note");

               ui->widget->xAxis->setBasePen(QPen(Qt::white));
               ui->widget->xAxis->setTickPen(QPen(Qt::white));
               ui->widget->xAxis->grid()->setVisible(true);
               ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
               ui->widget->xAxis->setTickLabelColor(Qt::white);
               ui->widget->xAxis->setLabelColor(Qt::white);

               // prepare y axis:
               ui->widget->yAxis->setRange(0,4);
               ui->widget->yAxis->setPadding(5); // a bit more space to the left border
               ui->widget->yAxis->setLabel("Nombre Des Clients");
               ui->widget->yAxis->setBasePen(QPen(Qt::white));
               ui->widget->yAxis->setTickPen(QPen(Qt::white));
               ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
               ui->widget->yAxis->grid()->setSubGridVisible(true);
               ui->widget->yAxis->setTickLabelColor(Qt::white);
               ui->widget->yAxis->setLabelColor(Qt::white);
               ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
               ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

               // Add data:

               regen->setData(ticks, regenData);

               // setup legend:
               ui->widget->legend->setVisible(true);
               ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
               ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
               ui->widget->legend->setBorderPen(Qt::NoPen);
               QFont legendFont = font();
               legendFont.setPointSize(5);
               ui->widget->legend->setFont(legendFont);
               ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

statevaluation::~statevaluation()
{
    delete ui;
}
