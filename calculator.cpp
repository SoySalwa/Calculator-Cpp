#include "calculator.h"
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QtMath>
#include <iostream>
#include <QApplication>
#include "exprtk/exprtk.hpp"
#include "styles.h"

Styles styles;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
{
    createLayoutCalculator();
}

void Calculator::createLayoutCalculator() {
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setStyleSheet("background-color: black");
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Display
    QVBoxLayout* screen = new QVBoxLayout(this);
    screen->setContentsMargins(20, 0, 20, 0);
    screen->setAlignment(Qt::AlignRight | Qt::AlignBottom);

    cl_count = new QLabel("", this);
    cl_count->setObjectName("Counter");
    cl_count->setStyleSheet(styles.display());
    cl_count->setAlignment(Qt::AlignRight | Qt::AlignBottom);

    cl_result = new QLabel("", this);
    cl_result->setObjectName("result");
    cl_result->setStyleSheet(styles.messageResult());
    cl_result->setAlignment(Qt::AlignRight | Qt::AlignBottom);
    cl_result->setVisible(false);

    screen->addWidget(cl_count);
    screen->addWidget(cl_result);

    mainLayout->addLayout(screen);

    QWidget* specials = new QWidget(this);
    specials->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    specials->setStyleSheet("background-color: gray;");
    QGridLayout* special_layout = new QGridLayout(specials);

    special_layout->setSpacing(10);
    // Primera fila
    QPushButton* button_SIN = new QPushButton("sin", this);
    button_SIN->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_SIN->setStyleSheet(styles.specialButtons());

    QPushButton* button_COS = new QPushButton("cos", this);
    button_COS->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_COS->setStyleSheet(styles.specialButtons());

    QPushButton* button_TAN = new QPushButton("tan", this);
    button_TAN->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_TAN->setStyleSheet(styles.specialButtons());

    QPushButton* button_LOG = new QPushButton("log", this);
    button_LOG->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_LOG->setStyleSheet(styles.specialButtons());

    QPushButton* button_LN = new QPushButton("ln", this);
    button_LN->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_LN->setStyleSheet(styles.specialButtons());

    // Segunda fila

    QPushButton* button_PLeft = new QPushButton("(", this);
    button_PLeft->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_PLeft->setStyleSheet(styles.specialButtons());

    QPushButton* button_PRight = new QPushButton(")", this);
    button_PRight->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_PRight->setStyleSheet(styles.specialButtons());

    QPushButton* button_Sqr = new QPushButton("^", this);
    button_Sqr->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_Sqr->setStyleSheet(styles.specialButtons());

    QPushButton* button_R = new QPushButton("Raiz", this);
    button_R->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_R->setStyleSheet(styles.specialButtons());

    QPushButton* button_ex = new QPushButton("!", this);
    button_ex->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    button_ex->setStyleSheet(styles.specialButtons());

    // Agregar botones al grid
    special_layout->addWidget(button_SIN, 0, 0);
    special_layout->addWidget(button_COS, 0, 1);
    special_layout->addWidget(button_TAN, 0, 2);
    special_layout->addWidget(button_LOG, 0, 3);
    special_layout->addWidget(button_LN, 0, 4);

    special_layout->addWidget(button_PLeft, 1, 0);
    special_layout->addWidget(button_PRight, 1, 1);
    special_layout->addWidget(button_Sqr, 1, 2);
    special_layout->addWidget(button_R, 1, 3);
    special_layout->addWidget(button_ex, 1, 4);

    // Layout para los botones
    QGridLayout* gd_layout = new QGridLayout();

    // Primera fila
    QPushButton* button_AC = new QPushButton("AC", this);
    button_AC->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_AC->setStyleSheet(styles.OperationButtons());

    QPushButton* button_C = new QPushButton("C", this);
    button_C->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_C->setStyleSheet(styles.OperationButtons());

    QPushButton* button_Percent = new QPushButton("%", this);
    button_Percent->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_Percent->setStyleSheet(styles.OperationButtons());

    QPushButton* button_Divide = new QPushButton("/", this);
    button_Divide->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_Divide->setStyleSheet(styles.OperationButtons());

    // Segunda fila
    QPushButton* button_7 = new QPushButton("7", this);
    button_7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_7->setObjectName("commonButtons");
    button_7->setStyleSheet(styles.CommonButtons());

    QPushButton* button_8 = new QPushButton("8", this);
    button_8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_8->setObjectName("commonButtons");
    button_8->setStyleSheet(styles.CommonButtons());

    QPushButton* button_9 = new QPushButton("9", this);
    button_9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_9->setObjectName("commonButtons");
    button_9->setStyleSheet(styles.CommonButtons());

    QPushButton* button_multiply = new QPushButton("*", this);
    button_multiply->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_multiply->setStyleSheet(styles.OperationButtons());

    // Tercera fila
    QPushButton* button_4 = new QPushButton("4", this);
    button_4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_4->setObjectName("commonButtons");
    button_4->setStyleSheet(styles.CommonButtons());

    QPushButton* button_5 = new QPushButton("5", this);
    button_5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_5->setStyleSheet(styles.CommonButtons());

    QPushButton* button_6 = new QPushButton("6", this);
    button_6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_6->setObjectName("commonButtons");
    button_6->setStyleSheet(styles.CommonButtons());

    QPushButton* button_sustr = new QPushButton("-", this);
    button_sustr->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_sustr->setStyleSheet(styles.OperationButtons());

    // Cuarta fila
    QPushButton* button_1 = new QPushButton("1", this);
    button_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_1->setObjectName("commonButtons");
    button_1->setStyleSheet(styles.CommonButtons());

    QPushButton* button_2 = new QPushButton("2", this);
    button_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_2->setObjectName("commonButtons");
    button_2->setStyleSheet(styles.CommonButtons());

    QPushButton* button_3 = new QPushButton("3", this);
    button_3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_3->setObjectName("commonButtons");
    button_3->setStyleSheet(styles.CommonButtons());

    QPushButton* button_add = new QPushButton("+", this);
    button_add->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    button_add->setStyleSheet(styles.OperationButtons());

    // Quinta fila
    QPushButton* button_00 = new QPushButton("00", this);
    button_00->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_00->setObjectName("commonButtons");
    button_00->setStyleSheet(styles.CommonButtons());

    QPushButton* button_0 = new QPushButton("0", this);
    button_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_0->setObjectName("commonButtons");
    button_0->setStyleSheet(styles.CommonButtons());

    QPushButton* button_dot = new QPushButton(".", this);
    button_dot->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_dot->setStyleSheet(styles.CommonButtons());

    QPushButton* button_equal = new QPushButton("=", this);
    button_equal->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    button_equal->setStyleSheet(styles.OperationButtons());

    // Agregar botones al grid
    gd_layout->addWidget(button_AC, 0, 0);
    gd_layout->addWidget(button_C, 0, 1);
    gd_layout->addWidget(button_Percent, 0, 2);
    gd_layout->addWidget(button_Divide, 0, 3);

    gd_layout->addWidget(button_7, 1, 0);
    gd_layout->addWidget(button_8, 1, 1);
    gd_layout->addWidget(button_9, 1, 2);
    gd_layout->addWidget(button_multiply, 1, 3);

    gd_layout->addWidget(button_4, 2, 0);
    gd_layout->addWidget(button_5, 2, 1);
    gd_layout->addWidget(button_6, 2, 2);
    gd_layout->addWidget(button_sustr, 2, 3);

    gd_layout->addWidget(button_1, 3, 0);
    gd_layout->addWidget(button_2, 3, 1);
    gd_layout->addWidget(button_3, 3, 2);
    gd_layout->addWidget(button_add, 3, 3);

    gd_layout->addWidget(button_00, 4, 0);
    gd_layout->addWidget(button_0, 4, 1);
    gd_layout->addWidget(button_dot, 4, 2);
    gd_layout->addWidget(button_equal, 4, 3);

    connect(button_AC, &QPushButton::clicked, this, &Calculator::onClearClick);
    connect(button_C, &QPushButton::clicked, this, &Calculator::onBackClick);
    connect(button_Percent, &QPushButton::clicked, this, &Calculator::onOperatorClick);
    connect(button_Divide, &QPushButton::clicked, this, &Calculator::onOperatorClick);

    connect(button_7, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_8, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_9, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_multiply, &QPushButton::clicked, this, &Calculator::onOperatorClick);

    connect(button_4, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_5, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_6, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_sustr, &QPushButton::clicked, this, &Calculator::onOperatorClick);

    connect(button_1, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_2, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_3, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_add, &QPushButton::clicked, this, &Calculator::onOperatorClick);

    connect(button_00, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_0, &QPushButton::clicked, this, &Calculator::onCommonClicked);
    connect(button_dot, &QPushButton::clicked, this, &Calculator::onCommonClicked);

    connect(button_equal, &QPushButton::clicked, this, &Calculator::onEqualTo);

    mainLayout->addWidget(specials);
    mainLayout->addLayout(gd_layout);
}

