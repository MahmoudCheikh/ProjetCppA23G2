#include "commandefournisseur.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>


CommandeFournisseur::CommandeFournisseur(){}
CommandeFournisseur::CommandeFournisseur(int id){this->idCommande = id;}

    CommandeFournisseur::CommandeFournisseur(int idFournisseur,int idProduit,int quantite,QString dateEnvoi,QString dateReception){
        this->idCommande= lastId();
        this->idFournisseur = idFournisseur;
        this->idProduit= idProduit;
        this->quantite = quantite;
        this->dateEnvoi = dateEnvoi;
        this->dateReception = dateReception;
    }

    int CommandeFournisseur::getidCommande(){return this->idCommande;}
    int CommandeFournisseur::getidFournisseur(){return this->idFournisseur;}
    int CommandeFournisseur::getidProduit(){return this->idProduit;}
    int CommandeFournisseur::getquantite(){return this->quantite;}
    QString CommandeFournisseur::getdateEnvoi(){return this->dateEnvoi;}
    QString CommandeFournisseur::getdateReception(){return this->dateReception;}

    void CommandeFournisseur::setidCommande(int idCommande){this->idCommande = idCommande;}
    void CommandeFournisseur::setidFournisseur(int idFournisseur){this->idFournisseur = idFournisseur;}
    void CommandeFournisseur::setidProduit(int idProduit){this->idProduit = idProduit;}
    void CommandeFournisseur::setquantite(int quantite){this->quantite = quantite;}
    void CommandeFournisseur::setdateEnvoi(QString dateEnvoi){this->dateEnvoi = dateEnvoi;}
    void CommandeFournisseur::setdateReception(QString dateReception){this->dateReception = dateReception;}

    bool CommandeFournisseur::ajouter(){
        QSqlQuery query;

        QString stringIdCommande = QString::number(this->idCommande);
        QString stringIdFournisseur = QString::number(this->idFournisseur);
        QString stringIdProduit = QString::number(this->idProduit);
        QString stringQuantite = QString::number(this->quantite);



        query.prepare("INSERT INTO COMMANDE_FOURNISSEUR VALUES (?,?,?,?,?,?)");
        query.addBindValue(stringIdCommande);
        query.addBindValue(stringIdFournisseur);
        query.addBindValue(stringIdProduit);
        query.addBindValue(stringQuantite);
        query.addBindValue(this->dateEnvoi);
        query.addBindValue(this->dateReception);

        return query.exec();
    }
    bool CommandeFournisseur::supprimer(){
        QSqlQuery query;
        QString stringId = QString::number(this->idCommande);
qDebug() << stringId;
        query.prepare("DELETE FROM COMMANDE_FOURNISSEUR WHERE ID_COMMANDE=?");
        query.addBindValue(stringId);

        return query.exec();
    }
    bool CommandeFournisseur::modifier(){
        QSqlQuery query;


        QString stringIdCommande = QString::number(this->idCommande);
        QString stringIdFournisseur = QString::number(this->idFournisseur);
        QString stringIdProduit = QString::number(this->idProduit);
        QString stringQuantite = QString::number(this->quantite);
        query.prepare("UPDATE COMMANDE_FOURNISSEUR SET ID_FOURNISSEUR=?, ID_PRODUIT=?, QUANTITE=?, DATE_ENVOI=? ,DATE_RECEPTION=?  WHERE ID_COMMANDE=?");

        query.addBindValue(stringIdFournisseur);
        query.addBindValue(stringIdProduit);
        query.addBindValue(stringQuantite);
        query.addBindValue(this->dateEnvoi);
        query.addBindValue(this->dateReception);
        query.addBindValue(stringIdCommande);
        return query.exec();
    }

    QSortFilterProxyModel * CommandeFournisseur::afficher(){
        QSqlQueryModel* model   = new QSqlQueryModel();

        model->setQuery("select * from COMMANDE_FOURNISSEUR");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_COMMANDE"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("QUANTITE"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_ENVOI"));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("DATE_RECEPTION"));

        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
        proxyModel->setSourceModel(model);
        return proxyModel;
    }

    int CommandeFournisseur::lastId(){

        int lastId = 0;
        QSqlQuery qry3 ;
        qry3.prepare("select ID_COMMANDE from COMMANDE_FOURNISSEUR");
        if (qry3.exec()){
            while(qry3.next()){
            lastId = qry3.value(0).toInt();}
        }
        return lastId+1;
    }


    QSortFilterProxyModel * CommandeFournisseur::searchP(int f){
        QSqlQueryModel* model   = new QSqlQueryModel();
                QSqlQuery query;
                QString string ="SELECT * FROM COMMANDE_FOURNISSEUR WHERE ID_PRODUIT="+QString::number(f);
                model->setQuery(string);

                model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_COMMANDE"));
                model->setHeaderData(1, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
                model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
                model->setHeaderData(3, Qt::Horizontal,QObject::tr("QUANTITE"));
                model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_ENVOI"));
                model->setHeaderData(5, Qt::Horizontal,QObject::tr("DATE_RECEPTION"));
                QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
                proxyModel->setSourceModel(model);
                return proxyModel;

    }
    QSortFilterProxyModel * CommandeFournisseur::searchF(int f){
        QSqlQueryModel* model   = new QSqlQueryModel();
                QSqlQuery query;
                QString string ="SELECT * FROM COMMANDE_FOURNISSEUR WHERE ID_FOURNISSEUR="+QString::number(f);
                model->setQuery(string);

                model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID_COMMANDE"));
                model->setHeaderData(1, Qt::Horizontal,QObject::tr("ID_FOURNISSEUR"));
                model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID_PRODUIT"));
                model->setHeaderData(3, Qt::Horizontal,QObject::tr("QUANTITE"));
                model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_ENVOI"));
                model->setHeaderData(5, Qt::Horizontal,QObject::tr("DATE_RECEPTION"));
                QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(model);
                proxyModel->setSourceModel(model);
                return proxyModel;

    }
