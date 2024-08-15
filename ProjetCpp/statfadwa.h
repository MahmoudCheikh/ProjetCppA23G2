#ifndef STATFADWA_H
#define STATFADWA_H

#include <QDialog>
#include <QPainter>
#include <QSqlQuery>
#include <QDialog>

#include "connection.h"
using namespace std;

namespace Ui {
class statfadwa;
}

class statfadwa : public QDialog
{
    Q_OBJECT

public:
    explicit statfadwa(QWidget *parent = nullptr);
    ~statfadwa();
    int Statistique_partie2() ;
    int Statistique_partie3() ;
   int  Statistique_partie4();
   int  Statistique_partie5();
   void paintEvent(QPaintEvent *) ;

private slots:
    void on_pushButton_clicked();


private:
    Ui::statfadwa *ui;
};

#endif // STATFADWA_H
