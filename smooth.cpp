#include "smooth.h"

/*
    Parametros:
                Mat img = imagem de entrada
                Mat saida = imagem de saida
                int i = linha da imagem
                int j = coluna da imagem
                int top = limite superior
                int botton = limite inferior
                int left = limite a esquerda
                int right = limite a direita
*/
void calculaRGB(cv::Mat img, cv::Mat img_saida, int i, int j, int top, int botton, int left, int right)
{
    unsigned int media[3] = {0,0,0};
    for(int rows = top; rows < botton; ++rows)
    {
        for(int cols = left; cols < right; ++cols)
        {
            media[0] += img.at<cv::Vec3b>(rows,cols)[0];
            media[1] += img.at<cv::Vec3b>(rows,cols)[1];
            media[2] += img.at<cv::Vec3b>(rows,cols)[2];
        }
    }
    int qtd = (botton-top)*(right-left);
    img_saida.at<cv::Vec3b>(i, j)[0] = (unsigned char)(media[0]/qtd);
    img_saida.at<cv::Vec3b>(i, j)[1] = (unsigned char)(media[1]/qtd);
    img_saida.at<cv::Vec3b>(i, j)[2] = (unsigned char)(media[2]/qtd);
}

void sequencialColorido(std::string nome_imagem, std::string imagem_saida){//char *nome_imagem, char *imagem_saida){
    //cout << "nome da imagem: " << nome_imagem << "\n";
    cv::Mat img = cv::imread(nome_imagem);
    cv::Mat img_saida(img.rows, img.cols, CV_8UC3);
    //canto superior esquerdo
    calculaRGB(img, img_saida, 0, 0, 0, 3, 0, 3);
    calculaRGB(img, img_saida, 0, 1, 0, 3, 0, 4);
    calculaRGB(img, img_saida, 1, 0, 0, 4, 0, 3);
    calculaRGB(img, img_saida, 1, 1, 0, 4, 0, 4);
    //canto superior direito
    calculaRGB(img, img_saida, 0, img.cols-1, 0, 3, img.cols-3, img.cols);
    calculaRGB(img, img_saida, 0, img.cols-2, 0, 3, img.cols-4, img.cols);
    calculaRGB(img, img_saida, 1, img.cols-1, 0, 4, img.cols-3, img.cols);
    calculaRGB(img, img_saida, 1, img.cols-2, 0, 4, img.cols-4, img.cols);
    //canto inferior esquerdo
    calculaRGB(img, img_saida, img.rows-1, 0, img.rows-3, img.rows, 0, 3);
    calculaRGB(img, img_saida, img.rows-1, 1, img.rows-3, img.rows, 0, 4);
    calculaRGB(img, img_saida, img.rows-2, 0, img.rows-4, img.rows, 0, 3);
    calculaRGB(img, img_saida, img.rows-2, 1, img.rows-4, img.rows, 0, 4);
    //canto inferior direito
    calculaRGB(img, img_saida, img.rows-1, img.cols-1, img.rows-3, img.rows, img.cols-3, img.cols);
    calculaRGB(img, img_saida, img.rows-1, img.cols-2, img.rows-3, img.rows, img.cols-4, img.cols);
    calculaRGB(img, img_saida, img.rows-2, img.cols-1, img.rows-4, img.rows, img.cols-3, img.cols);
    calculaRGB(img, img_saida, img.rows-2, img.cols-2, img.rows-4, img.rows, img.cols-4, img.cols);
    
    for(int j = 2; j < img.cols-2; ++j)
    {
        calculaRGB(img, img_saida, 0, j, 0, 2, j-2, j+2);//primeira linha
        calculaRGB(img, img_saida, 1, j, 0, 3, j-2, j+2);//segunda linha
        calculaRGB(img, img_saida, img.rows-2, j, img.rows-4, img.rows, j-2, j+2);//penultima linha
        calculaRGB(img, img_saida, img.rows-1, j, img.rows-3, img.rows, j-2, j+2);//ultima linha
    }
    for(int i=2 ; i<img.rows-2 ; ++i){
        //executar o codigo
        calculaRGB(img,img_saida, i, 0, i-2,i+2,0,3);//primeira coluna
        calculaRGB(img,img_saida, i, 1, i-2,i+2,0,4);//segunda coluna
        for(int j=2; j<img.cols-2; ++j)//miolo da imagem
        {
            calculaRGB(img,img_saida, i, j, i-2,i+2,j-2,j+2);
        }
        calculaRGB(img,img_saida, i, img.cols-2, i-2,i+2,img.cols-4,img.cols);//penultima coluna
        calculaRGB(img,img_saida, i, img.cols-1, i-2,i+2,img.cols-3,img.cols);//ultima coluna
    }
    //apresentar os resultado

    cv::imwrite(imagem_saida, img_saida);
}



