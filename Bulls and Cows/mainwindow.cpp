#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->info->setText("Игра не начата");
    ui->new_game->setText("Новая игра");
    ui->results->clear();
    ui->results->setColumnCount(3);
    QStringList headers;
    headers << "Число" << "Быки" << "Коровы";
    ui->results->setHorizontalHeaderLabels(headers);
    ui->results->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    playing = false;
    ui->lineEdit->setEnabled(false);

    leaderboardForm = new Form();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete leaderboardForm;
}

void MainWindow::on_new_game_clicked()
{
    if (ui->new_game->text() == "Новая игра")
    {
        ui->info->setText("Игра началась!");
        number = generate_num();
        ui->new_game->setText("Сдаться");
        playing = true;
        int rowCount = ui->results->rowCount();
        for (int row = 0; row < rowCount; ++row) {
            ui->results->removeRow(0);
        }
        ui->lineEdit->clear();
        ui->lineEdit->setEnabled(true);
        qDebug() << number;
    }
    else
    {
        ui->info->setText("Игра не начата");
        ui->new_game->setText("Новая игра");
        playing = false;
        ui->lineEdit->clear();
        ui->lineEdit->setEnabled(false);
    }
}


void MainWindow::on_Check_but_clicked()
{
    Enter = ui->lineEdit->text();
    if (playing)
    {
        bool ok;
        int enter_num = Enter.toInt(&ok);
        QString str_num = QString::number(number);

        if (!ok) {
            ui->info->setText("Это не число!");
            return;
        }

        if (enter_num > 9999 || enter_num < 1000) {
            ui->info->setText("Это не 4-ех значное число!");
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (Enter[i] == Enter[j] && i != j)
                {
                    ui->info->setText("Совпадают цифры!");
                    return;
                }
            }
        }


        int b = 0;
        int cows = 0;

        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (str_num[i] == Enter[j])
                    cows += 1;
            }
            if (str_num[i] == Enter[i])
                b += 1;
        }
        cows -= b;
        trys += 1;
        if (!check_game(b)){

        QStringList row;
        row << Enter << QString::number(b) << QString::number(cows);

        int rowIndex = ui->results->rowCount();
        ui->results->insertRow(rowIndex);

        for (int col = 0; col < 3; ++col) {
            ui->results->setItem(rowIndex, col, new QTableWidgetItem(row[col]));
        }
        ui->info->setText("Попробуйте еще");
        ui->lineEdit->clear();
        }
    }

}


int MainWindow::generate_num()
{
    int number_1 = QRandomGenerator::global()->bounded(1, 10);
    int number_2 = QRandomGenerator::global()->bounded(10);
    while(number_1 == number_2)
    {
        number_2 = QRandomGenerator::global()->bounded(10);
    }
    int number_3 = QRandomGenerator::global()->bounded(10);
    while(number_1 == number_3 || number_2 == number_3)
    {
        number_3 = QRandomGenerator::global()->bounded(10);
    }
    int number_4 = QRandomGenerator::global()->bounded(10);
    while(number_1 == number_4 || number_2 == number_4 || number_3 == number_4)
    {
        number_4 = QRandomGenerator::global()->bounded(10);
    }
    return (number_1 * 1000 + number_2 * 100 + number_3 * 10 + number_4);
}



void MainWindow::on_records_clicked()
{
    leaderboardForm->show();

}

bool MainWindow::check_game(int b)
{
    if (b == 4)
    {
        ui->info->setText("Вы победили!");
        ui->new_game->setText("Новая игра");
        playing = false;

        if (rows_in_records < 3 || max_rec > trys)
        {
            bool ex;

            QString name = QInputDialog::getText(this, "Введите ваше имя", "Имя:", QLineEdit::Normal, "", &ex);

            if (ex && !name.isEmpty()) {
                max_rec = leaderboardForm->addToLeaderboard(name, trys);
                leaderboardForm->show();
                if (max_rec > trys)
                {++rows_in_records;}
            }
            trys = 0;
            return true;
        }
    }
    return false;

}
