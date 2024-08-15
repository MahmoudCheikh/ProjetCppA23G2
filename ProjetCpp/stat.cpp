/*#include "stat.h"
#include <QVector>
#include<QObject>
#include<QtWidgets>
#include <QSqlQuery>
#include <QDialog>
//#include"ui_dialog.h"
#include<iostream>

stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}

int stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE  where PRIX <= 5") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE  where PRIX >5 and PRIX <=10") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE  where PRIX >10 and PRIX <15") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}
int stati::Statistique_partie5()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from COMMANDE  where PRIX >15") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;
}
void stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int a=Statistique_partie4();
        cout<<a<<endl ;
        int d=Statistique_partie5();
            cout<<d<<endl ;


        float s2= b*100 ;
        float s3=c*100;
        float s1= a*100;
         float s4= d*100;
        float nb = a+b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float q1 ;
        q1 = s1/nb ;
        float q4 ;
        q4 = s4/nb ;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z;
        z= (q1*360)/100;
        float w;
        w= (q4*360)/100;

    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-300,this->width()-300);

    painter.setBrush(Qt::darkBlue);
    painter.drawPie(size,0,16*y);
    ui->labelF->setText("Prix inferieure à 5 dt") ;
    painter.setBrush(Qt::darkGreen);
    painter.drawPie(size,16*y,16*m);
    ui->label_2F->setText("Prix entre 5dt et 10dt") ;
    painter.setBrush(Qt::darkGray);
    painter.drawPie(size,16*(y+m),16*z);
    ui->label_3F->setText("Prix entre 10dt et 15dt") ;

    painter.setBrush(Qt::darkRed);
    painter.drawPie(size,16*(y+m+z),16*w);
   ui->label_4F->setText("Prix supérieure à 15 dt");


}

void stati::on_pushButton_clicked()
{
    hide();
}
*/
