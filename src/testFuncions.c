#include "aux_funcs.h"
#include "ga.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 5
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

     //test de evaluaFormula() y init_poblacion()
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
    
    printf("\nTest fitness\nFitness de cromosomes es: ");
    for (int i = 0; i < nCromosomes; i++) {
        printf("%u%s", fitness[i], (i+1==nCromosomes) ? "\n" : ",");
    }

    //Test seleccionar_padres()
    seleccionar_padres(poblacion, fitness, seleccionados, nCromosomes, kParametre);
    printf("\nTest seleccionar_padres()\nPadres seleccionados:");
    for (int i = 0; i < nCromosomes; i++) {
        printf("\nPadre %2d: ", i+1);
        for (int j = 0; j < NUM_GENS; j++) {
            printf("%d", seleccionados[i][j]);
        }
    }
    printf("\n\n");


    //test one point crossover
    


 //Test ejecutar_GA() {imprimir_estado(), onePointCrossover(), mutarCromosomas(), seleccionar_padres(), evaluaFormula()}
    int *mejor = ejecutar_GA(poblacion, fitness, seleccionados, poblacion_nueva, nGeneracions, nCromosomes, probMutacio, kParametre);
    printf("Mejor cromosoma final:\n");
    for (int j = 0; j < NUM_GENS; j++) {
        printf("%d", mejor[j]);
    }
    printf("\n\n");

    //Liberar memoria mejor
    free(mejor);

        //Test mutar()
    printf("Test mutar():\n");
    for (int g = 0; g < 5; g++) {
        int original = rand() % 2;
        int m = mutar(original, probMutacio);
        printf("  gen=%d -> mutado=%d\n", original, m);
    }
    printf("\n");


    return 0;
}
