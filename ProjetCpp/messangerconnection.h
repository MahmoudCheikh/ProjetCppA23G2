#ifndef MESSANGERCONNECTION_H
#define MESSANGERCONNECTION_H

#include <QDialog>



class MessangerConnection
{
    Q_OBJECT

public:

    QString hostname () const {return  mHostname;}
    quint16 port () const{return  mport;}
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:

    QString mHostname;
    quint16 mport;
};

#endif // MESSANGERCONNECTION_H
