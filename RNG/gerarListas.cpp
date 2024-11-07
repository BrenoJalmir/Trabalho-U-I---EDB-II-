#include "list_RNG.hpp"
#include <iostream>

int main() {

    std::cout << "Qual o tamanho da lista?" <<  std::endl;
    std::cout << "[1] 100\n[2] 1.000\n[3] 10.000" << std::endl;
    int opt = 0;
    std::cin >> opt;

    switch(opt) {
        case 1: listGenerator(100); break;
        case 2: listGenerator(1000); break;
        case 3: listGenerator(10000); break;
        default: std::cout << "Opcao invalida!" << std::endl; break;
    }

    return 0;
}