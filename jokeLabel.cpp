#include "jokeLabel.h"
#include<QFile>
#include<QXmlStreamReader>
#include<QTextCodec>
#include<QTextStream>
JokeLabel::JokeLabel(QWidget *parent)
    : QLabel(parent),
    joke(new QString)
{
    
}
QString* JokeLabel::jokeLoader (int n)
{
    /*通过QFile打开birhtday.xml,QTextStream读取birthday.xml 通过QTextStream设置编码显示中文，然后通过QXmlStreamReader处理xml文件*/
    QFile xmlFile(":/birthday.xml");   
    if (!xmlFile.exists() || (xmlFile.error() != QFile::NoError)) {
        return 0;
    }
    xmlFile.open(QIODevice::ReadOnly);
    QTextStream textReader(&xmlFile);
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    textReader.setCodec(codec);//转换显示中文
    QString content = textReader.readAll();
    xmlFile.close ();
    QXmlStreamReader reader(content);
    while (!reader.atEnd()) {
        reader.readNext();
        if (reader.isStartElement()&&
            reader.name ()=="joke"&&
            reader.attributes().value ("id").toString ().toInt()==n) {//获取随机数对应的joke
            *joke= reader.attributes().value("content").toString ();
            break;
         }
    }
   return joke;    
}


JokeLabel::~JokeLabel()
{
    
}
