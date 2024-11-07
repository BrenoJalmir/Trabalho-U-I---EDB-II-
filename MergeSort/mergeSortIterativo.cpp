#include <iostream>

// MERGE SORT
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

// Função para printar o vetor
void printVetor(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n-1)
            std::cout << arr[i] << " ";
        else
            std::cout << arr[i] << "\n" << std::endl;
    }
}

// Função main com o vetor e a chamada da função iterativa
int main() {
    // Vetor a ser ordenado (altere se quiser)
    int arr[9] = {9,8,2,18,5,14,7,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int opt = 0;
    std::cout << "Vetor a ser ordenado:" << std::endl;
    printVetor(arr, n);
    
    iterativeMergeSort(n, arr);

    std::cout << "\nVetor ordenado:" << std::endl;
    printVetor(arr, n);

    return 0;
}