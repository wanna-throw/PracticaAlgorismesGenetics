#include "ga.h"   
#include "aux_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getNumGenera(){
    int nGenera;
    scanf("%d", &nGenera);
    if(nGenera == 0){
        nGenera = NUM_GENERACIONS;
    }
    return nGenera;
}

int getNumCromo(){
    int nCromo;
    scanf("%d", &nCromo);
    if(nCromo == 0){
        nCromo = CROMOSOMES;
    }
    return nCromo;
}

/***
 * 
 */
float getNumProb(){
    float numProb;
    scanf("%f", &numProb);
    if(numProb == 0){
        numProb = PROBABILITAT;
    }
    return numProb;
}

int getNumK(){
    int kParam;
    scanf("%d", &kParam);
    if(kParam == 0){
        kParam = K;
    }
    return kParam; 
}

/***
 * @param param
 * @brief funcio que comprova si el int esta dins dels valors correctes
 * @return correcte
 */
bool esCorrecteInt(int param){
    bool correcte = true;
    if((param < 0) || (param > 9999)){
        correcte = false;
        printf("El parametre ha de ser mes gran que 0 i mes petit que 9999\n");
    }
    return correcte;
}

/***
 * @param param
 * @brief funcio que comprova si el float esta dins dels valors correctes
 * @return correcte
 */
bool esCorrecteFloat(float param){
    bool correcte = true;
    if(param < 0 || param > 1){
        correcte = false;
        printf("El parametre ha de ser mes gran que 0 i mes petit que 1");
    }
    return correcte;
}

/***
 * @param nGene
 * @param nCromo
 * @param probMut
 * @param kParam
 * @brief Es una funcio que crida altres funcions inicialitza els parametres amb valors introduits 
 *        per l'usuari. En cas d'una insercio invalida li torna a demanar el valor i en cas de 
 *        presionar "enter" s'aplica el valor que hi ha per default.
 */
void insercioParam(int *nGene, int *nCromo, float *probMut, int *kParam){
    
    do{
    printf("\nInserta el nombre de Generacions que vulguis computar: (Introdueix 0 per Default:100)\n");
    *nGene = getNumGenera();
    }while(esCorrecteInt(*nGene) == false);
    printf("\nEl nombre de Generacions es: %d", *nGene);
    
    do{
    printf("\nInserta el nombre de Cromosomes que vulguis computar: (Introdueix 0 per Default:40)\n");
    *nCromo = getNumCromo();
    }while(esCorrecteInt(*nCromo) == false);
    printf("\nEl nombre de Cromosomes es: %d", *nCromo);

    do{
    printf("\nInserta la probabilitat de mutacio que vulguis computar: (Introdueix 0 per Default:0.05)\n");
    *probMut = getNumProb();
    }while(esCorrecteFloat(*probMut) == false);
    printf("\nEl nombre de probabilitat de mutacio es: %f", *probMut);

    do{
    printf("\nInserta el nombre del parametre K que vulguis computar: (Introdueix 0 per Default:10)\n");
    *kParam = getNumK();
    }while(esCorrecteInt(*kParam) == false);
    printf("\nEl nombre de K es: %d", *kParam);
}


int mutar(int gen, float probabilidad){

    int mutacio;

        mutacio = rand() % 101;

        /*Probabilidad de 0,05 de mutacion*/
        if (mutacio >= 1 && mutacio <= (int)(probabilidad*100)){

            /*Si el gen es 0 pasa a 1 */
            if(gen == 0){
                gen = 1;
            }
            /*Si el gen es 1 pasa a 0 */
            else {
                gen = 0;
            }
        }

        return gen;
}
