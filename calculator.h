#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLabel>

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    void createLayoutCalculator();
    void onClearClick();
    void onBackClick();
    void onEqualTo();
    void onOperatorClick();

    void onCommonClicked();

private:
    bool lastNumeric = false;
    bool stateError = false;
    bool lastDot = false;

    QLabel* cl_count;
    QLabel* cl_result;
};
#endif // CALCULATOR_H
