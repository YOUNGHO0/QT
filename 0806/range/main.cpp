#include <iostream>
#include <QApplication>
#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QStyleFactory>
#include <QDial>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QDial * dial = new QDial();
    dial-> setWrapping(true);
    dial -> setNotchesVisible(false);9
    QObject::connect(dial,&QDial::valueChanged,[](int value){std::cout<<value << std::endl; });

    dial->show();

    return QApplication::exec();
}
