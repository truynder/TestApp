#ifndef XMLREADANDWRITE_H
#define XMLREADANDWRITE_H
#include <QtXml/QtXml>

void SaveXMLFile(QString domain, QString port, QString user);
QMap<QString,QString> ReadXMLFile();

#endif // XMLREADANDWRITE_H
