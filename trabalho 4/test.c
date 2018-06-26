#include <stdio.h>
#include "grafo.h"
#include  "dfs.h"

int main()
{
    vetor kkeaeman;
    grafo g = randgrafo(5,20,0);
    printgrafo(g);
    kkeaeman=dfs(g,0);
    fullpath(g,0);
    liberagrafo(g);
    printvet(kkeaeman,5);
    return 0;
}
