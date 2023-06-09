#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QDialog>
#include <QDate>
#include <QString>
#include "neworderform.h"



namespace Ui {
class workspace;
}

class workspace : public QDialog
{
    Q_OBJECT

public:
    explicit workspace(QWidget *parent);
    ~workspace();

signals:

public slots:

    void receiveInformation( QString name, QDate date,QString type,QString money, QString email);

    void deleteEventSlot(QDate d);

private slots:

    void on_newOrder_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:

    Ui::workspace *ui;

    int activeOrders = 0;
    bool autorized;

protected:
};

#endif // WORKSPACE_H
