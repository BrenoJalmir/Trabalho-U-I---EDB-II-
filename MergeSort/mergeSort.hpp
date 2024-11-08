#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

// Função recursiva para implementar o algoritmo Merge Sort
void recursiveMergeSort(int n, int *arr, int inicio, int fim);

// Função iterativa para implementar o algoritmo Merge Sort
void iterativeMergeSort(int n, int *arr);

// Função auxiliar para mesclar dois subvetores ordenados
void merge(int n, int *arr, int inicio, int meio, int fim);

#endif