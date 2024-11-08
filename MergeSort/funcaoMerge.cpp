#include "mergeSort.hpp"

// Função auxiliar para mesclar dois subvetores ordenados
void merge(int n, int *arr, int inicio, int meio, int fim) { // O(n) e Ω(1)
    int i = inicio, j = meio + 1, k = inicio; // O(1)
    int aux[n]; // O(1)

    while (i <= meio && j <= fim) { // O(n) e Ω(1)
        if (arr[i] < arr[j]) {
            aux[k] = arr[i];
            i++;
        } else {
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= meio) { // O(n) e Ω(1)
        aux[k] = arr[i];
        i++;
        k++;
    }

    while (j <= fim) { // O(n) e Ω(1)
        aux[k] = arr[j];
        j++;
        k++;
    }

    for (int p = inicio; p <= fim; p++) { // O(n) e Ω(1)
        arr[p] = aux[p];
    }
}