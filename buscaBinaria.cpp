#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

int buscaBinariaRecursiva(const vector<int>& A, int esq, int dir, int x) {

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

int buscaBinaria(const vector<int>& A, int x) {
    return buscaBinariaRecursiva(A, 0, A.size() - 1, x);
}

int main() {
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> idades;
    std::ifstream file("./lists/idades_10000_ordenadas.txt");

    std::string line;
    while (std::getline(file, line)) {
        idades.push_back(std::stoi(line));
    }

    int resultado = buscaBinaria(idades, 30);
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
    std::cout << "O código levou " << duration.count() << " microssegundos para rodar." << std::endl;

    return 0;
}
