#include <iostream>
#include <vector>
#include<algorithm>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;


bool idadeRep2(vector<int> Idade){
sort(Idade.begin(),Idade.end());
return Idade[0]==Idade[1];
}


int main() {
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> idades;
    std::ifstream file("./lists/idades_10000.txt");

    std::string line;
    while (std::getline(file, line)) {
        idades.push_back(std::stoi(line));
    }

    if (idadeRep2(idades)) {
        cout << "There are repeated minimum ages." << endl;
    } else {
        cout << "No repeated minimum ages." << endl;
    }

    // Captura o tempo de término
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::duration<double, std::micro> duration = end - start;

    // Exibe o tempo de execução
    std::cout << "O código levou " << duration.count() << " microssegundos para rodar." << std::endl;

    return 0;
}
