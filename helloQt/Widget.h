//
// Created by lee on 2024. 8. 5..
//

#ifndef WIDGET_H
#define WIDGET_H
#include <QLabel>
#include <qpushbutton.h>
#include <QWidget>

class Widget : public QWidget {
    Q_OBJECT;
public:
    QLabel * label;
    void setLabel();
    Widget(QWidget * parent = 0);
    double first = 0;
    char op = NULL;
public slots:
    void slotQuit();

    void onPushButtonClicked(QPushButton *sender);
    signals:
        void opClicked();
        void numClicked();

};



#endif //WIDGET_H
