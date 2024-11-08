#include "quickSort.hpp"

//Função recursiva
void quickSortRecursivo(int vetor[], int inicio, int fim) 
{ 
    if (inicio < fim) { 
        //Separando dois vetores para chamadas recursivas
        int pivo = particionar(vetor, inicio, fim); 
        quickSortRecursivo(vetor, inicio, pivo - 1); 
        quickSortRecursivo(vetor, pivo + 1, fim); 
    } 
} 
