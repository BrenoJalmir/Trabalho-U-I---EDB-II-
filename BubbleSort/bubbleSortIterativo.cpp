#include "bubbleSort.hpp"

// Função bubbleSort iterativa, que recebe um ponteiro de inteiros v e um inteiro n, que é o tamanho do vetor v.
void bubbleSortI(int *v, int n){
  // Começa a função supondo que o vetor está desordenado
  int ordenado = 0;
  // Enquanto o vetor não estiver ordenado
  while(!ordenado){
    // Supõe que o vetor está ordenado
    ordenado = 1;
    // Percorre o vetor
    for (int i = 1; i < n; i++){
      // Se o elemento anterior for maior que o atual
      if (v[i-1]> v[i]){
        // Se entrou no if, o vetor não está ordenado e faz a troca dos valores
        ordenado = 0;
        int temp = v[i-1];
        v[i-1] = v[i];
        v[i] = temp;
      }
    }
  }
}