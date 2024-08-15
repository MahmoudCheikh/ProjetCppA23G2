#ifndef COMMANDEFOURNISSEUR_H
#define COMMANDEFOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

class CommandeFournisseur
{
    int idCommande;
    int idFournisseur;
    int idProduit;
    int quantite;

    QString dateEnvoi;
    QString dateReception;

public:
    CommandeFournisseur();
    CommandeFournisseur(int);
    CommandeFournisseur(int,int,int,QString,QString);

    int getidCommande();
    int getidFournisseur();
    int getidProduit();
    int getquantite();
    QString getdateEnvoi();
    QString getdateReception();

    void setidCommande(int);
    void setidFournisseur(int);
    void setidProduit(int);
    void setquantite(int);
    void setdateEnvoi(QString);
    void setdateReception(QString);

    bool ajouter();
    bool supprimer();
    bool modifier();
    QSortFilterProxyModel * afficher();

    QSortFilterProxyModel * searchP(int);
    QSortFilterProxyModel * searchF(int);

    int lastId();

};

#endif // COMMANDEFOURNISSEUR_H
