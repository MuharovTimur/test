#include "neworderform.h"
#include "ui_neworderform.h"
#include "spravka.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>

newOrderForm::newOrderForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newOrderForm)
{
    ui->setupUi(this);
    connect(ui->cancelBtn, &QPushButton::clicked, [=](){ delete(this); });
}

newOrderForm::~newOrderForm()
{
    delete ui;
}

void newOrderForm::on_doneBtn_clicked()
{
    QString name = ui->orderName->text();
    QDate date = ui->orderDate->date();
    QString email = ui->emailEdit->text();

    bool any;
    QString type;

    QString login = ui->login->text();
    QDate currentDate = QDate::currentDate();
    QString money = ui->moneyEdit->text();

    if (ui->illustration->isChecked()) type ="Иллюстрация"; any = true;
    if (ui->komix->isChecked()) type="Комикс"; any = true;
    if (ui->adMaterials->isChecked()) type ="Рекламные материалы"; any = true;
    if (ui->diagrams->isChecked()) type="Диаграммы"; any = true;
    if (ui->concept->isChecked()) type = "Концептуальные изображения"; any = true;
    if (ui->games->isChecked()) type = "Для игр"; any = true;
    if (ui->portrait->isChecked()) type = "Портрет"; any = true;
    if (ui->animation->isChecked()) type = "Анимация"; any = true;

    if (!any){QMessageBox::warning(this, "Предупреждение", "Выберите тип заказа!", QMessageBox::Ok);}

    if (date < currentDate) {QMessageBox::warning(this,"Предупреждение", "Введите другую дату",QMessageBox::Ok);}


    QString dateS = date.toString("dd.MM.yyyy");
    QFile file("C:/Users/987/Documents/orders.csv");
    if ( !file.open(QFile::Append) ) {
        qDebug() <<"File not exists";
    } else {
        QTextStream out(&file);
        out << login << ";" << name << ";" << dateS << ";" <<  type << ";" <<  money << ";" <<  email << ";" << "0" << endl;
        file.close();
    }

    emit sendInfo(name, date, type, money, email, "0");
    close();
}

void newOrderForm::on_pushButton_clicked()
{
    spravka* spravka1 = new spravka(this);
    spravka1->exec();
}

void newOrderForm::on_cancelBtn_clicked()
{
    reject();
}

