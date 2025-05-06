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

void mutar(int *cromosoma, int i){

    int mutacio;

    for(int j = 0; j < NUM_GENS; j++){

        mutacio = rand() % 10001;
        printf("%d ", mutacio);

        /*Probabilidad de 0,05 de mutacion*/
        if (mutacio >= 1 && mutacio <= PROBABILITAT){

            /*Si el gen es 0 pasa a 1 */
            if(cromosoma[i * NUM_GENS + j] == 0){
                cromosoma[i * NUM_GENS + j] = 1;
            }
            /*Si el gen es 1 pasa a 0 */
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

void insercioParam(int nGene, int nCromo, float probMut, int kParam){
    bool llegit;

    printf("\nInserta el nombre de Generacions que vulguis computar: (Default:100)\n");
    llegit = scanf("%d", &nGene);
    if(llegit == false){
        nGene = NUM_GENS;
    }
    printf("\nEl nombre de Generacions es: %d", nGene);

    printf("\nInserta el nombre de Cromosomes que vulguis computar: (0|Default:40)\n");
    llegit = scanf("%d", &nCromo);
    if(llegit == false){
        nCromo = N;
    }
    printf("\nEl nombre de Cromosomes es: %d", nCromo);

    printf("\nInserta la probabilitat de mutacio que vulguis computar: (0|Default:0.05)\n");
    scanf("%f", &probMut);
    if(probMut == 0){
        probMut = PROBABILITAT;
    }
    printf("\nEl nombre de probabilitat de mutacio es: %d", probMut);

    printf("\nInserta el nombre del parametre K que vulguis computar: (0|Default:5)\n");
    scanf("%d", &kParam);
    if(kParam == 0){
        kParam = K;
    }
    printf("\nEl nombre de K es: %d", kParam);
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
    //Bueno al fin y al cabo es lo mismo, pero si quieres te lo pongo como sizeof(int), eso si la N es necesaria aunque debo cambiarla por nGeneraciones
    int *poblacion = malloc(N * NUM_GENS * sizeof(int));
    int *fitness = malloc(N * NUM_GENS * sizeof(int));
    int *seleccionados = malloc(N * NUM_GENS * sizeof(int));
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