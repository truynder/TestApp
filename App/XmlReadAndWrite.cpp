#include "XmlReadAndWrite.h"
#include "PjSipadptr.h"

/*void SaveXMLFile(PjSipadaptr *adptr){
    QMap<QString,QString> map;
    map["SipControllerList"]=adptr->sip_id.;
    map["SipDomain"]=adptr->
    map["StationLoginUser"]
    map["PrevSipUserAccount"]


    QFile *file=new QFile("config.xml");
    file->open(QIODevice::WriteOnly | QIODevice::ReadOnly);

     QXmlStreamWriter xmlWriter(file);
     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();

     xmlWriter.writeStartElement("data");
     QMapIterator<QString,QString> i(map);
     while(i.hasNext()){
      i.next();
      xmlWriter.writeStartElement("parametr");
      xmlWriter.writeTextElement("name", i.key() );
      xmlWriter.writeTextElement("value", i.value());
      xmlWriter.writeEndElement();
      }
      xmlWriter.writeEndElement();
      file->close();
}


QMap<QString,QString> ReadXMLFile(){
    QMap<QString,QString> map;
    QFile* xmlFile = new QFile("config.xml");
    xmlFile->open(QIODevice::ReadOnly | QIODevice::Text);
    QXmlStreamReader  *xmlReader = new QXmlStreamReader(xmlFile);

    *Просмотрим XML файл, пока не дойдем до конца.*
     while(!xmlReader->atEnd() && !xmlReader->hasError())
      {
         *Читаем следующий элемент.*
         QXmlStreamReader::TokenType token = xmlReader->readNext();
         *Если token StartDocument, продолжаем просмотр.*
         if(token == QXmlStreamReader::StartDocument)
           {
            continue;
            }
           *Если token это StartElement, просматриваем теги*
           if(token == QXmlStreamReader::StartElement)
            {
             if(xmlReader->name() == "name")
              {
               map.key(xmlReader->readElementText());
               }

              if(xmlReader->name() == "value")
               {
                map.value( xmlReader->readElementText());
                }
             }

       }
     return map;
}
*/

