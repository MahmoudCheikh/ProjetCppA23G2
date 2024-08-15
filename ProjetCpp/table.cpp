#include "table.h"
#include <iostream>
#include<QtWidgets>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QObject>

#include <QThread>
QT_CHARTS_USE_NAMESPACE
using namespace  std;

Table::Table()
{

}
void Table :: setNUM_TABLE(int n){NUM_TABLE=n;}
void Table:: setNB_CHAISES(int n){NB_CHAISES=n;}
void Table:: setEMPLACEMENT(QString n){EMPLACEMENT=n;}
void Table:: setDISPONIBILITE(QString n){DISPONIBILITE=n;}
void Table :: setDEBARRASSAGE(int n){DEBARRASSAGE=n;}
int Table::get_NUM_TABLE(){return this->NUM_TABLE;}
int Table:: get_NB_CHAISES(){return this->NB_CHAISES;}
QString Table:: get_EMPLACEMENT(){return this->EMPLACEMENT;}
QString Table:: get_DISPONIBILITE(){return this->DISPONIBILITE;}
int Table:: get_DEBARRASSAGE(){return this->DEBARRASSAGE;}
Table::Table(int NUM_TABLE){this->NUM_TABLE = NUM_TABLE;}

Table::Table(int NUM_TABLE,int NB_CHAISES,QString EMPLACEMENT,QString DISPONIBILITE,int DEBARRASSAGE){
    this->NUM_TABLE = NUM_TABLE;
    this->NB_CHAISES =NB_CHAISES;
    this->EMPLACEMENT =EMPLACEMENT;
    this->DISPONIBILITE = DISPONIBILITE;
    this->DEBARRASSAGE = DEBARRASSAGE;

}

/*int Table::lastId(){
        int lastId = 1;
        QSqlQuery qry3 ;
        qry3.prepare("select NUM_TABLE from TABLES");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;}*/
bool Table::ajouter(){
    QSqlQuery query;
   // int l=lastId();
     /*  QString num= QString ::number(NUM_TABLE).*/
    query.prepare("INSERT INTO TABLES VALUES (?, ?, ?, ?,?)");
    query.addBindValue(this->NUM_TABLE);
    query.addBindValue(this->NB_CHAISES);
    query.addBindValue(this->EMPLACEMENT);
    query.addBindValue(this->DISPONIBILITE);
    query.addBindValue(this->DEBARRASSAGE);


    return query.exec();
}
QSqlQueryModel * Table::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from TABLES");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NUM_TABLE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NB_CHAISES"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("EMPLACEMENT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("DEBARRASSAGE"));

return model;
    }

bool Table::supprimer(int NUM_TABLE){
        QSqlQuery query;
        query.prepare("DELETE FROM TABLES WHERE NUM_TABLE=?");
        query.addBindValue(NUM_TABLE);
        return query.exec();
    }
bool Table ::modifier()
    {
     QString res1 = QString::number(NUM_TABLE);
       QString  res2= QString::number(NB_CHAISES);
        QString res3= QString(EMPLACEMENT);
        QString res4= QString(DISPONIBILITE);
      QString res5 = QString::number(DEBARRASSAGE);

        QSqlQuery edit;


                          edit.prepare("update TABLES set NUM_TABLE=:NUM_TABLE, NB_CHAISES=:NB_CHAISES , EMPLACEMENT=:EMPLACEMENT , DISPONIBILITE=:DISPONIBILITE ,DEBARRASSAGE=:DEBARRASSAGE   WHERE NUM_TABLE=:NUM_TABLE");

                          edit.bindValue(":NUM_TABLE",res1);
                          edit.bindValue(":NB_CHAISES",res2);
                          edit.bindValue(":EMPLACEMENT",res3);
                          edit.bindValue(":DISPONIBILITE",res4);
                          edit.bindValue(":DEBARRASSAGE",res5);

                          return    edit.exec();
    }
