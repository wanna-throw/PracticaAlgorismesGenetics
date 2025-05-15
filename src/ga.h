#ifndef GA_H
#define GA_H

#include <limits.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 10
#define PROBABILITAT      0.05

/**
 * @param taula         Matriz de población [nCromosomes][NUM_GENS]
 * @param num_cromosomes Número de cromosomas (filas) de la matriz
 * @brief Inicializa cada gen de cada cromosoma con 0 o 1 aleatorio.
 */
void init_poblacion(int **taula, int num_cromosomes);

void evaluaFormula(int **poblacion, int *fitness, int num_cromosomes);

/**
 * @param poblacion     Matriz de población [nCromosomes][NUM_GENS]
 * @param fitness       Vector de fitness de tamaño nCromosomes
 * @param seleccionados Matriz donde copiar los padres seleccionados
 * @param nCromosomes   Número de cromosomas (tamaño población)
 * @param k             Tamaño del torneo
 * @brief Selección por torneo: para cada plaza de padre, elige k candidatos al azar
 *        y copia el de menor fitness al array seleccionados.
 */
void seleccionar_padres(int **poblacion, const int *fitness, int **seleccionados, int nCromosomes, int k);

void onePointCrossover(int **taula, int n_cromosomes);

void faseSupervivencia(int **poblacion_nueva, int **poblacion, int n_cromosomes);

void imprimir_estado(int gen, int mejor_error, int mejor_index, int *cromosoma);

/**
 * @param poblacion         Matriz de población [nCromosomes][NUM_GENS]
 * @param fitness           Vector de fitness [nCromosomes]
 * @param seleccionados     Matriz temporal de padres [nCromosomes][NUM_GENS]
 * @param poblacion_nueva   Matriz donde escribir la nueva generación
 * @param n_generaciones    Número de iteraciones (generaciones) a ejecutar
 * @param n_cromosomes      Tamaño de la población
 * @param prob_mut          Probabilidad de mutación (0.0–1.0)
 * @param kParam            Tamaño del torneo para selección
 * @brief Ejecuta el bucle principal del algoritmo genético: evaluación,
 *        selección, cruce, mutación, supervivencia y swap de poblaciones.
 * @return Puntero al array de NUM_GENS bits del mejor cromosoma global.
 */
int *ejecutar_GA(int **poblacion, int *fitness, int **seleccionados, int **poblacion_nueva, int n_generaciones, int n_cromosomes, float prob_mut, int kParam);

void libMemTaula2D(int **taula);
void libMemTaula1D(int *taula);
void libMem(int **poblacio, int *fitness, int **seleccionados, int **poblacion_nuevam, int *mejor);

void imprimirContra(int *taula);

#endif /* GA_H */ 
