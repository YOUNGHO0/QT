#include <QApplication>
#include <QPushButton>

#include "Widget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Widget w;
    w.resize(300,500);
    w.show();
    return QApplication::exec();
}
