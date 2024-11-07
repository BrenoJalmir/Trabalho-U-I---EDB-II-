#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

int bBinRec(const vector<int>& A, int esq, int dir, int x) {
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
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> idades;
    std::ifstream file("./lists/idades_10000_ordenadas.txt");

    std::string line;
    while (std::getline(file, line)) {
        idades.push_back(std::stoi(line));
    }

    int resultado = bBinRec(idades, 0, idades.size() - 1, 30); // Usando .size() (complexidade O(1)) para obter o tamanho do vetor
    if (resultado != -1) {
        cout << "Elemento encontrado no índice: " << resultado << endl;
    }
    else {
        cout << "Elemento não encontrado." << endl;
    }

    // Captura o tempo de término
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::duration<double, std::micro> duration = end - start;

    // Exibe o tempo de execução
    std::cout << "O código levou " << duration.count() << " milissegundos para rodar." << std::endl;

    return 0;
}