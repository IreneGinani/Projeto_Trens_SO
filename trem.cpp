#include "trem.h"

Trem::Trem(int id, int x, int y, std::pair<int, int> tuple, int altura, int largura, Semaforo *sem1, Semaforo *sem2, Semaforo *sem3, Semaforo *sem4, Semaforo *sem5, Semaforo *sem6, Semaforo *sem7, Semaforo *sem8, Semaforo *sem9, Semaforo *sem10)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->tuple = tuple;
    this->altura = altura;
    this->largura = largura;
    this->sem1 = sem1;
    this->sem2 = sem2;
    this->sem3 = sem3;
    this->sem4 = sem4;
    this->sem5 = sem5;
    this->sem6 = sem6;
    this->sem7 = sem7;
    this->sem8 = sem8;
    this->sem9 = sem9;
    this->sem10 = sem10;
    this->rc1 = false;
    this->rc2 = false;
    this->rc3 = false;
    this->rc4 = false;
    this->rc5 = false;
    this->rc6 = false;
    this->rc7 = false;
    this->rc8 = false;
    this->rc9 = false;
    this->rc10 = false;
    velocidade = 50;
    enable = false;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}


void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}
void Trem::stop()
{
    switch(id){

            case 1:


                //Entrando em Região crítica 1...
                if (x == 170 and y == 140)
                {

                    sem1->P();

                }

                //Teste se saiu da Região crítica 1...
                if (x == 170 and y == 210)
                {
                    sem1->V();

                }
                //Entrando em Região crítica 8...
                if (x == 170 and y == 240)
                {

                    sem8->P();

                }

                //Teste se saiu da Região crítica 8...
                if (x == 160 and y == 290)
                {

                    sem8->V();

                }

                // Está em Região crítica 1...
                if(x == 170 && (y > 150 && y < 200)){
                    this->rc1 = true;
                }else{
                    this->rc1 = false;
                }

                // Está em Região crítica 8...
                if(x == 170 && (y > 250 && y < 300)){
                    this->rc8 = true;
                }else{
                    this->rc8 = false;
                }

                break;

            case 2:

                //Entrando em Região crítica 1...
                if (x == 170 and y == 190)
                {
                    sem1->P();
                }

                //Teste se saiu da Região crítica 1...
                if (x == 170 and y == 140)
                {
                    sem1->V();
                }

                //Entrando em Região crítica 2...
                if (x == 310 and y == 140)
                {
                    sem2->P();
                }

                //Teste se saiu da Região crítica 2...
                if (x == 310 and y == 190)
                {
                    sem2->V();
                }

                //Entrando em Região crítica 4...
                if (x == 310 and y == 190)
                {
                    sem4->P();
                }

                //Teste se saiu da Região crítica 4...
                if (x == 220 and y == 190)
                {
                    sem4->V();
                }

                // Está em Região crítica 1...
                if(x == 170 && (y > 150 && y < 200)){
                    this->rc1 = true;
                }else{
                    this->rc1 = false;
                }

                // Está em Região crítica 2...
                if(x == 310 && (y > 150 && y < 200)){
                    this->rc2 = true;
                }else{
                    this->rc2 = false;
                }
                // Está em Região crítica 4...
                if((x > 250 && x < 320) && y==190){
                    this->rc4 = true;
                }else{
                    this->rc4 = false;
                }


                    break;


                case 3:


                    //Entrando em Região crítica 2...
                    if (x == 310 and y == 190)
                    {
                        sem2->P();
                    }

                    //Teste se saiu da Região crítica 2...
                    if (x == 310 and y == 140)
                    {
                        sem2->V();
                    }
                    //Entrando em Região crítica 3...
                    if (x == 450 and y == 140)
                    {
                        sem3->P();
                    }

                    //Teste se saiu da Região crítica 3...
                    if (x == 450 and y == 190)
                    {
                        sem3->V();
                    }
                    //Entrando em Região crítica 5...
                    if (x == 380 and y == 190)
                    {
                        sem5->P();
                    }

                    //Teste se saiu da Região crítica 5...
                    if (x == 310 and y == 190)
                    {
                        sem5->V();
                    }
                    // Está em Região crítica 2...
                    if(x == 310 && (y > 150 && y < 200)){
                        this->rc2 = true;
                    }else{
                        this->rc2 = false;
                    }
                    // Está em Região crítica 3...
                    if(x == 450 && (y > 150 && y < 200)){
                        this->rc3 = true;
                    }else{
                        this->rc3 = false;
                    }
                    // Está em Região crítica 5...
                    if((x > 320 && x < 390) && y==190){
                        this->rc5 = true;
                    }else{
                        this->rc5 = false;
                    }

                    break;

                case 4:

                    //Entrando em Região crítica 3...
                    if (x == 450 and y == 190)
                    {
                        sem3->P();
                    }
                    //Teste se saiu da Região crítica 3...
                    if (x == 450 and y == 140)
                    {
                        sem3->V();
                    }

                    //Entrando em Região crítica 10...
                    if (x == 450 and y == 290)
                    {
                        sem10->P();
                    }
                    //Teste se saiu da Região crítica 10...
                    if (x == 450 and y == 230)
                    {
                        sem10->V();
                    }

                    // Está em Região crítica 3...
                    if(x == 450 && (y > 150 && y < 200)){
                        this->rc3 = true;
                    }else{
                        this->rc3 = false;
                    }
                    // Está em Região crítica 10...
                    if(x == 450 && (y > 250 && y < 300)){
                        this->rc10 = true;
                    }else{
                        this->rc10 = false;
                    }


                    break;

                case 5:

                    //Entrando em Região crítica 7...
                    if (x == 310 and y == 240)
                    {
                        sem7->P();
                    }

                    //Teste se saiu da Região crítica 7...
                    if (x == 380 and y == 240)
                    {
                        sem7->V();
                    }

                    //Entrando em Região crítica 9...
                    if (x == 310 and y == 290)
                    {
                        sem9->P();
                    }

                    //Teste se saiu da Região crítica 9...
                    if (x == 310 and y == 240)
                    {
                        sem9->V();
                    }

                    //Entrando em Região crítica 10...
                    if (x == 450 and y == 240)
                    {
                        sem10->P();
                    }
                    //Teste se saiu da Região crítica 10...
                    if (x == 450 and y == 290)
                    {
                        sem10->V();
                    }

                    // Está em Região crítica 7...
                    if((x > 320 && x < 390) && y==240){
                        this->rc7 = true;
                    }else{
                        this->rc7 = false;
                    }
                    // Está em Região crítica 9...
                    if(x == 310 && (y > 250 && y < 300)){
                        this->rc9 = true;
                    }else{
                        this->rc9 = false;
                    }
                    // Está em Região crítica 10...
                    if(x == 450 && (y > 250 && y < 300)){
                        this->rc10 = true;
                    }else{
                        this->rc10 = false;
                    }


                    break;

                case 6:


                    //Entrando em Região crítica 6...
                    if (x == 240 and y == 240)
                    {
                        sem6->P();
                    }

                    //Teste se saiu da Região crítica 6...
                    if (x == 310 and y == 240)
                    {
                        sem6->V();
                    }
                    //Entrando em Região crítica 8...
                    if (x == 170 and y == 290)
                    {
                        sem8->P();
                    }

                    //Teste se saiu da Região crítica 8...
                    if (x == 170 and y == 240)
                    {
                        sem8->V();
                    }
                    //Entrando em Região crítica 9...
                    if (x == 310 and y == 240)
                    {
                        sem9->P();
                    }

                    //Teste se saiu da Região crítica 9...
                    if (x == 310 and y == 290)
                    {
                        sem9->V();
                    }
                    // Está em Região crítica 6...
                    if((x > 250 && x < 320) && y==240){
                        this->rc6 = true;
                    }else{
                        this->rc6 = false;
                    }
                    // Está em Região crítica 8...
                    if(x == 170 && (y > 250 && y < 300)){
                        this->rc8 = true;
                    }else{
                        this->rc8 = false;
                    }
                    // Está em Região crítica 9...
                    if(x == 310 && (y > 250 && y < 300)){
                        this->rc9 = true;
                    }else{
                        this->rc9 = false;
                    }

                    break;
                case 7:

                    //Entrando em Região crítica 4...
                    if (x == 240 and y == 190)
                    {
                        sem4->P();
                    }

                    //Teste se saiu da Região crítica 4...
                    if (x == 310 and y == 190)
                    {
                        sem4->V();
                    }

                    //Entrando em Região crítica 5...
                    if (x == 310 and y == 190)
                    {
                        sem5->P();
                    }

                    //Teste se saiu da Região crítica 5...
                    if (x == 380 and y == 190)
                    {
                        sem5->V();
                    }
                    //Entrando em Região crítica 6...
                    if (x == 310 and y == 240)
                    {
                        sem6->P();
                    }

                    //Teste se saiu da Região crítica 6...
                    if (x == 240 and y == 220)
                    {
                        sem6->V();
                    }
                    //Entrando em Região crítica 7...
                    if (x == 380 and y == 240)
                    {
                        sem7->P();
                    }

                    //Teste se saiu da Região crítica 7...
                    if (x == 310 and y == 240)
                    {
                        sem7->V();
                    }

                    // Está em Região crítica 4...
                    if((x > 240 && x < 310) && y==190){
                        this->rc4 = true;
                    }else{
                        this->rc4 = false;
                    }
                    // Está em Região crítica 5...
                    if((x > 310 && x < 380) && y==190){
                        this->rc5 = true;
                    }else{
                        this->rc5 = false;
                    }
                    // Está em Região crítica 6...
                    if((x > 240 && x < 310) && y==240){
                        this->rc6 = true;
                    }else{
                        this->rc6 = false;
                    }
                    // Está em Região crítica 7...
                    if((x > 310 && x < 380) && y==240){
                        this->rc7 = true;
                    }else{
                        this->rc7 = false;
                    }
                    break;

                default:
                    break;
    }
}



