#include "login.h"
#include <QSplashScreen>
#include <QTimer>
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "utilisateur.h"
#include "droitacces.h"
#include "login.h"
#include <QDateTime>
#include <QMessageBox>
#include "string.h"
#include "smtp.h"
#include <QDateTime>
#include <QCalendarWidget>
#include <QFile>
#include <QPrintDialog>
#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QGraphicsOpacityEffect>
#include <QCompleter>
#include <QKeyEvent>
#include <QMediaPlayer>
#include<QGraphicsOpacityEffect>
#include<QMessageBox>
#include <QCoreApplication>
#include <QPdfWriter>
#include <QPainter>
#include <QPdfWriter>
#include <QUrl>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include"QMessageBox"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPushButton>
#include<QFileInfo>
#include <QMovie>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "produit.h"
#include "stock.h"
#include "transaction.h"
#include "evaluation.h"
#include "plat.h"
#include "menu.h"
#include "table.h"
#include "commande.h"
#include "smtp.h"
#include "stat.h"
#include "fournisseur.h"
#include "offrefournisseur.h"
#include "commandefournisseur.h"
#include "stat_evaluation_fedi.h"
#include "connection.h"
#include "notification.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QSortFilterProxyModel>
#include <QAbstractSocket>//mail
#include <QMap>
#include<QAbstractSocket>
#include <string>
#include <QLabel>
#include <QDate>
#include <QtWidgets/QMessageBox>
#include <QMainWindow>
#include <QCalendarWidget>
#include <QPixmap>
#include <QMediaPlayer>
#include <QMovie>
#include <QSsl>
#include <QSslSocket>
#include <QNetworkAccessManager>
#include <QPrinter>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QDesktopWidget>
//#include <QIconDragEvent>
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
#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QObject>
//#include <QPrinter>
#include <QFileDialog>
#include <QPlainTextEdit>
#include <QPropertyAnimation>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QtCharts>
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QSqlQueryModel *model=new QSqlQueryModel();
            QSqlQuery qry;
            qry.prepare("select LIBELLE_DROIT from DROITS_ACCES");
            qry.exec();
            model->setQuery(qry);
            ui->liste_droit->setModel(model);
            ui->liste_droit_3->setModel(model);


            mSystemTrayIcon = new QSystemTrayIcon(this);
            mSystemTrayIcon->setIcon(QIcon("C:/QTP/ProjetCppA23G2/ProjetCpp/hat.png"));
            mSystemTrayIcon->setVisible(true);

            //-------------------------
            QMediaPlayer *player = new QMediaPlayer;
            QMediaPlaylist *playlist  = new QMediaPlaylist;
                player->setVideoOutput(ui->video);
                playlist->addMedia(QUrl::fromLocalFile(("C:/QTP/ProjetCppA23G2/ProjetCpp/video.mp4")));
            playlist->setPlaybackMode(QMediaPlaylist::Loop);
                player->setVolume(0);
                player->setPlaylist(playlist);
                player->play();
                qDebug() << "mediaStatus: " << player->mediaStatus() << "error: " << player->error();
            //-------------------------
    media = new QMediaPlayer (this);
    media->setMedia( QUrl::fromLocalFile("C:/QTP/ProjetCppA23G2/ProjetCpp/theme.mp3"));
    media->play();

    QPixmap pix150("C:/QTP/ProjetCppA23G2/ProjetCpp/koujniti_logo.png");
           QPixmap pix1("C:/QTP/ProjetCppA23G2/ProjetCpp/calque 0.png");
           QPixmap pix2("C:/QTP/ProjetCppA23G2/ProjetCpp/man1.png");
           QPixmap pix3("C:/QTP/ProjetCppA23G2/ProjetCpp/padlock_78356.png");
           QPixmap pix4("C:/QTP/ProjetCppA23G2/ProjetCpp/add-user-2-256.png");
           QPixmap pix5("C:/QTP/ProjetCppA23G2/ProjetCpp/mui.png");

           ui->hola->setPixmap(pix1);
           ui->music->setToolTip("Music");
           ui->label_30->setPixmap(pix150);
           ui->label_32->setPixmap(pix3);
           ui->label_33->setPixmap(pix3);
           ui->label_34->setPixmap(pix2);
           ui->label_35->setPixmap(pix4);
           ui->label_31->setPixmap(pix4);
           ui->music->setPixmap(pix5);

           myMoviebg = new QMovie(this);
           myMoviebg = new QMovie("C:/QTP/ProjetCppA23G2/ProjetCpp/gif.mp4");

                  ui->gif->setMovie(myMoviebg);

                      myMoviebg->start();

}

