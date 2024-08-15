#ifndef STATEVALUATION_H
#define STATEVALUATION_H

#include <QMainWindow>


namespace Ui {
class statevaluation;
}

class statevaluation : public QMainWindow
{
    Q_OBJECT

public:
    explicit statevaluation(QWidget *parent = nullptr);
    ~statevaluation();

private:
    Ui::statevaluation *ui;
};
#endif // STATEVALUATION_H
