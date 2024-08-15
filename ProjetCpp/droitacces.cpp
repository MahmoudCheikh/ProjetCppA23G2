#include "droitacces.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include "QMessageBox"
droit_acces::droit_acces()
{

}

droit_acces::droit_acces(int Code_droit,QString libelle_droit)
{

    this->Code_droit=Code_droit;
    this->libelle_droit=libelle_droit;
}

bool droit_acces::Ajouter_droit()
{
       QString ress=QString::number(Code_droit);
       QSqlQuery Query;
       Query.prepare("INSERT INTO DROITS_ACCES(CODE_DROIT,LIBELLE_DROIT)"
                     "values(:Code_droit,:libelle_droit)");
       Query.bindValue(":Code_droit",ress);
       Query.bindValue(":libelle_droit",libelle_droit);
       return Query.exec();
}

QSqlQueryModel * droit_acces::afficher_droit()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from DROITS_ACCES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code_droit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_droit "));
    return model;
}

bool droit_acces::supprimer_droit(QString code)
{
QSqlQuery query;
query.prepare("Delete from DROITS_acces where CODE_DROIT = :CODE_DROIT ");
query.bindValue(":CODE_DROIT", code);
return    query.exec();
}

bool droit_acces::modifier_droit(int code,QString libel)
{

    QSqlQuery qry;

        qry.prepare("UPDATE DROITS_ACCES set libelle_droit=(?) where CODE_DROIT=(?)");
        qry.addBindValue(libel);
        qry.addBindValue(code);

   return  qry.exec();
}
