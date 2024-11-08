### 2.0. Ambiente computacional
* **Placa mãe**: AMD b450m gaming
* **Processador**: Ryzen 7 5700X3D
* **Placa de vídeo**: Geforce RTX 3050
* **Memória ram**:2x8GB DDR4 3200hz
* **Sistema operacional**: Windows 10 pro


### 2.1. Função interativa
#### idadeRep
<details>
  <summary>Clique aqui para ver o código!</summary>
  
```c++
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;


bool idadeRep(const vector<int>& Idade){
    int tam = Idade.size();
    int menor = 200;
    for(int i = 0; i<tam; i++){
        if (Idade[i]<menor){
        menor = Idade[i];
        }
    }

    for(int i = 0; i<tam; i++){
        if (Idade[i]==menor){
        return true;
        }
    }

    return false;
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

    if (idadeRep(idades)) {
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

```
</details>

#### idadeRep2
<details>
  <summary>Clique aqui para ver o código!</summary>
  
```c++
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

```
</details>


#### Comparação

* Tabela:

| Algoritmo | Instância 100    | Instância 1000      | Instância 10000     |
|-----------|------------------|---------------------|---------------------|
| idadeRep  | 0 microssegundos | 0 microssegundos    | 4001 microssegundos |
| idadeRep2 | 0 microssegundos | 1000 microssegundos | 6001 microssegundos |


* Gráfico:

![Gráfico de comparação interativa](https://i.ibb.co/8bFbjqR/idade-Rep-Graph.png)

Após analisar o gráfico e a tabela, podemos inferir que, para instâncias pequenas, os dois algoritmos tem um tempo de processamento similar. Em alguns casos, o tempo de processamento foi de "0" microssegundos, o que é uma limitação do contador devido ao hardware que foi utilizado.

Para Instâncias de tamanho 1000, já podermos ver uma diferença maior. Baseando-se no gráfico, podemos ver que `idadeRep2` cresce mais rapidamente que `idadeRep`, o que fica mais claro na instância de tamanho 10000.

### 2.2. Função recursiva

#### buscaBinaria
<details>
  <summary>Clique aqui para ver o código!</summary>

```c++
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

```
</details>

#### bBinRec
<details>
  <summary>Clique aqui para ver o código!</summary>

```c++
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
```
</details>

#### Comparação

* Tabela:

| Algoritmo    | Instância 100    | Instância 1000   | Instância 10000     |
|--------------|------------------|------------------|---------------------|
| buscaBinaria | 0 microssegundos | 0 microssegundos | 3000 microssegundos |
| bBinRec      | 0 microssegundos | 0 microssegundos | 5000 microssegundos |

* Gráfico: 

![Gráfico de comparação recursiva](https://i.ibb.co/sqdCKWy/recursiva-Graph.png)

Para coletar os dados de tempo de execução dos programas, usamos o número 30 como o número a ser buscado pelas duas funções.

Essas duas funções foram um pouco mais difíceis de comparar, pois a única diferença perceptível é a partir de vetores com mais de 10000 elementos. Para vetores menores, no ambiente computacional testado, as duas funções não fazem muita diferença. É perceptível, no entanto, que a função `buscaBinaria` cresce mais devagar que `bBinRec`, principalmente em valores mais altos (como em vetores de tamanho 10 mil), onde a segunda função leva 66% a mais de tempo para ser executada.