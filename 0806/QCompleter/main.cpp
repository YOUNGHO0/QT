#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QStringList>
#include <QCompleter>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//  External e
    QLineEdit *line_edit = new QLineEdit();

    QStringList comPLetionList;
    comPLetionList << "hello" << "bryan"<< "kelvin"<< "Beth";
    QCompleter * stringCompleter = new QCompleter(comPLetionList,line_edit);
    stringCompleter -> setCaseSensitivity(Qt::CaseInsensitive);
    line_edit-> setCompleter(stringCompleter);
    line_edit->show();

    QObject::connect(line_edit,&QLineEdit::editingFinished,[=]() {
        qDebug() << "hello" << line_edit->text();
        //외부클래스 External에 id/pw입력값을 주저야 한다면
        // e.afterLogin(id,pw);


    });
    return QApplication::exec();
}
