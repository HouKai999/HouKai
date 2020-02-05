#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptimer=new QTimer;
    setWindowTitle("Dragon Ball");
    connect(this->ptimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    this->ui->textBrowser->setStyleSheet("border-image: url(:/kklt2.png);");
    this->ui->Start->setStyleSheet("border-image: url(:/cl.jfif);");
    this->ui->Record->setStyleSheet("border-image: url(:/ch.jfif);");
    this->ui->Stop->setStyleSheet("border-image: url(:/bjt.jpg);");
    this->ui->Clear->setStyleSheet("border-image: url(:/cb.jpg);");
    this->setStyleSheet("border-image: url(:/hwk.jpg);");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updateTime()
{
    QTime current = QTime::currentTime();
    int t = this->baseTime.msecsTo(current);
    QTime showTime(00,00,00);
    showTime = showTime.addMSecs(t);
    showStr = showTime.toString("mm:ss:zzz");
    ui->Timer->setDigitCount(8);
    this->ui->Timer->display(showStr);
}
void MainWindow::on_Start_clicked()
{
    this->baseTime = QTime::currentTime();
    this->ptimer->start(1);
}
void MainWindow::on_Record_clicked()
{
    this->ui->textBrowser->append(showStr);
}

void MainWindow::on_Clear_clicked()
{
    this->ptimer->stop();
    this->ui->Timer->display("00:00:000");
    this->ui->textBrowser->clear();
}

void MainWindow::on_Stop_clicked()
{
    this->ptimer->stop();
    if(showStr<="00:10:500"&&showStr>="00:09:500")
    {
        QMessageBox::information(NULL,"恭喜！","减1000俯卧撑",QMessageBox::Yes);
    }
}
