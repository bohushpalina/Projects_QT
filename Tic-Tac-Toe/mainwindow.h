#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QGridLayout>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, int size = 3);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateStatusPlayer();
    void check_game();
    void computerMove();


private slots:
    void on_Clear_clicked();
    void Clicked_button();

    void on_checkBox_checkStateChanged(const Qt::CheckState &arg1);

private:
    int N = 3;
    Ui::MainWindow *ui;
    QPushButton*** buttons;
    QGridLayout* gridLayout;
    bool player_1 = true;
    int** arr;
    bool playing = true;
    bool vsComputer = false;

    QString style = "font-size: 24px;"
                    "font-weight: bold;"
                    "color: #34495e;"
                    "background-color: #ecf0f1;"
                    "border: 2px solid #95a5a6;"
                    "border-radius: 10px;"
                    "min-width: 30px;"
                    "min-height: 30px;";

    QString winStyle = "font-size: 24px;"
                       "font-weight: bold;"
                       "color: green;"
                       "background-color: #ecf0f1;"
                       "border: 2px solid #95a5a6;"
                       "border-radius: 10px;"
                       "min-width: 30px;"
                       "min-height: 30px;";

};
#endif // MAINWINDOW_H
