#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "vet.h"

double secondsvet(){
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  return ((double) now.tv_sec * 1000000) + ((double)now.tv_nsec)/ 1000;
}

vetor criavet(int n){
    return malloc(n* sizeof(int));
}
void destroivet(vetor v){
    free(v);
}
void enchervet(vetor v, int n){
    v[0] = 0;
    for(int i = 1; i<n; i++){
        v[i] = 0;
    }
}
void randvet(vetor v, int n){
    srand(time(NULL));
    for(int i = 0; i<n; i++){
        v[i] = rand();
    }
}
void randbvet(vetor v, int n){
    srand(time(NULL));
    for(int i = 0; i<n; i++){
        v[i] = rand()%(n*5);
    }
}
void quick(vetor v, int inicio, int fim);
void sortvet(vetor v, int n){
    quick(v, 0, n - 1);
}

void printvet(vetor v, int n){
    printf("\n");
    for(int i = 0; i<n; i++){
        printf("%d", v[i]);
    }
    printf("\n");
}
void scanvet(vetor v, int n){
    for(int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
}
int buscaseqvet(vetor v, int n, int chave){
    int i;
    for(i = 0; i < n; i++){
        if(v[i] == chave){
            return i;
        }
    }
    return -1;
}
int buscabinvet(vetor v, int n, int chave){
    int inicio, pivot, fim;
    inicio = 0;
    fim = n-1;
    while (inicio <= fim) {
        pivot = (inicio + fim)/2;
        if (v[pivot] == chave) {
            return pivot;
        }
        if (v[pivot] < chave) {
            inicio = pivot + 1;
        }
        else {
             fim = pivot - 1;
        }
    }
    return -1;
}
void insertionvet (vetor v, int tamanho) {
    int i, j;
    int pivot;
    for(j = 1; j < tamanho; j++ ) {
        i = j -1;
        pivot = v[j];
        while((i>=0) && (v[i]<pivot)) {
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = pivot;
    }
}
void bubblevet (vetor v, int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux          = v[j];
                v[j]     = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}
void quick(vetor v, int inicio, int fim) {
    int pivot;
    int aux;
    int i,j;
    if(fim - inicio > 0) {
        i = inicio;
        j = fim;
        pivot = v[(i+j)/2];
        do {
            while(v[i] < pivot) i++;
            while(v[j] > pivot) j--;
            if(i<= j) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++; j--;
            }
        } while (i<=j);
        quick(v,inicio, j);
        quick(v, i,fim);
    }
}
void quickpausevet(vetor v, int inicio, int fim) {
    int pivot;
    int aux;
    int i,j;
    if(fim - inicio > 0) {
        i = inicio;
        j = fim;
        pivot = v[(i+j)/2];
        do {
            while(v[i] < pivot) i++;
            while(v[j] > pivot) j--;
            if(i<= j) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++; j--;
            }
        } while (i<=j);
        quick(v,inicio, j);
        getchar();
        quick(v, i,fim);
        getchar();
    }
}
void copiavet(vetor v1,vetor v2, int n){
    for (int i = 0; i < n; ++i) {
        v2[i] = v1[i];
    }
}
double timebinvet(vetor vet, int n, int chave){
    double time1 = secondsvet();
    int result = buscabinvet(vet, n, chave);
    double time2 = secondsvet();
    double time_spent = (time2 - time1) / 1000;
    if(result >=  0){
        printf("\nAchei na posicao %d\n", result);
    }
    else{
        printf("\nNao achei\n");
    }
    printf("\nA busca binaria demorou %lf milissegundos\n", time_spent);
    return time_spent;
}
double timeseqvet(vetor vet, int n, int chave){
    double time1 = secondsvet();
    int result = buscaseqvet(vet, n, chave);
    double time2 = secondsvet();
    double time_spent = (time2 - time1) / 1000;
    if(result >= 0){
        printf("\nAchei na posicao %d\n", result);
    }
    else{
        printf("\nNao achei\n");
    }
    printf("\nA busca sequencal demorou %lf milissegundos\n", time_spent);
    return time_spent;
}
double timequickvet(vetor vet, int n){
    double time1 = secondsvet();
    quick(vet, 0, n-1);
    double time2 = secondsvet();
    double time_spent = (time2 - time1) / 1000000;
    printf("\nO Quick Sort demorou %lf segundos\n", time_spent);
    return time_spent;
}
double timeinsertionvet(vetor vet, int n){
    double time1 = secondsvet();
    insertionvet(vet, n);
    double time2 = secondsvet();
    double time_spent = (time2 - time1) / 1000000;
    printf("\nO Insertion Sort demorou %lf segundos\n", time_spent);
    return time_spent;
}
double timebubblevet(vetor vet, int n){
    double time1 = secondsvet();
    bubblevet(vet, n);
    double time2 = secondsvet();
    double time_spent = (time2 - time1) / 1000000;
    printf("\nO Bubble Sort demorou %lf segundos\n", time_spent);
    return time_spent;
}

void quickparcial(vetor v, int inicio, int fim);
void trocamid(vetor v, int n){
    int aux = v[0];
    v[0] = v[n/2];
    v [n/2] = aux;
}
void quickparcialvet(vetor v, int n) {

  quickparcial (v, 0, n-1);
  trocamid(v, n+1);

}
void quickparcial(vetor v, int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;
  if(fim - inicio > 0) {
    i = inicio;
    j = fim;
    pivot = v[(i+j)/2];

    do {
      while(v[i] < pivot) i++;
      while(v[j] > pivot) j--;
      if(i<= j) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++; j--;
      }
    } while (i<=j);


    quick(v,j/2, j);
    quick(v, i,fim);
  }
}
