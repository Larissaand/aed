#ifndef AED2_DFS_H
#define AED2_DFS_H

#include "grafo.h"
#include "vet.h"


vetor dfs(grafo g,int i);
void dfs_b(grafo g, int i);
double timedfs(grafo g, int i);
int conexo(grafo g, int i);
void fullpath(grafo g, int i);
int _subgrafos();

#endif
