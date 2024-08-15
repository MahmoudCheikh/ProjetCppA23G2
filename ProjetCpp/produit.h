#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
class produit
{
    int ID_PRODUIT;
    QString NOM_PRODUIT;
    QString CATEGORIE_PRODUIT;


public:
    produit();
    produit(int);
    produit(QString,QString);

    int getID_PRODUIT();
    QString getNOM_PRODUIT();
    QString getCATEGORIE_PRODUIT();


    void setID_PRODUIT(int);
    void setNOM_PRODUIT(QString);
    void setCATEGORIE_PRODUIT(QString);


    bool ajouter();
    bool supprimer(int);
    bool update();
    QSqlQueryModel * afficher();

    void rechercher(QTableView* table,QString CATEGORIE_PRODUIT);

    QSqlQueryModel * rechercher_cr1(const QString &NOM_PRODUIT);
    QSqlQueryModel * rechercher_cr2(const QString &CATEGORIE_PRODUIT);
    void rechercher_cr3(QTableView* table,int num1);

    void tri(QTableView* table);
    void tri1(QTableView* table);
    void tri2(QTableView* table);
    int check();

    int lastId();

};

#endif // PRODUIT_H
