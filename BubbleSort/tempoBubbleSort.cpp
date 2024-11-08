#include "../RNG/list_RNG.hpp"
#include "bubbleSort.hpp"
#include <iostream>
#include <fstream>

// g++ ./BubbleSort/tempoBubbleSort.cpp ./BubbleSort/bubbleSortIterativo.cpp ./BubbleSort/bubbleSortRecursivo.cpp ./RNG/list_RNG.cpp -o q2.5 -g -W

/* Função main para transformar a lista em vetor, chamar o algoritmo de ordenação
   e testar o tempo de execução do algoritmo */ 
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
    
    // bubbleSort(arr, n);
    bubbleSortR(arr, n);

    vectorToList(arr, n);

    return 0;
}