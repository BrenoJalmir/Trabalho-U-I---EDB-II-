#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream file("./lists/idades_1000.txt");  // Cria o arquivo "numeros.txt"
    if (!file.is_open()) {
        std::cerr << "Erro: Não foi possível criar o arquivo." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Inicializa o gerador de números aleatórios

    for (int i = 0; i < 1000; ++i) {
        int numero = std::rand() % 101;  // Gera um número aleatório entre 0 e 100
        file << numero << (i != 999 ? "\n" : "");     // Escreve o número no arquivo em uma nova linha
    }

    file.close();
    std::cout << "Arquivo 'idades_100.txt' gerado com sucesso!" << std::endl;
    return 0;
}
