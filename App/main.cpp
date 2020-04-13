#include <iostream>
#include <pjsua2.hpp>
#include <pjsua.h>
#include <pjlib.h>
#include <pjsua-lib/pjsua.h>
#include <pjsua-lib/pjsua_internal.h>
#include <QString>
#include <PjSipadptr.h>
#include "mainwindow.h"
#include <QApplication>
#include <pj/pool.h>
#include <app_config.h>
#include <readXmlFile.h>





int main(int argc, char *argv[])
{
 QApplication a(argc, argv);
 MainWindow w;
 w.show();
 return a.exec();
}


