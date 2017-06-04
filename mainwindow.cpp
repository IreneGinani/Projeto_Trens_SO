#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->valida = true;

    QPixmap pix1("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway.png");
    QPixmap pix2("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway2.png");
    QPixmap pix3("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway3.png");
    QPixmap pix4("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway4.png");
    QPixmap pix5("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway5.png");
    QPixmap pix6("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway6.png");
    QPixmap pix7("/Users/adelinofernandes/Documents/Projeto_Trens_SO/img/subway7.png");

    ui->labelTrem01->setPixmap(pix1);
    ui->labelTrem02->setPixmap(pix2);
    ui->labelTrem03->setPixmap(pix3);
    ui->labelTrem04->setPixmap(pix4);
    ui->labelTrem05->setPixmap(pix5);
    ui->labelTrem06->setPixmap(pix6);
    ui->labelTrem07->setPixmap(pix7);


    semaforo1 = new Semaforo(1,1,IPC_CREAT|0600);
    semaforo2 = new Semaforo(2,1,IPC_CREAT|0600);
    semaforo3 = new Semaforo(3,1,IPC_CREAT|0600);
    semaforo4 = new Semaforo(4,1,IPC_CREAT|0600);
    semaforo5 = new Semaforo(5,1,IPC_CREAT|0600);
    semaforo6 = new Semaforo(6,1,IPC_CREAT|0600);
    semaforo7 = new Semaforo(7,1,IPC_CREAT|0600);
    semaforo8 = new Semaforo(8,1,IPC_CREAT|0600);
    semaforo9 = new Semaforo(9,1,IPC_CREAT|0600);
    semaforo10 = new Semaforo(10,1,IPC_CREAT|0600);

    //trem1
    std::pair<int, int> tuple1;
    tuple1.first = 110;
    tuple1.second = 140;
    trem1 = new Trem(1,110,220,tuple1, 150, 60, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));


    //trem2
    std::pair<int, int> tuple2;
    tuple2.first = 170;
    tuple2.second = 140;
    trem2 = new Trem(2,230,140,tuple2, 50, 140, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));


    //trem3
    std::pair<int, int> tuple3;
    tuple3.first = 310;
    tuple3.second = 140;
    trem3 = new Trem(3,380,140,tuple3, 50, 140, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));


    //trem4
    std::pair<int, int> tuple4;
    tuple4.first = 450;
    tuple4.second = 140;
    trem4 = new Trem(4,510,220,tuple4, 150, 60, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));


    //trem5
    std::pair<int, int> tuple5;
    tuple5.first = 310;
    tuple5.second = 240;
    trem5 = new Trem(5,380,290,tuple5, 50, 140, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));


    //trem6
    std::pair<int, int> tuple6;
    tuple6.first = 170;
    tuple6.second = 240;
    trem6 = new Trem(6,230,290,tuple6, 50, 140, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));


    //trem7
    std::pair<int, int> tuple7;
    tuple7.first = 240;
    tuple7.second = 190;
    trem7 = new Trem(7,380,210,tuple7, 50, 140, semaforo1, semaforo2, semaforo3, semaforo4, semaforo5, semaforo6, semaforo7, semaforo8, semaforo9, semaforo10);
    connect(trem7,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterfaceTrem(int,int,int)));



    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
    trem7->start();


    server = std::thread(&MainWindow::servidor,this);

}

MainWindow::~MainWindow()
{
    server.join();
    delete ui;
}

void MainWindow::updateInterfaceTrem(int id, int x, int y)
{
    switch(id){
        case 1:
            atualizaSemaforo();
            ui->labelTrem01->setGeometry(x,y,25,25);
            break;
        case 2:
            atualizaSemaforo();
            ui->labelTrem02->setGeometry(x,y,25,25);
            break;
        case 3:
            atualizaSemaforo();
            ui->labelTrem03->setGeometry(x,y,25,25);
            break;
        case 4:
            atualizaSemaforo();
            ui->labelTrem04->setGeometry(x,y,25,25);
            break;
        case 5:
            atualizaSemaforo();
            ui->labelTrem05->setGeometry(x,y,25,25);
            break;
        case 6:
            atualizaSemaforo();
            ui->labelTrem06->setGeometry(x,y,25,25);
            break;
        case 7:
            atualizaSemaforo();
            ui->labelTrem07->setGeometry(x,y,25,25);
            break;
        default:
            break;
    }
}

