#ifndef OFFREFOURNISSEUR_H
#define OFFREFOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
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

class OffreFournisseur
{
    int idProduit;
    int idFournisseur;
    int prix;


public:
    OffreFournisseur();
    OffreFournisseur(int,int);
    OffreFournisseur(int,int,int);

    int getidProduit();
    int getidFournisseur();
    int getprix();

    void setidProduit(int);
    void setidFournisseur(int);
    void setprix(int);

    bool ajouter();
    bool supprimer();
    bool modifier();
    QSortFilterProxyModel * afficher();

    int lastIdFournisseur();
    int lastIdProduit();
    QVBoxLayout * stat();
    QSortFilterProxyModel * searchProduit(int);
    QSortFilterProxyModel * searchFournisseur(int);

};
#endif // OFFREFOURNISSEUR_H
