#include "calculator.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon appIcon;
    //appIcon.addFile("/res/icons/16x16.png", QSize(16, 16));
    //appIcon.addFile("/res/icons/32x32.png", QSize(32, 32));
    appIcon.addFile(":/res/drawable-hdpi/48x48.png", QSize(48, 48));
    appIcon.addFile(":/res/drawable-mdpi/64x54.png", QSize(64, 64));
    appIcon.addFile(":/res/drawable-xhdpi/128x128.png", QSize(128, 128));
    //appIcon.addFile("/res/icons/256x256.png", QSize(256, 256));
    a.setWindowIcon(appIcon);


    Calculator w;
    w.setWindowIcon(appIcon);
    w.show();
    return a.exec();
}
