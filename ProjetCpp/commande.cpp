#include "commande.h"
#include "table.h"
#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QObject>
#include<QSqlRecord>
#include<QDebug>
#include<QString>
#include<QObject>
#include <QFile>

Commande::Commande()
{

}
 void Commande:: setID_COMMANDE(int n){ID_COMMANDE=n;}
void Commande:: setQUANTITE(int n){QUANTITE=n;}
void Commande:: setLIBELLE(QString n){LIBELLE=n;}
void Commande:: setDESCRIPTION(QString n){DESCRIPTION=n;}
void Commande :: setPRIX(float n){PRIX=n;}
void Commande :: setNUM_TABLE(int n){NUM_TABLE=n;}

int Commande::get_ID_COMMANDE(){return this->ID_COMMANDE;}
int Commande:: get_QUANTITE(){return this->QUANTITE;}
QString Commande:: get_LIBELLE(){return this->LIBELLE;}
QString  Commande:: get_DESCRIPTION(){return this->DESCRIPTION;}
float Commande:: get_PRIX(){return this->PRIX;}
int Commande::get_NUM_TABLE(){return this->NUM_TABLE;}
Commande::Commande(int ID_COMMANDE){this->ID_COMMANDE = ID_COMMANDE;}

Commande::Commande(int ID_COMMANDE,int QUANTITE,QString LIBELLE,QString DESCRIPTION,float PRIX,int NUM_TABLE){

    this->ID_COMMANDE=ID_COMMANDE;
    this->QUANTITE =QUANTITE;
     this->LIBELLE =LIBELLE;
    this->DESCRIPTION = DESCRIPTION;
    this->PRIX = PRIX;
     this->NUM_TABLE = NUM_TABLE;

}
 bool Commande ::ajouter(){
     QSqlQuery query;
  QString stringInt = QString::number(this->NUM_TABLE);
     query.prepare("INSERT INTO COMMANDE VALUES (?,?,?,?,?,?)");
 QString id = QString::number(this->ID_COMMANDE);
 QString prix = QString::number(this->PRIX);



    query.addBindValue(id);
      query.addBindValue(this->QUANTITE);
       query.addBindValue(this->LIBELLE);
       query.addBindValue(this->DESCRIPTION);
      query.addBindValue(prix);
       query.addBindValue(this->NUM_TABLE);
       //query.addBindValue(stringInt);
       qDebug() << id << prix ;
       return query.exec();
}
QSqlQueryModel *Commande::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from COMMANDE");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_COMMANDE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("LIBELLE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("PRIX (DT)"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("NUM_TABLE"));

return model;
    }
bool Commande::supprimer(int ID_COMMANDE){
        QSqlQuery query;
        query.prepare("DELETE FROM COMMANDE WHERE ID_COMMANDE=?");
        query.addBindValue(ID_COMMANDE);
        return query.exec();
    }

bool Commande ::modifier()
    {
        QString res1 = QString::number(ID_COMMANDE);
       QString res2 = QString::number(QUANTITE);
        QString res3= QString(LIBELLE);
        QString res4= QString(DESCRIPTION);
     QString res5 = QString::number(PRIX);
      QString res6 = QString::number(NUM_TABLE);

        QSqlQuery edit;


                          edit.prepare("update COMMANDE set ID_COMMANDE=:ID_COMMANDE, QUANTITE=:QUANTITE , LIBELLE=:LIBELLE , DESCRIPTION=:DESCRIPTION ,PRIX=:PRIX ,NUM_TABLE=:NUM_TABLE   WHERE ID_COMMANDE=:ID_COMMANDE");
                          edit.bindValue(":ID_COMMANDE",res1);
                          edit.bindValue(":QUANTITE",res2);
                          edit.bindValue(":LIBELLE",res3);
                          edit.bindValue(":DESCRIPTION",res4);
                          edit.bindValue(":PRIX",res5);
                          edit.bindValue(":NUM_TABLE",res6);

                          return    edit.exec();
}
int Commande::check() // check if it exsits or not  par id
{
    int res1=get_ID_COMMANDE();
 QString res2 = QString::number(res1);
    QSqlQuery query;

    query.prepare("select * from COMMANDE where ID_COMMANDE =:ID_COMMANDE");
    query.bindValue(":ID_COMMANDE",res2);


    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 1) {
        return 0;
    }
   else
        return 1;
  }
int Commande::checkL() // check if it exsits or not  par id
{
    QString res1=get_LIBELLE();

    QSqlQuery query;

    query.prepare("select * from COMMANDE where LIBELLE =:LIBELLE");
    query.bindValue(":LIBELLE",res1);


    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user >= 1) {
        return 0;
    }


    }
int Commande::check_tab() //
{
    int res1=get_NUM_TABLE();
 QString res2 = QString::number(res1);
    QSqlQuery query;

    query.prepare("select * from COMMANDE where NUM_TABLE =:NUM_TABLE");
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
/*int Commande::check_tabcom() //
{
    int res1=get_NUM_TABLE();
 QString res2 = QString::number(res1);
    QSqlQuery query;

    query.prepare("SELECT NUM_TABLE from COMMANDE  INNER JOIN  TABLES   ON COMMANDE.NUM_TABLE=:TABLES.NUM_TABLE");
    query.bindValue(":COMMANDE.NUM_TABLE",res2);


    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 0) {
        return 0;
    }
    else if (count_user >= 1 ) {
        return 1;
    }
    else{
        return 2;
    }}*/
void Commande::recherche(QTableView* table,int ID_COMMANDE)//CHERCHER PAR ID COMMANDE
{
 QSqlQueryModel *model= new QSqlQueryModel();
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from COMMANDE  where ID_COMMANDE=:ID_COMMANDE");
   query->bindValue(":ID_COMMANDE",ID_COMMANDE);
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();}
void Commande::rechercheL(QTableView* table,QString LIBELLE)//CHERCHER PAR LIBELLE
{
 QSqlQueryModel *model= new QSqlQueryModel();
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from COMMANDE  where LIBELLE=:LIBELLE");
   query->bindValue(":LIBELLE",LIBELLE);
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();}
void Commande::rechercheTAB(QTableView* table,int NUM_TABLE)//CHERCHER PAR LIBELLE
{
 QSqlQueryModel *model= new QSqlQueryModel();
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from COMMANDE  where NUM_TABLE=:NUM_TABLE");
   query->bindValue(":NUM_TABLE",NUM_TABLE);
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();}
void Commande::tri_ID(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from COMMANDE ORDER BY ID_COMMANDE ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void Commande::tri_LIBELLE(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from COMMANDE  ORDER BY LIBELLE ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void Commande::tri_P(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from COMMANDE  ORDER BY PRIX ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
