#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include "connection.h"

class Client:public Connection
{
    Q_OBJECT
public:
    Client(QTreeWidgetItem *,QGridLayout *);
    ~Client();
    QLineEdit* serverAddressInput=nullptr;
    QLineEdit* serverPortInput=nullptr;
private:
    QPushButton* connectButton=nullptr;
    QTcpSocket *qTcpSocket=nullptr;
    QTimer* timer=nullptr;
    QVBoxLayout* qVBoxLayoutLeft=nullptr;
    QLabel* qLabel1=nullptr;
    QLabel* qLabel2=nullptr;
    QLabel* qLabel=nullptr;    
    void receiveEdit_append(QString qString);
    void tcp_sendData();

private slots:
    void on_connectButton_clicked();
    void tcp_connected();
    void tcp_disconnected();
    void click_connectButton();
    void tcp_connect();
    void tcp_disconnect();
    void tcp_readyRead();
    void on_sendButton_clicked();
//    void keyPressEvent(QKeyEvent  *event);
    void on_receiveClearButton_clicked();
    void on_pingCheckBox_stateChanged(int state);
    void ping_interval_time_timeout();
};

#endif // CLIENT_H
