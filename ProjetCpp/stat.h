/*#ifndef STAT_H
#define STAT_H
#include <QDialog>
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>

#include "connection.h"
using namespace std;

namespace Ui {
class stati;
}

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
       int Statistique_partie2() ;
       int Statistique_partie3() ;
      int  Statistique_partie4();
      int  Statistique_partie5();


     void paintEvent(QPaintEvent *) ;
    ~stati();
private slots:
    void on_pushButton_clicked();

private:
    Ui::stati *ui;


};




#endif // STAT_H
*/
