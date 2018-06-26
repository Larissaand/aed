#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "grafo.h"
#include "dfs.h"
#include "vet.h"

typedef struct aresta{ //para a função randgrafo
    int x;
    int y;
} aresta; //precisei criar a struct para tratar valores repetidos no rand

int** criamat(int tam){  //para afunção criagrafo
    int** mat= malloc(tam*sizeof(vetor));
    for(int i = 0; i<tam; i++){
        mat[i] = malloc(tam*sizeof(int));
    }
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            mat[i][j] = 0;
        }
    }
    return mat;
}
vetor cpyvertice(vetor v, int tam){ //para a função criagrafo
    vetor vet = (vetor) malloc(tam*sizeof(int));
    for(int i = 0; i < tam; i++){
        vet[i] = v[i];
    }
    return vet;
}
grafo criagrafo(vetor v, int tam){
    grafo g = (grafo) malloc(sizeof(struct grafo));
    g->a = 0;
    g->v = tam;
    g->ver = cpyvertice(v, tam);
    g->mat = criamat(tam);
}
void  inserearesta(grafo g, int p, int d, int ori){
    p = buscaseqvet(g->ver, g->v, p);
    d = buscaseqvet(g->ver, g->v, d);
    switch(ori){
        case 1: //grafo orientado
            if(g->mat[p][d] == 0){
                g->mat[p][d] = 1;
                g->a++;
            }
        break;
        default: //grafo não orientado
            if(g->mat[p][d] == 0){
                g->mat[p][d] = 1;
                g->mat[d][p] = 1;
                g->a++;
            }
        break;
    }

}
void liberaaresta(grafo g, int p, int d, int ori){
    switch(ori){
        case 1: //grafo orientado
            if(g->mat[p][d] == 1){
                g->mat[p][d] = 0;
                g->a--;
            }
        break;
        default: //grafo não orientado
            if(g->mat[p][d] == 1){
                g->mat[p][d] = 0;
                g->mat[d][p] = 0;
                g->a--;
            }
        break;
    }
}
void printgrafo(grafo g){
    int tam = g->v;
    printf(" ");
    for(int i = 0; i < tam; i++){
        printf(" %d", g->ver[i]);
    }
    printf("\n");
    for(int i = 0; i < tam; i++){
        printf("%d", g->ver[i]);
        for(int j = 0; j < tam; j++){
            printf(" %d", g->mat[i][j]);
        }
        printf("\n");
    }

}
void liberagrafo(grafo g){
    free(g->ver);
    for(int i = 0; i < g->v; i++){
        free(g->mat[i]);
    }
    free(g->mat);
    free(g);
}
int verificapar(aresta* usadas, int x, int y, int arestas){ //função para randgrafo
    int f = 1;
    for(int i = 0; i < arestas; i++){
        if(usadas[i].x == x && usadas[i].y == y){
            f = 0;
        }
    }
    return f;
}
void inserepar(aresta* usadas, int i, int x, int y){ //função para randgrafo
    usadas[i].x = x;
    usadas[i].y = y;
}
grafo randgrafo(int grau, int c, int ori){
    srand(time(NULL));
    int arestas = (grau*(grau-1)*c)/100; //número total de arestas no grafo
    aresta* usadas = malloc(arestas*sizeof(aresta)); //vetor para evitar arestas repetidas
    int x, y, z;
    vetor v = criavet(grau);
    for(int i = 0; i < grau; i++){
        z = rand()%GRAU_MAX;
        if(buscaseqvet(v, arestas, z) < 0){
            v[i] = z;
        }
        else{
            i--;
        }
    }
    grafo g = criagrafo(v,grau);
    for(int i = 0; i < arestas; i++){
        if(i<grau){
            x=i;
        }else{
            x=rand()%grau;
        }
        y = rand()%grau;
        if(x != y && verificapar(usadas, x, y, arestas)){
            inserepar(usadas, i, x, y);
            inserearesta(g, v[x],v[y], ori);
        }else{
            i--;
        }
    }
    free(usadas);
    destroivet(v);
    return g;
}
