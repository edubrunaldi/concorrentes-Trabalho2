#include "smoof.h"


int menuNodes(){
    int n_threads;
    do{
        printf("\n\n\n");
        printf("Digite o numero de nodes que deseja utilizar no programa: \n");
        printf(" 2 - Utiliza 2 nodes\n");
        printf(" 3 - Utiliza 3 nodes\n");
        printf(" 4 - Utiliza 4 nodes\n");
        printf("> ");
        scanf("%d", &n_threads);
    }while(n_threads < 2 || n_threads > 4);
    return n_threads;
}

int menuThreads(){
    int n_threads;
    do{
        printf("\n\n\n");
        printf("Digite o numero de threads que deseja utilizar no programa: \n");
        printf(" 2 - Cria 2 threads\n");
        printf(" 3 - Cria 3 threads\n");
        printf(" 4 - Cria 4 threads\n");
        printf("> ");
        scanf("%d", &n_threads);
    }while(n_threads < 2 || n_threads > 4);
    return n_threads;
}

int main(){

    int opcao;
    int n_threads;
    char* nome_imagem = malloc(512*sizeof(char));
    printf("V2.0-----Concorrentes-----\n");
    printf("Eduardo Brunaldi dos Santos & Igor de Souza Baliza\n"); 
    printf("\n\n\n");
    do{
        printf("Menu Principal:\n");
        printf("    1- Executar sequencial\n");
        printf("    2- Executar concorrente\n");
        printf("    0- Sair\n");
        printf("Digite uma das opcoes: ");
        scanf("%d",&opcao);

        switch (opcao){
            case 0:
                printf("Fechando  o programa!\n");
                break;
            case 1:
                 scanf("%s",nome_imagem);
                sequencial(nome_imagem);
                break;
            case 2:
                scanf("%s",nome_imagem);
                n_threads = menuThreads();
                n_nodes = menuNodes();
                concorrente(nome_imagem, n_threads, n_nodes);
                break;
            default:
                printf("Opcao invalida, selecione outra opcao.\n");
        }
    }while(opcao !=0);

    return 0;
}