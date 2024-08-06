//
// Created by lee on 2024. 8. 5..
//

#include "Widget.h"

#include <iostream>
#include <QPushButton>
#include "QLabel"
#include <set>
#include <map>
#include <QGridLayout>
void Widget::makeLabel() {
    label = new QLabel("0",this);
    label->setFixedSize(300,100);
    label->setStyleSheet("border : 1px solid black;"
        "margin : 20px ");

    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
}

Widget::Widget(QWidget *parent):QWidget(parent) {

    makeLabel();

    QString str[4][4] = {
        "7","8","9","*",
        "4","5","6","-",
        "1","2","3","+",
        "0","C","=","/"
    };

    std::set<QString> mySet = {"+","-","*","/","C","="};

    QGridLayout * layout = new QGridLayout(this);
    for(int i =0; i<4; i++) {
        for(int j=0; j<4; j++) {
            QPushButton * q = new QPushButton(str[i][j],this);
            q->setFixedSize(70, 70);  // 정사각형 크기 설정
            q->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            if(mySet.count(q->text()) != 0) {
                QObject::connect(q,&QPushButton::clicked,this,&Widget::handleOpClick);
                layout->addWidget(q,i,j);
                continue;
            }
           layout->addWidget(q,i,j);
            QObject::connect(q,&QPushButton::clicked,this,&Widget::handleNumClick);
        }
    }




}

Widget::~Widget() {
}

void Widget::handleOpClick() {

    auto handleOperator = [&](auto func) {
        if(prevNumber !="0") {
            label->setText(func(prevNumber,label->text()));
            prevNumber = "0";
        }
        else {
            prevNumber = label->text();
            label->setText("0");
        }
    };
    auto plus = [&](QString s1, QString s2) {
        return QString::number(s1.toDouble() + s2.toDouble());
    };

    auto minus =[&](QString s1, QString s2) {
        return QString::number(s1.toDouble() - s2.toDouble());
    };

    auto multi = [&](QString s1, QString s2) {
        return QString::number(s1.toDouble() * s2.toDouble());
    };

    auto divide = [&](QString s1, QString s2) {
        return QString::number(s1.toDouble() / s2.toDouble());
    };
    auto clear = [&]() {
        prevNumber = "0";
        label->setText("0");
    };

    std::map<QString, std::function<QString(QString,QString)>> map = {{"+",plus},{"-",minus},{"*",multi},{"/",divide}} ;
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    auto equal =  [&]() {
        if(op != "") {
            QString chars = map.at(op)(prevNumber,label->text());
            label->setText(chars);
            prevNumber = "0";
        }
    };

    // 명령어 처리용 맵 (std::function<void()> 타입)
    std::map<QString, std::function<void()>> commandMap = {
        {"C", clear},
        {"=", equal}
    };

    if(map.find(button->text()) != map.end()) {
        op = button->text();
        handleOperator(map.at(button->text()));
    }
    else if(commandMap.find(button->text()) != commandMap.end() ) {
        commandMap.at(button->text())();
    }




}

void Widget::handleNumClick() {

    QPushButton * q = qobject_cast<QPushButton*>(sender());

    double num = label->text().toDouble();
    num*=10;
    num += q->text().toDouble();

    label->setText(QString::number(num));

    std::cout<< q->text().toStdString()<<std::endl;
}


