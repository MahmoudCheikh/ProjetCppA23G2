#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlTableModel>
#include <QTableView>
class Transaction
{
    int ID_FACTURE;
    QString NOM_CLIENT;
    QString  NUM_CLIENT;
    QString ADRESSE_CLIENT;
    QDate DATE_HEURE;
    int PRIX;
    int ID_UTILISATEUR;

public:
    Transaction();
    Transaction(int);
    Transaction(QString , QString , QString , QDate , int , int);

    int getID_FACTURE();
    QString getNOM_CLIENT();
    QString getNUM_CLIENT();
    QString getADRESSE_CLIENT();
    QDate getDATE_HEURE();
    int getPRIX();
    int getID_UTILISATEUR();

    void setID_FACTURE(int);
    void setNOM_CLIENT(QString);
    void setNUM_CLIENT(QString);
    void setADRESSE_CLIENT(QString);
    void setDATE_HEURE(QDate);
    void setPRIX(int);
    void setID_UTILISATEUR(int);

    bool ajouter();
    bool update();
    bool supprimer(int);
    QSqlQueryModel * afficher();

    void trie(QTableView* table);
    void tri1(QTableView* table);
    void tri2(QTableView* table);

    void recherche1(QTableView* table,int);
    void recherche2(QTableView* table,QString);
    void recherche3(QTableView* table,QString);
    int check();
    int checkt();

    int lastId();

};


#endif // TRANSACTION_H
