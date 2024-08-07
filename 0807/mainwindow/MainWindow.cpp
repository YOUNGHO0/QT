//
// Created by lee on 2024. 8. 7..
//

#include "MainWindow.h"
#include "MainWindow.h"
#include <QMenuBar>
#include <QApplication>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QDockWidget>
#include <QMdiSubWindow>
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {

     mdiArea = new QMdiArea(this);
     setCentralWidget(mdiArea);

     edit = new QTextEdit(this);
    mdiArea->addSubWindow(edit);

    QMenuBar * menuBar =new QMenuBar(this);
    setMenuBar(menuBar);
    //
    QAction *newAct = new QAction(QIcon("image.png"),"&newFile",this);
    QAction *act2 = makeAction("image.png",tr("&New"), tr("Ctrl+Q"),tr("make new file"),this,SLOT(newFile()));
    QAction * quitAct = makeAction("image.png","&Edit",tr("Ctrl+Q"),tr("Quit this program"),qApp,SLOT(quit()));
    newAct->setShortcut(tr("Ctrl+A"));
    newAct->setStatusTip(tr("make new File"));
    connect(newAct,  &QAction::triggered, this,&MainWindow::newFile);

    QMenu *fileMenu = menuBar->addMenu("&File");
    QMenu *editMenu = menuBar->addMenu("&Edit");
    fileMenu->addAction(newAct);
    editMenu->addAction(quitAct);
    editMenu->addAction(act2);

    QStatusBar *statusbar = statusBar();
    QLabel * statusLabel = new QLabel(tr("QT Editor"), statusbar);
    statusLabel->setObjectName("statusLabel");
    statusbar->showMessage("started",1500);
    fileMenu->addAction(act2);

    QToolBar* fileToolbar = addToolBar("&File");
    fileToolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolbar->addAction(newAct);

    fileToolbar->addSeparator();
    fileToolbar->addAction(quitAct);
    QMenu *windowMenu = menuBar->addMenu("&window");
    QMenu* toolbarMenu = windowMenu->addMenu("&toolBar");
    toolbarMenu->addAction(fileToolbar->toggleViewAction());

    QFontComboBox *fontCombobox = new QFontComboBox(mdiArea);


    addToolBarBreak();
    QToolBar *formatToolbar = addToolBar("&Format");
    QDoubleSpinBox *sizeSpinBox = new QDoubleSpinBox(this);

    formatToolbar->addSeparator();
    formatToolbar->addWidget(fontCombobox);
    formatToolbar->addWidget(sizeSpinBox);

    QMenu *myMenu = menuBar->addMenu("op");

    connect(sizeSpinBox,&QDoubleSpinBox::valueChanged, edit,&QTextEdit::setFontPointSize);
    QAction * action = makeAction("image.png","undo", "Ctrl+o","Hello",this,SLOT(undo()));
    QAction * action1 = makeAction("image.png","Copy", "Ctrl+p","Hello",this,SLOT(copy()));
    QAction * action2 = makeAction("image.png","paste", "Ctrl+q","Hello",this,SLOT(paste()));
    QAction * redo = makeAction("image.png","redo", "Ctrl+q","Hello",this,SLOT(redo()));
    // QAction * zoomin= makeAction("image.png","zoomin", "Ctrl+q","Hello",edit,SLOT(zoomin()));
    // QAction * zoomout= makeAction("image.png","zoomout", "Ctrl+1","Hello",edit,SLOT(zoomout()));
    myMenu->addAction(redo);
    // myMenu->addAction(zoomin);
    // myMenu->addAction(zoomout);
    myMenu->addAction(action);
    myMenu->addAction(action1);
    myMenu->addAction(action2);

    QDockWidget *dock = new QDockWidget("Dock Widget",mdiArea);
    dock ->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    dock->setWidget(mdiArea);


    toolbarMenu ->addAction(dock->toggleViewAction());



}


QAction * MainWindow::makeAction(QString icon, QString text, QString shortCut, QString tooltip, QObject *recv,
    const char *slot) {
    qDebug() << "make Action";
    QAction* act = new QAction(text ,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    connect(act,SIGNAL(triggered()), recv,slot);
    return act;
}

void MainWindow::undo() {
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    QTextEdit*textEdit = (QTextEdit*)subWindow->widget();
    textEdit->undo();
}

void MainWindow::redo() {
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    QTextEdit*textEdit = (QTextEdit*)subWindow->widget();
    textEdit->redo();
}

void MainWindow::copy() {
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    QTextEdit*textEdit = (QTextEdit*)subWindow->widget();
    textEdit->copy();
}

void MainWindow::paste() {
    qDebug()<< "notworking";
    QMdiSubWindow* subWindow = mdiArea->currentSubWindow();
    QTextEdit*textEdit = (QTextEdit*)subWindow->widget();
    textEdit->paste();
}

QTextEdit* MainWindow::newFile() {

    qDebug() << "make";
    QTextEdit *textEdit = new QTextEdit;
    mdiArea->addSubWindow(textEdit);

    textEdit->show();
    return textEdit;

}
