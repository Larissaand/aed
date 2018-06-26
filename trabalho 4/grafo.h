#ifndef AED2_GRAFO_H
#define AED2_GRAFO_H
#include "vet.h"


#define GRAU_MAX 100

typedef struct grafo{ //contém o número de arestas, número de vértices e a matriz.
    int v;
    int a;
    vetor ver;
    int** mat;
}* grafo;


grafo criagrafo(vetor v, int tam); //cria um grafo a partir de um vetor vertices
void  inserearesta(grafo g, int p, int d, int ori); //insere uma arestano grafo (ori indica se o grafo é orientado)
void liberaaresta(grafo g, int p, int d, int ori); //remove uma arestano grafo (ori indica se o grafo é orientado)
void printgrafo(grafo g); //mostra o grafo
void liberagrafo(grafo g); //free no grafo
grafo randgrafo(int grau, int c, int ori); //cria um grafo randomico (c é a conectividade do grafo)



#endif
