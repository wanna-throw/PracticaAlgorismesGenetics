#ifndef GA_H
#define GA_H

#include <limits.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 5
#define PROBABILITAT      0.05

/**
 * @param taula         Matriz de población [nCromosomes][NUM_GENS]
 * @param num_cromosomes Número de cromosomas (filas) de la matriz
 * @brief Inicializa cada gen de cada cromosoma con 0 o 1 aleatorio.
 */
void init_poblacion(int **taula, int num_cromosomes);

/***
 * @param poblacion
 * @param fitness
 * @param num_cromosomes
 * @brief Assigna el fitness que te cada cromosoma en referencia a la formula de la contrasenya
 */
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

/***
 * @param taula
 * @param n_cromosomes
 * @brief Funcion que intercambia los valores de 2 en 2 filas hasta una posicion random
 */
void onePointCrossover(int **taula, int n_cromosomes);

/***
 * @param poblacion_nueva
 * @param poblacion
 * @param n_cromosomes
 * @brief funcio que aplica el relleu generacional (copia els cromosomes de la taula de poblacion en la taula de poblacion_nueva)
 */
void faseSupervivencia(int **poblacion_nueva, int **poblacion, int n_cromosomes);

/***
 * @param gen
 * @param mejor_error
 * @param mejor_index
 * @param cromosoma
 * @brief funcio que imprimeix els parametres de cada generacio
 */
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

/**
 * @param taula
 * @brief libera la memoria de les taules de 2 dimensions
 */
void libMemTaula2D(int **taula);

/**
 * @param taula
 * @brief libera la memoria de les taules de 1 dimensio
 */
void libMemTaula1D(int *taula);

/**
 * @param poblacio
 * @param fitness
 * @param seleccionados
 * @param poblacion_nueva
 * @param mejor
 * @brief wrapper que crida les funcions libMemTaula1D() i libMemTaula2D() per les taules introduides
 */
void libMem(int **poblacio, int *fitness, int **seleccionados, int **poblacion_nueva, int *mejor);

/***
 * @param taula
 * @brief funcio que imprimeix per pantalla els valors de la taula introduida
 */
void imprimirContra(int *taula);

#endif /* GA_H */ 
