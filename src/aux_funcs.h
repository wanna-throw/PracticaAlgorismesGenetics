#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

#include <stdbool.h>

//getters
int  getNumGenera(int nGenera);
int  getNumCromo(int nCromo);
/***
 * 
 */
float getNumProb(float numProb);
int  getNumK(int kParam);
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

int  mutar(int gen, float probabilidad);

#endif /* AUX_FUNCS_H */
