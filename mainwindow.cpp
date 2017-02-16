#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include "kohonennet.h"

using std::vector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    net = new KohonenNet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString path = ui->lineEdit->text() + ".bmp";
    QPixmap pic(path);
    ui->label->setPixmap(pic);
    int number = net->handle(QImage(ui->lineEdit->text() + ".bmp"));
    ui->label_2->setText("Number detected : " + QString::number(number));
}
