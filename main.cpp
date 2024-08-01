#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "widgets/mainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow m1;

    return QApplication::exec();
}