Login::~Login()
{
    delete ui;
}



void Login::on_Login_ins_clicked()
{
        ui->stackedWidget->setCurrentIndex(1);
}

void Login::on_Login_connexion_clicked()
{

       QString email=ui->login_email->text();
       QString mdp=ui->login_mdp->text();
       QSqlQuery qry;
       qry.prepare("select * from UTILISATEURS where EMAIL_UTILISATEUR=:email and MDP_UTILISATEUR=:mdp");
        qry.bindValue(":email",email);
        qry.bindValue(":mdp",mdp);
       qry.exec();
   qry.next();
   if(email.isEmpty()&& mdp.isEmpty())
   {QMessageBox :: critical(nullptr,QObject::tr("Erreur "),
                            QObject::tr("Vérifier votre login ou mot de passe\n"
                                        "click cancel to exit "),QMessageBox ::Cancel);}
   else
    if(email==qry.value(3).toString() && mdp==qry.value(4).toString())
    {
        if(qry.value(5).toString() == "Gerant"){
            ui->stackedWidget->setCurrentIndex(10);
            MainWindow *w =new MainWindow(this);
            QSplashScreen *splash= new QSplashScreen;
            splash->setPixmap(QPixmap("C:/Users/PC/Desktop/Projet C++/Photos/koujinti.png"));
            splash->show();

            QTimer::singleShot(2500,splash,SLOT(close()));
            QTimer::singleShot(2500,w,SLOT(show()));
            w->show();
        }else{
            //ui->stackedWidget->setCurrentIndex(3);
             MainWindow *w =new MainWindow(this);
             QSplashScreen *splash= new QSplashScreen;
             splash->setPixmap(QPixmap("C:/Users/PC/Desktop/Projet C++/Photos/koujinti.png"));
             splash->show();

             QTimer::singleShot(2500,splash,SLOT(close()));
             QTimer::singleShot(2500,w,SLOT(show()));
             w->show();
             this->setVisible(false);
        }
    }
    else
       { QMessageBox :: critical(nullptr,QObject::tr("Erreur "),
                                 QObject::tr("Vérifier votre login ou mot de passe\n"
                                             "click cancel to exit "),QMessageBox ::Cancel);}
}

void Login::on_affiche_utilisateur_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
ui->tab_affiche->setModel(tmputilisateur.afficher_utilisateur());
}

