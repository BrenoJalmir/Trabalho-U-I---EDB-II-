#include "../RNG/list_RNG.hpp"
#include "quickSort.hpp"
#include <iostream>
#include <fstream>

// g++ ./QuickSort/tempoQuickSort.cpp ./QuickSort/quickSortIterativo.cpp ./QuickSort/funcaoParticionar.cpp ./QuickSort/quickSortRecursivo.cpp ./RNG/list_RNG.cpp -o q2.5 -g -W

// Função main para transformar a lista em vetor e chamar o algoritmo de ordenação
int main() {
    
    // Altere a lista a ser ordenada aqui
    std::string fileName = "./listas/lista_100.txt";
    std::ifstream list;
    list.open(fileName, std::ios::in);

    if (!list.is_open())
        return 1;  

    int n = getFileSize(list);
    int *arr = new int[n];

    listToVector(arr, fileName, n);
    
    // quickSortIterativo(arr, 0, n);
    quickSortRecursivo(arr, 0, n);

    vectorToList(arr, n);

    return 0;
}