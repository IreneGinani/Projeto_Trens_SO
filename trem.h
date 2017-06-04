#ifndef TREM_H
#define TREM_H

#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <QObject>
#include <thread>
#include <chrono>
#include <string>

#include "semaforo.h"


using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int,std::pair<int,int>, int, int, Semaforo *, Semaforo *, Semaforo *, Semaforo *, Semaforo *, Semaforo *, Semaforo *, Semaforo *, Semaforo *, Semaforo *);
    ~Trem();
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);
    std::chrono::time_point<std::chrono::system_clock> inicio1, fim1;
    int segundos_decorridos1 = 0;
    std::chrono::time_point<std::chrono::system_clock> inicio2, fim2;
    int segundos_decorridos2 = 0;
    std::chrono::time_point<std::chrono::system_clock> inicio3, fim3;
    int segundos_decorridos3 = 0;
    std::chrono::time_point<std::chrono::system_clock> inicio4, fim4;
    int segundos_decorridos4 = 0;
    std::chrono::time_point<std::chrono::system_clock> inicio5, fim5;
    int segundos_decorridos5 = 0;
    std::chrono::time_point<std::chrono::system_clock> inicio6, fim6;
    int segundos_decorridos6 = 0;
    std::chrono::time_point<std::chrono::system_clock> inicio7, fim7;
    int segundos_decorridos7 = 0;
    std::string decorridos1;
    std::string decorridos2;
    std::string decorridos3;
    std::string decorridos4;
    std::string decorridos5;
    std::string decorridos6;
    std::string decorridos7;

    std::string medio1;
    std::string medio2;
    std::string medio3;
    std::string medio4;
    std::string medio5;
    std::string medio6;
    std::string medio7;


    float valor_medio = 0.0;
    float valor_medio2 = 0.0;
    float valor_medio3 = 0.0;
    float valor_medio4 = 0.0;
    float valor_medio5 = 0.0;
    float valor_medio6 = 0.0;
    float valor_medio7 = 0.0;

    int teste = 0;
    int teste2 = 0;
    int teste3 = 0;
    int teste4 = 0;
    int teste5 = 0;
    int teste6 = 0;
    int teste7 = 0;


signals:
    void updateGUI(int,int,int);

private:
   std::thread threadTrem;
   int id;

   int velocidade;
   bool enable;
   int largura;
   int altura;
   std::pair<int,int> tuple;
   bool rc1;
   bool rc2;
   bool rc3;
   bool rc4;
   bool rc5;
   bool rc6;
   bool rc7;
   bool rc8;
   bool rc9;
   bool rc10;
   Semaforo *sem1;
   Semaforo *sem2;
   Semaforo *sem3;
   Semaforo *sem4;
   Semaforo *sem5;
   Semaforo *sem6;
   Semaforo *sem7;
   Semaforo *sem8;
   Semaforo *sem9;
   Semaforo *sem10;
   int x;
   int y;
   void stop();
};

#endif // TREM_H



