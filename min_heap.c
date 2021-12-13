#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "min_heap.h"

int pai (int i) {return (i - 1)/2;}

int esquerda (int i) {return (i * 2) + 1;}

int direita (int i) {return (i * 2) + 2;}

int heap_minimun (int V[]) {return V[0];}

void trocar (int *V, int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir (int *V, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void min_heapify (int *V, int size, int i) {
    int menor;
    int esq = esquerda(i);
    int dir = direita(i);

    if(esq < size && V[esq] < V[i]) {
        menor = esq; //menor é o filho da esquerda
    }
    else {menor = i;} //menor é o pai/raiz

    if(dir < size && V[dir] < V[menor]) {
        menor = dir; //menor é o filho da direita
    }

    if(menor != i) {
        trocar(V, i, menor);
        min_heapify(V, size, menor);
    }
}

void build_min_heap (int *V, int size) {

    for(int i = floor (size/2) - 1; i>-1; i--) {
        min_heapify(V, size, i);
    }

    //Heap-sort invertido
    //for (int i = size-1; i>0; i--) {
        //trocar (V, 0, i);
        //size = i;
        //min_heapify (V, size, 0);
    //}
}

int heap_extract_min (int *V, int *size) {
    if (*size < 1) {printf("Erro: Heap underflow!\a");}
    
    int min = V[0];
    V[0] = V[*size-1];
    (*size)--;
    min_heapify (V, *size, 0);

    return min;
}

/* Diminui o valor da chave (prioridade) do elemento x para um novo valor k*/
void heap_decrease_key (int *V, int i, int chave, int size) {

    if (chave > V[i]) {
        printf("Erro: chave maior que atual!\a");
        return;
    }

    V[i] = chave;

    while ( i>0 && V[pai(i)] > V[i] ) {
        trocar (V, i, pai(i));
        i = pai(i);
    }
}

void min_heap_insert (int *V, int chave, int *size) {
    (*size)++;
    V[(*size)-1] = INT_MAX;
    heap_decrease_key(V, (*size)-1, chave, *size);
}

int main () {

    int size = 10; 
    int *V; 
    int V_ini[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};   

    V = (int *) malloc (size * sizeof(int));

    for (int i=0;i<size;i++) {
        V[i] = V_ini[i];
    }

    printf("\nFila original:\n ");
    imprimir (V, size);

    build_min_heap (V, size);

    printf("\nbuild_min_heap() \n Min-Heap:\n ");    
    imprimir (V, size);

    int min = heap_extract_min (V, &size);

    printf("\nheap_extract_min(1) \n Elem %d extraido da fila:\n ", min);
    imprimir (V, size);

    //Modificando a última chave {16} para o valor {1}!
    heap_decrease_key (V, size-1, 1, size);

    printf("\nheap_decrease_key(16->1) \n Ultima chave {16} modificada para o valor {1}:\n ");
    imprimir (V, size);

    //Inserindo uma nova chave com valor {0}
    min_heap_insert (V, 0, &size);
    
    printf("\n min_heap_insert(0) \n Insercao da chave {0}: \n ");
    imprimir (V, size);

    printf("\n");

    return 0;
}

