#include <iostream> 
#include "quickSort.hpp"

// Função iterativa
void quickSortIterativo(int vetor[], int inicio, int fim) 
{ 
    // Criar pilha auxiliar
    int pilha[fim - inicio + 1]; 
    int topo = -1; 

    // Empilhar valores de inicio e fim 
    pilha[++topo] = inicio; 
    pilha[++topo] = fim; 

    // Enquanto não estiver vazia, desempilhar da pilha 
    while (topo >= 0) { 
        // Desempilhar inicio e fim 
        fim = pilha[topo--]; 
        inicio = pilha[topo--]; 

        // Botar pivo no lugar final dele
        int pivo = particionar(vetor, inicio, fim); 

        // Se tiver elementos menores (à esquerda), por na pilha
        if (pivo - 1 > inicio) { 
            pilha[++topo] = inicio; 
            pilha[++topo] = pivo - 1; 
        } 

        // Se tiver elementos maiores (à direita), por na pilha
        if (pivo + 1 < fim) { 
            pilha[++topo] = pivo + 1; 
            pilha[++topo] = fim; 
        } 
    } 
} 
