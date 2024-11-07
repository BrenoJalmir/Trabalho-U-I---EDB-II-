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

// Função recursiva para implementar o algoritmo Merge Sort
void recursiveMergeSort(int n, int *arr, int inicio, int fim) {

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        recursiveMergeSort(n, arr, inicio, meio);
        recursiveMergeSort(n, arr, meio + 1, fim);
        merge(n, arr, inicio, meio, fim); // O(n)
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

// Função main com o vetor e a chamada da função recursiva
int main() {
    // Vetor a ser ordenado (altere se quiser)
    int arr[9] = {9,8,2,18,5,14,7,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int opt = 0;
    std::cout << "Vetor a ser ordenado:" << std::endl;
    printVetor(arr, n);
    
    recursiveMergeSort(n, arr, 0, n - 1);

    std::cout << "\nVetor ordenado:" << std::endl;
    printVetor(arr, n);

    return 0;
}