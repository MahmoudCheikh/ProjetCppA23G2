#include <QDebug>
#include "evaluation.h"
#include <QSqlQuery>
#include <QVariant>
#include <QTableView>
#include <QSqlTableModel>

Evaluation::Evaluation(){}


Evaluation::Evaluation(int ID_NOTE){this->ID_NOTE = ID_NOTE;}

Evaluation::Evaluation(QString NOM_CLIENT,int NOTE_CLIENT ,QString REMARQUE_CLIENT,int ID_FACTURE)
{
    this->ID_NOTE = lastId();
    this->NOM_CLIENT = NOM_CLIENT;
    this->NOTE_CLIENT =NOTE_CLIENT;
    this->REMARQUE_CLIENT = REMARQUE_CLIENT;
    this->ID_FACTURE = ID_FACTURE;

}
    int Evaluation::getID_NOTE(){return this->ID_NOTE;}
    QString Evaluation::getNOM_CLIENT(){return this->NOM_CLIENT;}
    int Evaluation::getNOTE_CLIENT(){return this->NOTE_CLIENT;}
    QString Evaluation::getREMARQUE_CLIENT(){return this->REMARQUE_CLIENT;}
    int Evaluation::getID_FACTURE(){return this->ID_FACTURE;}


    void Evaluation::setID_NOTE(int ID_NOTE){this->ID_NOTE = ID_NOTE;};
    void Evaluation::setNOM_CLIENT(QString NOM_CLIENT){this->NOM_CLIENT = NOM_CLIENT;}
    void Evaluation::setNOTE_CLIENT(int NOTE_CLIENT){this->NOTE_CLIENT = NOTE_CLIENT;}
    void Evaluation::setREMARQUE_CLIENT(QString REMARQUE_CLIENT){this->REMARQUE_CLIENT = REMARQUE_CLIENT;}
    void Evaluation::setID_FACTURE(int ID_FACTURE){this->ID_FACTURE =ID_FACTURE;}

    int Evaluation::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_NOTE from EVALUATION");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool Evaluation::ajouter(){
        QSqlQuery query;
        int l=lastId();

        QString stringInt = QString::number(this->ID_NOTE);

        query.prepare("INSERT INTO EVALUATION VALUES (?, ?, ?, ? , ?)");
        query.addBindValue(l);
        query.addBindValue(this->NOM_CLIENT);

        stringInt = QString::number(this->NOTE_CLIENT);
        query.addBindValue(stringInt);
        query.addBindValue(this->REMARQUE_CLIENT);



        stringInt = QString::number(this->ID_FACTURE);
        qDebug() << stringInt;
        query.addBindValue(stringInt);

        return query.exec();
}

    int Evaluation::check() // check befor delete
    {
        int res1=getID_NOTE();
     QString res2 = QString::number(res1);
        QSqlQuery query;

        query.prepare("select * from EVALUATION where ID_NOTE =:ID_NOTE");
        query.bindValue(":ID_NOTE",res2);


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

    bool Evaluation::supprimer(int ID_NOTE){
        QSqlQuery query;
        QString stringId = QString::number(ID_NOTE);

        query.prepare("DELETE FROM EVALUATION WHERE ID_NOTE=?");
        query.addBindValue(stringId);

        return query.exec();
    }

    bool Evaluation::update()
    {
        QString res=QString::number(ID_NOTE);
        QString res1= QString(NOM_CLIENT);
        QString res2= QString::number(NOTE_CLIENT);
        QString res3= QString(REMARQUE_CLIENT);
        QString res4= QString::number(ID_FACTURE);
        QSqlQuery edit;


                          edit.prepare("update EVALUATION set NOM_CLIENT = :NOM_CLIENT, NOTE_CLIENT = :NOTE_CLIENT , REMARQUE_CLIENT = :REMARQUE_CLIENT , ID_FACTURE = :ID_FACTURE    WHERE ID_NOTE = :ID_NOTE");

                          edit.bindValue(":ID_NOTE",res);
                          edit.bindValue(":NOM_CLIENT",res1);
                          edit.bindValue(":NOTE_CLIENT",res2);
                          edit.bindValue(":REMARQUE_CLIENT",res3);
                          edit.bindValue(":ID_FACTURE",res4);

                          return    edit.exec();
    }

    int Evaluation::checkH() // check if it exsits or not  par id
    {
        int res=getID_NOTE();
     QString res2 = QString::number(res);
        QSqlQuery query;

        query.prepare("select * from EVALUATION where ID_NOTE =:ID_NOTE");
        query.bindValue(":ID_NOTE",res2);


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



QSqlQueryModel * Evaluation::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from EVALUATION");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_NOTE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOTE_CLIENT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("REMARQUE_CLIENT"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_FACTURE"));
  return model;
    }


QSqlQueryModel * Evaluation::rechercher3(const QString &ID_NOTE)
{
    QSqlQueryModel * model = new QSqlQueryModel();



    model->setQuery("select * from EVALUATION where ((ID_NOTE ) LIKE '%"+ID_NOTE+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_NOTE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOTE_CLIENT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("REMARQUE_CLIENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_FACTURE"));


    return model;
}

QSqlQueryModel * Evaluation::rechercher2(const QString &NOM_CLIENT)
{
    QSqlQueryModel * model = new QSqlQueryModel();



    model->setQuery("select * from EVALUATION where ((NOM_CLIENT ) LIKE '%"+NOM_CLIENT+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_NOTE"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_CLIENT"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOTE_CLIENT"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("REMARQUE_CLIENT"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("ID_FACTURE"));


    return model;
}

void Evaluation::rechercher1(QTableView* table,int NOTE_CLIENT){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from EVALUATION where NOTE_CLIENT=:NOTE_CLIENT");
    query->bindValue(":NOTE_CLIENT",NOTE_CLIENT);
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}

void Evaluation::tri1(QTableView *table){}


void Evaluation::tri2(QTableView *table){
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from EVALUATION  ORDER BY ID_NOTE DESC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}

void Evaluation::tri3(QTableView *table){


    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from EVALUATION  ORDER BY NOTE_CLIENT DESC");
    query->exec();
    model->setQuery(*query);
    table->setModel(model);
    table->show();

}
