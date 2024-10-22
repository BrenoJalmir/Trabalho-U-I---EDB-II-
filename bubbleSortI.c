#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n){
  int ordenado = 0;
  while(!ordenado){
    ordenado = 1;
    for (int i = 1; i < n; i++){
      if (v[i-1]> v[i]){
        ordenado = 0;
        int temp = v[i-1];
        v[i-1] = v[i];
        v[i] = temp;
      }
    }
  }
}

void bubbleSortR(int *v, int n){
  if (n == 1){
    return;
  } else {
    bubbleSortR(v, n-1);
    for (int i = n-1; i > 0; i--){
      if (v[i-1] > v[i]){
        int temp = v[i-1];
        v[i-1] = v[i];
        v[i] = temp;
      }
    }
  }
}

void printArray(int *v, int n){
  for(int i = 0; i < n; i++){
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main(){
  int n = 5;
  int* vetor = (int*) malloc(n * sizeof(int));

  for (int i = 0; i < n; i++){
    scanf("%d", &vetor[i]);
  }

  printArray(vetor, n);
  bubbleSortR(vetor, n);
  printArray(vetor, n);

  return 0;
}