int Table::check() // check if it exsits or not  par id
{
    int res1=get_NUM_TABLE();
 QString res2 = QString::number(res1);
    QSqlQuery query;

    query.prepare("select * from TABLES where NUM_TABLE =:NUM_TABLE");
    query.bindValue(":NUM_TABLE",res2);


    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 1) {
        return 0;
    }
    else if (count_user > 1 ) {
        return 1;
    }
}
int Table::check1() // check if it exsits or not  par id
{
    int res1=get_NB_CHAISES();
 QString res2 = QString::number(res1);
    QSqlQuery query;

    query.prepare("select * from TABLES where NB_CHAISES=:NB_CHAISES");
    query.bindValue(":NB_CHAISES",res2);


    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 1) {
        return 0;
    }
    else if (count_user > 1 ) {
        return 1;
    }
}
 void Table::recherche(QTableView* table,int NUM_TABLE)//recherche table PAR SON NUM
 {
  QSqlQueryModel *model= new QSqlQueryModel();  //'"+ide+"%'  '"+spec+"'
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TABLES  where NUM_TABLE=:NUM_TABLE");
    query->bindValue(":NUM_TABLE",NUM_TABLE);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();}
 void Table::rechercheC(QTableView* table,int NB_CHAISES)//recherche table PAR NBR CHAISES
 {
  QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
     QString CHAI = QString::number(NB_CHAISES);
    query->prepare("select * from TABLES  where NB_CHAISES=:NB_CHAISES");
    query->bindValue(":NB_CHAISES",CHAI);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();}
 void Table::rechercheD(QTableView* table,int DEBARRASSAGE)//recherche table PAR ETAT debarrassage
 {
  QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    QString DEB = QString::number(DEBARRASSAGE);
    query->prepare("select * from TABLES  where DEBARRASSAGE=:DEBARRASSAGE");

    query->bindValue(":DEBARRASSAGE",DEB);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();}


void Table::tri_Num(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TABLES  ORDER BY NUM_TABLE ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void Table::tri_NB(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TABLES  ORDER BY NB_CHAISES ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void Table::tri_DEB(QTableView* table)// trier selon etat debarrassage
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TABLES  ORDER BY DEBARRASSAGE ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
int Table::lastIDNumtable(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select MAX(NUM_TABLE) from TABLES");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId;
    }

    int Table::lastIDnbchaise(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select MAX(NB_CHAISES) from TABLES");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId;
    }


   QVBoxLayout * Table::stat(){
        int countTABLE = this->lastIDNumtable();
        int countNBCHAISES = this->lastIDnbchaise();
        QStringList categories;
        for (int j = 1;j<= countNBCHAISES;j++) {
            categories << QString::fromStdString(std::to_string(j));
        }
        cout << countTABLE << " " << countNBCHAISES << endl;
         QBarSeries *series = new QBarSeries();
        for (int i=1;i <= countTABLE;i++) {
            std::string s = std::to_string(i);
            QString qstr = QString::fromStdString(s);
            QBarSet *set0 = new QBarSet(qstr);
            for (int j=1;j<= countNBCHAISES;j++) {

                QSqlQuery query;

                QString stringnbchaises = QString::number(j);
                QString stringnumTable = QString::number(i);

                query.prepare("SELECT DEBARRASSAGE FROM TABLES WHERE NUM_TABLE=? AND NB_CHAISES=?");

                query.addBindValue(stringnumTable);
                query.addBindValue(stringnbchaises);

                 query.exec();
                 if(query.next()){
                     *set0 << query.value(0).toUInt();
                 }else{
                     *set0 << 0;
                 }
            }
            series->append(set0);
        }
           QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("Offres prix produit");
           chart->setAnimationOptions(QChart::SeriesAnimations);
           QBarCategoryAxis *axis = new QBarCategoryAxis();
           axis->append(categories);
           chart->createDefaultAxes();
           chart->setAxisX(axis, series);
           chart->legend()->setVisible(true);
           chart->legend()->setAlignment(Qt::AlignBottom);
           QChartView *chartView = new QChartView(chart);
           chartView->setRenderHint(QPainter::Antialiasing);
           QVBoxLayout *mainLayout = new QVBoxLayout;
           mainLayout->addWidget(chartView);
           return mainLayout;

    }
