#ifndef TEACHERDASH_H
#define TEACHERDASH_H

#include <QDialog>

namespace Ui {
class teacherdash;
}

class teacherdash : public QDialog
{
    Q_OBJECT

public:
    explicit teacherdash(QWidget *parent = nullptr);
    ~teacherdash();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::teacherdash *ui;
};

#endif // TEACHERDASH_H
