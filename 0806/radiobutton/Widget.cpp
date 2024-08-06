//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) {

    resize(140,110);
    buttonGroup = new QButtonGroup(this);
    for(int i =0; i<4; i++) {
        QString str = QString("RadioBUtton %1").arg(i+1);
        radioButton[i] = new QRadioButton(str,this);
        radioButton[i]->move(10,10+20*i);
        buttonGroup-> addButton(radioButton[i]);
    }

    connect(buttonGroup,&QButtonGroup::buttonClicked,this,[=]() {

        // for(int i =0; i<4; i++) {
        //     if(radioButton[i] -> isChecked())
        //         qDebug() <<"----" << radioButton[i] ->text();
        // }
    });

}
