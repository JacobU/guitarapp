#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget dw;

    w.setWindowTitle("Git-ar");
    w.show();
    return a.exec();
}
