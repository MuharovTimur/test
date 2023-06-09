#ifndef NEWORDERFORM_H
#define NEWORDERFORM_H

#include <QDialog>
#include <QDate>

namespace Ui {
class newOrderForm;
}

class newOrderForm : public QDialog
{
    Q_OBJECT

public:
    explicit newOrderForm(QWidget *parent = nullptr);
    ~newOrderForm();


public slots:


signals:
    void sendInfo( QString name, QDate date, QString type,QString money, QString email , bool is_ready);

private slots:
    void on_doneBtn_clicked();

    void on_pushButton_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::newOrderForm *ui;

};

#endif // NEWORDERFORM_H
