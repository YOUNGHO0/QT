#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "Widget.h"

int main(int argc, char *argv[]) {
    QApplication q(argc, argv);
    // QWidget w;
    // QLabel hello("<font color= blue>" \
    //      "hello <i>Qt!</i> </font>",&w);
    // hello.show();
    // //
    // hello.resize(499,499);
    //
    // hello.movie();
    //
    // QPushButton quit("Quit", &w);
    // quit.resize(320,599);
    // quit.show();
    // // QObject::connect(&quit,SIGNAL(clicked()),&a,SLOT(quit()));
    //
    // QObject::connect(&quit,&QPushButton::clicked, &hello,[&](){quit.setText("hi");});
    // w.show();

    Widget w;

    w.show();


    return QApplication::exec();
}
