//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) {
    resize(140,110);

    buttonGroup = new QButtonGroup(this);
     buttonGroup -> setExclusive(true);
       // connect(buttonGroup, &QButtonGroup::idClicked,&Widget::selectButton);
    connect(buttonGroup, &QButtonGroup::idClicked,this,&Widget::selectButton);

    for(int i =0; i<4; i++) {
        QString str = QString("checkBox %1").arg(i);
        checkBox[i] = new QCheckBox(str,this);
        checkBox[i]-> move(10,10+20*i);
        buttonGroup -> addButton(checkBox[i]);

    }

}

void Widget::selectButton(int id) {
    QCheckBox * check_box = qobject_cast<QCheckBox*>(sender());

    qDebug() << "Button with ID" << id << "was clicked." ;
}
