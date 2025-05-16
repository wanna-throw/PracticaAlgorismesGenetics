#include "ga.h"
#include "aux_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

void init_poblacion(int **taula, int num_cromosomes) {
    for (int i = 0; i < num_cromosomes; i++) {
        for (int j = 0; j < NUM_GENS; j++) {
            /* En cada índice se imprime 1 o 0 de forma aleatoria */
            taula[i][j] = rand() % 2;
        }
    }
}

void evaluaFormula(int **poblacion, int *fitness, int num_cromosomes){
    for(int i = 0; i < num_cromosomes; i++){
        int suma = 0;
        for (int j = 0; j < NUM_GENS; j++) {
            suma += suma + poblacion[i][j] * (j*j) - 1977;
        }
        fitness[i] = abs(suma);
    }
}

void seleccionar_padres(int **poblacion, const int *fitness, int **seleccionados, int nCromosomes, int k) {
    for (int i = 0; i < nCromosomes; i++) {
        int mejor = rand() % nCromosomes;
        for (int t = 1; t < k; t++) {
            int cand = rand() % nCromosomes;
            if (fitness[cand] < fitness[mejor])
                mejor = cand;
        }
        /* Copiamos la fila mejor al i-ésimo seleccionado */
        memcpy(seleccionados[i], poblacion[mejor], NUM_GENS * sizeof(int));
    }
}

void onePointCrossover(int **taula, int n_cromosomes){
    int crossoverPoint;
    int aux;
    for (int i = 0; i < n_cromosomes - 1; i = i + 2){
        crossoverPoint = rand() % NUM_GENS;
        for (int j = 0; j < crossoverPoint; j++){
            aux = taula[i][j];
            taula[i][j] = taula[i + 1][j];
            taula[i + 1][j] = aux;
        }
    }
}

void faseSupervivencia(int **poblacion_nueva, int **poblacion, int n_cromosomes){
    for(int i = 0; i < n_cromosomes; i++){
        memcpy(poblacion[i], poblacion_nueva[i], NUM_GENS * sizeof(int));
    }
}

void imprimir_estado(int gen,int mejor_error,int mejor_index,int *cromosoma) {
    printf("Generacion %d | Mejor error: %d | Indice: %d | Genes: ", gen + 1, mejor_error, mejor_index);
    for (int j = 0; j < NUM_GENS; j++) {
        printf("%d", cromosoma[j]);
    }
    printf("\n");
}

int *ejecutar_GA(int **poblacion, int *fitness, int **seleccionados, int **poblacion_nueva, int n_generaciones, int n_cromosomes, float prob_mut, int kParam)
{
    int  mejor_error_global = INT_MAX;
    int  gen_mejor_global   = -1;
    int *mejor_cromosoma    = malloc(NUM_GENS * sizeof *mejor_cromosoma);
    if (!mejor_cromosoma) {
        perror("malloc mejor_cromosoma");
        exit(EXIT_FAILURE);
    }

    for (int gen = 0; gen < n_generaciones; gen++) {
        /*Evaluar fitness */
        evaluaFormula(poblacion, fitness, n_cromosomes);

        /*Hallar el mejor de la generación actual */
        int mejor_error = INT_MAX;
        int mejor_index = 0;
        for (int i = 0; i < n_cromosomes; i++) {
            if (fitness[i] < mejor_error) {
                mejor_error = fitness[i];
                mejor_index = i;
            }
        }

        imprimir_estado(gen, mejor_error, mejor_index, poblacion[mejor_index]);

        /*Actualizar global si corresponde */
        if (mejor_error < mejor_error_global) {
            mejor_error_global = mejor_error;
            gen_mejor_global = gen;
            /* Copia completa de la fila */
            memcpy(mejor_cromosoma, poblacion[mejor_index], NUM_GENS * sizeof *mejor_cromosoma);
        }

        /*Selección por torneo */
        seleccionar_padres(poblacion, fitness, seleccionados, n_cromosomes, kParam);

        /*Cruce (implementado por Dario) */
        onePointCrossover(seleccionados, n_cromosomes);

    /*Mutación gen a gen: mutamos los seleccionados tras el crossover*/
    for (int i = 0; i < n_cromosomes; i++) {
        for (int j = 0; j < NUM_GENS; j++) {
            poblacion_nueva[i][j] =
            mutar(seleccionados[i][j], prob_mut);
        }
    }

        /*Supervivencia*/
        faseSupervivencia(poblacion_nueva, poblacion, n_cromosomes);

        /*Reemplazo: swap de punteros */
        int **tmp = poblacion;
        poblacion = poblacion_nueva;
        poblacion_nueva = tmp;
    }

    /*Imprimir generación de la mejor solución */
    printf("\nMejor solucion encontrada en generacion %d\n\n", gen_mejor_global + 1);

    /*Evaluar e imprimir fitness final */
    evaluaFormula(poblacion, fitness, n_cromosomes);
    printf("Fitness de cada cromosoma:\n");
    for (int i = 0; i < n_cromosomes; i++) {
        printf("[%d] = %d\n", i+1, fitness[i]);
    }
    printf("\n");

    /*Devolver el mejor cromosoma encontrado */
    return mejor_cromosoma;
}

void libMemTaula2D(int **taula){
    for (int i = 0; i < NUM_GENS; i++){
        free(taula[i]);
    }
    free(taula);
}

void libMemTaula1D(int *taula){
    /* fitness es 1D, solo un free */
    free(taula);
}

void libMem(int **poblacio, int *fitness, int **seleccionados, int **poblacion_nueva, int *mejor){
    //libera memoria de la taula y el punter poblacio
    libMemTaula2D(poblacio);
    //libera memoria de la taula y el punter fitness
    libMemTaula1D(fitness);
    //libera memoria de la taula y el punter seleccionados
    libMemTaula2D(seleccionados);
    //libera memoria de la taula y el punter poblacion_nueva
    libMemTaula2D(poblacion_nueva);
    //libera memoria de la taula y el punter mejor
    libMemTaula1D(mejor);
}

void imprimirContra(int *taula){
    printf("\nLa contrasenya es: ");
    for(int i = 0; i < NUM_GENS; i++){
        printf("%d", taula[i]);
    }
}
