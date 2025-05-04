#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GENS 30
#define N 100

void init_poblacion(int *taula){

    for (int i = 0; i < N; i++){
        for (int j = 0 ; j < NUM_GENS; j++){

             taula[i * NUM_GENS + j] = rand() % 2;

            }
        }
}


void evaluaFormula(poblacio){

}

void libMem(){

}

int main(){
    
    srand(time(NULL));
    int *poblacion = malloc(N * NUM_GENS * sizeof *poblacion);
    init_poblacion(poblacion);

    if (!poblacion) {
        perror("malloc");
        exit(EXIT_FAILURE);
        }

    evaluaFormula(poblacion);
    libMem();


    free(poblacion);
    return 0;
}


