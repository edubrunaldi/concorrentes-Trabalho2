#ifndef __SMOOTH_H__
#define __SMOOTH_H__

#include <iostream>
#include <string>
#include <opencv/cv.h>
#include <opencv/ml.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <sys/time.h>
#include <omp.h>
#include <mpi.h>

#define MASTER_TO_SLAVE_TAG 1
#define SLAVE_TO_MASTER_TAG 10 
#define PAI 0
#define INICIO 0
#define MEIO 1
#define FIM 2

/*
    Reecebendo a imagem colorida, calculamos a media(5x5) de suas tres cores (R,G,B)
    e ja realocamos o novo valor para  o pixel recebido.
    Esssa funcao eh valida tanto para o metodo sequencial quanto o paralelo
    pois mech

*/
void calculaRGB(cv::Mat img, cv::Mat img_saida, int i, int j, int top, int botton, int left, int right);


/*
    Recebendo o path da imagem de entrada e o path da imagem pos smooth,
    separamos a imagem em pedaços de forma que toda lateral com distancia de 2 pixels
    eh contanda em especial ja que nao como esta no canto nao eh possivel fazer 5x5.
    ja o "miolo", podemos fazer em um loop ja que todos pixels dentro dele eh possivel fazer 5x5.
*/
void sequencialColorido(std::string nome_imagem, std::string imagem_saida);


/*
    Reecebendo a imagem preto branco, calculamos a media(5x5) de sua unica cor(R)
    e ja realocamos o novo valor para  o pixel recebido

*/
void calculaCinza(cv::Mat img, cv::Mat img_saida, int i, int j, int top, int botton, int left, int right);

/*
    Recebendo o path da imagem de entrada e o path da imagem pos smooth,
    separamos a imagem em pedaços de forma que toda lateral com distancia de 2 pixels
    eh contanda em especial ja que nao como esta no canto nao eh possivel fazer 5x5.
    ja o "miolo", podemos fazer em um loop ja que todos pixels dentro dele eh possivel fazer 5x5.
*/
void sequencialCinza(std::string nome_imagem, std::string imagem_saida);


/*
    Reecebendo a imagem preto branco, calculamos a media(5x5) de sua unica cor(R)
    e ja realocamos o novo valor para  o pixel recebido.
    Essa funcao recebe apenas um vetor da imagem, e nao a imagem inteira,
    O calculo feito nessa funcao eh identida a de calculaCinza, apenas mudamos
    a forma que pegamos e gravamos os pixels desejados.

*/
void calculaConCinza(unsigned char *img, unsigned char *img_saida, int i, int j, int top, int botton, int left, int right, int width);


/*
    Reecebendo a imagem preto branco, calculamos a media(5x5) de sua unica cor(R)
    e ja realocamos o novo valor para  o pixel recebido.
    Essa funcao eh feita de forma paralela(concorrente), e recebemos 2 argumentos a mais
    em relacao as funcoes sequencias: argc  e argv, argumentos recebido pela main()
    que repacamos para o MPI_Init(&argc,&argv), para ele receber as flags:
                                                        -np (numero de threads)
                                                        --hostfile (arquivo com nomes dos hosts)

*/
void concorrenteCinza(std::string nome_imagem, std::string imagem_saida,  int argc, char *argv[]);

/*
    Reecebendo a imagem colorida, calculamos a media(5x5) de sua unica cor(R)
    e ja realocamos o novo valor para  o pixel recebido.
    Essa funcao recebe apenas um vetor da imagem, e nao a imagem inteira,
    O calculo feito nessa funcao eh identida a de calculaRGB, apenas mudamos
    a forma que pegamos e gravamos os pixels desejados.
*/
void calculaConRGB(unsigned char *img, unsigned char *img_saida, int i, int j, int top, int botton, int left, int right, int width);


/*
    Reecebendo a imagem colorida, calculamos a media(5x5) de suas  cores(R,G,B)
    e ja realocamos o novo valor para  o pixel recebido.
    Essa funcao eh feita de forma paralela(concorrente), e recebemos 2 argumentos a mais
    em relacao as funcoes sequencias: argc  e argv, argumentos recebido pela main()
    que repacamos para o MPI_Init(&argc,&argv), para ele receber as flags:
                                                        -np (numero de threads)
                                                        --hostfile (arquivo com nomes dos hosts)

*/
void concorrenteColorido(std::string nome_imagem, std::string imagem_saida, int argc, char *argv[]);


#endif