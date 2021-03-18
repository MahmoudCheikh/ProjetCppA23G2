#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stock.h"
#include "produit.h"
//#include "smtp.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();



    void on_TRI_clicked();
    void on_TRI_2_clicked();


   // void sendMail();
    //void mailSent(QString status);

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
