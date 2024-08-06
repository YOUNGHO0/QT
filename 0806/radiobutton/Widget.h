//
// Created by lee on 2024. 8. 6..
//

#ifndef WIDGET_H
#define WIDGET_H
#include <QtWidgets/qwidget.h>
#include <QRadioButton>
#include <QButtonGroup>
class Widget : public QWidget{
public:
    QButtonGroup * buttonGroup;
    QRadioButton* radioButton[4];
    Widget(QWidget * parent = 0);;
    ~Widget(){};


};



#endif //WIDGET_H
