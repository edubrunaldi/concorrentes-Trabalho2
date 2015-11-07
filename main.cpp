#include "smooth.h"



int menuThreads(){
    int n_threads;
    do{
        std::cout << "\n\n\n";
        std::cout << "Digite o numero de threads que deseja utilizar no programa: " << "\n";
        std::cout << " 2 - Cria 2 threads\n";
        std::cout << " 3 - Cria 3 threads\n";
        std::cout << " 4 - Cria 4 threads\n";
        std::cout << "> ";
        std::cin >> n_threads;
    }while(n_threads < 2 || n_threads > 4);
    return n_threads;
}

int main(){

    int opcao;
    int n_threads;
    //char* nome_imagem = (char*) malloc(512*sizeof(char));
    //char *nome_imagem = new char[512];   
    //char *nome_saida = new char[512];   
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

        switch (opcao){
            case 0:
                std::cout << "Fechando  o programa!\n"; 
                break;
            case 1:
                std::cout << "Nome da Imagem: ";
                std::cin >> nome_imagem;
                std::cout << "Nome da Saida: ";
                std::cin >> nome_saida;
                sequencialColorido(nome_imagem, nome_saida);
                break;
            case 2:
                std::cout << "Nome da Imagem: ";
                std::cin >> nome_imagem;
                n_threads = menuThreads();
                concorrente(nome_imagem, n_threads);
                break;
            default:
                std::cout << "Opcao invalida, selecione outra opcao.\n"; 
        }
    }while(opcao !=0);

    return 0;
}