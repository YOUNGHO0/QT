//
// Created by lee on 2024. 8. 7..
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include <QTextEdit>
#include <QMdiArea>
class MainWindow : public QMainWindow {

    Q_OBJECT
public:
    QTextEdit *edit;
    QMdiArea * mdiArea;
    MainWindow(QWidget *parent = 0);
    ~MainWindow(){};
    QAction * makeAction(QString icon, QString text, QString shortCut, QString tooltip, QObject*recv,const char*slot);

public slots:
    QTextEdit* newFile();
    void undo();
    void redo();
    void copy();
    void paste();


};




#endif //MAINWINDOW_H
