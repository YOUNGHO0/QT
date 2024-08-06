#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QLineEdit * e = new QLineEdit();


    e->resize(300,100);
    e->show();
    e->setInputMask("ABC");
    QObject::connect(e,&QLineEdit::textChanged,[](QString text){std::cout <<text.toStdString()<<std::endl;});
    return QApplication::exec();


}
