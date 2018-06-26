#ifndef AED2_BFS_H
#define AED2_BFS_H

#include "grafo.h"

typedef struct nog { //no arv busca em largura
    int dado;
    int nf;          //número de filhos
    struct nog** vf; //vetor de filhos
} nog;
typedef nog* arvg;
typedef struct cc { //struct para controle de cor
    int dado;
    int cor;
    // 0==branco  1==cinza  2==preto
} cc; 
typedef cc* vcc; //vetor de controle de cor


#endif