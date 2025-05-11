#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent, int size)
    : QMainWindow(parent)
    , N(size), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons = new QPushButton**[N];
    arr = new int*[N];
    for (int i = 0; i < N; ++i) {
        buttons[i] = new QPushButton*[N];
        arr[i] = new int[N];
    }
    int but_size = 240 / N;


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            QPushButton* btn = new QPushButton("");
            btn->setFixedSize(but_size, but_size);
            btn->setStyleSheet(style);
            btn->setText("");
            buttons[i][j] = btn;
            connect(btn, SIGNAL(clicked()), this, SLOT(Clicked_button()));

            ui->gridLayout->addWidget(btn, i, j);
        }
    }

    on_Clear_clicked();
}
MainWindow::~MainWindow()
{
    delete ui;
    for (int i = 0; i < N; ++i) {
        delete[] buttons[i];
        delete[] arr[i];
    }
    delete[] buttons;
    delete[] arr;
}

void MainWindow::on_Clear_clicked()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            buttons[i][j]->setText("");
            buttons[i][j]->setStyleSheet(style);
        }
    }

    player_1 = true;
    playing = true;
    updateStatusPlayer();
}

void MainWindow::Clicked_button()
{
    QPushButton *q = qobject_cast<QPushButton*>(sender());
    if (!q || !q->text().isEmpty() || !playing) return;

    if (player_1)
        q->setText("X");
    else
        q->setText("0");

    check_game();

    if (!playing) return;

    player_1 = !player_1;
    updateStatusPlayer();

    if (vsComputer && !player_1 && playing)
    {
        computerMove();
        check_game();
    }
}

void MainWindow::computerMove()
{
    QTimer::singleShot(1000, this, [this]() {
        QVector<QPair<int, int>> emptyCells;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (buttons[i][j]->text().isEmpty())
                    emptyCells.append({i, j});
            }
        }

        if (!emptyCells.isEmpty())
        {
            int idx = QRandomGenerator::global()->bounded(emptyCells.size());
            int x = emptyCells[idx].first;
            int y = emptyCells[idx].second;

            buttons[x][y]->setText("0");
            check_game();

            if (playing)
            {
                player_1 = true;
                updateStatusPlayer();
            }
        }
    });
}

void MainWindow::updateStatusPlayer()
{
    if (!vsComputer)
        ui->Player->setText(player_1 ? "Player 1" : "Player 2");
    if (vsComputer)
        ui->Player->setText(player_1 ? "Player 1" : "Computer");
}

void MainWindow::check_game()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            QPushButton* btn = buttons[i][j];
            if (btn->text() == "")
                arr[i][j] = 0;
            if (btn->text() == "X")
                arr[i][j] = 1;
            if (btn->text() == "0")
                arr[i][j] = 2;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 2; ++j)
        {
            if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2] && arr[i][j]) {
                playing = false;
                buttons[i][j]->setStyleSheet(winStyle);
                buttons[i][j + 1]->setStyleSheet(winStyle);
                buttons[i][j + 2]->setStyleSheet(winStyle);
                ui->Player->setText((arr[i][j] == 1 ? "Winner: Player 1" : (vsComputer ? "Winner: Computer" : "Winner: Player 2")));
                return;
            }

            if (arr[j][i] == arr[j + 1][i] && arr[j][i] == arr[j + 2][i] && arr[j][i]) {
                playing = false;
                buttons[j][i]->setStyleSheet(winStyle);
                buttons[j + 1][i]->setStyleSheet(winStyle);
                buttons[j + 2][i]->setStyleSheet(winStyle);
                ui->Player->setText((arr[j][i] == 1 ? "Winner: Player 1" : (vsComputer ? "Winner: Computer" : "Winner: Player 2")));
                return;
            }
        }
    }

    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = 0; j < N - 2; ++j)
        {
            if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j]) {
                playing = false;
                buttons[i][j]->setStyleSheet(winStyle);
                buttons[i + 1][j + 1]->setStyleSheet(winStyle);
                buttons[i + 2][j + 2]->setStyleSheet(winStyle);
                ui->Player->setText((arr[i][j] == 1 ? "Winner: Player 1" : (vsComputer ? "Winner: Computer" : "Winner: Player 2")));
                return;
            }

            if (arr[i][j + 2] == arr[i + 1][j + 1] && arr[i][j + 2] == arr[i + 2][j] && arr[i][j + 2]) {
                playing = false;
                buttons[i][j + 2]->setStyleSheet(winStyle);
                buttons[i + 1][j + 1]->setStyleSheet(winStyle);
                buttons[i + 2][j]->setStyleSheet(winStyle);
                ui->Player->setText((arr[i][j + 2] == 1 ? "Winner: Player 1" : (vsComputer ? "Winner: Computer" : "Winner: Player 2")));
                return;
            }
        }
    }


    bool draw = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] == 0) {
                draw = false;
                break;
            }
        }
    }

    if (draw) {
        playing = false;
        ui->Player->setText("DRAW");
    }

}

void MainWindow::on_checkBox_checkStateChanged(const Qt::CheckState &state)
{
    vsComputer = (state == Qt::Checked);
    on_Clear_clicked();
}

