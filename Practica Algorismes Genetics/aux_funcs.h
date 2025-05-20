#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

#include <stdbool.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 5
#define PROBABILITAT      0.05

//getters
int  getNumGenera();
int  getNumCromo();
float getNumProb();
int  getNumK();

/***
 * @param param
 * @brief funcio que comprova si el int esta dins dels valors correctes
 * @return correcte
 */
bool esCorrecteInt(int param);
/***
 * @param param
 * @brief funcio que comprova si el float esta dins dels valors correctes
 * @return correcte
 */
bool esCorrecteFloat(float param);
/***
 * @param nGene
 * @param nCromo
 * @param probMut
 * @param kParam
 * @brief Es una funcio que crida altres funcions inicialitza els parametres amb valors introduits 
 *        per l'usuari. En cas d'una insercio invalida li torna a demanar el valor i en cas de 
 *        presionar "enter" s'aplica el valor que hi ha per default.
 */
void insercioParam(int *nGene, int *nCromo, float *probMut, int *kParam);

/**
 * @param gen
 * @param probabilidad
 * @brief Aplica mutación a un gen con probabilidad dada.
 * @return gen mutado (0→1 o 1→0) o el mismo gen si no muta.
 */
int  mutar(int gen, float probabilidad);

#endif /* AUX_FUNCS_H */
