#include <stdio.h>
#include <stdlib.h>

#include "max_heap.h"

int pai (int i) {return (i - 1)/2;}

int esquerda (int i) {return (i * 2) + 1;}

int direita (int i) {return (i * 2) + 2;}

int heap_maximum (int V[]) {return V[0];}

/* Remove e retorna o elemento de V com a maior chave (prioridade) */
int heap_extract_max (int V[], int size) {
    if (size < 1) {printf("Erro: Heap underflow!\a");}
    
    int max = V[0];
    V[0] = V[size-1];
    size--;
    max_heapify (V, size, 0);

    return max;
}

void trocar (int V[], int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

void imprimir (int V[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

void max_heapify (int V[], int size, int i) {
    int maior;
    int esq = esquerda(i);
    int dir = direita(i);

    if(esq < size && V[esq] > V[i]) {
        maior = esq; //maior é o filho da esquerda
    }
    else {maior = i;} //maior é o pai/raiz

    if(dir < size && V[dir] > V[maior]) {
        maior = dir; //maior é o filho da direita
    }

    if(maior != i) {
        trocar(V, i, maior);
        max_heapify(V, size, maior);
    }
}

/* Aumenta o valor da chave (prioridade) do elemento x para um novo valor k*/
void heap_increase_key (int V[], int i, int chave) {
    if (chave < V[i]) {
        printf("Erro: chave menor que atual!\a");
        return;
    }

    V[i] = chave;

    while ( i>0 && V[pai(i)] < V[i] ){
        trocar (V, i, pai(i));
        i = pai(i);
    }
}

/* Diminui o valor da chave (prioridade) do elemento x para um novo valor k*/
void heap_decrease_key (int V[], int i, int chave, int size) {
    if (chave > V[i]) {
        printf("Erro: chave maior que atual!\a");
        return;
    }

    V[i] = chave;

    while ( i>0 && V[pai(i)] > V[i] ) {
        trocar (V, i, pai(i));
        i = pai(i);
    }

    max_heapify(V, size, i);
}

/* Insere o elememento x no conjunto V */
void max_heap_insert(int V[], int size, int chave) {
    size++;
    V[size-1] = INT_MIN;
    heap_increase_key(V, size-1, chave);
}

int main () {

    int size = 12;

    int v[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

    imprimir (v, size);

    /*Modificando a chave da posição 0 para o valor 1!*/   
    heap_decrease_key (v, 0, 1, size);
    
    printf ("After decrease-key: \n");
    imprimir (v, size);

    return 0;
}

