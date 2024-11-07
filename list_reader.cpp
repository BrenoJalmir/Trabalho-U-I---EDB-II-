#include <fstream>
#include <limits>
#include <iostream>
#include <string>

// Pula para uma determinada linha do arquivo
std::string GotoLine(std::ifstream &file, unsigned int n_linha) {

    file.seekg(std::ios::beg);
    for(unsigned int i = 0; i < n_linha - 1; i++){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    std::string linha;
    if (std::getline(file, linha))
        return linha;
    
    return "ERROR: Invalid line";
}

// Lê um número aleatório a patir de lista.txt
std::string retornarNumero(int n_linha, std::string fileName) {

    std::string numero;
    std::ifstream file;

    file.open(fileName, std::ios::in);

    if (file.is_open()) {
        numero = GotoLine(file, n_linha);
    }
    else {
        return "ERROR: Could not open file";
    }

    file.close();

    return numero;
}