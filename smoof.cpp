#include "smoof.h"

void sequencial(char *nome_imagem){
    cout << "nome da imagem: " << nome_imagem << "\n";
}


void concorrente(char *nome_imagem, int n_threads, int n_nodes){
    cout << "nome da imagem: " << nome_imagem << "\n";
    cout << "threads: " << n_threads << "\n";
    cout << "nodes: " << n_nodes << "\n";
}