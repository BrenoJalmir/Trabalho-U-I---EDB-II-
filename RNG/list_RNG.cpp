#include "list_RNG.hpp"
#include <iostream>
#include <ctime>
#include <fstream>

// Gera a lista aleatória
// Tem como parâmetro o tamanho desejado para a lista
// Retorna o nome da lista
std::string listGenerator(int size) {
    srand(time(NULL));
    std::ofstream list;
    std::string fileName = "lista_" + std::to_string(size);

    list.open(fileName, std::ios::out);
    if (list.is_open()) {
        for (int i = 0; i < size; i++) {
            list << rand() % 1001;
            if (i < size - 1)
                list << std::endl;
        }
    }

    list.close();

    return fileName;
}

// Copia o conteúdo da lista para um vetor de mesmo tamanho
// Tem como parâmetros uma referência ao vetor, o nome do arquivo e o número de linhas
// Retorna 0 em caso de sucesso e 1 caso falhe
int listToVector(int* &vector, std::string fileName, int size) {
    std::ifstream list;
    list.open(fileName, std::ios::in);

    if (!list.is_open())
        return 1;

    for (int i = 0; i < size; i++)
        list >> vector[i];

    list.close();

    return 0;
}

// Copia o conteúdo de um vetor para uma arquivo txt
// Tem como parâmetro uma referência ao vetor
// Retorna 0 em caso de sucesso e 1 caso falhe
int vectorToList(int* &vector, int size) {
    std::ofstream list;
    list.open("output", std::ios::out);

    if (!list.is_open())
        return 1;

    for (int i = 0; i < size; i++) {
        list << vector[i];
        if (i < size - 1)
            list << std::endl;
    }

    list.close();

    return 0;
}

// Retorna o número de linhas da lista
// Tem como parâmetro o nome do arquivo
// Retorna o número de linhas ou 0 caso falhe
int getFileSize(std::ifstream &file) {
    std::string line;
    int n_lines = 0;
    
    if (!file.is_open())
        return 0;

    while (std::getline(file, line))
        n_lines++;

    return n_lines;
}