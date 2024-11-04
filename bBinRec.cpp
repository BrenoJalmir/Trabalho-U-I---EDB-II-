#include <iostream>
#include <chrono>
using namespace std;

int bBinRec(int A[], int esq, int dir, int x) {
    if (esq > dir) {
        return -1; // Caso base: elemento não encontrado
    }

    int m = (esq + dir) / 2;

    if (A[m] == x) {
        return m; // Elemento encontrado
    }
    else if (A[m] > x) {
        return bBinRec(A, esq, m - 1, x); // Busca na metade esquerda
    }
    else {
        return bBinRec(A, m + 1, dir, x); // Busca na metade direita
    }
}

int main() {
    // Capturando tempo de execução
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

        // Exemplo de uso - substitua o código abaixo
        int A[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 81, 91, 102, 114, 125};
        int n = sizeof(A) / sizeof(A[0]); //Essa divisão resulta no tamanho do vetor baseado na quantidade de bytes que ele ocupa e no tipo de elementos nele (tentei garantir maior performance).

        int x = 56; // Elemento a ser buscado

        int resultado = bBinRec(A, 0, n - 1, x);
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