#include <iostream>
#include <QApplication>
#include <QPushButton>

class T {
public:
    int num;
    T(){};
    ~T(){};
};

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QPushButton * pushButton = new QPushButton("", 0);
    pushButton->setShortcut(QKeySequence("a"));
    pushButton->setCheckable(true);

    pushButton->setIcon(QIcon("resource/images.png"));
    pushButton->setIconSize(QSize(1000,1000));
    pushButton->
    QObject::connect(pushButton,&QPushButton::toggled, [&](bool flag) {

        std::cout << "hello"<< std::endl;

    });
    pushButton->show();
    return a.exec();
}
