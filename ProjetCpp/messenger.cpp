#include "messenger.h"
#include "messangerconnection.h"
#include <QTcpSocket>
#include <QTextStream>

namespace Duartecorporation
{
void messanger::on_ok_clicked()
{
mHostname = "localhost";
mport = 3333;
accept();
}

void messanger::on_cancel_clicked()
{
reject();
}
}