void Login::on_pushButton_clicked()
{
        int row =ui->tab_affiche->selectionModel()->currentIndex().row();
        QString id=ui->tab_affiche->model()->index(row,0).data().toString();

        bool test =tmputilisateur.supprimer_utilisateur(id);
        if(row==-1)
        { QMessageBox::critical(nullptr, QObject::tr("Supprimer un utilisateur"),
                                QObject::tr("Erreur ! selectionnez utilisateur que vous voulez le supprimer !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else
        {
        if(test)
        {
            notification no;
            no.notification_supprimer();
            ui->tab_affiche->setModel(tmputilisateur.afficher_utilisateur());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un utilisateur"),
                        QObject::tr("utilisateur  supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->tab_affiche->setModel(tmputilisateur.afficher_utilisateur());


        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un utilisateur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }


void Login::on_tab_affiche_doubleClicked()
{

    int row =ui->tab_affiche->selectionModel()->currentIndex().row();
    ui->stackedWidget->setCurrentIndex(2);
    ui->inscription_id_3->setText(ui->tab_affiche->model()->index(row,0).data().toString());
    ui->inscription_nom_3->setText(ui->tab_affiche->model()->index(row,1).data().toString());
    ui->inscription_prenom_3->setText(ui->tab_affiche->model()->index(row,2).data().toString());
    ui->inscription_email_3->setText(ui->tab_affiche->model()->index(row,3).data().toString());
    ui->inscription_mdp_3->setText(ui->tab_affiche->model()->index(row,4).data().toString());
    ui->inscription_role_3->setCurrentText(ui->tab_affiche->model()->index(row,5).data().toString());
}





void Login::on_modifier_utilisateur_clicked()
{
    int id=ui->inscription_id_3->text().toInt();
    QString nom=ui->inscription_nom_3->text();
      QString prenom=ui->inscription_prenom_3->text();
      QString email=ui->inscription_email_3->text();
        QString mdp=ui->inscription_mdp_3->text();
        QString role=ui->inscription_role_3->currentText();

      if(nom.isEmpty()|| prenom.isEmpty()||nom.contains(QRegExp("^[a-z+$+A-Z]"))==0||prenom.contains(QRegExp("^[a-z+$+A-Z]"))==0||email.isEmpty()||mdp.isEmpty()||role.isEmpty())
        {


          QMessageBox::information(nullptr, QObject::tr("erreur"),
                            QObject::tr("Vérifier vos champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
   {
         Utilisateur u( id,nom, prenom , email, mdp ,role);
          bool test=u.modifier_utilisateur(id,nom,prenom,email,mdp,role);
      if(test)
      {
          notification no;



          QMessageBox::information(nullptr, QObject::tr("Modifier un utilisateur"),
                            QObject::tr("UTILISATEUR modifie.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);
          ui->tab_affiche->setModel(tmputilisateur.afficher_utilisateur());
          no.notification_modifier();


   }
ui->stackedWidget->setCurrentIndex(5);

      }
}

void Login::on_ajouter_droit_clicked()
{
    int code_droit=ui->inscription_id_3->text().toInt();
    QString libelle_droit=ui->inscription_nom->text();
        droit_acces d;


      if(libelle_droit.isEmpty()|| libelle_droit.contains(QRegExp("^[a-z+$+A-Z]"))==0)
        {


          QMessageBox::information(nullptr, QObject::tr("erreur"),
                            QObject::tr("Vérifier vos champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
   {
         droit_acces d( code_droit,libelle_droit);
          bool test=d.Ajouter_droit();
      if(test)
      {



          QMessageBox::information(nullptr, QObject::tr("Ajouter un droit"),
                            QObject::tr("droit ajoutée.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);

   }


      }
}


void Login::on_inscription_inscrit_2_clicked()
{

    QString nom=ui->inscription_nom_2->text();
      QString prenom=ui->inscription_prenom_2->text();
      QString email=ui->inscription_email_2->text();
        QString mdp=ui->inscription_mdp_2->text();
        QString role=ui->inscription_role->currentText();
        Utilisateur u;


      if(nom.isEmpty()|| prenom.isEmpty()||nom.contains(QRegExp("^[a-z+$+A-Z]"))==0||prenom.contains(QRegExp("^[a-z+$+A-Z]"))==0||email.isEmpty()||mdp.isEmpty())
        {


          QMessageBox::information(nullptr, QObject::tr("erreur"),
                            QObject::tr("Vérifier vos champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
   {
          notification no;
          int id=u.lastId();
         Utilisateur u( id,nom, prenom , email, mdp ,role);
          bool test=u.Ajouter_utilisateur();
      if(test)
      {

           ui->stackedWidget->setCurrentIndex(3);
          no.ajout_notification();
          QMessageBox::information(nullptr, QObject::tr("Ajouter un utilisateur"),
                            QObject::tr("UTILISATEUR ajoutée.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);



   }


      }
}

void Login::on_inscription_inscrit_clicked()
{
    QString nom=ui->inscription_nom->text();
      QString prenom=ui->inscription_prenom->text();
      QString email=ui->inscription_email->text();
        QString mdp=ui->inscription_mdp->text();
        QString role=ui->inscription_role->currentText();
        Utilisateur u;


      if(nom.isEmpty()|| prenom.isEmpty()||nom.contains(QRegExp("^[a-z+$+A-Z]"))==0||prenom.contains(QRegExp("^[a-z+$+A-Z]"))==0||email.isEmpty()||mdp.isEmpty()||role.isEmpty()||u.controlsaisieMail(email)==false)
        {


          QMessageBox::information(nullptr, QObject::tr("erreur"),
                            QObject::tr("Vérifier vos champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
   {
          int id=u.lastId();
         Utilisateur u( id,nom, prenom , email, mdp ,role);
          bool test=u.Ajouter_utilisateur();
      if(test)
      {



          QMessageBox::information(nullptr, QObject::tr("Ajouter un utilisateur"),
                            QObject::tr("UTILISATEUR ajoutée.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);

   }


}
}


void Login::on_liste_droit_currentIndexChanged(const QString &arg1)
{
    QString nom=arg1;
     QSqlQuery qry;
     qry.prepare("select CODE_DROIT from DROITS_ACCES where LIBELLE_DROIT =:nom");
     qry.bindValue(":nom", nom);
 if(qry.exec())
 {while(qry.next())
     {

     ui->codedroit_inscri->setText(qry.value(0).toString());
 }
 }
}

void Login::on_ajoute_droit_clicked()
{
    Utilisateur u;
      QString Code_droit=ui->codedroit_inscri->text();

          bool test=u.affecter_droit(Code_droit);
      if(test)
      {

          QMessageBox::information(nullptr, QObject::tr("Ajouter un droit"),
                            QObject::tr("droit ajoutée.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);

   }
 ui->tab_droit->setModel(tmpdroit_u.afficher_droit());

}

void Login::on_supp_droit_clicked()
{
    int row =ui->tab_droit->selectionModel()->currentIndex().row();
    QString id=ui->tab_droit->model()->index(row,2).data().toString();

    bool test =tmpdroit_u.supprimer_droit(id);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un droit"),
                            QObject::tr("Erreur ! selectionnez droit que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
        ui->tab_droit->setModel(tmpdroit_u.afficher_droit());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un droit"),
                    QObject::tr("droit  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tab_droit->setModel(tmpdroit_u.afficher_droit());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un droit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Login::on_modifier_droit_clicked()
{
    int code=ui->modif_code->text().toInt();
    QString libelle=ui->modif_lib->text();;

      if(libelle.isEmpty())
        {
          QMessageBox::information(nullptr, QObject::tr("erreur"),
                            QObject::tr("Vérifier vos champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
   {
         Utilisateur u;
          bool test=u.modifier_droit(code,libelle);
      if(test)
      {

          QMessageBox::information(nullptr, QObject::tr("Modifier un droit"),
                            QObject::tr("DROIT modifie.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);
          ui->tab_droit->setModel(tmpdroit_u.afficher_droit());


   }

      }
}

void Login::on_tab_droit_doubleClicked()
{
    int row =ui->tab_droit->selectionModel()->currentIndex().row();
    ui->modif_code->setText(ui->tab_droit->model()->index(row,2).data().toString());
    ui->modif_lib->setText(ui->tab_droit->model()->index(row,3).data().toString());

}

void Login::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Login::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->affiche_droit->setModel(tmpdroit.afficher_droit());
}

void Login::on_supprimer_droit_clicked()
{
    int row =ui->affiche_droit->selectionModel()->currentIndex().row();
    QString id=ui->affiche_droit->model()->index(row,0).data().toString();

    bool test =tmpdroit.supprimer_droit(id);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un droit"),
                            QObject::tr("Erreur ! selectionnez droit que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un droit"),
                    QObject::tr("droit  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
                ui->affiche_droit->setModel(tmpdroit.afficher_droit());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer un droit"),
                    QObject::tr("Erreur ! Ce droit est affecté a un utilisateur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Login::on_ajout_droit_clicked()
{
    int code=ui->ajout_codedroit->text().toInt();
      QString libelle=ui->ajout_libelledroit->text();
        Utilisateur u;


      if(libelle.isEmpty())
        {
          QMessageBox::information(nullptr, QObject::tr("erreur"),
                            QObject::tr("Vérifier vos champs.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
      }
      else
   {
        droit_acces d(code,libelle);
          bool test=d.Ajouter_droit();
      if(test)
      {



          QMessageBox::information(nullptr, QObject::tr("droit un utilisateur"),
                            QObject::tr("droit ajoutée.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);
   }


}
}

void Login::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Login::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->aff_droitutilisateur->setModel(tmputilisateur.afficher_droitutilisateur());
}

void Login::on_tri_clicked()
{
        Utilisateur u;
        /*QString critere=ui->cb_historique->currentText();*/
            QString mode;
             if (ui->id_asc->isChecked()==true)
        {
                 ui->tab_affiche->setModel(u.trie_id_asc());


       }
             else if(ui->id_des->isChecked()==true)

                { ui->tab_affiche->setModel(u.trie2_id_des());}

             else if(ui->nom_asc->isChecked()==true)

             {ui->tab_affiche->setModel(u.trie_nom_asc());}

             else if(ui->nom_desc->isChecked()==true)

             {ui->tab_affiche->setModel(u.trie2_nom_des());}

             else if(ui->role_asc->isChecked()==true)

             {ui->tab_affiche->setModel(u.trie_role_asc());}

             else if(ui->role_desc->isChecked()==true)

             {ui->tab_affiche->setModel(u.trie2_role_des());}
}

void Login::on_recherche_clicked()
{
    Utilisateur u;
        QString text;
        if (ui->radio_id->isChecked()==true)
    {
    text=ui->rech_line->text();
         if(text == "")

         {

             ui->tab_affiche->setModel(u.afficher_utilisateur());

         }

         else

         {



             ui->tab_affiche->setModel(u.chercher_ut(text));

         }
        }
         if(ui->radio_role->isChecked()==true)
        {
            text=ui->rech_line->text();
                 if(text == "")

                 {

                     ui->tab_affiche->setModel(u.afficher_utilisateur());

                 }

                 else

                 {



                     ui->tab_affiche->setModel(u.chercher_ut1(text));

                 }

        }
         else if     (ui->radio_nom->isChecked()==true)
         {

             text=ui->rech_line->text();
                  if(text == "")

                  {

                      ui->tab_affiche->setModel(u.afficher_utilisateur());

                  }

                  else

                  {



                      ui->tab_affiche->setModel(u.chercher_ut2(text));

                  }
}}

void Login::on_Supp_droitut_clicked()
{
    int row =ui->aff_droitutilisateur->selectionModel()->currentIndex().row();
    QString id=ui->aff_droitutilisateur->model()->index(row,0).data().toString();

    bool test =tmputilisateur.supprimer_droit_utilisateur(id);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un droit"),
                            QObject::tr("Erreur ! selectionnez droit que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
        ui->aff_droitutilisateur->setModel(tmputilisateur.afficher_droitutilisateur());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un droit"),
                    QObject::tr("droit  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
                ui->aff_droitutilisateur->setModel(tmputilisateur.afficher_droitutilisateur());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un droit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Login::on_pushButton_6_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);
   int row =ui->tab_affiche->selectionModel()->currentIndex().row();
   QString id=ui->tab_affiche->model()->index(row,0).data().toString();
   ui->line_id->setText(id);
   ui->AJT_DROIT->setModel(tmpdroit_u.afficher_droit_1(id));

}

void Login::on_ajoute_droit_3_clicked()
{
    Utilisateur u;
      QString Code_droit=ui->codedroit_inscri_3->text();
      QString id=ui->line_id->text();

          bool test=u.affecter_nvdroit(Code_droit,id);
      if(test)
      {

          QMessageBox::information(nullptr, QObject::tr("Ajouter un droit"),
                            QObject::tr("droit ajoutée.\n"
                                        "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);

   }
 ui->AJT_DROIT->setModel(tmpdroit_u.afficher_droit_1(id));
}

void Login::on_liste_droit_3_currentIndexChanged(const QString &arg2)
{
    QString nom=arg2;
     QSqlQuery qry;
     qry.prepare("select CODE_DROIT from DROITS_ACCES where LIBELLE_DROIT =:nom");
     qry.bindValue(":nom", nom);
 if(qry.exec())
 {while(qry.next())
     {

     ui->codedroit_inscri_3->setText(qry.value(0).toString());
 }
 }
}


void Login::on_pushButton_7_clicked()
{

    QTableView *table;
            table = ui->tab_affiche;

            QString filters("CSV files (.csv);;All files (.*)");
            QString defaultFilter("CSV files (*.csv)");
            QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                               filters, &defaultFilter);
            QFile file(fileName);

            QAbstractItemModel *model =  table->model();
            if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                QTextStream data(&file);
                QStringList strList;
                for (int i = 0; i < model->columnCount(); i++) {
                    if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                        strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") << "\n";
                for (int i = 0; i < model->rowCount(); i++) {
                    strList.clear();
                    for (int j = 0; j < model->columnCount(); j++) {

                        if (model->data(model->index(i, j)).toString().length() > 0)
                            strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                        else
                            strList.append("");
                    }
                    data << strList.join(";") + "\n";
                }
                file.close();
                QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                          QObject::tr("Export avec succes .\n"
                                                      "Click OK to exit."), QMessageBox::Ok);
            }

}
//--------------------------------------------~MUSIC_PLAY~-------------------------------------------------------

void Login::on_play1_clicked()
{
    media->play() ;
}

void Login::on_pause1_clicked()
{
    media->pause();
}

void Login::on_mute1_clicked()
{
    media->setMuted(true);
}

void Login::on_pushButton_8_clicked()
{

    QString str;
    str.append("<html><head></head><body>"
               "<center><img src=\"C:/QTP/ProjetCppA23G2/ProjetCpp/man1.png\"><br><br><br>"
               "<center>"+QString("Les Employees de notre restaurant"));
                 str.append("<table border=1><tr>") ;
                 str.append("<td>"+QString("ID_UTILISATEUR")+"</td>") ;
                 str.append("<td>"+QString("NOM_UTILISATEUR")+"</td>") ;
                 str.append("<td>"+QString("PRENOM_UTILISATEUR")+"</td>") ;
                 str.append("<td>"+QString("email_UTILISATEUR")+"</td>") ;
                 str.append("<td>"+QString("mdp_UTILISATEUR")+"</td>") ;
                 str.append("<td>"+QString("role_UTILISATEUR")+"</td>") ;

                 QSqlQuery* query=new QSqlQuery();
                 query->exec("SELECT * FROM UTILISATEURS");

                 while(query->next())
                 {
                 str.append("<tr><td>");
                 str.append(query->value(0).toString()) ;
                 str.append("</td><td>") ;
                 str.append(query->value(1).toString());
                 str.append("</td><td>") ;
                 str.append(query->value(2).toString());
                 str.append("</td><td>") ;
                 str.append(query->value(3).toString());
                 str.append("</td><td>") ;
                 str.append(query->value(4).toString());
                 str.append("</td><td>") ;
                 str.append(query->value(5).toString());
                 str.append("</td></td>");
                 }
              str.append("</table></center></body></html>") ;

              QPrinter printer ;
              printer.setOrientation(QPrinter::Portrait);
              printer.setOutputFormat(QPrinter::PdfFormat);
              printer.setPaperSize(QPrinter::A4) ;

              QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","..","PDF(*.pdf)");

              if (path.isEmpty()) return ;
              printer.setOutputFileName(path) ;

              QTextDocument doc;
              doc.setHtml(str) ;
              doc.print(&printer);
}

void Login::on_pushButton_9_clicked()
{
    Utilisateur u;
        ui->tab_affiche->setModel(u.afficher_utilisateur());
}


void Login::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void Login::on_sendBtn_2F_clicked()
{
    Smtp* smtp = new Smtp("fedi.hannachi@esprit.tn","191JMT4861", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        smtp->sendMail("fedi.hannachi@esprit.tn", ui->rcpt_2F->text() , ui->subject_2F->text(),ui->msg_2F->toPlainText());
}

void Login::on_pushButton_10_clicked()
{
    stat_evaluation_fedi *p = new stat_evaluation_fedi ();
      p->show();
}
