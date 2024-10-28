#include <stdio.h>
#include <stdlib.h>

// Função bubbleSort iterativa, que recebe um ponteiro de inteiros v e um inteiro n, que é o tamanho do vetor v.
void bubbleSort(int *v, int n){
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

void printArray(int *v, int n){
  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main(){
  // int n = 5;
  // int* vetor = (int*) malloc(n * sizeof(int));

  // for (int i = 0; i < n; i++){
  //   scanf("%d", &vetor[i]);
  // }

  // printArray(vetor, n);
  // bubbleSortR(vetor, n);
  // printArray(vetor, n);

  // free(vetor);

  return 0;
}