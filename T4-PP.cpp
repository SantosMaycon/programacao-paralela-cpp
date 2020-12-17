// Autores: Maycon Santos e Pedro Henrique
// Maquina utilizada: Ubuntu 14.04 
// Comando utilizado para compilar: g++ T4-PP.cpp -o executavel-T4 -pthread -std=c++11
// Comando para executar depois de compilar: ./executavel-T4

#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

sem_t semSoma, semCalculo;
int i, j, n = 4;
float soma, A[][4] = {1, 0, 0, 0,0.6, 1, 0, 0, 0.2, -3, 1, 0,1, 1, 1, 1}, X[4], B[] = {1,-7,-26,4};

void somatorio() {
  for (i = 0; i < n; i++) {
    sem_wait(&semSoma);   
    
    soma = 0;
    for (j = 0; j <= i - 1; j++) {
      soma += A[i][j] * X[j];
    }
    
    sem_post(&semCalculo);
  }
}

void calculo() {
  for (int i = 0; i < n; i++) {
    sem_wait(&semCalculo);
    
    X[i] = ( (B[i] - soma) / A[i][i] );

    sem_post(&semSoma);
  }
}

int main() {
  sem_init(&semSoma,0,1);
  sem_init(&semCalculo,0,0);

  thread t_Soma(somatorio), 
         t_Calculo(calculo);

  t_Soma.join();
  t_Calculo.join();

  cout << "\nResutado dos valores de X:\n";
	for(i = 0 ; i < 4 ; i++ ) {
		printf("X[%d]: %f\n", i+1, X[i]);
	}
  cout << "\n";

  return 0;
}
