#include <QApplication>
#include <QPushButton>
#include <QTextBrowser>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QTextBrowser *tb = new QTextBrowser();
    tb->setSource(QUrl("https://www.naver.com"));
    tb->resize(500,500);
    tb->show();
    return QApplication::exec();
}
