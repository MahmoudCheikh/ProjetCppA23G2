#ifndef TABLE_H
#define TABLE_H
#include <QString>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>

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


class Table
{
 int NUM_TABLE;
int NB_CHAISES;
QString EMPLACEMENT;
QString DISPONIBILITE;
int DEBARRASSAGE;
public:

  void setNUM_TABLE(int n);
  void setNB_CHAISES(int n);
  void setEMPLACEMENT(QString n);
  void setDISPONIBILITE(QString n);
  void setDEBARRASSAGE(int n);
  int get_NUM_TABLE();
  int get_NB_CHAISES();
  QString get_EMPLACEMENT();
  QString get_DISPONIBILITE();
  int get_DEBARRASSAGE();

    Table(int);
   Table(int,int,QString,QString,int);
    Table();
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool modifier();
    int check();
    int check1();
     void recherche(QTableView* table,int NUM_TABLE);
      void rechercheC(QTableView* table,int NB_CHAISES);
      void rechercheD(QTableView* table,int DEBARRASSAGE);


      void tri_Num(QTableView* table);
      void tri_NB(QTableView* table);
      void tri_DEB(QTableView* table);
      QVBoxLayout * stat();
      int lastIDNumtable();
      int lastIDnbchaise();


};
//;
#endif // TABLE_H
