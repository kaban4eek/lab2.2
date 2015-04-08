#ifndef SIMPLEPENDULUM_H
#define SIMPLEPENDULUM_H

#include <QMainWindow>
#include<QString>

namespace Ui {
class SimplePendulum;
}
class SimplePendulum : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimplePendulum(QWidget *parent = 0);
    ~SimplePendulum();
    void Initialdisplay(int l);
    void display(int strL);

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);



private slots:
    void on_pushButton_clicked();

    void on_pushButton_Reset_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::SimplePendulum *ui;
};

#endif // SIMPLEPENDULUM_H
