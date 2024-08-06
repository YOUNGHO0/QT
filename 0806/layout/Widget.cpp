//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"

#include <QPushButton>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent): QWidget(parent) {

    QPushButton *pushButton1 = new QPushButton();
    pushButton1->setText("button1");
    QPushButton *pushButton2 = new QPushButton();
    pushButton2->setText("button2");

    QPushButton *pushButton3 = new QPushButton();
    pushButton3->setText("button3");
    QHBoxLayout *layout = new QHBoxLayout();
    // QVBoxLayout *layout = new QVBoxLayout();
    layout-> setContentsMargins(0,0,0,0);
    layout-> addWidget(pushButton1);
    layout-> addWidget(pushButton2);
    layout-> addWidget(pushButton3);
    setLayout(layout);




}
