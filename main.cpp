#include "exportdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExportDialog w;
    w.show();

    return a.exec();
}
