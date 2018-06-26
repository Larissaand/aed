#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "bfs.h"
int ffila = 0;
int tammax;

vcc criavcc(int* ver, int tam){
    vcc controle = malloc(tam*sizeof(cc));
    for(int i = 0; i < tam; i++)
    {
        controle[i].dado = ver[i];
        controle[i].cor = 0;
    }
    return controle;
}
vetor criafila(int tam){
    vetor fila = criavet(tam);
    for(int i = 0; i<tam; i++){
        fila[i] = 0;
    }
    tammax = tam;
    return fila;
}
void addfila(vetor fila, int val){
    fila[ffila] = val;
    ffila++;
}
void removefila(vetor fila){
    for(int i = 1; i < tammax; i++){
        fila[i-1] = fila[i];
    }
    ffila--;
}
arvg bfs(grafo g){
    int tam = g->v;
    vetor fila = criafila;
    vcc ctr = criavcc(g->ver, tam);
    ctr[0].cor = 1;
    //incompleto

}