#include "smooth.h"

int main(int argc, char *argv[])
{
    int opcao=0, opcao_cor=0;
    std::string nome_imagem;
    std::string nome_saida;
    //cabecalho do programa
    std::cout << "V2.0-----Concorrentes-----\n" ;
    std::cout << "Eduardo Brunaldi dos Santos & Igor de Souza Baliza\n";
    std::cout << "\n\n\n";

    //menu principal
    do{
        // primeira escolha que o usuario deve fazer
        std::cout << "Menu Principal:\n"; 
        std::cout << "    1- Executar sequencial\n"; 
        std::cout << "    2- Executar concorrente\n";
        std::cout << "    0- Sair\n";
        std::cout << "Digite uma das opcoes: ";
        std::cin >> opcao;
        if (opcao==0)
            break;
        // Segunda escolha que deve o usuario deve fazer
        do{
            std::cout << "Escolha o tipo de Imagem:\n";
            std::cout << "1 - RGB\n";
            std::cout << "2 - Grayscale\n";
            std::cout << "Digite uma das opcoes: ";
            std::cin >> opcao_cor;
        }while(opcao_cor < 1 || opcao_cor > 2);

        //dado a primeira e a segunda opcao escolhidada
        // pesquisamos a funcao que sera chamada
        switch (opcao){
            case 0:
                std::cout << "Fechando  o programa!\n"; 
                break;
            case 1:
                //opcao_cor ==1 eh colorido, se zero entao grayscale
               if(opcao_cor == 1){
                    sequencialColorido("rgb/1.jpg", "saida/seq/rgb/1.jpg");
                    sequencialColorido("rgb/2.jpg", "saida/seq/rgb/2.jpg");
                    sequencialColorido("rgb/3.jpg", "saida/seq/rgb/3.jpg");
                    sequencialColorido("rgb/4.jpg", "saida/seq/rgb/4.jpg");
                }else{
                    sequencialCinza("gray/1.jpg", "saida/seq/gray/1.jpg");
                    sequencialCinza("gray/2.jpg", "saida/seq/gray/2.jpg");
                    sequencialCinza("gray/3.jpg", "saida/seq/gray/3.jpg");
                    sequencialCinza("gray/4.jpg", "saida/seq/gray/4.jpg");
                }
                break;
            case 2:
                if(opcao_cor == 1){
                    concorrenteColorido("rgb/1.jpg", "saida/conc/rgb/1.jpg", argc, argv);
                    concorrenteColorido("rgb/2.jpg", "saida/conc/rgb/2.jpg", argc, argv);
                    concorrenteColorido("rgb/3.jpg", "saida/conc/rgb/3.jpg", argc, argv);
                    concorrenteColorido("rgb/4.jpg", "saida/conc/rgb/4.jpg", argc, argv);
                }else{
                    concorrenteCinza("gray/1.jpg", "saida/conc/gray/1.jpg", argc, argv);
                    concorrenteCinza("gray/2.jpg", "saida/conc/gray/2.jpg", argc, argv);
                    concorrenteCinza("gray/3.jpg", "saida/conc/gray/3.jpg", argc, argv);
                    concorrenteCinza("gray/4.jpg", "saida/conc/gray/4.jpg", argc, argv);
                }
                break;
            default:
                std::cout << "Opcao invalida, selecione outra opcao.\n"; 
        }
    }while(opcao !=0);

    return 0;
}