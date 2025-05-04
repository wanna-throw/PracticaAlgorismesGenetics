#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GENS 30
#define N 100

void init_poblacion(int taula[N][NUM_GENS]){

    srand(time(NULL));
    for (int i = 0; i < N; i++){
        for (int j = 0 ; j < NUM_GENS; j++){

            taula[i][j]= rand() % 2;

            }
        }


}


void evaluaFormula(int poblacio[N][NUM_GENS]){

}

void libMem(){

}

int main(){
    
    int poblacio[N][NUM_GENS];
    init_poblacion(poblacio);
    evaluaFormula(poblacio);
    libMem();

    return 0;
}