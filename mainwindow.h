#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include "semaforo.h"
#include <QMainWindow>
#include <thread>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <QCloseEvent>
#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close

#define MAXMSG 100
#define PORTNUM 4325


using namespace std;

namespace Ui {
class MainWindow;
}

class Dados
{
public:
    int dados1;
    int dados2;
    int escolha;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void servidor();
    static void socket_(MainWindow *window, int socketDescriptor, Dados dados);//MUDAR DEPOIS
    void velocidade_trem(int velocidade);//MUDAR
    void velocidade_trem(int trem, int velocidade);//MUDAR
    void roda_trem(bool rodar);//MUDAR
    void roda_trem(int trem, bool rodar);//MUDAR

public slots:
    void updateInterfaceTrem(int,int,int);
    void atualizaSemaforo();
private:
    Ui::MainWindow *ui;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    Trem *trem6;
    Trem *trem7;
    bool valida;
    std::thread guiasem;
    Semaforo* semaforo1;
    Semaforo* semaforo2;
    Semaforo* semaforo3;
    Semaforo* semaforo4;
    Semaforo* semaforo5;
    Semaforo* semaforo6;
    Semaforo* semaforo7;
    Semaforo* semaforo8;
    Semaforo* semaforo9;
    Semaforo* semaforo10;
    void closeEvent(QCloseEvent *event);
    std::thread server;

};

#endif // MAINWINDOW_H
