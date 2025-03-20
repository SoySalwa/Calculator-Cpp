#include "styles.h"

QString Styles::OperationButtons() {
    QString op_styles = R"(
    QPushButton {
        background-color: "#000000";
        color: orange;
        font-size: 24pt;
        border: none;
        border-radius: 50px;
    }

    QPushButton:hover {
        background-color: rgba(0, 0, 0, 160);
        border: none;
        border-radius: 50px;
    }
    )";

    return op_styles;
}

QString Styles::CommonButtons() {
    QString cb_styles = R"(
    QPushButton {
        background-color: "#000000";
        color: #ffdc00;
        font-size: 24pt;
        border: none;
        border-radius: 50px;
    }

    QPushButton:hover {
        background-color: rgba(0, 0, 0, 160);
        border: none;
        border-radius: 50px;
    }
    )";

    return cb_styles;
}

QString Styles::display() {
    QString dp_styles = R"(
        QLabel {
            font-size: 32pt;
            qproperty-alignment: 'AlignRight | AlignBottom';
    }
    )";

        return dp_styles;
}


QString Styles::messageResult() {
    QString mr_styles = R"(
        QLabel {
            font-size: 24pt;
            color: rgba(255, 255, 255, 100);
            qproperty-alignment: 'AlignRight | AlignBottom';
    }
    )";

    return mr_styles;
}


QString Styles::specialButtons() {
    QString sp_styles = R"(
    QPushButton {
        background-color: none;
        color: rgba(255, 255, 255, 200);
        font-size: 16pt;
        border: none;
        border-radius: 50px;
        padding: 12px
    }
    )";

    return sp_styles;
}

Styles::Styles() {}
