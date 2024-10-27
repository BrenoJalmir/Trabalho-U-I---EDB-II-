#include <iostream>
#include <vector>
#include<algorithm>
#include <random>
#include <chrono>

using namespace std;

//Gera números aleatórios e 1 a 100
int generateNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    return dist(gen);
}



bool idadeRep2(vector<int> Idade){
sort(Idade.begin(),Idade.end());
return Idade[0]==Idade[1];
}


int main() {
    // Captura o tempo de início
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> idades;

    for(int i=0; i<1000000; i++){
        idades.push_back(generateNumber());
    }

    if (idadeRep2(idades)) {
        cout << "There are repeated minimum ages." << endl;
    } else {
        cout << "No repeated minimum ages." << endl;
    }

    // Captura o tempo de término
    auto end = std::chrono::high_resolution_clock::now();

    // Calcula a duração em milissegundos
    std::chrono::duration<double, std::milli> duration = end - start;

    // Exibe o tempo de execução
    std::cout << "O código levou " << duration.count() << " milissegundos para rodar." << std::endl;

    return 0;
}
