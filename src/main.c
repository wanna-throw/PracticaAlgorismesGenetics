#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void libMem(int *vla, int *fitness, int *seleccionados){
    free(vla);
    free(fitness);
    free(seleccionados);
}
/*Necessito que si es default entonces que devuelva cada parametro por ejemplo null y asi saber si utilizar las constantes*/
void insercioParam(int nGene, int nCromo, float probMut, int kParam){

    printf("Inserta el nombre de Generacions que vulguis computar: (Default:100)\n");
    scanf("%d", &nGene);
    printf("Inserta el nombre de Cromosomes que vulguis computar: (Default:40)\n");
    scanf("%d", &nCromo);
    printf("Inserta la probabilitat de mutacio que vulguis computar: (Default:0.05)\n");
    scanf("%f", &probMut);
    printf("Inserta el nombre del parametre K que vulguis computar: (Default:5)\n");
    scanf("%d", &kParam);
}

int main(){
    
    //variables
    int nGeneracions;
    int nCromosomes;
    float probMutacio;
    int kParam;

    insercioParam(nGeneracions, nCromosomes, probMutacio, kParam);

    srand(time(NULL));
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

    libMem(poblacion, fitness, seleccionados);
    return 0;
}
