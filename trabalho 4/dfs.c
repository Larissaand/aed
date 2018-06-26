#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "dfs.h"
vetor visitado;
vetor v_res;
int k;
int sg;

vetor dfs(grafo g,int i){
  int l;
  sg=0;
  visitado = criavet(g->v);
  enchervet(visitado,g->v);
  v_res = criavet(g->v);
  enchervet(v_res,g->v);
  for(l=0;l<g->v; l++){
    if(!visitado[l]){
      dfs_b(g,l);
      sg++;
    }
  } 
  return(v_res);
}
void dfs_b(grafo g, int i){
  int j;
  v_res[k]=i;
  visitado[i]=1;
  for (j=0; j<g->v; j++){
    if(!visitado[j] && g->mat[i][j]==1){
      k++;
      dfs_b(g,j);
    }
  }
}

double timedfs(grafo g, int i){
    double time1 = secondsvet();
    vetor result = dfs(g,i);
    double time2 = secondsvet();
    double time_spent = (time2 - time1) / 1000;
}

int _subgrafos() { return sg; }

int conexo(grafo g, int i){
  dfs(g,i);
  if(_subgrafos() == 1) printf("É conexo");
  else printf("não é conexo");
}

void fullpath(grafo g, int i){
  int a;
  for (a=0; a<g->v; a++){
    printvet(dfs(g,a),g->v);
    print("\n");
  }
}

