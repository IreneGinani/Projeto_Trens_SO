#include <cstdio>     
#include <cstring>     
#include <cstdlib>    
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <unistd.h>   
#include <iostream>     
#include <sstream>
#include <fstream>

#define MAXMSG 1024
#define PORTNUM 4325

#define PATH_ADC "/sys/bus/iio/devices/iio:device0/in_voltage1_raw"
#define GPIO115 "../../../sys/class/gpio/gpio115/value"
#define GPIO20 "../../../sys/class/gpio/gpio20/value"
#define GPIO7 "../../../sys/class/gpio/gpio7/value"

int valor_potenciometro, potencia, botao1, botao2, botao3;

int readAnalog()
{
        FILE* arquivo = fopen(PATH_ADC, "r");
        rewind(arquivo);
        fscanf(arquivo, "%i", &potencia);
        fclose(arquivo);
		valor_potenciometro = potencia;
		
		return potencia;	
}

int readbotao1(){
        int number;
        FILE* arquivo = fopen(GPIO115, "r");
        rewind(arquivo);
        fscanf(arquivo, "%i", &number);
        fclose(arquivo);
		botao1 = number;
        
        return number;        
}

int readbotao2(){
        int number;
        FILE* arquivo = fopen(GPIO20, "r");
        rewind(arquivo);
        fscanf(arquivo, "%i", &number);
        fclose(arquivo);
		botao2 = number;
        
        return number;        
}

int readbotao3(){
        int number;
        FILE* arquivo = fopen(GPIO7, "r");
        rewind(arquivo);
        fscanf(arquivo, "%i", &number);
        fclose(arquivo);
		botao3 = number;
        
        return number;        
}



int velocidade_trem()
{
	int velocidade;
	while(true) {
	
		if (readAnalog() > 0 and readAnalog() <=1500)
			velocidade = 400;
		else if (readAnalog() > 1500 and readAnalog() <=3000)
			velocidade = 250;
		else if (readAnalog() > 3000 and readAnalog() <=4095)
		velocidade = 50;
		if(readbotao1() == 1) break;
	}
	return velocidade;
}

class Dados
{
public:
	int dados1;
	int dados2;
	int escolha;
	
};

int main(int argc, char *argv[])
{
    struct sockaddr_in endereco;
    int socketId;
    Dados dados;
    int bytesenviados;
    int contador = 1;

    while(true) {
    	system("clear");
    	std::cout << "_________________________________________________" << std::endl;
    	std::cout << "             Controlador dos Trens			   " << std::endl;
    	std::cout << "_________________________________________________" << std::endl;
    	sleep(1);
    	std::cout << "1- Defina umaa velocidade para um trem específico" << std::endl;
    	std::cout << "2- Defina uma velocidade para todos os trens" << std::endl;
        std::cout << "3- Ligar ou desligar um trem específico" << std::endl;
        std::cout << "4- Ligar ou desligar todos os trens" << std::endl;
        
        std::cout << "\n Qual função de 1 à 4 executar: " << std::endl;
        
		
		
		while (readbotao1() != 1) {

			if (readbotao2() == 1 and (contador != 4))
			{		
				contador++;
				std::cout << "Opc: " << contador << std::endl;
			} else if (readbotao3() == 1 and (contador != 1))
			{
				contador--;
				std::cout << "Opc: " << contador << std::endl;
			}
			usleep(400000);

		}

		dados.escolha = contador;

        switch(dados.escolha) {
        	case 1:
        	std::cout << "Escolha um trem: ";
                std::cin >> dados.dados1;
                std::cout << "Informe sua velocidade no potenciometro: " << std::endl;
        		dados.dados2 = velocidade_trem();
        		break;
        	case 2:
        	 	std::cout << "Informe a velocidade para todos os trens: " << std::endl;
        		dados.dados1 = velocidade_trem();
        		break;
        	case 3:
				std::cout << "Escolha um trem para ligar ou desligar: " << std::endl;
                std::cin >> dados.dados1;
                std::cout << "Ligar ou desligar o trem: " << std::endl;
                std::cin >> dados.dados2;
        		break;
        	case 4:
        	    std::cout << "Ligar ou desligar todos os trens?" << std::endl;
                std::cin >> dados.dados1;
        	 	break;
        	default:
        		break;
        }
	    /*
	     * Configurações do endereço
	    */
	    memset(&endereco, 0, sizeof(endereco));
	    endereco.sin_family = AF_INET;
	    endereco.sin_port = htons(PORTNUM);
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

	    //Conectando o socket cliente ao socket servidor
	    if ( connect (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
	    {
	        printf("Falha ao executar connect()\n");
	        exit(EXIT_FAILURE);
	    }
	    printf ("Cliente conectado ao servidor\n");

	    //Enviar uma msg para o cliente que se conectou
	    printf("Cliente vai enviar uma mensagem\n");
	    bytesenviados = send(socketId,&dados,sizeof(dados),0);

	    if (bytesenviados == -1)
	    {
	        printf("Falha ao executar send()");
	        exit(EXIT_FAILURE);
	    }

	    close(socketId);
	}
    return 0;
}