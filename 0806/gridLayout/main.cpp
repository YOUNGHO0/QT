#include <QApplication>
#include <QPushButton>
#include <QGridLayout>

#include "Widget.h"
#define NO_OF_ROW 3
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Widget w ;
    w.show();

    return QApplication::exec();
}
