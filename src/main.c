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
    
    //variables
    int nGeneracions;
    int nCromosomes;
    float probMutacio;
    int kParam;

    insercioParam(&nGeneracions, &nCromosomes, &probMutacio, &kParam);

    // taules malloc
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

    int *mejor = ejecutar_GA(poblacion, fitness, seleccionados, poblacion_nueva, nGeneracions, nCromosomes, probMutacio, kParam);

    for (int j = 0; j < NUM_GENS; j++){
        printf("%d", mejor[j]);
    }

    evaluaFormula(poblacion, fitness, nCromosomes); 
    imprimirContra(mejor);

    libMem(poblacion, fitness, seleccionados, poblacion_nueva);
    free(mejor);

    return 0;
}
