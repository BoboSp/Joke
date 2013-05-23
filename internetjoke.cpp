#include"internetjoke.h"
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QTextStream>
#include<QTextCodec>
InternetJoke::InternetJoke(QWidget *parent)
    : QDialog(parent),joke(new QString),
      networkAccess(new QNetworkAccessManager(this)),
    url(new QString("http://www.jokearea.com/")),
    codec(QTextCodec::codecForName("U-TF8"))
{
    requestHttp ();
    connect(networkAccess,SIGNAL(finished(QNetworkReply*))
            ,this,SLOT(showHttp(QNetworkReply*)));
}
void InternetJoke::requestHttp ()
{
    networkAccess->get(QNetworkRequest(QUrl(*url)));
}
void InternetJoke::showHttp (QNetworkReply *reply)
{
    int i,j;
    QTextStream textReader(reply);
    textReader.setCodec(codec);//转换显示中文
    QString content = textReader.readAll();
    content.simplified ();
    content.remove ("<br />");
    content.remove ("&nbsp");
    content.remove("&rdquo");
    content.remove (";");
    content.remove("\n");
    content.remove("</a>");
    content.remove ("hr/");
    content.remove ("&ldquo");
    content.remove ("&hellip");
    content.remove ("&quot");
    content.remove ("&mdash");
    if((j=content.indexOf("<p>", 0)) != -1) {
      if(( i=content.indexOf("</p>",j-5,Qt::CaseInsensitive))!=-1){
          *joke=content.mid(j+3,i-j-3);
       } 
     }
}

InternetJoke::~InternetJoke()
{
    delete joke;
    delete networkAccess;
    delete url;
}
