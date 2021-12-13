#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

int pai (int i);

int esquerda (int i);

int direita (int i);

int heap_minimun (int V[]);

void trocar (int *V, int a, int b);

void imprimir (int *V, int size);

void min_heapify (int *V, int size, int i);

void build_min_heap (int *V, int size);

int heap_extract_min (int *V, int *size);

void heap_decrease_key (int *V, int i, int chave, int size);

void min_heap_insert (int *V, int chave, int *size);

#endif