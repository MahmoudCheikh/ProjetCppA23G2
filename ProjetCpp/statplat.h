#ifndef STATPLAT_H
#define STATPLAT_H


        #include <QMainWindow>

        namespace Ui {
        class statPlat;
        }

        class statPlat : public QMainWindow
        {
            Q_OBJECT

        public:
            explicit statPlat(QWidget *parent = nullptr);
            ~statPlat();

        private:
            Ui::statPlat *ui;
        };


#endif // STATPLAT_H
