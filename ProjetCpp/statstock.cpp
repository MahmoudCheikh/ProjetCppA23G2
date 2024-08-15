#include "statstock.h"
#include "ui_statstock.h"
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
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSlice>
#include <QtWidgets/QGridLayout>


QT_CHARTS_USE_NAMESPACE
statStock::statStock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statStock)
{
    ui->setupUi(this);


    QPixmap pix1("C:/QTP/ProjetCppA23G2/ProjetCpp/calque 0.png");
    ui->label->setPixmap(pix1);

       // set dark background gradient:
               QLinearGradient gradient(111, 5, 20, 300);
               gradient.setColorAt(0, QColor(115, 15, 20));
               gradient.setColorAt(0.38, QColor(140, 105, 150));
               gradient.setColorAt(1, QColor(150, 300, 12));
               ui->widget->setBackground(QBrush(gradient));

               // create empty bar chart objects:
               QCPBars *regen = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

               regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders


               // set names and colors:

               regen->setName("LES QUANTITÉS DES STOCKS");
               regen->setPen(QPen(QColor(0, 168, 140).lighter(180)));
               regen->setBrush(QColor(0, 168, 140));



               // prepare x axis with country labels:
               QVector<double> ticks;
               QVector<QString> labels;

               QVector<double> regenData;


               ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15;
               QSqlQuery q;

           q.prepare("select CATEGORIE_STOCK ,count(QUANTITE)as somme from STOCKAGE group by CATEGORIE_STOCK ");

               if(q.exec()){
               while (q.next()) {


                labels << q.value(0).toString();

                regenData   << q.value(1).toDouble();

               }}
               QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
               textTicker->addTicks(ticks, labels);

               ui->widget->xAxis->setTicker(textTicker);
               ui->widget->xAxis->setTickLabelRotation(60);
               ui->widget->xAxis->setTickLength(0, 2);
               ui->widget->xAxis->setRange(0, 6);
               ui->widget->xAxis->setLabel("QUANTITE");

               ui->widget->xAxis->setBasePen(QPen(Qt::white));
               ui->widget->xAxis->setTickPen(QPen(Qt::white));
               ui->widget->xAxis->grid()->setVisible(true);
               ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
               ui->widget->xAxis->setTickLabelColor(Qt::white);
               ui->widget->xAxis->setLabelColor(Qt::white);

               // prepare y axis:
               ui->widget->yAxis->setRange(0,1);
               ui->widget->yAxis->setPadding(5); // a bit more space to the left border
               ui->widget->yAxis->setLabel("somme");
               ui->widget->yAxis->setBasePen(QPen(Qt::white));
               ui->widget->yAxis->setTickPen(QPen(Qt::white));
               ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
               ui->widget->yAxis->grid()->setSubGridVisible(true);
               ui->widget->yAxis->setTickLabelColor(Qt::white);
               ui->widget->yAxis->setLabelColor(Qt::white);
               ui->widget->yAxis->grid()->setPen(QPen(QColor(5, 5, 5), 0, Qt::SolidLine));
               ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(300, 300, 320), 0, Qt::DotLine));

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

statStock::~statStock()
{
    delete ui;
}
