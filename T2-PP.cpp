// Autores: Maycon Santos e Pedro Henrique
// Maquina utilizada: Ubuntu 14.04 
// Comando Utilizado para compilar: g++ T2-PP.cpp -o executavel-T2 -pthread -std=c++11
// Comando para executar depos de compilar: ./executavel-T2

#include <iostream>
#include <thread>

using namespace std;

void soma( int a, int b) {
  srand(clock());

  int soma = a + b, tempo = (1 + rand() % 20);
  cout << "Eu sou a Thread SOMA (" << soma << ") e vou dormir por " << tempo << " segundos!\n"; 
  
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread SOMA (" << soma << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

void subtracao( int a, int b) {
  srand(clock());

  int subtracao = a - b, tempo = (1 + rand() % 20);
  cout << "Eu sou a Thread SUBTRAÇÃO (" << subtracao << ") e vou dormir por " << tempo << " segundos!\n";
  
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread SUBTRAÇÃO (" << subtracao << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

void multiplicacao( int a, int b) {
  srand(clock());

  int multiplicacao = a * b, tempo = (1 + rand() % 20);
  cout << "Eu sou a Thread MULTIPLICAÇÃO (" << multiplicacao << ") e vou dormir por " << tempo << " segundos!\n";
 
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread MULTIPLICAÇÃO (" << multiplicacao << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

void divisao( int a, int b) {
  srand(clock());

  int divisao = a / b, tempo = (1 + rand() % 20);
  cout << "Eu sou a Thread DIVISÃO (" << divisao << ") e vou dormir por " << tempo << " segundos!\n";
  
  this_thread::sleep_for (chrono::seconds(tempo));;
  
  cout << "Eu sou a Thread DIVISÃO (" << divisao << "). Já se passaram " << tempo << " segundos, então terminei!\n"; 
}

int main() {
  cout << "\n";
  int a, b;

   cout << "Informe um valor inteiro: ";
   cin >> a;
  
   cout << "informe outro valor inteiro: ";
   cin >> b;
   cout << "\n";

  thread So(soma, a, b), 
         Su(subtracao, a, b), 
         Mu(multiplicacao, a, b), 
         Di(divisao, a, b);
  
  So.join();
  Su.join();
  Mu.join();
  Di.join();

  cout << "\n";

  return 0;
}