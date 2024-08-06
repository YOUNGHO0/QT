#include <QApplication>
#include <QPushButton>
#include <QSpinBox>
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QSpinBox * box = new QSpinBox();

    box->resize(300,300);

    QObject::connect(box,&QSpinBox::valueChanged, [](int value) {
        qDebug() << value;
    });

    box->setStyleSheet("QSpinBox::up-button {"
                        "subcontrol-origin: padding;"
                        "subcontrol-position: top right;"
                        "width: 20px; height: 20px;"
                        "}"
                        "QSpinBox::down-button {"
                        "subcontrol-origin: padding;"
                        "subcontrol-position: bottom right;" |     8
                        "width: 20px; height: 20px;"
                        "}");

    box->show();
    return QApplication::exec();
}
