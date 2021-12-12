#include <stdio.h>
#include <stdlib.h>

int pai (int i) {
    return (i - 1)/2;
}

int esquerda (int i) {
    return (i * 2) + 1;
}

int direita (int i) {
    return (i * 2) + 2;
}

void trocar (int *V, int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir (int *V, int size) {
    int i;
    for (i = 0; i < size; i++) {
    printf("%d ", V[i]);
    }
    printf("\n");
}

void min_heapify (int *V, int size, int i) {
    /*TERMINAR!*/
}

void build_min_heap (int *V, int size) {
    /*TERMINAR!*/
}

int heap_extract_min (int *V, int *size) {
    /*TERMINAR!*/
}

void heap_decrease_key (int *V, int i, int chave, int size) {
    /*TERMINAR!*/
}

void min_heap_insert (int *V, int chave, int *size) {
    /*TERMINAR!*/
}

int main () {

    int size = 10;

   //vetor inicial:  {4, 1, 3, 2, 16, 9, 10, 14, 8, 7}

    /*
    imprimir (v, size);

    build_min_heap (v, size);
    
    imprimir (v, size);
    
    heap_extract_min (v, &size);
    
    imprimir (v, size);
    
   //Modificando a última chave {16} para o valor {1}!
    heap_decrease_key (v, size-1, 1, size);
    
    imprimir (v, size);

   //Inserindo uma nova chave com valor {0}!
    min_heap_insert (v, 0, &size);
    
    imprimir (v, size);
   */
    
    return 0;
}

