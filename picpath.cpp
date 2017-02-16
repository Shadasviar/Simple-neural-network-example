#include "picpath.h"
#include "ui_picpath.h"

PicPath::PicPath(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PicPath)
{
    ui->setupUi(this);
}

PicPath::~PicPath()
{
    delete ui;
}

void PicPath::on_pushButton_clicked()
{

}
