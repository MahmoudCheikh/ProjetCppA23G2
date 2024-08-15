#ifndef STATSTOCK_H
#define STATSTOCK_H

#include <QMainWindow>
#include <QWidget>
#include <QMap>
#include <QVector>
namespace Ui {
class statStock;
}

class statStock : public QMainWindow
{
    Q_OBJECT

public:
    explicit statStock(QWidget *parent = nullptr);
    ~statStock();


private:
    Ui::statStock *ui;

};

#endif // STATSTOCK_H
