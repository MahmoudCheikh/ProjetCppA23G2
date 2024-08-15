#ifndef DROITACCES_H
#define DROITACCES_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include "QMessageBox"

class droit_acces
{
int Code_droit;
QString libelle_droit;


public:
    droit_acces();
     droit_acces(int,QString);
     bool Ajouter_droit();
     bool supprimer_droit(QString);
     bool modifier_droit(int,QString);
     QSqlQueryModel * afficher_droit();
};

#endif // DROITACCES_H
