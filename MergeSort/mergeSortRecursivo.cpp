#include <iostream>
#include "mergeSort.hpp"

// Função recursiva para implementar o algoritmo Merge Sort
void recursiveMergeSort(int n, int *arr, int inicio, int fim) {

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        recursiveMergeSort(n, arr, inicio, meio);
        recursiveMergeSort(n, arr, meio + 1, fim);
        merge(n, arr, inicio, meio, fim); // O(n)
    }
}
