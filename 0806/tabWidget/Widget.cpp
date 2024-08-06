//
// Created by lee on 2024. 8. 6..
//

#include "Widget.h"

#include <QApplication>
#include <QDial>
#include <QCalendarWidget>
#include <QTextEdit>
#include <QTabWidget>
Widget::Widget(QWidget *parent): QWidget(parent) {
    resize(140,110);
    QDial *dial = new QDial(this);
    QCalendarWidget* calendarWidget = new QCalendarWidget(this);
    QTextEdit*textEdit = new QTextEdit("Tabb 3",this);
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->addTab(dial,"TaB &1");
    tabWidget->addTab(calendarWidget,"TAB &2");
    tabWidget->addTab(textEdit,"Tab & 3");
    resize(tabWidget->sizeHint());

}