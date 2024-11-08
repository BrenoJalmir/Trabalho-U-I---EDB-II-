#include "bubbleSort.hpp"

// Função bubbleSort recursiva, que recebe um ponteiro de inteiros v e um inteiro n, que é o tamanho do vetor v.
void bubbleSortR(int *v, int n){
  // Se o vetor tiver tamanho 1, ele já está ordenado
  if (n == 1) return;
  // Percorre o vetor
  for (int i = 1; i < n; i++){
    // Se o elemento anterior for maior que o atual
    if (v[i-1] > v[i]){
      // Faz a troca dos valores
      int temp = v[i-1];
      v[i-1] = v[i];
      v[i] = temp;
    }
  }
  // Chama a função recursivamente com o vetor de tamanho n-1, pois o último valor já está na posição correta, sendo o maior valor do vetor.
  bubbleSortR(v, n-1);
}