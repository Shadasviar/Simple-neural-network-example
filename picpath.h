#ifndef PICPATH_H
#define PICPATH_H

#include <QWidget>

namespace Ui {
class PicPath;
}

class PicPath : public QWidget
{
    Q_OBJECT

public:
    explicit PicPath(QWidget *parent = 0);
    ~PicPath();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PicPath *ui;
};

#endif // PICPATH_H
