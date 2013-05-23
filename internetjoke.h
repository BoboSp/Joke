#include<QDialog>
#include<QNetworkAccessManager>
class InternetJoke : public QDialog
{
    Q_OBJECT
    
public:
    InternetJoke(QWidget *parent = 0);
    ~InternetJoke();
    void requestHttp();
     QString *joke;
public slots:
     void showHttp(QNetworkReply *reply);
private:
    QNetworkAccessManager *networkAccess;
    QString *url;
    QTextCodec *codec;
   
};
