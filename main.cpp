#include "smooth.h"


int main(){

    int opcao=0, opcao_cor=0;
    std::string nome_imagem;
    std::string nome_saida;
    std::cout << "V2.0-----Concorrentes-----\n" ;
    std::cout << "Eduardo Brunaldi dos Santos & Igor de Souza Baliza\n";
    std::cout << "\n\n\n";
    do{
        std::cout << "Menu Principal:\n"; 
        std::cout << "    1- Executar sequencial\n"; 
        std::cout << "    2- Executar concorrente\n";
        std::cout << "    0- Sair\n";
        std::cout << "Digite uma das opcoes: ";
        std::cin >> opcao;
        if (opcao==0)
            break;
        do{
            std::cout << "Escolha o tipo de Imagem:\n";
            std::cout << "1 - RGB\n";
            std::cout << "2 - Grayscale\n";
            std::cin >> opcao_cor;
        }while(opcao_cor < 1 || opcao_cor > 2);

        std::cout << "Nome da Imagem: ";
        std::cin >> nome_imagem;
        std::cout << "Nome da Saida: ";
        std::cin >> nome_saida;

        switch (opcao){
            case 0:
                std::cout << "Fechando  o programa!\n"; 
                break;
            case 1:
                if(opcao_cor == 1)
                    sequencialColorido(nome_imagem, nome_saida);
                else
                    sequencialCinza(nome_imagem, nome_saida);
                break;
            case 2:
                if(opcao_cor == 1)
                    concorrenteCinza(nome_imagem, nome_saida);
                else
                    concorrenteRGB(nome_imagem, nome_saida);
                break;
            default:
                std::cout << "Opcao invalida, selecione outra opcao.\n"; 
        }
    }while(opcao !=0);

    return 0;
}