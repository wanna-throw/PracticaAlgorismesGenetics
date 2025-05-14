#ifndef GA_H
#define GA_H

#include <limits.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 10
#define PROBABILITAT      0.05

void init_poblacion(int **taula, int num_cromosomes);

//a revisar
void evaluaFormula(int **poblacion, int *fitness, int num_cromosomes);

void seleccionar_padres(int **poblacion, const int *fitness, int **seleccionados, int nCromosomes, int k);

void onePointCrossover(int **taula, int n_cromosomes);

void faseSupervivencia(int **poblacion_nueva, int **poblacion, int n_cromosomes);

void imprimir_estado(int gen, int mejor_error, int mejor_index, int *cromosoma);

int *ejecutar_GA(int **poblacion, int *fitness, int **seleccionados, int **poblacion_nueva, int n_generaciones, int n_cromosomes, float prob_mut, int kParam);

void libMemTaula2D(int **taula);
void libMemTaula1D(int *taula);
void libMem(int **poblacio, int *fitness, int **seleccionados, int **poblacion_nueva);

void imprimirContra(int *taula);

#endif /* GA_H */ 
