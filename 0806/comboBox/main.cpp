#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QComboBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QComboBox* combo_box;
    combo_box = new QComboBox();
    combo_box->addItem("hello");
    combo_box->addItem("hi");
    combo_box->setEditable(true);
    combo_box->addItems();
    combo_box->show();

    QObject::connect(combo_box,&QComboBox::editTextChanged,[](QString s) {
        std::cout << "¹¹Áö" << Qt::endl;
        qDebug() << s;
    });

    QObject::connect(combo_box,&QComboBox::currentTextChanged, [](QString s) {
       qDebug()<< s;
    });
    return QApplication::exec();

}
