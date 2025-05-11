#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->leaderboard->setColumnCount(2);
    ui->leaderboard->setHorizontalHeaderLabels({"Имя", "Попытки"});
    ui->leaderboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Form::~Form()
{
    delete ui;
}


int Form::addToLeaderboard(const QString &name, int attempts)
{
    int rows = ui->leaderboard->rowCount();
    int max = -1;

    if (rows > 0) {
        max = ui->leaderboard->item(rows - 1, 1)->text().toInt();
    }


    if (rows >= 3) {
        if (ui->leaderboard->item(2, 1)->text().toInt() > attempts) {
            ui->leaderboard->removeRow(2);
            ui->leaderboard->insertRow(2);
            ui->leaderboard->setItem(2, 0, new QTableWidgetItem(name));
            ui->leaderboard->setItem(2, 1, new QTableWidgetItem(QString::number(attempts)));
            ui->leaderboard->sortItems(1, Qt::AscendingOrder);
            max = ui->leaderboard->item(rows - 1, 1)->text().toInt();
            return max;
        }
        else {
            return max;
        }
    }


    ui->leaderboard->insertRow(rows);
    ui->leaderboard->setItem(rows, 0, new QTableWidgetItem(name));
    ui->leaderboard->setItem(rows, 1, new QTableWidgetItem(QString::number(attempts)));
    ui->leaderboard->sortItems(1, Qt::AscendingOrder);

    max = ui->leaderboard->item(rows, 1)->text().toInt();
    return max;
}

