// Autores: Maycon Santos e Pedro Henrique
// Maquina utilizada: Ubuntu 14.04 
// Comando Utilizado para compilar: g++ T3-PP.cpp -o executavel-T3 -pthread -std=c++11
// Comando para executar depos de compilar: ./executavel-T3

#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

sem_t semSo, semSu, semMu, semDi;

void soma( int a, int b, int n ) {
  while(n > 0) {
    sem_wait(&semSo);
    srand(clock());

    int soma = a + b, tempo = (1 + rand() % 10);
    cout << "\nEu sou a Thread SOMA (" << soma << ") e vou dormir por " << tempo << " segundos!\n"; 
    
    this_thread::sleep_for (chrono::seconds(tempo));;
    
    cout << "SOMA (" << soma << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semSu);
    n--;
  }
}

void subtracao( int a, int b, int n ) {
  while(n > 0) {
    sem_wait(&semSu);
    srand(clock());

    int subtracao = a - b, tempo = (1 + rand() % 10);
    cout << "Eu sou a Thread SUBTRAÇÃO (" << subtracao << ") e vou dormir por " << tempo << " segundos!\n";
    
    this_thread::sleep_for (chrono::seconds(tempo));;
    
    cout << "SUBTRAÇÃO (" << subtracao << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semMu);
    n--;
  }
}

void multiplicacao( int a, int b, int n ) {
  while(n > 0) {
    sem_wait(&semMu);
    srand(clock());

    int multiplicacao = a * b, tempo = (1 + rand() % 10);
    cout << "Eu sou a Thread MULTIPLICAÇÃO (" << multiplicacao << ") e vou dormir por " << tempo << " segundos!\n";
  
    this_thread::sleep_for (chrono::seconds(tempo));;
    
    cout << "MULTIPLICAÇÃO (" << multiplicacao << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semDi);
    n--;
  }
}

void divisao( int a, int b, int n ) {
  while(n > 0) {
    sem_wait(&semDi);
    srand(clock());

    int divisao = a / b, tempo = (1 + rand() % 10);
    cout << "Eu sou a Thread DIVISÃO (" << divisao << ") e vou dormir por " << tempo << " segundos!\n";
    
    this_thread::sleep_for (chrono::seconds(tempo));;
    
    cout << "DIVISÃO (" << divisao << "). Já se passaram " << tempo << " segundos, então terminei!\n\n"; 
    sem_post(&semSo);
    n--;
  }
}

int main() {
  cout << "\n";
  int a, b, n;

  cout << "Informe um valor inteiro: ";
  cin >> a;

  cout << "informe outro valor inteiro: ";
  cin >> b;
 
  cout << "Informe a quantidade de vez do loop: ";
  cin >> n;

  if( n <= 0) {
    n = 1;
  }

  sem_init(&semSo,0,1);
  sem_init(&semSu,0,0);
  sem_init(&semMu,0,0);
  sem_init(&semDi,0,0);


  thread So(soma, a , b, n), 
         Su(subtracao, a, b, n),
         Mu(multiplicacao, a, b, n), 
         Di(divisao, a, b, n);
  
  So.join();
  Su.join();
  Mu.join();
  Di.join();

  return 0;
}