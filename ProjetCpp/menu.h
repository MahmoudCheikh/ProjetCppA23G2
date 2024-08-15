#ifndef MENU_H
#define MENU_H
#include <QString>
#include <QSqlQueryModel>
#include <QDateEdit>
#include <QTableView>

class menu
{
    int ID_MENU;
    QDate DATE_MENU;
    QString NOM_MENU;
    QString CATEGORIE_MENU;


public:
    menu();
    menu(int);
    menu(QDate,QString,QString);

    int getID_MENU();
    QDate getDATE_MENU();
    QString getNOM_MENU();
    QString getCATEGORIE_MENU();


    void setID_MENU(int);
    void setDATE_MENU(QDate);
    void setNOM_MENU(QString);
    void setCATEGORIE_MENU(QString);


    bool ajouter();
    bool supprimer();
    QSqlQueryModel * afficher();
    bool modifier();
    void recherche(QTableView* table,int n);
    int lastId();
    int check1();
};

#endif // FOURNISSEUR_H
