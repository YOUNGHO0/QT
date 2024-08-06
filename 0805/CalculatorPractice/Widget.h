//
// Created by lee on 2024. 8. 5..
//

#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <QtWidgets/qwidget.h>
#include <QVBoxLayout>

class Widget : public QWidget{
    Q_OBJECT
public:
    QString prevNumber = "0";
    QString op = "";
    QLabel* label;
    void makeLabel();

    Widget(QWidget * parent = 0);

    ~Widget();

    void handleNumClick();
    void handleOpClick();
    signals:
    void NumClicked();
    void OpClicked();

};



#endif //WIDGET_H
