#include "produit.h"
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>

produit::produit(){}


produit::produit(int ID_PRODUIT){this->ID_PRODUIT = ID_PRODUIT;}


produit::produit(QString NOM_PRODUIT,QString CATEGORIE_PRODUIT){
    this->ID_PRODUIT = lastId();
    this->NOM_PRODUIT = NOM_PRODUIT;
    this->CATEGORIE_PRODUIT =CATEGORIE_PRODUIT;

}

    int produit::getID_PRODUIT(){return this->ID_PRODUIT;}
    QString produit::getNOM_PRODUIT(){return this->NOM_PRODUIT;}
    QString produit::getCATEGORIE_PRODUIT(){return this->CATEGORIE_PRODUIT;}


    void produit::setID_PRODUIT(int ID_PRODUIT){this->ID_PRODUIT = ID_PRODUIT;};
    void produit::setNOM_PRODUIT(QString NOM_PRODUIT){this->NOM_PRODUIT = NOM_PRODUIT;}
    void produit::setCATEGORIE_PRODUIT(QString CATEGORIE_PRODUIT){this->CATEGORIE_PRODUIT = CATEGORIE_PRODUIT;}


    int produit::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_PRODUIT from PRODUIT");
        if (qry3.exec())
        {
            while(qry3.next())
            {
            lastId = qry3.value(0).toInt();
            }
         }
        return lastId+1;
    }


    bool produit::ajouter(){
        QSqlQuery query;

        int l=lastId();
        QString stringId = QString::number(this->ID_PRODUIT);

        query.prepare("INSERT INTO PRODUIT (ID_PRODUIT,NOM_PRODUIT,CATEGORIE_PRODUIT) VALUES (?, ?, ?)");
        query.addBindValue(l);
        query.addBindValue(this->NOM_PRODUIT);
        query.addBindValue(this->CATEGORIE_PRODUIT);


        return query.exec();
}

    bool produit::supprimer(int ID_PRODUIT){
        QSqlQuery query;
        QString stringId = QString::number(ID_PRODUIT);

        query.prepare("DELETE FROM PRODUIT WHERE ID_PRODUIT=?");
        query.addBindValue(stringId);

        return query.exec();
    }

QSqlQueryModel * produit::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from PRODUIT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_PRDUIT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("CATEGORIE_PRODUIT"));


    return model;
    }




bool produit::update()
{
    QString res=QString::number(ID_PRODUIT);
    QString res1= QString(NOM_PRODUIT);
    QString res2= QString(CATEGORIE_PRODUIT);
    QSqlQuery edit;


                      edit.prepare("update PRODUIT set NOM_PRODUIT = :NOM_PRODUIT, CATEGORIE_PRODUIT = :CATEGORIE_PRODUIT WHERE ID_PRODUIT = :ID_PRODUIT");

                      edit.bindValue(":ID_PRODUIT",res);
                      edit.bindValue(":NOM_PRODUIT",res1);
                      edit.bindValue(":CATEGORIE_PRODUIT",res2);
                      return    edit.exec();
}
void produit::rechercher(QTableView *table, QString NOM_PRODUIT){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PRODUIT where NOM_PRODUIT='"+NOM_PRODUIT+"'");
    query->bindValue(":NOM_PRODUIT",NOM_PRODUIT);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

QSqlQueryModel * produit::rechercher_cr1(const QString &NOM_PRODUIT)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from PRODUIT where ((NOM_PRODUIT ) LIKE '%"+NOM_PRODUIT+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("CATEGORIE_PRODUIT"));


    return model;
}
QSqlQueryModel * produit::rechercher_cr2(const QString &CATEGORIE_PRODUIT)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from PRODUIT where ((CATEGORIE_PRODUIT ) LIKE '%"+CATEGORIE_PRODUIT+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("CATEGORIE_PRODUIT"));


    return model;
}

void produit::rechercher_cr3(QTableView* table,int num1){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PRODUIT  where ID_PRODUIT=:ID_PRODUIT");
    query->bindValue(":ID_PRODUIT",num1);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
void produit::tri(QTableView* table){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PRODUIT  ORDER BY ID_PRODUIT ");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void produit::tri1(QTableView* table){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PRODUIT  ORDER BY CATEGORIE_PRODUIT ");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

void produit::tri2(QTableView* table){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PRODUIT  ORDER BY NOM_PRODUIT ");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}

int produit::check() // check befor delete
{
    int res1=getID_PRODUIT();
 QString res2 = QString::number(res1);
    QSqlQuery query;

    query.prepare("select * from PRODUIT where ID_PRODUIT =:ID_PRODUIT");
    query.bindValue(":ID_PRODUIT",res2);


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
