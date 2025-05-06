#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define NUM_GENS 30
#define N 100
#define K 10
#define PROBABILITAT 5

void init_poblacion(int *taula, int num_generaciones){

    for (int i = 0; i < num_generaciones; i++){
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

void seleccionar_padres(const int *poblacion, const int *fitness, int *seleccionados, int num_generaciones, int param_k) {
    for (int i = 0; i < num_generaciones; i++) {

        int mejor = rand() % num_generaciones;

        for (int t = 1; t < param_k; t++) {
            int candidato = rand() % num_generaciones;
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
    //Bueno al fin y al cabo es lo mismo, pero si quieres te lo pongo como sizeof(int), eso si la N es necesaria aunque debo cambiarla por nCromosomes
    int *poblacion = malloc(nCromosomes * NUM_GENS * sizeof(int));
    int *fitness = malloc(nCromosomes * NUM_GENS * sizeof(int));
    int *seleccionados = malloc(nCromosomes * NUM_GENS * sizeof(int));
    init_poblacion(poblacion, nCromosomes);
    seleccionar_padres(poblacion, fitness, seleccionados, nCromosomes, kParam);
    poblacion[0] = mutar(poblacion[0], probMutacio);

    if (!poblacion || !fitness || !seleccionados) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    evaluaFormula(poblacion);
    imprimirContra();
    libMem(poblacion, fitness, seleccionados);
    return 0;
}