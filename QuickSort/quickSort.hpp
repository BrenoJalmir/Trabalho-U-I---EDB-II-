#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

// Função que define pivô como o último e bota ele no lugar entre os maiores (que ele) e menores (que ele)
int particionar(int vetor[], int inicio, int fim);

// Quick sort recursivo
void quickSortRecursivo(int vetor[], int inicio, int fim);

// Quick sort iterativo
void quickSortIterativo(int vetor[], int inicio, int fim);

#endif