void Trem::run()
{
    while(true){
        switch(id){

        case 1:

            if(x == 170 and y == 140){
                inicio1 = std::chrono::system_clock::now();

            }
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }
            if(x == 170 and y == 140)
                fim1 = std::chrono::system_clock::now();
            segundos_decorridos1 = std::chrono::duration_cast<std::chrono::seconds> (fim1-inicio1).count();
            if(segundos_decorridos1 != 0 and segundos_decorridos1 < 100)
                decorridos1 = std::to_string(segundos_decorridos1);



            if(segundos_decorridos1 < 100 and x == 170 and y == 140){

                teste++;
                if(teste >= 1){

                valor_medio = (valor_medio + segundos_decorridos1);
                }
            }


            medio1 = std::to_string(valor_medio/(teste));


            break;
        case 2:
            if(x == 170 and y == 190)
                inicio2 = std::chrono::system_clock::now();
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }
            if(x == 170 and y == 190)
                fim2 = std::chrono::system_clock::now();
            segundos_decorridos2 = std::chrono::duration_cast<std::chrono::seconds> (fim2-inicio2).count();
            if(segundos_decorridos2 != 0 and segundos_decorridos2 < 100)
                decorridos2 = std::to_string(segundos_decorridos2);

            if(segundos_decorridos2 < 100 and x == 170 and y == 190){

                teste2++;
                if(teste2 >= 1){

                valor_medio2 = (valor_medio2 + segundos_decorridos2);
                }
            }


            medio2 = std::to_string((valor_medio2/(teste2)));


            break;
        case 3:
            if(x == 310 and y == 190)
                inicio3 = std::chrono::system_clock::now();
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }
            if(x == 310 and y == 190)
                fim3 = std::chrono::system_clock::now();
            segundos_decorridos3 = std::chrono::duration_cast<std::chrono::seconds> (fim3-inicio3).count();
            if(segundos_decorridos3 != 0 and segundos_decorridos3 < 100)
                decorridos3 = std::to_string(segundos_decorridos3);

            if(segundos_decorridos3 < 100 and x == 310 and y == 190){

                teste3++;
                if(teste3 >= 1){

                valor_medio3 = (valor_medio3 + segundos_decorridos3);
                }
            }


            medio3 = std::to_string((valor_medio3/(teste3)));

            break;
        case 4:
            if(x == 450 and y == 190)
                inicio4 = std::chrono::system_clock::now();
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }
            if(x == 450 and y == 190)
                fim4 = std::chrono::system_clock::now();
            segundos_decorridos4 = std::chrono::duration_cast<std::chrono::seconds> (fim4-inicio4).count();
            if(segundos_decorridos4 != 0 and segundos_decorridos4 < 100)
                decorridos4 = std::to_string(segundos_decorridos4);

            if(segundos_decorridos4 < 100 and x == 450 and y == 190){

                teste4++;
                if(teste4 >= 1){

                valor_medio4 = (valor_medio4 + segundos_decorridos4);
                }
            }


            medio4 = std::to_string((valor_medio4/(teste4)));


            break;
        case 5:
            if(x == 310 and y == 240)
                inicio5 = std::chrono::system_clock::now();
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }
            if(x == 310 and y == 240)
                fim5 = std::chrono::system_clock::now();
            segundos_decorridos5 = std::chrono::duration_cast<std::chrono::seconds> (fim5-inicio5).count();
            if(segundos_decorridos5 != 0 and segundos_decorridos5 < 100)
                decorridos5 = std::to_string(segundos_decorridos5);

            if(segundos_decorridos5 < 100 and x == 310 and y == 240){

                teste5++;
                if(teste5 >= 1){

                valor_medio5 = (valor_medio5 + segundos_decorridos5);
                }
            }


            medio5 = std::to_string((valor_medio5/(teste5)));

            break;
        case 6:
            if(x == 240 and y == 240)
                inicio6 = std::chrono::system_clock::now();
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }
            if(x == 240 and y == 240)
                fim6 = std::chrono::system_clock::now();
            segundos_decorridos6 = std::chrono::duration_cast<std::chrono::seconds> (fim6-inicio6).count();
            if(segundos_decorridos6 != 0 and segundos_decorridos6 < 100)
                decorridos6 = std::to_string(segundos_decorridos6);

            if(segundos_decorridos6 < 100 and x == 240 and y == 240){

                teste6++;
                if(teste6 >= 1){

                valor_medio6 = (valor_medio6 + segundos_decorridos6);
                }
            }


            medio6 = std::to_string((valor_medio6/(teste6)));

            break;
        case 7:
            if(x == 240 and y == 190)
                inicio7 = std::chrono::system_clock::now();
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == this->tuple.second && x < (this->tuple.first + largura))//direita
                    x+=10;
                else if (x == (this->tuple.first + largura) && y < (this->tuple.second + altura))//baixo
                    y+=10;
                else if (x > this->tuple.first && y == (this->tuple.second + altura))//esquerda
                    x-=10;
                else//cima
                    y-=10;
            }

            if(x == 240 and y == 190)
                fim7 = std::chrono::system_clock::now();
            segundos_decorridos7 = std::chrono::duration_cast<std::chrono::seconds> (fim7-inicio7).count();
            if(segundos_decorridos7 != 0 and segundos_decorridos7 < 100)
                decorridos7 = std::to_string(segundos_decorridos7);

            if(segundos_decorridos7 < 100 and x == 240 and y == 190){

                teste7++;
                if(teste7 >= 1){

                valor_medio7 = (valor_medio7 + segundos_decorridos7);
                }
            }


            medio7 = std::to_string((valor_medio7/(teste7)));

            break;
        default:
            break;
        }

        stop();
        this_thread::sleep_for(chrono::milliseconds(velocidade));
        usleep(20000);
    }

}

