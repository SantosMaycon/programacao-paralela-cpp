// Autores: Maycon Santos e Pedro Henrique
// Maquina utilizada: Ubuntu 14.04 
// Comando Utilizado para compilar: g++ T1-PP.cpp -o executavel-T1 -pthread -std=c++11
// Comando para executar depos de compilar: ./executavel-T1

#include <iostream>
#include <thread>

using namespace std;

void college() {
  cout << "Instituto Federal Fluminense\n";
}

void subjects() {
  cout << "Programação Paralela\n";
}

int main() {
  thread first(subjects), second(college);
  
  first.join();
  second.join();
  
  return 0;
}