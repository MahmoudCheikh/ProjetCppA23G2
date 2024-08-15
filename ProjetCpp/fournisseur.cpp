#include "fournisseur.h"
#include <QSqlQuery>
#include <QVariant>

Fournisseur::Fournisseur(){}


Fournisseur::Fournisseur(int id){this->id = id;}

Fournisseur::Fournisseur(QString nom,QString adresse,QString mail,int telephone){
    this->id = lastId();
    this->nom = nom;
    this->mail =mail;
    this->telephone = telephone;
    this->adresse = adresse;
}
    int Fournisseur::getId(){return this->id;}
    QString Fournisseur::getNom(){return this->nom;}
    QString Fournisseur::getAdresse(){return this->adresse;}
    QString Fournisseur::getMail(){return this->mail;}
    int Fournisseur::getTelephone(){return this->telephone;}

    void Fournisseur::setId(int id){this->id = id;};
    void Fournisseur::setNom(QString nom){this->nom = nom;}
    void Fournisseur::setAdresse(QString adresse){this->adresse = adresse;}
    void Fournisseur::setMail(QString mail){this->mail = mail;}
    void Fournisseur::setTelephone(int telephone){this->telephone = telephone;}

    int Fournisseur::lastId(){
        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_FOURNISSEUR from FOURNISSEUR");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    bool Fournisseur::ajouter(){
        QSqlQuery query;

        QString stringTelephone = QString::number(this->telephone);
        QString stringId = QString::number(this->id);

        query.prepare("INSERT INTO FOURNISSEUR VALUES (?, ?, ?, ? , ?)");
        query.addBindValue(stringId);
        query.addBindValue(this->nom);
        query.addBindValue(stringTelephone);
        query.addBindValue(this->adresse);
        query.addBindValue(this->mail);

        return query.exec();
}

    bool Fournisseur::supprimer(){
        QSqlQuery query;
        QString stringId = QString::number(id);

        query.prepare("DELETE FROM FOURNISSEUR WHERE ID_FOURNISSEUR=?");
        query.addBindValue(stringId);

        return query.exec();
    }

    bool Fournisseur::modifier(){
        QSqlQuery query;

        QString stringTelephone = QString::number(this->telephone);
        QString stringId = QString::number(this->id);

        query.prepare("UPDATE FOURNISSEUR SET NOM=?, TELEPHONE=?, ADRESSE=?, MAIL=? WHERE ID_FOURNISSEUR=?");
        query.addBindValue(this->nom);
        query.addBindValue(stringTelephone);
        query.addBindValue(this->adresse);
        query.addBindValue(this->mail);
        query.addBindValue(stringId);

        return query.exec();
    }

QSortFilterProxyModel * Fournisseur::afficher(){
    QSqlQueryModel* model   = new QSqlQueryModel();

    model->setQuery("select * from FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("MAIL"));

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
    proxyModel->setSourceModel(model);
    return proxyModel;
    }


QSortFilterProxyModel * Fournisseur::searchNom(QString f){
            QSqlQueryModel* model   = new QSqlQueryModel();
            QSqlQuery query;
            QString string ="SELECT * FROM FOURNISSEUR WHERE NOM LIKE '"+f + "'";
            model->setQuery(string);
            model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
            model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
            model->setHeaderData(2, Qt::Horizontal,QObject::tr("TELEPHONE"));
            model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal,QObject::tr("MAIL"));
            QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
            proxyModel->setSourceModel(model);
            return proxyModel;
}
QSortFilterProxyModel * Fournisseur::searchTelephone(QString f){
    QSqlQueryModel* model   = new QSqlQueryModel();
    QSqlQuery query;
    QString string ="SELECT * FROM FOURNISSEUR WHERE TELEPHONE LIKE "+f;
    model->setQuery(string);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("MAIL"));
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
    proxyModel->setSourceModel(model);
    return proxyModel;
}
QSortFilterProxyModel * Fournisseur::searchMail(QString f){
    QSqlQueryModel* model   = new QSqlQueryModel();
    QSqlQuery query;
    QString string ="SELECT * FROM FOURNISSEUR WHERE MAIL LIKE '"+f+"'";
    model->setQuery(string);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("MAIL"));
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
    proxyModel->setSourceModel(model);
    return proxyModel;
}
QSortFilterProxyModel * Fournisseur::searchAdresse(QString f){
    QSqlQueryModel* model   = new QSqlQueryModel();
    QSqlQuery query;
    QString string ="SELECT * FROM FOURNISSEUR WHERE ADRESSE LIKE '"+f+"'";
    model->setQuery(string);
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("MAIL"));
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
    proxyModel->setSourceModel(model);
    return proxyModel;
}
