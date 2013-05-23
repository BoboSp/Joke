#include<QLabel>
#include"internetjoke.h"
class JokeLabel : public QLabel
{
    Q_OBJECT  
public:
    JokeLabel(QWidget *parent = 0);
    ~JokeLabel();
    QString *jokeLoader(int n);
    QString *joke;
};