void calculaCinza(cv::Mat img, cv::Mat img_saida, int i, int j, int top, int botton, int left, int right)
{
    unsigned int media = 0;
    for(int rows = top; rows < botton; ++rows)
    {
        for(int cols = left; cols < right; ++cols)
        {
            media += img.at<cv::Vec3b>(rows,cols)[0];
        }
    }
    int qtd = (botton-top)*(right-left);
    img_saida.at<uchar>(i, j) = (unsigned char)(media/qtd);
}

void sequencialCinza(std::string nome_imagem, std::string imagem_saida){
    //cout << "nome da imagem: " << nome_imagem << "\n";
    cv::Mat img = cv::imread(nome_imagem);
    cv::Mat img_saida(img.rows, img.cols, CV_8UC1);
    //canto superior esquerdo
    calculaCinza(img, img_saida, 0, 0, 0, 3, 0, 3);
    calculaCinza(img, img_saida, 0, 1, 0, 3, 0, 4);
    calculaCinza(img, img_saida, 1, 0, 0, 4, 0, 3);
    calculaCinza(img, img_saida, 1, 1, 0, 4, 0, 4);
    //canto superior direito
    calculaCinza(img, img_saida, 0, img.cols-1, 0, 3, img.cols-3, img.cols);
    calculaCinza(img, img_saida, 0, img.cols-2, 0, 3, img.cols-4, img.cols);
    calculaCinza(img, img_saida, 1, img.cols-1, 0, 4, img.cols-3, img.cols);
    calculaCinza(img, img_saida, 1, img.cols-2, 0, 4, img.cols-4, img.cols);
    //canto inferior esquerdo
    calculaCinza(img, img_saida, img.rows-1, 0, img.rows-3, img.rows, 0, 3);
    calculaCinza(img, img_saida, img.rows-1, 1, img.rows-3, img.rows, 0, 4);
    calculaCinza(img, img_saida, img.rows-2, 0, img.rows-4, img.rows, 0, 3);
    calculaCinza(img, img_saida, img.rows-2, 1, img.rows-4, img.rows, 0, 4);
    //canto inferior direito
    calculaCinza(img, img_saida, img.rows-1, img.cols-1, img.rows-3, img.rows, img.cols-3, img.cols);
    calculaCinza(img, img_saida, img.rows-1, img.cols-2, img.rows-3, img.rows, img.cols-4, img.cols);
    calculaCinza(img, img_saida, img.rows-2, img.cols-1, img.rows-4, img.rows, img.cols-3, img.cols);
    calculaCinza(img, img_saida, img.rows-2, img.cols-2, img.rows-4, img.rows, img.cols-4, img.cols);
    
    for(int j = 2; j < img.cols-2; ++j)
    {
        calculaCinza(img, img_saida, 0, j, 0, 2, j-2, j+2);//primeira linha
        calculaCinza(img, img_saida, 1, j, 0, 3, j-2, j+2);//segunda linha
        calculaCinza(img, img_saida, img.rows-2, j, img.rows-4, img.rows, j-2, j+2);//penultima linha
        calculaCinza(img, img_saida, img.rows-1, j, img.rows-3, img.rows, j-2, j+2);//ultima linha
    }
    for(int i=2 ; i<img.rows-2 ; ++i){
        //executar o codigo
        calculaCinza(img,img_saida, i, 0, i-2,i+2,0,3);//primeira coluna
        calculaCinza(img,img_saida, i, 1, i-2,i+2,0,4);//segunda coluna
        for(int j=2; j<img.cols-2; ++j)//miolo da imagem
        {
            calculaCinza(img,img_saida, i, j, i-2,i+2,j-2,j+2);
        }
        calculaCinza(img,img_saida, i, img.cols-2, i-2,i+2,img.cols-4,img.cols);//penultima coluna
        calculaCinza(img,img_saida, i, img.cols-1, i-2,i+2,img.cols-3,img.cols);//ultima coluna
    }
    //apresentar os resultado

    cv::imwrite(imagem_saida, img_saida);
}












void concorrente(std::string nome_imagem, int n_threads){//char *nome_imagem, int n_threads){
    std::cout << "nome da imagem: " << nome_imagem << "\n";
    std::cout << "threads: " << n_threads << "\n";

    for(int i=0 ; i<10 ; ++i){
        //executar o codigo
        //gravar em um arquivo
    }
    //apresentar os resultado
}