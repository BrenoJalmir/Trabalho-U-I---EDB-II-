#include <iostream> 
#include <vector>
#include <algorithm>

bool idadeRep(std::vector<int> Idade){
  int tam = Idade.size();
  int menor = 200;
  int menor_index = 0;
  for (int i = 0; i < tam; i++){
    if (Idade[i] < menor){
      menor = Idade[i];
      menor_index = i;
    }
  }
  for (int i = 0; i < tam; i++){
    if(Idade[i] == menor && i != menor_index){
      return true;
    }
  }
  return false;
}

bool idadeRep2(std::vector<int> Idade){
  sort(Idade.begin(), Idade.end());
  return Idade[0] == Idade[1];
}

int main(){

  

  return 0;
}