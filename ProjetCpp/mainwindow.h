#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stock.h"
#include "smtp.h"
#include "produit.h"
#include <QMediaPlayer>
#include <QSystemTrayIcon>
#include "smtp.h"
#include <QPropertyAnimation>
#include <QTableView>
#include "transactionmain.h"
#include "arduino.h"

namespace Ui {
class MainWindow;
class QSystemTrayIcon;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sendMail();
    void mailSent(QString);
    void sendMail2();
    void mailSent2(QString);

    void sendMail4();
    void mailSent4(QString);
    void sendMail3();
    void mailSent3(QString);
//----------------------------------------MENU---------------------------------------------------
    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

//---------------------------------------------~MARIEM~-----------------------------------------------------

    void on_recherche_produit_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_TRI_clicked();

    void on_TRI_2_clicked();

    void on_tableView_B_doubleClicked();

    void on_tableView_A_doubleClicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_mute_clicked();

    void on_tableView_B_clicked();

   //void on_tableView_A_clicked();

    void on_rechercherStock_clicked();

    void on_PDF_STOCK_clicked();

    void on_Afficher_Produit_clicked();

    void on_Afficher_Stock_clicked();

    void on_statis_clicked();

    void setButtonIcon();

    void on_historique_clicked();

    void showTime();
//----------------------------------------AHMED------------------------------------------------
    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();



    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_rechercher_clicked();

    //void on_lineEdit_10_cursorPositionChanged(int arg1, int arg2);

    void on_rechercher_2_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_57_clicked();
//------------------------------------------AZIZ----------------------------------------------------
    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_tableView_3_clicked();

    void on_tableView_4_clicked();

    void on_PDF_aziz_clicked();

    void on_tri_aziz_clicked();

    void on_tri_aziz_1_clicked();

    void on_afficher_menu_clicked();

   // void on_tableView_8_clicked();
//--------------------------------------------FADWA-------------------------------------------------------------------

    void on_pushButton_fadwa1_clicked();

    void on_pushButton_fadwa2_clicked();

    void on_pushButton_fadwa3_clicked();

    void on_pushButton_fadwa4_clicked();

    void on_pushButton_fadwa5_clicked();

    void on_pushButton_fadwa6_clicked();

    //void on_pushButton_37_clicked();


    void on_pushButton_fadwa7_clicked();

    void on_pushButton_fadwa8_clicked();

    void on_pushButton_fadwa9_clicked();

//-------------------------------------------------------------------------------------------------------------------------
    void on_tableView_7F_clicked(const QModelIndex &index);


    void on_F_ADD_clicked();

    void on_F_UPDATE_clicked();

    void on_pushButton_44_clicked();

    void on_CF_ADD_clicked();
    void on_pushButton_fadwa40_clicked();

    void on_pushButton_fadwa41_clicked();

    void on_tableView_8F_clicked(const QModelIndex &index);

    void on_pushButton_fadwa42_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_47_clicked();

    void on_sendBtn_2_clicked();

    void on_OF_ADD_clicked();

    void on_OF_UPDATE_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_49_clicked();

    void on_pushButton_48_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_56_clicked();

//------------------------------------------------------------------------------------------------------------------------------------------

    void on_pdf_f_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_fadwa43_clicked();

    void on_rechercher_3_clicked();

   // void on_rechercher_4_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_59_clicked();

    void on_rechercher_5_clicked();
   // void on_tableView_7_clicked(const QModelIndex &index);

    void on_recher_clicked();


    //void on_tableView_8_clicked(const QModelIndex &index);
    void on_pushButton_fadwa44_clicked();


    void on_recher_2_clicked();

    void on_pushButton_DB_clicked();

    void on_pushButton_deb1_clicked();

    void on_pushButton_prix_clicked();

    void on_pushButton_ntab_clicked();

    void on_sendBtn_2F_clicked();

    void updateFournisseursTabsCombos();

    void on_STATF_clicked();

    void on_buttonStock_clicked();

    void on_pushButton_441_clicked();

   // void on_idDeCommande_clicked();

//    void on_libelle_clicked();

  //  void on_nombredechaises_clicked();

    void on_F_act_clicked();


    void on_actOF_clicked();

    void on_CF_Act_clicked();
//----------------------------------------------------------ARDUNIO------------------------------------------------


    //void on_pushButton_60_clicked();



    void on_state_eva_clicked();


    void on_excelbutton_clicked();

    void on_pushButton_exc_clicked();



     void on_AllumeLED1_clicked();

     void on_AllumeLED2_clicked();

     //void on_msgLDC_clicked();

     void on_pushButton_pdfFADWA_clicked();

     void on_pushButton_annuler1_clicked();

     void on_pushButton_annuler2_clicked();



    void on_arduinoM_M_clicked();

    void on_consommer_clicked();



    void on_rechercher_4_clicked();



    //void on_tableView_8_clicked(const QModelIndex &index);

   // void on_rcpt_3a_editingFinished();
  // -------------------------------------------------------ARDUINO---------------------------------------------------------
   // slot permettant la mise à jour du label état de la lampe 1,
        // ce slot est lancé à chaque réception d'un message de Arduino

    void on_Arduinobutt1_clicked();

    void on_stat_plat_clicked();


private:
    Ui::MainWindow *ui;
    QMediaPlayer *media;
    QMovie *myMoviebg;
    QSystemTrayIcon *mSystemTrayIcon;
    QPropertyAnimation *animation;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
    QString datastring;
};

#endif // MAINWINDOW_H
