#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QPixmap>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <string>
#include <QSqlQueryModel>
class notification
{
public:
    notification();
    void ajout_notification();
    void notification_supprimer();
    void stock_manquant();
    void stock_exces();
    void notification_modifier_fedi();
    void notification_modifier();
};


#endif // NOTIFICATION_H