#include <iostream>
#include <opencv.h>
#include <cv.h>
#include <ml.h>
#include <cxcore.h>
#include <highgui.h>
 
using namespace cv;
using namespace std;

void sequencial(char *nome_imagem);
void concorrente(char *nome_imagem, int n_threads, int n_nodes);