#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int generate_num();
    bool check_game(int);

private slots:
    void on_new_game_clicked();
    void on_Check_but_clicked();
    void on_records_clicked();

private:
    Ui::MainWindow *ui;
    Form* leaderboardForm;
    int number;
    bool playing = false;
    QString Enter;
    int trys = 0;
    int max_rec = 0;
    int rows_in_records = 0;
};
#endif // MAINWINDOW_H
