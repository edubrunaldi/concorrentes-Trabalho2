#include "smoof.h"


int menuNodes(){
    int n_nodes;
    do{
        cout << "\n\n\n";
        cout << "Digite o numero de nodes que deseja utilizar no programa: " << "\n";
        cout << " 2 - Cria 2 nodes\n";
        cout << " 3 - Cria 3 nodes\n";
        cout << " 4 - Cria 4 nodes\n";
        cout << "> ";
        cin >> n_nodes;
    }while(n_nodes < 2 || n_nodes > 4);
    return n_nodes;
}

int menuThreads(){
    int n_threads;
    do{
        cout << "\n\n\n";
        cout << "Digite o numero de threads que deseja utilizar no programa: " << "\n";
        cout << " 2 - Cria 2 threads\n";
        cout << " 3 - Cria 3 threads\n";
        cout << " 4 - Cria 4 threads\n";
        cout << "> ";
        cin >> n_threads;
    }while(n_threads < 2 || n_threads > 4);
    return n_threads;
}

int main(){

    int opcao;
    int n_threads;
    int n_nodes;
    //char* nome_imagem = (char*) malloc(512*sizeof(char));
    char *nome_imagem = new char[512];
    cout << "V2.0-----Concorrentes-----\n" ;
    cout << "Eduardo Brunaldi dos Santos & Igor de Souza Baliza\n";
    cout << "\n\n\n";
    do{
        cout << "Menu Principal:\n"; 
        cout << "    1- Executar sequencial\n"; 
        cout << "    2- Executar concorrente\n";
        cout << "    0- Sair\n";
        cout << "Digite uma das opcoes: ";
        cin >> opcao;

        switch (opcao){
            case 0:
                cout << "Fechando  o programa!\n"; 
                break;
            case 1:
                cout << "Nome da Imagem: ";
                cin >> nome_imagem;
                sequencial(nome_imagem);
                break;
            case 2:
                cout << "Nome da Imagem: ";
                cin >> nome_imagem;
                n_threads = menuThreads();
                n_nodes = menuNodes();
                concorrente(nome_imagem, n_threads, n_nodes);
                break;
            default:
                cout << "Opcao invalida, selecione outra opcao.\n"; 
        }
    }while(opcao !=0);
    
    free(nome_imagem);

    return 0;
}