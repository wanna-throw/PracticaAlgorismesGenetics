#include "aux_funcs.h"
#include "ga.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 10
#define PROBABILITAT      0.05


int main(){
    //test de insercioParam()
    int nGeneracions, nCromosomes, kParametre;
    float probMutacio;

    int *w = &nGeneracions;
    int *x = &nCromosomes;
    int *y = &kParametre;
    float *z = &probMutacio;

    insercioParam(w, x, z, y);

     //test de evaluaFormula()
    int **poblacion = malloc(nCromosomes * sizeof(int*));
    int *fitness    = malloc(nCromosomes * sizeof *fitness);
    int **seleccionados = malloc(nCromosomes * sizeof(int*));
    int **poblacion_nueva = malloc(nCromosomes * sizeof(int*));

    if (!poblacion || !fitness || !seleccionados || !poblacion_nueva) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nCromosomes; i++) {
        poblacion[i]        = malloc(NUM_GENS * sizeof(int));
        seleccionados[i]    = malloc(NUM_GENS * sizeof(int));
        poblacion_nueva[i]  = malloc(NUM_GENS * sizeof(int));
        
        if (!poblacion[i] || !seleccionados[i] || !poblacion_nueva[i]) {
            perror("malloc fila");
            exit(EXIT_FAILURE);
        }
    }
    srand(time(NULL));
    init_poblacion(poblacion, nCromosomes);
    evaluaFormula(poblacion, fitness, nCromosomes);
    
    printf("\nFitness de cromosomes es: ");
    for(int i = 0; i < CROMOSOMES; i++){
        printf("%d,", fitness[i]);
    }

    //test one point crossover
    


    return 0;
}
