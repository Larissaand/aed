#ifndef AED2_VET_H
#define AED2_VET_H


typedef int* vetor;

//Para Todas as fuções: a variável 'n' representa o número de elementos do vetor
vetor criavet(int n);//retorna um ponteiro para o vetor
void enchervet(vetor v, int n);//preenche o vetor com elementos aleatórios e ordenados
void randvet(vetor v, int n);//preenche o vetor com elementos aleatórios e desordenados
void destroivet(int v[]);//free
void sortvet(vetor v, int n);//quicksort
void printvet(vetor v, int n);//printar cada elemento do vetor
void scanvet(vetor v, int n);//recebe cada elemento do vetor vido do teclado
int buscaseqvet(vetor v, int n, int chave);//busca sequencial (retorna o indice do valor procurado ou -1)
int buscabinvet(vetor v, int n, int chave);//busca binária (retorna o indice do valor procurado ou -1)
void insertionvet (vetor v, int tamanho);//ordena por inserção direta
void bubblevet (vetor v, int n);//ordena com bubble...
void copiavet(vetor v1,vetor v2, int n);//copia v1 para o vetor v2
double timebinvet(vetor v, int n, int chave);//tempo da busca binária no vetor
double timeseqvet(vetor v, int n, int chave);//tempo da busca sequencial no vetor
double timebubblevet(vetor v, int n);//tempo para bubble sort
double timeinsertionvet(vetor v, int n);//tempo para insertion sort
double timequickvet(vetor v, int n);//tempo para quick sort
void quickpausevet(vetor v, int inicio, int fim);//para verificar a quantidade de memoria alocada
void quickparcialvet(vetor v, int n); //quicksort parcial 
void randbvet(vetor v, int n); //gera um vetor desordenado com números baixos
#endif