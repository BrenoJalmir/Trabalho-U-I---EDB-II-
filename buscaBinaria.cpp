#include <iostream>
#include <chrono>
using namespace std;

int buscaBinariaRecursiva(int A[], int esq, int dir, int x) {

    if (esq > dir) {
        return -1; // Caso base: elemento não encontrado
    }

    int m = (esq + dir) / 2; // Define o índice do elemento central da lista

    if (A[m] == x) {
        return m; // Elemento encontrado
    }
    else if (A[m] < x) {
        return buscaBinariaRecursiva(A, m + 1, dir, x); // Busca na metade direita
    }
    else {
        return buscaBinariaRecursiva(A, esq, m - 1, x); // Busca na metade esquerda
    }
}

int buscaBinaria(int A[], int n, int x) {
    return buscaBinariaRecursiva(A, 0, n - 1, x);
}

int main() {
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    //Exemplo de uso
    int A[] = {1, 3, 5, 7, 9};
    int n = sizeof(A) / sizeof(A[0]); //Essa divisão resulta no tamanho do vetor baseado na quantidade de bytes que ele ocupa e no tipo de elementos nele (tentei garantir maior performance).
    int x = 5;

    int resultado = buscaBinaria(A, n, x);
    if (resultado != -1) {
        cout << "Elemento encontrado no índice: " << resultado << endl;
    }
    else {
        cout << "Elemento não encontrado." << endl;
    }

    // Captura o tempo de término
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::duration<double, std::milli> duration = end - start;

    // Exibe o tempo de execução
    std::cout << "O código levou " << duration.count() << " milissegundos para rodar." << std::endl;

    return 0;
}