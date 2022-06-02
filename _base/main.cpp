#include <_UI/exemainwlg.h>
#include <_base/exeGlobal.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    exeGlobal::init();
    ExeMainWlg w;
    w.show();
    return a.exec();
}
