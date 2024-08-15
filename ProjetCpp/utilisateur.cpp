#include "utilisateur.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <string>
#include <iostream>
#include <QThread>
#include "QMessageBox"
Utilisateur::Utilisateur()
{
id=0;
nom="";
prenom="";
email="";
mdp="";
role="";
}
int Utilisateur::lastId(){
    int lastId = 0;
    QSqlQuery qry3 ;
    qry3.prepare("select ID_UTILISATEUR from UTILISATEURS");
    if (qry3.exec()){
        while(qry3.next()){
        lastId = qry3.value(0).toInt();}
    }
    return lastId+1;
}
Utilisateur::Utilisateur(int id,QString nom,QString prenom,QString email,QString mdp,QString role)
{
    email=email.toLower();
    email[0]=email[0].toUpper();
    nom=nom.toLower();
    nom[0]=nom[0].toUpper();
    prenom=prenom.toLower();
    prenom[0]= prenom[0].toUpper();

    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->mdp=mdp;
    this->role=role;

}
bool Utilisateur::Ajouter_utilisateur()
{
       QString ress=QString::number(id);
       QSqlQuery Query;
       Query.prepare("INSERT INTO UTILISATEURS(ID_UTILISATEUR,NOM_UTILISATEUR,PRENOM_UTILISATEUR,email_UTILISATEUR,mdp_UTILISATEUR,role_UTILISATEUR)"
                     "values(:id,:nom,:prenom,:email,:mdp,:role)");
       Query.bindValue(":id",ress);
       Query.bindValue(":nom",nom);
       Query.bindValue(":prenom",prenom);
       Query.bindValue(":email",email);
       Query.bindValue(":mdp",mdp);
       Query.bindValue(":role",role);
       return Query.exec();
}
QSqlQueryModel * Utilisateur::afficher_utilisateur()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from UTILISATEURS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("mdp"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));
    return model;
}

bool Utilisateur::supprimer_utilisateur(QString idd)
{
QSqlQuery query;
query.prepare("Delete from UTILISATEURS where ID_UTILISATEUR = :ID_UTILISATEUR ");
query.bindValue(":ID_UTILISATEUR", idd);
return    query.exec();
}

bool Utilisateur::supprimer_droit_utilisateur(QString idd)
{
QSqlQuery query;
query.prepare("Delete from DROIT_UTILISATEURS where ID_UTILISATEUR = :ID_UTILISATEUR ");
query.bindValue(":ID_UTILISATEUR", idd);
return    query.exec();
}

bool Utilisateur::modifier_utilisateur(int idd,QString nomm,QString prenomm,QString emaill,QString mdpp,QString rolee)
{

    QSqlQuery qry;

           emaill=emaill.toLower();
           emaill[0]=emaill[0].toUpper();

    nomm=nomm.toLower();
           nomm[0]=nomm[0].toUpper();
            prenomm=prenomm.toLower();
                   prenomm[0]= prenomm[0].toUpper();

        qry.prepare("UPDATE UTILISATEURS set NOM_UTILISATEUR=(?),PRENOM_UTILISATEUR=(?),EMAIL_UTILISATEUR=(?),MDP_UTILISATEUR=(?),ROLE_UTILISATEUR=(?)  where ID_UTILISATEUR=(?)");
        qry.addBindValue(nomm);
        qry.addBindValue(prenomm);
        qry.addBindValue(emaill);
        qry.addBindValue(mdpp);
        qry.addBindValue(rolee);
        qry.addBindValue(idd);

   return  qry.exec();
}

