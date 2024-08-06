//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>
Widget::Widget(QWidget *parent): QWidget(parent) {
    QStringList labels;
    labels << "&ID "<< "&PassWord" ;
    QLineEdit * lineEdit[2];

    QFormLayout *formLayout = new QFormLayout;
    for(int i =0; i<2; i++) {
        lineEdit[i] = new QLineEdit(this);
        formLayout-> addRow(labels.at(i), lineEdit[i]);
    }
    lineEdit[1]->setEchoMode(QLineEdit::Password);
    QGroupBox * groupBox = new QGroupBox("&login", this);
    groupBox->move(5,5);
    groupBox->setLayout(formLayout);
    resize(groupBox->sizeHint().width()+10,
            groupBox->sizeHint().height()+10);

}

