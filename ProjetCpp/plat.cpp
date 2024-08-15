#include "plat.h"
#include "menu.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QtWidgets>

plat::plat(){}


plat::plat(QString NOM_PLAT){this->NOM_PLAT = NOM_PLAT;}

plat::plat(QString NOM_PLAT,QString INGREDIENTS_PLAT,QString SPECIALITE_PLAT,float PRIX_PLAT,int ID_MENU){
    this->NOM_PLAT = NOM_PLAT;
    this->INGREDIENTS_PLAT = INGREDIENTS_PLAT;
    this->SPECIALITE_PLAT =SPECIALITE_PLAT;
    this->PRIX_PLAT = PRIX_PLAT;
    this->ID_MENU = ID_MENU;

}
    QString plat::getNOM_PLAT(){return this->NOM_PLAT;}
    QString plat::getINGREDIENTS_PLAT(){return this->INGREDIENTS_PLAT;}
    QString plat::getSPECIALITE_PLAT(){return this->SPECIALITE_PLAT;}
    float plat::getPRIX_PLAT(){return this->PRIX_PLAT;}
     int plat::getID_MENU(){return this->ID_MENU;}


    void plat::setNOM_PLAT(QString NOM_PLAT){this->NOM_PLAT = NOM_PLAT;}
     void plat::setINGREDIENTS_PLAT(QString INGREDIENTS_PLAT){this->INGREDIENTS_PLAT = INGREDIENTS_PLAT;}
    void plat::setSPECIALITE_PLAT(QString SPECIALITE_PLAT){this->SPECIALITE_PLAT = SPECIALITE_PLAT;}
    void plat::setPRIX_PLAT(float PRIX_PLAT){this->PRIX_PLAT = PRIX_PLAT;}
    void plat::setID_MENU(int  ID_MENU){this->ID_MENU = ID_MENU;}


    /*int menu::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_MENU from MENU");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }*/


    bool plat::ajouter(){
            QSqlQuery query;
           // int l=lastId();

            QString stringInt = QString::number(this->ID_MENU);

            query.prepare("INSERT INTO PLAT VALUES (?, ?, ?, ? , ?)");
            //query.addBindValue(l);
            query.addBindValue(this->NOM_PLAT);
            query.addBindValue(this->INGREDIENTS_PLAT);
            query.addBindValue(this->SPECIALITE_PLAT);
            stringInt = QString::number(this->PRIX_PLAT);
            query.addBindValue(stringInt);
            stringInt = QString::number(this->ID_MENU);
            qDebug() << stringInt;
            query.addBindValue(stringInt);

            return query.exec();
    }
    bool plat::supprimer(){
        QSqlQuery query;
        query.prepare("DELETE FROM PLAT WHERE NOM_PLAT=?");
        query.addBindValue(NOM_PLAT);
        return query.exec();
    }


QSqlQueryModel * plat::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from PLAT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PLAT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("INGREDIENTS_PLAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SPECIALITE_PLAT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_PLAT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_MENU"));


    return model;
    }
/*bool plat::modifier(){
     QString res=QString(NOM_PLAT);
     QString res1=QString (INGREDIENTS_PLAT);
     QString res2=QString (SPECIALITE_PLAT);
     QString res3=QString::number(PRIX_PLAT);
      QString res4=QString::number(ID_MENU);

        QSqlQuery edit;
edit.prepare("update PLAT set NOM_PLAT =:NOM_PLAT, INGREDIENTS_PLAT =:INGREDIENTS_PLAT, SPECIALITE_PLAT=:SPECIALITE_PLAT,PRIX_PLAT=:PRIX_PLAT,ID_MENU=:ID_MENU where NOM_PLAT =:NOM_PLAT");
                          edit.bindValue(":NOM_PLAT",res);
                          edit.bindValue(":INGREDIENTS_PLAT",res1);
                          edit.bindValue(":SPECIALITE_PLAT",res2);
                          edit.bindValue(":PRIX_PLAT",res3);
                         edit.bindValue(":ID_MENU",res4);
                          return    edit.exec();



}*/
bool plat::modifier()
    {
        QString res1= QString(NOM_PLAT);
        QString res2= QString(INGREDIENTS_PLAT);
        QString res3= QString(SPECIALITE_PLAT);
        QString res4= QString::number(PRIX_PLAT);
        QString res5= QString::number(ID_MENU);

        QSqlQuery edit;


                          edit.prepare("update PLAT set NOM_PLAT=:NOM_PLAT, INGEDIENTS_PLAT=:INGREDIENTS_PLAT , SPECIALITE_PLAT=:SPECIALITE_PLAT , PRIX_PLAT=:PRIX_PLAT ,ID_MENU=:ID_MENU   WHERE NOM_PLAT=:NOM_PLAT");
                          edit.bindValue(":NOM_PLAT",res1);
                          edit.bindValue(":INGREDIENTS_PLAT",res2);
                          edit.bindValue(":SPECIALITE_PLAT",res3);
                          edit.bindValue(":PRIX_PLAT",res4);
                          edit.bindValue(":ID_MENU",res5);

                          return    edit.exec();
    }

void plat::trie(QTableView* table){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PLAT  ORDER BY ID_MENU ASC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void plat::recherche(QTableView* table,QString spec){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PLAT  where SPECIALITE_PLAT='"+spec+"'");
    query->bindValue(":SPECIALITE_PLAT",spec);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
void plat::recherche1(QTableView* table,int spec){

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PLAT  where ID_MENU=:ID_MENU");
    query->bindValue(":ID_MENU",spec);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
QSqlQueryModel * plat::chercher_ut(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from PLAT where ((SPECIALITE_PLAT ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PLAT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("INGREDIENTS_PLAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SPECIALITE_PLAT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_PLAT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_MENU"));

    return model;
}


QSqlQueryModel * plat::chercher_ut1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from PLAT where ((NOM_PLAT ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PLAT"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("INGREDIENTS_PLAT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("SPECIALITE_PLAT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_PLAT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_MENU"));

    return model;
}
void plat::chercher_ut2(QTableView* table,int aux){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PLAT  where ID_MENU=:ID_MENU");
    query->bindValue(":ID_MENU",aux);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
QSqlQueryModel* plat::tri()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from PLAT ORDER BY PRIX_PLAT asc");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PLAT"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("INGREDIENTS_PLAT"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("SPECIALITE_PLAT"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_PLAT"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_MENU"));


    return model;
}

QSqlQueryModel* plat::tri2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from PLAT ORDER BY PRIX_PLAT desc");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PLAT"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("INGREDIENTS_PLAT"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("SPECIALITE_PLAT"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX_PLAT"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_MENU"));


    return model;
}
void plat::tri(QTableView* table){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from PLAT  ORDER BY NOM_PLAT ");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();
}
int plat::check1() // check if it exsits or not  par id
{
    QString res1=getNOM_PLAT();
 QString res2 =QString(res1);
    QSqlQuery query;

    query.prepare("select * from PLAT where NOM_PLAT=:NOM_PLAT");
    query.bindValue(":NOM_PLAT",res2);


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
