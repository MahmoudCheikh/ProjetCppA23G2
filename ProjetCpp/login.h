#ifndef LOGIN_H
#define LOGIN_H
#include <QMainWindow>
#include <QPropertyAnimation>
#include "utilisateur.h"
#include "droitacces.h"
#include <QMainWindow>
#include <windows.h>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include <QMediaPlayer>
#include"fournisseur.h"
#include <QSystemTrayIcon>
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_Login_ins_clicked();

    void on_Login_connexion_clicked();

    void on_affiche_utilisateur_clicked();

    void on_pushButton_clicked();

    void on_tab_affiche_doubleClicked();

    void on_modifier_utilisateur_clicked();

    void on_ajouter_droit_clicked();

    void on_inscription_inscrit_2_clicked();

    void on_inscription_inscrit_clicked();

    void on_liste_droit_currentIndexChanged(const QString &arg1);

    void on_ajoute_droit_clicked();

    void on_supp_droit_clicked();

    void on_modifier_droit_clicked();

    void on_tab_droit_doubleClicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_supprimer_droit_clicked();

    void on_ajout_droit_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_tri_clicked();

    void on_recherche_clicked();

    void on_Supp_droitut_clicked();

    void on_pushButton_6_clicked();

    void on_ajoute_droit_3_clicked();

    void on_liste_droit_3_currentIndexChanged(const QString &arg2);

    void on_pushButton_7_clicked();

    void on_play1_clicked();

    void on_mute1_clicked();

    void on_pause1_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();



    void on_pushButton_11_clicked();

    void on_sendBtn_2F_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::Login *ui;
    QPropertyAnimation *animation,*animation1;
    Utilisateur tmputilisateur,tmpdroit_u;
    droit_acces tmpdroit;
    QMediaPlayer *media;
    QMovie *myMoviebg;
    QSystemTrayIcon *mSystemTrayIcon;
};
#endif // LOGIN_H
