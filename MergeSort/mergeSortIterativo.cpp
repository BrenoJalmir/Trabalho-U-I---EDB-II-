#include <iostream>
#include "mergeSort.hpp"

// Função mínima que retorna o menor de dois números
int min(int x, int y) { return (x < y)? x :y; } // O(1)

// Função iterativa para implementar o algoritmo Merge Sort
void iterativeMergeSort(int n, int *arr) { // Θ(n log n)

    int tam_atual; // O(1)
    int inicio;    // O(1)
 
    for (tam_atual = 1; tam_atual <= n-1; tam_atual = 2 * tam_atual) { // O(log n) pois o array dobra em cada iteração

        for (inicio = 0; inicio < n-1; inicio += 2 * tam_atual) { // O(n)
            int meio = min(inicio + tam_atual - 1, n-1); // O(1)
            int fim = min(inicio + 2 * tam_atual - 1, n-1); // O(1)
    
            merge(n, arr, inicio, meio, fim); // O(n)
        }
    }
}
