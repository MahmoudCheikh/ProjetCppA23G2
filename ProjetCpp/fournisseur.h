#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
class Fournisseur
{
    int id;
    QString nom;
    QString adresse;
    QString mail;
    int telephone;

public:
    Fournisseur();
    Fournisseur(int);
    Fournisseur(QString,QString,QString,int);

    int getId();
    QString getNom();
    QString getAdresse();
    QString getMail();
    int getTelephone();

    void setId(int);
    void setNom(QString);
    void setAdresse(QString);
    void setMail(QString);
    void setTelephone(int);

    bool ajouter();
    bool modifier();
    bool supprimer();
    QSortFilterProxyModel * afficher();

    QSortFilterProxyModel * searchNom(QString);
    QSortFilterProxyModel * searchTelephone(QString);
    QSortFilterProxyModel * searchMail(QString);
    QSortFilterProxyModel * searchAdresse(QString);


    int lastId();

};

#endif // FOURNISSEUR_H
