#ifndef _MAX_HEAP_H_
#define _MAX_HEAP_H_

int pai (int i);
int esquerda (int i);
int direita (int i);

int heap_maximum (int V[]);

int heap_extract_max (int V[], int size);

void trocar (int V[], int a, int b);

void imprimir (int V[], int size);

void max_heapify (int V[], int size, int i);

void heap_increase_key (int V[], int i, int chave);

void heap_decrease_key (int V[], int i, int chave, int size);

void max_heap_insert(int V[], int size, int chave);

#endif