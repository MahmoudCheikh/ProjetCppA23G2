#ifndef STAT_EVALUATION_FEDI_H
#define STAT_EVALUATION_FEDI_H


#include <QMainWindow>
#include <QWidget>
#include <QMap>
#include <QVector>
namespace Ui {
class stat_evaluation_fedi;
}

class stat_evaluation_fedi : public QMainWindow
{
    Q_OBJECT

public:
    explicit stat_evaluation_fedi(QWidget *parent = nullptr);
    ~stat_evaluation_fedi();


private:
    Ui::stat_evaluation_fedi *ui;

};

#endif // STAT_EVALUATION_FEDI_H
