#ifndef __SMOOTH_H__
#define __SMOOTH_H__

#include <iostream>
#include <string>
#include <opencv/cv.h>
#include <opencv/ml.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
//#include <omp.h>
//#include <ctime>
//#include <mpi.h>
 
//using namespace std;


void sequencialColorido(std::string nome_imagem, std::string imagem_saida);
//void sequencialColorido(char *nome_imagem, char *imagem_saida);
void concorrente(std::string nome_imagem, int n_threads);
//void concorrente(char *nome_imagem, int n_threads);


#endif