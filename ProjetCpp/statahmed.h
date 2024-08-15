#ifndef STATAHMED_H
#define STATAHMED_H

#include <QMainWindow>

namespace Ui {
class statahmed;
}

class statahmed : public QMainWindow
{
    Q_OBJECT

public:
    explicit statahmed(QWidget *parent = nullptr);
    ~statahmed();

private:
    Ui::statahmed *ui;
};

#endif // STATAHMED_H