void Calculator::onClearClick() {
    if (cl_count) cl_count->setText("");
    if (cl_result) {
        cl_result->setText("");
        cl_result->setVisible(false);
    }

    stateError = false;
    lastNumeric = false;
    lastDot = false;
}

void Calculator::onBackClick() {
    if (cl_count) {
        QString text = cl_count->text();
        //QString text_result = cl_result->text();

        if (!text.isEmpty()) {
            text.chop(1);
            cl_count->setText(text);
            cl_result->setVisible(true);

            if (text.isEmpty()) {
                lastNumeric = false;
                lastDot = false;
            } else {
                QChar lastChar = text.at(text.length() - 1);
                lastNumeric = lastChar.isDigit() || lastChar == '.';
                lastDot = (lastChar == '.');
            }
        }
    }
}

void Calculator::onOperatorClick() {
    QPushButton* button_values = qobject_cast<QPushButton*>(sender());
    button_values->setAutoRepeat(false);
    QString button_text = button_values->text();

    if (!stateError && lastNumeric) {
        cl_count->setText(cl_count->text().append(button_text));
        lastDot = false;
        lastNumeric = false;
    }
    onEqualTo();
}

void Calculator::onEqualTo() {
    if (!cl_count || !cl_result) {
        qWarning() << "Error: No se encontraron los QLabel.";
        return;
    }

    if (lastNumeric && !stateError) {
        QString expressionText = cl_count->text();
        std::string exprStr = expressionText.toStdString();

        exprtk::expression<double> expression;
        exprtk::parser<double> parser;

        if (!parser.compile(exprStr, expression)) {
            qWarning() << "Error: No se pudo compilar la expresión.";
            cl_result->setText("Error de sintaxis");
            cl_result->setVisible(true);
            stateError = true;
            lastNumeric = false;
            return;
        }

        try {
            double result = expression.value();
            QString resultStr = QString::number(result, 'g', 10);
            cl_result->setText("= " + resultStr);
            cl_result->setVisible(true);
        } catch (const std::exception &e) {
            qWarning() << "Error de evaluación:" << e.what();
            cl_result->setText("Error matemático");
            cl_result->setVisible(true);
            stateError = true;
            lastNumeric = false;
        }
    }
}


void Calculator::onCommonClicked() {
    QPushButton* button_values = qobject_cast<QPushButton*>(sender());
    button_values->setAutoRepeat(false);
    QString button_text = button_values->text();

    if (stateError) {
        cl_count->setText(button_text);
        stateError = false;
    } else {
        cl_count->setText(cl_count->text().append(button_text));
    }

    lastNumeric = true;
}

Calculator::~Calculator() {}
