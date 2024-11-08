#include "quickSort.hpp"

// Função que define pivô como o último e bota ele no lugar entre os maiores (que ele) e menores (que ele)
int particionar(int vetor[], int inicio, int fim) 
{ 
    int pivo = vetor[fim]; 
    int i = (inicio - 1);
    int temp = 0 ;

    for (int j = inicio; j <= fim - 1; j++) { 
        if (vetor[j] <= pivo) { 
            i++; 
            temp = vetor[i]; 
            vetor[i] = vetor[j];
            vetor[j] = temp;
        } 
    } 
    temp = vetor[i + 1]; 
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return (i + 1); 
} 