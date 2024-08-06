//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"
#define NO_OF_ROW 3
#include <QGridLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent):QWidget(parent) {

    QGridLayout* grid_layout = new QGridLayout();
    QPushButton *pushButtoN[NO_OF_ROW *NO_OF_ROW];

    for(int i =0; i<NO_OF_ROW; i++) {

        for(int j =0;j<NO_OF_ROW; j++) {

            int p = i+j*NO_OF_ROW;
            QString str = QString("Button%1").arg(p+1);
            pushButtoN[p]= new QPushButton(str,this);
            grid_layout->addWidget(pushButtoN[p],i,j);
        }
    }

    setLayout(grid_layout);

}
