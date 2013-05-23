#include "mainwindow.h"
#include<QHBoxLayout>
#include<QDebug>
#include<QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    label(new JokeLabel),interJoke(new InternetJoke),titleLabel(new QLabel),
    scrollArea(new QScrollArea),
    quitButton(new QPushButton(tr("Quit"),this)),
    refreshButton(new QPushButton(this)),
    interfreshButton(new QPushButton(this))
      
{
    x=1;
    /*设置MainWindow的风格：背景图片及其位置*/
    setStyleSheet(QString::fromUtf8("background-color:grey;\
                                     border:none;"));
    setFixedSize (480,700);
    initAllLabel();
    createPushButton ();
    jokeLayout();
    connect(refreshButton,SIGNAL(released()),this,SLOT(showJoke()));
    connect(quitButton,SIGNAL(released()),this,SLOT(close()));
    connect(interfreshButton,SIGNAL(released()),this,SLOT(showInterJoke()));
    
}
void MainWindow::initAllLabel()
{
    label->setFixedWidth (450);
    label->setWordWrap(true);//text包裹在label中，实现自动换行
    label->setAlignment(Qt::AlignTop);//文字对齐 
    /*设置label的风格，颜色：黑，无边界，字体大小*/
    /*关于stylesheet可以参考qt文档的Qt StyleSheet Reference*/
    label->setStyleSheet (tr("color:white;border:none;font:bold normal;\
                             font-size: 18px"));            
    titleLabel->setFixedWidth (480);
    titleLabel->setText (tr("开心一笑"));
    titleLabel->setAlignment (Qt::AlignHCenter);
    titleLabel->setStyleSheet (tr("color:white;border:none;\
                                  font:bold normal;font-size: 26px"));
    titleLabel->setMargin (0);
    scrollArea->setWidget(label);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
void MainWindow::showJoke()
{
    refreshButton->clearFocus ();
    int n=std::rand()%67;//产生随机数
    label->setText(*label->jokeLoader (n));
    label->adjustSize ();
}
void MainWindow::showInterJoke()
{
    interfreshButton->clearFocus ();
    interJoke->requestHttp ();
    label->setText (*interJoke->joke);
    label->adjustSize ();
}
void MainWindow::jokeLayout ()
{
    QHBoxLayout *hboxlayout=new QHBoxLayout;
    hboxlayout->addWidget (refreshButton);
    hboxlayout->addWidget (interfreshButton);
    hboxlayout->addWidget (quitButton);
    
    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget (titleLabel);
    mainLayout->addWidget (scrollArea);
    mainLayout->addLayout(hboxlayout);
    setLayout(mainLayout);
}

MainWindow::~MainWindow ()
{
    delete label;
    delete titleLabel;
    delete interJoke;
    delete scrollArea;
    delete quitButton;
    delete refreshButton; 
    delete interfreshButton;
    
}

void MainWindow::createPushButton ()
{
    quitButton->setStyleSheet
                            (QString::fromUtf8\
                            ("background-image: url(:/toolbutton);\
                            background-position:center;\
                            border:none;color:white;\
                            font:  normal;\
                            font-size: 13px"));
    quitButton->setFixedSize (65,44);
    quitButton->setDefault (false);
    
    refreshButton->setStyleSheet
                                (QString::fromUtf8\
                                ("background-image: url(:/toolbutton);\
                                 background-position: center;\
                                 border:none;color:white;\
                                 font: normal ;\
                                 font-size: 13px;"));
    refreshButton->setText (tr("Joke"));
    refreshButton->setFixedSize (65,44);  
    refreshButton->setDefault (false);
    
    interfreshButton->setStyleSheet(QString::fromUtf8\
                                   ("background-image: url(:/toolbutton);\
                                    background-position: center;\
                                    border:none;color:white;\
                                    font: normal ;\
                                    font-size: 13px;"));
    interfreshButton->setText (tr("network"));
    interfreshButton->setFixedSize (65,44);  
    interfreshButton->setDefault (false);
}
