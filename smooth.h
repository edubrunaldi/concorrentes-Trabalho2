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

void calculaRGB(cv::Mat img, cv::Mat img_saida, int i, int j, int top, int botton, int left, int right);
void sequencialColorido(std::string nome_imagem, std::string imagem_saida);
void calculaCinza(cv::Mat img, cv::Mat img_saida, int i, int j, int top, int botton, int left, int right);
void sequencialCinza(std::string nome_imagem, std::string imagem_saida);
void concorrente(std::string nome_imagem, int n_threads);


#endif