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


void evaluaFormula(int *poblacio){


}

void libMem(int *vla){
    free(*vla);
}

void insercioParam(int nGene, int nCromo, float probMut, int kParam){

    printf("Inserta el nombre de Generacions que vulguis computar: (Default:100)\n");
    scanf("%d", &nGene);
    printf("Inserta el nombre de Cromosomes que vulguis computar: (Default:40)\n");
    scanf("%d", &nCromo);
    printf("Inserta la probabilitat de mutacio que vulguis computar: (Default:0.05)\n");
    scanf("%f", &probMut);
    printf("Inserta el nombre del parametre K que vulguis computar: (Default:5)\n");
    scanf("%d", &kParam);
}

int main(){
    
    //variables
    int nGeneracions;
    int nCromosomes;
    float probMutacio;
    int kParam;

    insercioParam(nGeneracions, nCromosomes, probMutacio, kParam);

    srand(time(NULL));
    int *poblacion = malloc(N * NUM_GENS * sizeof *poblacion);
    init_poblacion(poblacion);

    if (!poblacion) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    


    evaluaFormula(poblacion);
    libMem(poblacion);

    free(poblacion);
    return 0;
}


