#include "../RNG/list_RNG.hpp"
#include "mergeSort.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

// g++ ./MergeSort/tempoMergeSort.cpp ./MergeSort/mergeSortIterativo.cpp ./MergeSort/funcaoMerge.cpp ./MergeSort/mergeSortRecursivo.cpp ./RNG/list_RNG.cpp -o q2.5 -g -W

// Função main para transformar a lista em vetor e chamar o algoritmo de ordenação
int main() {
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    // Altere a lista a ser ordenada aqui
    std::string fileName = "./listas/lista_10000.txt";
    std::ifstream list;
    list.open(fileName, std::ios::in);

    if (!list.is_open())
        return 1;  

    int n = getFileSize(list);
    int *arr = new int[n];

    listToVector(arr, fileName, n);
    
    iterativeMergeSort(n, arr);
    //recursiveMergeSort(n, arr, 0, n - 1);

    vectorToList(arr, n);

    // Captura o tempo de término
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::duration<double, std::micro> duration = end - start;

    // Exibe o tempo de execução
    std::cout << "O código levou " << duration.count() << " microssegundos para rodar." << std::endl;

    return 0;
}