void MainWindow::socket_(MainWindow *window, int socketDescriptor, Dados dados) {
    int byteslidos;

    //Verificando erros
    if (socketDescriptor == -1) {
        printf("Falha ao executar accept()");
        exit(EXIT_FAILURE);
    }

    // Receber uma msg do cliente
    byteslidos = recv(socketDescriptor, &dados, sizeof(dados), 0);

    if (byteslidos == -1) {
        printf("Falha ao executar recv()");
        exit(EXIT_FAILURE);
    } else if (byteslidos == 0) {
        printf("Cliente finalizou a conexão\n");
        exit(EXIT_SUCCESS);
    }

    switch(dados.escolha) {
        case 1:

            window->velocidade_trem(dados.dados1, dados.dados2);
            break;
        case 2:
            window->velocidade_trem(dados.dados1);
            break;
        case 3:
            window->roda_trem(dados.dados1, (bool)dados.dados2);
            break;
        case 4:
            window->roda_trem((bool)dados.dados1);
            break;
        default:
            break;
    }
    ::close(socketDescriptor);
}

void MainWindow::servidor()
{

    //variáveis do servidor
        struct sockaddr_in endereco;
        int socketId;

        //variáveis relacionadas com as conexões clientes
        struct sockaddr_in enderecoCliente;
        socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
        int conexaoClienteId;

        //Permitir inserir o caractere de fim de msg \0
        Dados dados;
        int byteslidos;

        /*
         * Configurações do endereço
        */
        memset(&endereco, 0, sizeof(endereco));
        endereco.sin_family = AF_INET;
        endereco.sin_port = htons(PORTNUM);
        //endereco.sin_addr.s_addr = INADDR_ANY;
        endereco.sin_addr.s_addr = inet_addr("192.168.7.1");

        /*
         * Criando o Socket
         *
         * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
         * PARAM2: SOCK_STREAM ou SOCK_DGRAM
         * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
        */
        socketId = socket(AF_INET, SOCK_STREAM, 0);

        //Verificar erros
        if (socketId == -1)
        {
            printf("Falha ao executar socket()\n");
            exit(EXIT_FAILURE);
        }

        //Conectando o socket a uma porta. Executado apenas no lado servidor
        if (::bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
        {
            printf("Falha ao executar bind()\n");
            exit(EXIT_FAILURE);
        }

        //Habilitando o servidor a receber conexoes do cliente
        if ( listen( socketId, 10 ) == -1)
        {
            printf("Falha ao executar listen()\n");
            exit(EXIT_FAILURE);
        }

        //servidor ficar em um loop infinito
        while(1)
        {
            conexaoClienteId = accept(socketId, (struct sockaddr *) &enderecoCliente, &tamanhoEnderecoCliente);
            std::thread t(&MainWindow::socket_, this, conexaoClienteId, dados);
            t.detach();
        }


}

void MainWindow::roda_trem(bool validar) {
    trem1->setEnable(validar);
    trem2->setEnable(validar);
    trem3->setEnable(validar);
    trem4->setEnable(validar);
    trem5->setEnable(validar);
    trem6->setEnable(validar);
    trem7->setEnable(validar);
}

void MainWindow::roda_trem(int trem, bool validar) {
    switch(trem){
    case 1:
        trem1->setEnable(validar);
        break;
    case 2:
        trem2->setEnable(validar);
        break;
    case 3:
        trem3->setEnable(validar);
        break;
    case 4:
        trem4->setEnable(validar);
        break;
    case 5:
        trem5->setEnable(validar);
        break;
    case 6:
        trem6->setEnable(validar);
        break;
    case 7:
        trem7->setEnable(validar);
        break;
    }
}


void MainWindow::velocidade_trem(int velocidade){
    trem1->setVelocidade(velocidade);
    trem2->setVelocidade(velocidade);
    trem3->setVelocidade(velocidade);
    trem4->setVelocidade(velocidade);
    trem5->setVelocidade(velocidade);
    trem6->setVelocidade(velocidade);
    trem7->setVelocidade(velocidade);
}

void MainWindow::velocidade_trem(int trem, int velocidade){
    switch(trem){
        case 1:
            trem1->setVelocidade(velocidade);
            break;
        case 2:
            trem2->setVelocidade(velocidade);
            break;
        case 3:
            trem3->setVelocidade(velocidade);
            break;
        case 4:
            trem4->setVelocidade(velocidade);
            break;
        case 5:
            trem5->setVelocidade(velocidade);
            break;
        case 6:
            trem6->setVelocidade(velocidade);
            break;
        case 7:
            trem7->setVelocidade(velocidade);
            break;
    }
}


void MainWindow::atualizaSemaforo(){
    ui->lcd_sem_01->display(semaforo1->getContador());
    ui->lcd_sem_02->display(semaforo2->getContador());
    ui->lcd_sem_03->display(semaforo3->getContador());
    ui->lcd_sem_04->display(semaforo4->getContador());
    ui->lcd_sem_05->display(semaforo5->getContador());
    ui->lcd_sem_06->display(semaforo6->getContador());
    ui->lcd_sem_07->display(semaforo7->getContador());
    ui->lcd_sem_08->display(semaforo8->getContador());
    ui->lcd_sem_09->display(semaforo9->getContador());
    ui->lcd_sem_10->display(semaforo10->getContador());
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit->clear();


    if(semaforo1->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 1 V()");
    else if(semaforo1->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 1 P()");

    if(semaforo2->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 2 V()");
    else if(semaforo2->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 2 P()");

    if(semaforo3->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 3 V()");
    else if(semaforo3->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 3 P()");

    if(semaforo4->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 4 V()");
    else if(semaforo4->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 4 P()");

    if(semaforo5->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 5 V()");
    else if(semaforo5->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 5 P()");

    if(semaforo6->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 6 V()");
    else if(semaforo6->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 6 P()");

    if(semaforo7->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 7 V()");
    else if(semaforo7->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 7 P()");

    if(semaforo8->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 8 V()");
    else if(semaforo8->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 8 P()");

    if(semaforo9->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 9 V()");
    else if(semaforo9->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 9 P()");

    if(semaforo10->getContador() == 1)
        ui->plainTextEdit->appendPlainText("Semáforo 10 V()");
    else if(semaforo10->getContador() == 0)
        ui->plainTextEdit->appendPlainText("Semáforo 10 P()");

        ui->plainTextEdit_2->appendPlainText("Trem1 Última volta:"+QString::fromStdString(trem1->decorridos1)+ " Valor médio:"+ QString::fromStdString(trem1->medio1));
        ui->plainTextEdit_2->appendPlainText("Trem2 Última volta:"+QString::fromStdString(trem2->decorridos2)+ " Valor médio:"+ QString::fromStdString(trem2->medio2));
        ui->plainTextEdit_2->appendPlainText("Trem3 Última volta:"+QString::fromStdString(trem3->decorridos3)+ " Valor médio:"+ QString::fromStdString(trem3->medio3));
        ui->plainTextEdit_2->appendPlainText("Trem4 Última volta:"+QString::fromStdString(trem4->decorridos4)+ " Valor médio:"+ QString::fromStdString(trem4->medio4));
        ui->plainTextEdit_2->appendPlainText("Trem5 Última volta:"+QString::fromStdString(trem5->decorridos5)+ " Valor médio:"+ QString::fromStdString(trem5->medio5));
        ui->plainTextEdit_2->appendPlainText("Trem6 Última volta:"+QString::fromStdString(trem6->decorridos6)+ " Valor médio:"+ QString::fromStdString(trem6->medio6));
        ui->plainTextEdit_2->appendPlainText("Trem7 Última volta:"+QString::fromStdString(trem7->decorridos7)+ " Valor médio:"+ QString::fromStdString(trem7->medio7));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    server.detach();
    delete semaforo1;
    delete semaforo2;
    delete semaforo3;
    delete semaforo4;
    delete semaforo5;
    delete semaforo6;
    delete semaforo7;
    delete semaforo8;
    delete semaforo9;
    delete semaforo10;

}
