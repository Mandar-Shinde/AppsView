
#include <QApplication>
#include <QtNetwork>
#include "AppViewer.h"
#include "PLog.h"

PLog *logger;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    logger = new PLog();
    logger->InitLogFile("./","test.txt",DEBUG,1024*1024*2);

    AppViewer* window = new AppViewer;
    window->insert(AppItem("try","code","group","http://www.w3schools.com/images/tryitimg.gif"));
    window->insert(AppItem("lamp","code","group","http://www.w3schools.com/images/lamp.jpg"));


    window->init();
    window->show();

    return app.exec();
}
