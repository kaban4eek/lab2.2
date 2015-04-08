#include "simplependulum.h"
#include "ui_simplependulum.h"
#include <QtGui>
#include <QPalette>
#include <QDebug>
#include<math.h>

static int DEFAULT_X_OFFSET= 600;
static int DEFAULT_Y_OFFSET= 60;
static int DEFAULT_X_PENDULUM_OFFSET= 55;
static int DEFAULT_Y_PENDULUM_OFFSET= 50;
static int DEFAULT_X_INITIAL_PENDULUM_OFFSET= 574;
static int DEFAULT_Y_INITIAL_PENDULUM_OFFSET= 232;
static float time_period=0;
const float pi =3.14;


SimplePendulum::SimplePendulum(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimplePendulum)
{
    ui->setupUi(this);
}

SimplePendulum::~SimplePendulum()
{
    delete ui;
}
void SimplePendulum::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void SimplePendulum::paintEvent(QPaintEvent *pEvent)
{
    int X=DEFAULT_X_OFFSET;
    int Y=DEFAULT_Y_OFFSET;

    QWidget::paintEvent(pEvent);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::yellow));

    X=DEFAULT_X_OFFSET;
    Y=DEFAULT_Y_OFFSET;

    int XE=DEFAULT_X_PENDULUM_OFFSET;
    int YE=DEFAULT_Y_PENDULUM_OFFSET;
    int XI=DEFAULT_X_INITIAL_PENDULUM_OFFSET;
    int YI=DEFAULT_Y_INITIAL_PENDULUM_OFFSET;

    painter.drawLine(590,60,610,60);
    painter.drawLine(600,60,X,Y+175);
    painter.drawEllipse(XI,YI,XE,YE);
}





void SimplePendulum::on_pushButton_clicked()
{
    QString Data1= ui->textEdit_length->toPlainText();
        int iLength=atoi(Data1.toLocal8Bit());
        Initialdisplay(iLength);
}
void SimplePendulum::Initialdisplay(int strLength)
{
    if(strLength)
    {
        DEFAULT_Y_OFFSET=strLength;
        int d=strLength-60;
        DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+d;
        this->repaint();
    }
    ui->pushButton->close();
}

void SimplePendulum::on_pushButton_Reset_clicked()
{
    {
        DEFAULT_X_OFFSET= 600;
        DEFAULT_Y_OFFSET= 60;
        DEFAULT_X_PENDULUM_OFFSET= 55;
        DEFAULT_Y_PENDULUM_OFFSET= 50;
        DEFAULT_X_INITIAL_PENDULUM_OFFSET= 574;
        DEFAULT_Y_INITIAL_PENDULUM_OFFSET= 232;
        this->repaint();
        ui->pushButton->show();
    }

}

void SimplePendulum::on_pushButton_2_clicked()
{
  display(DEFAULT_Y_OFFSET);
}

void SimplePendulum::display(int strL)
{
    time_period=2* pi *sqrt(strL/9.8);
       float iPeroid=time_period;
       QString period;
       period.sprintf ("%f",iPeroid);
       ui->label_Period->setText(period);
       float Motion=time_period/4;
       float iMotion=Motion;
       QString motion;
       motion.sprintf ("%f",iMotion);
       ui->label_Motion->setText(motion);
       for(int i=0;i<Motion;i++)
          {
              QEventLoop loop;
              QTimer::singleShot(300, &loop, SLOT(quit()));
              loop.exec();
              DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
              DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
              DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
              DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
              DEFAULT_X_PENDULUM_OFFSET=DEFAULT_X_PENDULUM_OFFSET;
              DEFAULT_Y_PENDULUM_OFFSET=DEFAULT_Y_PENDULUM_OFFSET;
              this->repaint();
          }
         for(int i=0;i<Motion;i++)
          {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
             this->repaint();

          }
         for(int i=0;i<Motion;i++)
          {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
             this->repaint();

          }
         for(int i=0;i<Motion;i++)
          {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
             this->repaint();

          }
         for(int i=0;i<Motion-1;i++)
         {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
             this->repaint();
         }
         for(int i=0;i<Motion-1;i++)
          {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
             this->repaint();

          }
         for(int i=0;i<Motion-1;i++)
          {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
             this->repaint();

          }
         for(int i=0;i<Motion-1;i++)
          {
             QEventLoop loop;
             QTimer::singleShot(300, &loop, SLOT(quit()));
             loop.exec();
             DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
             DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
             DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
             DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
             this->repaint();

          }

      }


