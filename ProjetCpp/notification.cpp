#include "notification.h"
#include <QSystemTrayIcon>
notification::notification()
{

}
void notification::ajout_notification()
{
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
      notifyIcon->show();
      notifyIcon->showMessage("Utilisateur Ajoutee ","Un nouveau utilisateur a été ajoutée",QSystemTrayIcon::Information,15000);

}
void notification::notification_supprimer()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Utilisateur supprimee","Un nouveau utilisateur a été supprimé ",QSystemTrayIcon::Critical,15000);
}
void notification::notification_modifier_fedi()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Utilisateur modifiee","Un nouveau utilisateur a été modifié ",QSystemTrayIcon::Warning,15000);
}

void notification::notification_modifier()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/QTP/ProjetCppA23G2/ProjetCpp/koujinti.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Utilisateur modifiee","Un nouveau stock a été modifié ",QSystemTrayIcon::Warning,15000);
}

void notification::stock_manquant()
{
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

      notifyIcon->setIcon(QIcon("C:/QTP/ProjetCppA23G2/ProjetCpp/hat.png"));
      notifyIcon->show();

      notifyIcon->showMessage("Stock Manquant ","La quantité de stock est inferieur à 50!\nVeuillez Commandez une nouvelle Fourniture! ",QSystemTrayIcon::Information,15000);
}
void notification::stock_exces()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/QTP/ProjetCppA23G2/ProjetCpp/hat.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Utilisateur supprimee","Un nouveau stock a été supprimé ",QSystemTrayIcon::Critical,15000);
}
