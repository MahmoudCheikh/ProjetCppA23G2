#include <QDebug>
#include "transaction.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDate>
#include <QTableView>
#include <QSqlTableModel>

//PDF
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

Transaction::Transaction(){}


Transaction::Transaction(int ID_FACTURE){this->ID_FACTURE = ID_FACTURE;}

Transaction::Transaction(QString NOM_CLIENT,QString NUM_CLIENT ,QString ADRESSE_CLIENT,QDate DATE_HEURE,int PRIX,int ID_UTILISATEUR)
{
    this->ID_FACTURE = lastId();
    this->NOM_CLIENT = NOM_CLIENT;
    this->NUM_CLIENT =NUM_CLIENT;
    this->ADRESSE_CLIENT = ADRESSE_CLIENT;
    this->DATE_HEURE = DATE_HEURE;
    this->PRIX = PRIX;
    this->ID_UTILISATEUR = ID_UTILISATEUR;
}
    int Transaction::getID_FACTURE(){return this->ID_FACTURE;}
    QString Transaction::getNOM_CLIENT(){return this->NOM_CLIENT;}
    QString Transaction::getNUM_CLIENT(){return this->NUM_CLIENT;}
    QString Transaction::getADRESSE_CLIENT(){return this->ADRESSE_CLIENT;}
    QDate Transaction::getDATE_HEURE(){return this->DATE_HEURE;}
    int Transaction::getPRIX(){return this->PRIX;}
    int Transaction::getID_UTILISATEUR(){return this->ID_UTILISATEUR;}


    void Transaction::setID_FACTURE(int ID_FACTURE){this->ID_FACTURE = ID_FACTURE;};
    void Transaction::setNOM_CLIENT(QString NOM_CLIENT){this->NOM_CLIENT = NOM_CLIENT;}
    void Transaction::setNUM_CLIENT(QString NUM_CLIENT){this->NUM_CLIENT = NUM_CLIENT;}
    void Transaction::setADRESSE_CLIENT(QString ADRESSE_CLIENT){this->ADRESSE_CLIENT = ADRESSE_CLIENT;}
    void Transaction::setDATE_HEURE(QDate DATE_HEURE){this->DATE_HEURE = DATE_HEURE;}
    void Transaction::setPRIX(int PRIX){this->PRIX = PRIX;}
    void Transaction::setID_UTILISATEUR(int ID_UTILISATEUR){this->ID_UTILISATEUR =ID_UTILISATEUR;}

    int Transaction::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_FACTURE from TRANSACTION");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool Transaction::ajouter(){
        QSqlQuery query;
        int l=lastId();

        QString stringInt = QString::number(this->ID_FACTURE);

        query.prepare("INSERT INTO TRANSACTION VALUES (?, ?, ?, ? , ?, ?, ?)");
        query.addBindValue(l);
        query.addBindValue(this->NOM_CLIENT);

        query.addBindValue(this->NUM_CLIENT);


        query.addBindValue(this->ADRESSE_CLIENT);
        query.addBindValue(this->DATE_HEURE);

        stringInt = QString::number(this->PRIX);
        query.addBindValue(stringInt);

        stringInt = QString::number(this->ID_UTILISATEUR);
        qDebug() << stringInt;
        query.addBindValue(stringInt);

        return query.exec();
}

    int Transaction::check() // check befor delete
    {
        int res1=getID_FACTURE();
     QString res2 = QString::number(res1);
        QSqlQuery query;

        query.prepare("select * from TRANSACTION where ID_FACTURE =:ID_FACTURE");
        query.bindValue(":ID_FACTURE",res2);


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
        else{
            return 2;
        }
    }

    bool Transaction::supprimer(int ID_FACTURE){
        QSqlQuery query;
        QString stringId = QString::number(ID_FACTURE);

        query.prepare("DELETE FROM TRANSACTION WHERE ID_FACTURE=?");
        query.addBindValue(stringId);

        return query.exec();
    }

    bool Transaction::update()
    {
       /* QString res=QString::number(ID_FACTURE);
        QString res1= QString(NOM_CLIENT);
        QString res2= QString(NUM_CLIENT);
        QString res3= QString(ADRESSE_CLIENT);
        QDate res4= QDate(DATE_HEURE);
        QString res5= QString::number(PRIX);
        QString res6= QString::number(ID_UTILISATEUR);
        QSqlQuery edit;


                          edit.prepare("update TRANSACTION set NOM_CLIENT = :NOM_CLIENT, NUM_CLIENT = :NUM_CLIENT , ADRESSE_CLIENT = :ADRESSE_CLIENT , DATE_HEURE = :DATE_HEURE , PRIX = :PRIX , ID_UTILISATEUR = :ID_UTILISATEUR   WHERE ID_FACTURE = :ID_FACTURE");

                          edit.bindValue(":ID_FACTURE",res);
                          edit.bindValue(":NOM_CLIENT",res1);
                          edit.bindValue(":NUM_CLIENT",res2);
                          edit.bindValue(":ADRESSE_CLIENT",res3);
                          edit.bindValue(":DATE_HEURE",res4);
                          edit.bindValue(":PRIX",res5);
                          edit.bindValue(":ID_UTILISATEUR",res6);

                          return    edit.exec();
                          */

        QString res=QString::number(ID_FACTURE);
                QString res1= QString(NOM_CLIENT);
                QString res2= QString(NUM_CLIENT);
                QString res3= QString(ADRESSE_CLIENT);
                QDate res4= QDate(DATE_HEURE);
                QString res5= QString::number(PRIX);
                QString res6= QString::number(ID_UTILISATEUR);
                QSqlQuery edit;



                edit.prepare("update TRANSACTION set NOM_CLIENT = :NOM_CLIENT, NUM_CLIENT = :NUM_CLIENT , ADRESSE_CLIENT = :ADRESSE_CLIENT , DATE_HEURE = :DATE_HEURE , PRIX = :PRIX , ID_UTILISATEUR = :ID_UTILISATEUR   WHERE ID_FACTURE = :ID_FACTURE");

                edit.bindValue(":ID_FACTURE",res);
                edit.bindValue(":NOM_CLIENT",res1);
                edit.bindValue(":NUM_CLIENT",res2);
                edit.bindValue(":ADRESSE_CLIENT",res3);
                edit.bindValue(":DATE_HEURE",res4);
                edit.bindValue(":PRIX",res5);
                edit.bindValue(":ID_UTILISATEUR",res6);


                                 return    edit.exec();

    }


    int Transaction::checkt() // check if it exsits or not  par id
    {
        int res=getID_FACTURE();
     QString res2 = QString::number(res);
        QSqlQuery query;

        query.prepare("select * from TRANSACTION where ID_FACTURE =:ID_FACTURE");
        query.bindValue(":ID_FACTURE",res2);


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
        else{
            return 2;
        }}



QSqlQueryModel * Transaction::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from TRANSACTION");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FACTURE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("NUM_CLIENT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE_CLIENT"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_HEURE"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("ID_UTILISATEUR"));
  return model;
    }


void Transaction::trie(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TRANSACTION  ORDER BY PRIX ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void Transaction::tri1(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TRANSACTION  ORDER BY DATE_HEURE DESC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void Transaction::tri2(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TRANSACTION  ORDER BY ID_FACTURE DESC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}




void Transaction::recherche1(QTableView* table,int spec){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TRANSACTION  where ID_FACTURE=:ID_FACTURE");
    query->bindValue(":ID_FACTURE",spec);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void Transaction::recherche2(QTableView* table,QString spec)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TRANSACTION  where NOM_CLIENT=:NOM_CLIENT");
    query->bindValue(":NOM_CLIENT",spec);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void Transaction::recherche3(QTableView* table,QString spec){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from TRANSACTION  where ADRESSE_CLIENT=:ADRESSE_CLIENT");
    query->bindValue(":ADRESSE_CLIENT",spec);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
