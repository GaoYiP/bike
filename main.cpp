#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/ICON/Icon/welcome2.jpg");
    pixmap.scaled(QApplication::desktop()->availableGeometry().size(),Qt::KeepAspectRatio);
    QSplashScreen splash(pixmap);
    splash.setDisabled(true);
    splash.show();
    QDateTime n = QDateTime::currentDateTime();
    QDateTime now;
    do{
        now = QDateTime::currentDateTime();
        a.processEvents();
    }while(n.secsTo(now)<=2);

    MainWindow w;
    QRect deskRect = QApplication::desktop()->availableGeometry();
    w.resize(deskRect.size());
    w.show();
    splash.finish(&w);

    return a.exec();
}
