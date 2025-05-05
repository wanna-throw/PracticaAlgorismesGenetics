#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GENS 30
#define N 100
#define K 10

void init_poblacion(int *taula){

    for (int i = 0; i < N; i++){
        for (int j = 0 ; j < NUM_GENS; j++){

             taula[i * NUM_GENS + j] = rand() % 2;

            }
        }
}

void mutar(int *cromosoma, int i){

    int mutacio;

    for(int j = 0; j < NUM_GENS; j++){

        mutacio = rand() % 101;
        printf("%d ", mutacio);
        if (mutacio >= 1 && mutacio <= 5){

            if (cromosoma[i * NUM_GENS + j] == 0){
                cromosoma[i * NUM_GENS + j] = 1;
            }
            else {
                cromosoma[i * NUM_GENS + j] = 0;
            }
        }
    }
}

void seleccionar_padres(int *taula, int *seleccionats){

    

}

void evaluaFormula(int *poblacio){
    
}

void libMem(){
        
}

int main(){
    
    srand(time(NULL));
    int *poblacion = malloc(N * NUM_GENS * sizeof *poblacion);
    int *fitness = malloc(N * NUM_GENS * sizeof *fitness);
    init_poblacion(poblacion);

    if (!poblacion) {
        perror("malloc");
        exit(EXIT_FAILURE);
        }

    mutar(poblacion, 0);
    seleccionar_padres(*poblacion, *fitness);
    libMEM();
    evaluaFormula(poblacion);



    free(poblacion);
    return 0;
}
