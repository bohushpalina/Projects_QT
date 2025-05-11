#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    int addToLeaderboard(const QString &name, int attempts);

private:
    Ui::Form *ui;
};

#endif // FORM_H
