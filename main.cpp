#include "mainwindow.h"
#include <QApplication>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
     QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));                      QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));//按钮显示中文不乱码
    MainWindow w;
    //w.showFullScreen ();
    w.show ();
    return a.exec();
}
