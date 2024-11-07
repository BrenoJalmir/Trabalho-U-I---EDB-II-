#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

int buscaBinaria(const std::vector<int>& A, int x) {
    int esq = 0; // Índice inicial
    int dir = A.size(); // Tamanho do vetor

    while (esq < dir) {
        int m = (esq + dir) / 2; // Ponto médio
        if (x > A[m]) {
            esq = m + 1; // Ajusta a posição da esquerda
        } else {
            dir = m; // Ajusta a posição da direita
        }
    }

    if (A[esq] == x) {
        return esq; // Retorna o índice se encontrar o valor
    }

    return -1; // Caso não encontre
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
