#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSortFilterProxyModel>

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include "QMessageBox"

class Utilisateur
{
    int id;
    QString nom;
    QString prenom;
    QString email;
    QString mdp;
    QString role;


public:
    Utilisateur();
    int lastId();
    Utilisateur(int,QString,QString,QString,QString,QString);
    bool Ajouter_utilisateur();
    bool supprimer_utilisateur(QString);
    bool modifier_utilisateur(int,QString,QString,QString,QString,QString);
    QSqlQueryModel * afficher_utilisateur();
    bool controlsaisieMail(QString mail);
    bool affecter_droit(QString);
    bool affecter_nvdroit(QString,QString);
    QSqlQueryModel * afficher_droit();
    QSqlQueryModel * afficher_droit_1(QString);
    bool supprimer_droit(QString);
    bool supprimer_droit_utilisateur(QString);
    bool modifier_droit(int,QString);
    QSqlQueryModel * afficher_droitutilisateur();
    QSqlQueryModel* trie_id_asc();
    QSqlQueryModel* trie2_id_des();
    QSqlQueryModel* trie_nom_asc();
    QSqlQueryModel* trie2_nom_des();
    QSqlQueryModel* trie_role_asc();
    QSqlQueryModel* trie2_role_des();
    QSqlQueryModel *chercher_ut(const QString &aux);
    QSqlQueryModel *chercher_ut1(const QString &aux);
    QSqlQueryModel *chercher_ut2(const QString &aux);
};

#endif // UTILISATEUR_H
