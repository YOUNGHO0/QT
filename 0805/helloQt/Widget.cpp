//
// Created by lee on 2024. 8. 5..
//

#include "Widget.h"

#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
void Widget::setLabel() {
    label = new QLabel("0",this);
    label->resize(300,100);
    label->setStyleSheet(
        "border: 2px solid black; "  // 2px 두께의 검정색 테두리
        "border-radius: 5px; "       // 테두리 모서리 둥글게
        "margin: 20px; "
        "text-align: right;" // 위젯 주변 여백 20px
    );
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

Widget::Widget(QWidget *parent): QWidget(parent) {
    this->resize(300,500);
    setLabel();

    QString buttonLabels[4][4] = {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", "C", "=", "+"}
    };

    QGridLayout *gridLayout = new QGridLayout;

    // Add buttons to grid layout
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            QPushButton *button = new QPushButton(buttonLabels[row][col], this);
            gridLayout->addWidget(button, row, col);
             connect(button, &QPushButton::clicked, this,[this,button]() {
                 onPushButtonClicked(button);
             } );
        }
    }

    QVBoxLayout *mainLayout = new QVBoxLayout;
    // mainLayout->addWidget(display);
    mainLayout->addLayout(gridLayout);
    this->setLayout(mainLayout);
    this->setFixedSize(300, 400); // Set the size of the widget



    // 위치 및 크기 설정




}

void Widget::slotQuit() {
    qDebug("slotQuit");
    std::cout<<"뭐지" <<std::endl;
}

void Widget::onPushButtonClicked(QPushButton * sender) {
    bool ok;
    double beforeNumber = label->text().toDouble(&ok);
    std::cout << "버튼 눌림" << sender->text().toStdString() << std::endl;
    std::string ty = sender->text().toStdString();
    char type = ty[0];
    switch  (type) {
        case '+':
            if(first != 0){
                double temp = this->label->text().toDouble();
                label->setText(QString::number(first +temp));
                first =0;
                return;
            }
            first = this->label->text().toDouble();
            label->setText(QString::number(0));
            this->op= '+';
            break;
        case '-':
            if(first != 0) {
                double temp = this->label->text().toDouble();
                label->setText(QString::number(first -temp));
                first =0;
                return;
            }
            first = this->label->text().toDouble();
        label->setText(QString::number(0));
            this->op = '-';
            break;
        case '/':
            if(first != 0) {
                double temp = this->label->text().toDouble();
                label->setText(QString::number(first /temp));
                first =0;
                return;
            }
            first = this->label->text().toDouble();
        label->setText(QString::number(0));
            this->op = '/';
            break;
        case '*':
            if(first != 0) {
                first = this->label->text().toDouble();
                double temp = this->label->text().toDouble();
                label->setText(QString::number(first *temp));
                first =0;
                return;
            }
            first = this->label->text().toDouble();
        label->setText(QString::number(0));
            this->op ='*';
            break;
        case 'C':
            this->op = NULL;
            this->label->setText("0");
            first =0;
            break;
        case '=':
            switch (op) {
                case '+':
                    label->setText(QString::number(label->text().toDouble()+first));
                    break;
                case '-':
                    label->setText(QString::number(first-label->text().toDouble()));
                    break;
                case '*':
                    label->setText(QString::number(first * label->text().toDouble()));
                case '/':
                    label->setText(QString::number(first / label->text().toDouble()));
            }

            first = 0;
            break;
        default:
            std::cout << "op" << op << std::endl;
            double sum = this->label->text().toDouble();
            sum *= 10;
            sum += sender->text().toDouble();
            this->label->setText(QString::number(sum));
            break;
    }
}
