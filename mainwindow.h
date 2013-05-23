#include<QPushButton>
#include<QDialog>
#include "jokeLabel.h"
#include<QLabel>
#include<QScrollArea>
class JokeLabel;
class MainWindow : public QDialog
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createPushButton();
    void jokeLayout();
    void initAllLabel();
signals:
    
public slots:
    void showJoke();
    void showInterJoke ();
private:
 JokeLabel *label;
 InternetJoke *interJoke;  
 QLabel *titleLabel;
  QScrollArea *scrollArea;
 QPushButton *quitButton;
 QPushButton *refreshButton;
 QPushButton *interfreshButton;
  int x;
};
