//
// Created by lee on 2024. 8. 6..
//

#ifndef WIDGET_H
#define WIDGET_H
#include <QtWidgets/qwidget.h>
#include <QCheckBox>
#include <QButtonGroup>
class Widget : public QWidget{
public:
    // QButtonGroup * buttonGroup;
    // QRadioButton* radioButton[4];

    QCheckBox * checkBox[4];
    QButtonGroup *buttonGroup;
    Widget(QWidget * parent = 0);
    ~Widget(){};


    public slots:
    void selectButton(int id);

};



#endif //WIDGET_H
