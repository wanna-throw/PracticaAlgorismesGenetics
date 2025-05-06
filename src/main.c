#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define NUM_GENS 30
#define N 100
#define K 10
#define PROBABILITAT 5

void init_poblacion(int *taula){

    for (int i = 0; i < N; i++){
        for (int j = 0 ; j < NUM_GENS; j++){
            
            /*En cada indice se imprime 1 o 0 de forma aleatoria*/
             taula[i * NUM_GENS + j] = rand() % 2;

            }
        }
}

//getters

int getIntParam(int param){
    bool llegit;
    llegit = scanf("%d", &param);
    if(llegit == false){
        param = NUM_GENS;
    }
    return param;
}

float getFloatParam(float param){
    bool llegit;
    llegit = scanf("%f", &param);
    if(llegit == false){
        param = NUM_GENS;
    }
    return param;
}


void insercioParam(int nGene, int nCromo, float probMut, int kParam){
    
    printf("\nInserta el nombre de Generacions que vulguis computar: (Default:100)\n");
    nGene = getIntParam(nGene);
    printf("\nEl nombre de Generacions es: %d", nGene);

    printf("\nInserta el nombre de Cromosomes que vulguis computar: (Default:40)\n");
    nCromo = getIntParam(nCromo);
    printf("\nEl nombre de Cromosomes es: %d", nCromo);

    printf("\nInserta la probabilitat de mutacio que vulguis computar: (Default:0.05)\n");
    probMut = getFloatParam(probMut);
    printf("\nEl nombre de probabilitat de mutacio es: %f", probMut);

    printf("\nInserta el nombre del parametre K que vulguis computar: (Default:5)\n");
    kParam = getIntParam(kParam);
    printf("\nEl nombre de K es: %d", kParam);
}


void mutar(int *cromosoma, int i){

    int mutacio;

    for(int j = 0; j < NUM_GENS; j++){

        mutacio = rand() % 10001;
        printf("%d ", mutacio);

        /*Probabilidad de 0,05 de mutacion*/
        if (mutacio >= 1 && mutacio <= PROBABILITAT){

            /*Si es el gen es 0 pasa a 1 */
            if(cromosoma[i * NUM_GENS + j] == 0){
                cromosoma[i * NUM_GENS + j] = 1;
            }
            /*Si es el gen es 1 pasa a 0 */
            else {
                cromosoma[i * NUM_GENS + j] = 0;
            }
        }
    }
}

void seleccionar_padres(const int *poblacion, const int *fitness, int *seleccionados) {
    for (int i = 0; i < N; i++) {

        int mejor = rand() % N;

        for (int t = 1; t < K; t++) {
            int candidato = rand() % N;
            if (fitness[candidato] < fitness[mejor]) {
                mejor = candidato;
            }
        }

        memcpy(&seleccionados[i * NUM_GENS],&poblacion[mejor   * NUM_GENS],NUM_GENS * sizeof(int));
    }
}

void evaluaFormula(int *poblacion){
    
}

void libMem(int *poblacio, int *fitness, int *seleccionados){
    
    for(int i = 0; i < sizeof(poblacio); i++){
        free(poblacio[i]);
    }
    free(poblacio);
    for(int i = 0; i < sizeof(fitness); i++){
        free(fitness[i]);
    }
    free(fitness);
    for(int i = 0; i < sizeof(seleccionados); i++){
        free(seleccionados[i]);
    }
    free(seleccionados);
}



void imprimirContra(){

}

int main(){
    
    //variables
    int nGeneracions;
    int nCromosomes;
    float probMutacio;
    int kParam;

    insercioParam(nGeneracions, nCromosomes, probMutacio, kParam);

    srand(time(NULL));
    //creo que esta mal declarado el malloc asi, lo correcto seria "= malloc(NUM_GENS *sizeof(int))"
    int *poblacion = malloc(N * NUM_GENS * sizeof *poblacion);
    int *fitness = malloc(N * NUM_GENS * sizeof *fitness);
    int *seleccionados = malloc(N * NUM_GENS * sizeof *seleccionados);
    init_poblacion(poblacion);

    if (!poblacion || !fitness || !seleccionados) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    mutar(poblacion, 0);
    seleccionar_padres(poblacion, fitness, seleccionados);
    evaluaFormula(poblacion);


    imprimirContra();
    libMem(poblacion, fitness, seleccionados);
    return 0;
}
