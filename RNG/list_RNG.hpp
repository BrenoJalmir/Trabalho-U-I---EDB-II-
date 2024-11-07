#ifndef LIST_RNG_HPP
#define LIST_RNG_HPP

#include <string>

// Gera a lista aleatória
// Tem como parâmetro o tamanho desejado para a lista
// Retorna o nome da lista
std::string listGenerator(int size);
// Copia o conteúdo da lista para um vetor de mesmo tamanho
// Tem como parâmetros o vetor, o nome do arquivo e o número de linhas
// Retorna 0 em caso de sucesso e 1 caso falhe
int listToVector(int* vector, std::string fileName, int size);
// Copia o conteúdo de um vetor para uma arquivo txt
// Tem como parâmetros o vetor e o tamanho dele
// Retorna 0 em caso de sucesso e 1 caso falhe
int vectorToList(int* vector, int size);
// Retorna o número de linhas da lista
// Tem como parâmetro uma referência ao arquivo
// Retorna o número de linhas ou 0 caso falhe
int getFileSize(std::ifstream &file);

#endif