#include "readXmlFile.h"


bool isOpen(){
    QFile file("config.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "file no create";
            return false;
        }
    return true;
}

QMap<QString,QString> createDefaultConfig(){
   QMap<QString,QString> data;
   data["SipLogin"]="0001";
   data["SipDomain"]="192.168.129.70";
   data["SipPassword"]="123456";


   QFile *file=new QFile("config.xml");
   file->open(QIODevice::WriteOnly | QIODevice::ReadOnly);

    QXmlStreamWriter xmlWriter(file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("data");
    QMapIterator<QString,QString> i(data);
    while(i.hasNext()){
     i.next();
     xmlWriter.writeStartElement("parametr");
     xmlWriter.writeTextElement("name", i.key() );
     xmlWriter.writeTextElement("value", i.value());
     xmlWriter.writeEndElement();
     }
     xmlWriter.writeEndElement();
     file->close();
     return data;
}

QMap<QString,QString> ReadXMLFile(){
    QMap<QString,QString> map;
    QString name;
    QString value;
    QFile* xmlFile = new QFile("config.xml");
    xmlFile->open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader  *xmlReader = new QXmlStreamReader(xmlFile);

    if(isOpen()==true){
    /*Просмотрим XML файл, пока не дойдем до конца.*/
    while(!xmlReader->atEnd() && !xmlReader->hasError())
     {
      /*Читаем следующий элемент.*/
      QXmlStreamReader::TokenType token = xmlReader->readNext();
      /*Если token StartDocument, продолжаем просмотр.*/
      if(token == QXmlStreamReader::StartDocument)
       {
        continue;
        }
       /*Если token это StartElement, просматриваем теги*/
       if(token == QXmlStreamReader::StartElement)
        {
         if(xmlReader->name() == "name")
         {
         name=xmlReader->readElementText();
         }

         if(xmlReader->name() == "value")
          {
          value=xmlReader->readElementText();
          }

         }

         if(name!="" && value!=""){
         map.insert(name,value);
         }

      }
    }
    else{
    map=createDefaultConfig();
    }

    return map;
}