bool Utilisateur::controlsaisieMail(QString mail){
    int i,test1=0,test2=0;


            for (i=0;i<mail.length();i++)
            {
     if( mail[i]=="@")
          test1=1;
     if( mail[i]==".")
         test2=1;
            }
    if((test1==1)&&(test2==1)){
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("email"),
                    QObject::tr("L'adresse mail non valid.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


}

 bool Utilisateur::affecter_droit(QString id)
 {
     QSqlQuery Query;
     Query.prepare("INSERT INTO DROIT_UTILISATEURS(ID_UTILISATEUR,CODE_DROIT) values ((select max(ID_UTILISATEUR) from UTILISATEURS),:id)");
     Query.bindValue(":id",id);
     return Query.exec();
 }
QSqlQueryModel * Utilisateur::afficher_droit()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select distinct utilisateurs.nom_utilisateur,utilisateurs.prenom_utilisateur,droits_acces.code_droit,droits_acces.libelle_droit from utilisateurs,droits_acces,droit_utilisateurs where droits_acces.code_droit=droit_utilisateurs.code_droit and utilisateurs.id_utilisateur = (select max(id_utilisateur) from utilisateurs) and utilisateurs.id_utilisateur = droit_utilisateurs.id_utilisateur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("code_droit "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("libelle_droit "));
        return model;
}

QSqlQueryModel * Utilisateur::afficher_droit_1(QString id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery Query;
    model->setQuery("select distinct utilisateurs.nom_utilisateur,utilisateurs.prenom_utilisateur,droits_acces.code_droit,droits_acces.libelle_droit from utilisateurs,droits_acces,droit_utilisateurs where droits_acces.code_droit=droit_utilisateurs.code_droit and utilisateurs.id_utilisateur = '"+id+"'  and utilisateurs.id_utilisateur = droit_utilisateurs.id_utilisateur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("code_droit "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("libelle_droit "));
        return model;
}

bool Utilisateur::supprimer_droit(QString idd)
{
QSqlQuery query;
query.prepare("Delete from DROIT_UTILISATEURS where code_droit = :code_droit");
query.bindValue(":code_droit", idd);
return    query.exec();
}

bool Utilisateur::modifier_droit(int code,QString libelle)
{

    QSqlQuery qry;

        qry.prepare("UPDATE DROITS_ACCES set libelle_droit=(?)  where Code_droit=(?);");
        qry.addBindValue(libelle);
        qry.addBindValue(code);

   return  qry.exec();
}


QSqlQueryModel * Utilisateur::afficher_droitutilisateur()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select utilisateurs.id_utilisateur,utilisateurs.nom_utilisateur,utilisateurs.prenom_utilisateur,utilisateurs.email_utilisateur,utilisateurs.role_utilisateur,droit_utilisateurs.code_droit from utilisateurs,droits_acces,droit_utilisateurs where droits_acces.code_droit=droit_utilisateurs.code_droit and utilisateurs.id_utilisateur = droit_utilisateurs.id_utilisateur;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("role "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("code_droit "));
        return model;
}

QSqlQueryModel* Utilisateur::trie_id_asc()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from utilisateurs ORDER BY ID_UTILISATEUR asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));


    return model;
}

QSqlQueryModel* Utilisateur::trie2_id_des()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from utilisateurs ORDER BY ID_UTILISATEUR desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));


    return model;
}

QSqlQueryModel* Utilisateur::trie_nom_asc()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from utilisateurs ORDER BY NOM_UTILISATEUR asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));


    return model;
}

QSqlQueryModel* Utilisateur::trie2_nom_des()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from utilisateurs ORDER BY NOM_UTILISATEUR desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));


    return model;
}

QSqlQueryModel* Utilisateur::trie_role_asc()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from utilisateurs ORDER BY ROLE_UTILISATEUR asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));


    return model;
}

QSqlQueryModel* Utilisateur::trie2_role_des()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from utilisateurs ORDER BY ROLE_UTILISATEUR desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Prenom"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("role"));


    return model;
}

QSqlQueryModel * Utilisateur::chercher_ut(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from utilisateurs where ((id_utilisateur ) = '"+aux+"')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("email"));
    model->setHeaderData(5,Qt::Vertical,QObject::tr("role"));

    return model;
}


QSqlQueryModel * Utilisateur::chercher_ut1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from utilisateurs where ((role_utilisateur ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("email"));
    model->setHeaderData(5,Qt::Vertical,QObject::tr("role"));

    return model;
}

QSqlQueryModel * Utilisateur::chercher_ut2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from utilisateurs where ((nom_utilisateur ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("email"));
    model->setHeaderData(5,Qt::Vertical,QObject::tr("role"));

    return model;
}

bool Utilisateur::affecter_nvdroit(QString code,QString id)
{
    QSqlQuery Query;
    Query.prepare("INSERT INTO DROIT_UTILISATEURS(ID_UTILISATEUR,CODE_DROIT) values (:id,:code)");
    Query.bindValue(":id",id);
    Query.bindValue(":code",code);
    return Query.exec();
}

