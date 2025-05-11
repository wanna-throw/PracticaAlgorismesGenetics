#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_GENS 30
#define CROMOSOMES 100
#define K 10
#define PROBABILITAT 0.05

void init_poblacion(int *taula, int num_cromosomes){

    for (int i = 0; i < num_cromosomes; i++){
        for (int j = 0 ; j < NUM_GENS; j++){
            
            /*En cada indice se imprime 1 o 0 de forma aleatoria*/
             taula[i * NUM_GENS + j] = rand() % 2;

            }
        }
}

//getters

int getNumGens(int nGens){
    bool llegit;
    llegit = scanf("%d", &nGens);
    if(llegit == false){
        nGens = NUM_GENS;
    }
    return nGens;
}

int getNumCromo(int nCromo){
    bool llegit;
    llegit = scanf("%d", &nCromo);
    if(llegit == false){
        nCromo = CROMOSOMES;
    }
    return nCromo;  
}

/***
 * 
 */
float getNumProb(float numProb){
    bool llegit;
    llegit = scanf("%f", &numProb);
    if(llegit == false){
        numProb = PROBABILITAT;
    }
    return numProb;
}

int getNumK(int kParam){
    bool llegit;
    llegit = scanf("%d", &kParam);
    if(llegit == false){
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
    bool correcte;
    if(param < 0 || param > 9999){
        correcte = false;
    }
    printf("El parametre ha de ser mes gran que 0 o mes petit que 9999");
    return correcte;
}

/***
 * @param param
 * @brief funcio que comprova si el float esta dins dels valors correctes
 * @return correcte
 */
bool esCorrecteFloat(float param){
    bool correcte;
    if(param < 0 || param > 1){
        correcte = false;
    }
    printf("El parametre ha de ser mes gran que 0 o mes petit que 1");
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
void insercioParam(int nGene, int nCromo, float probMut, int kParam){
    do{
    printf("\nInserta el nombre de Generacions que vulguis computar: (Default:100)\n");
    nGene = getNumGens(nGene);
    }while(esCorrecteInt(nGene) == false);
    printf("\nEl nombre de Generacions es: %d", nGene);

    do{
    printf("\nInserta el nombre de Cromosomes que vulguis computar: (Default:40)\n");
    nCromo = getNumCromo(nCromo);
    }while(esCorrecteInt(nCromo) == false);
    printf("\nEl nombre de Cromosomes es: %d", nCromo);

    do{
    printf("\nInserta la probabilitat de mutacio que vulguis computar: (Default:0.05)\n");
    probMut = getNumProb(probMut);
    }while(esCorrecteFloat(probMut) == false);
    printf("\nEl nombre de probabilitat de mutacio es: %f", probMut);

    do{
    printf("\nInserta el nombre del parametre K que vulguis computar: (Default:5)\n");
    kParam = getNumK(kParam);
    }while(esCorrecteInt(kParam) == false);
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

bool evaluaFormula(int *poblacion, int *fitness, int num_cromosomes){
    bool correcte = true;
    int formula;
    for(int i = 0; i < sizeof(poblacion); i++){
        formula = (poblacion[i]*(i^2) - 1977);
        if (formula != 0){
            correcte = false;
        }
    }
    return correcte;
}

void cruza_one_point(int **taula[][NUM_GENS]){
    int crossoverPoint;
    int aux;
    for (int i = 0; i < sizeof(taula) - 1; i = i + 2){
        crossoverPoint = rand() % sizeof(taula);
        for (int j = 0; j < crossoverPoint; j++){
            aux = taula[i][j];
            taula[i][j] = taula[i + 1][j];
            taula[i + 1][j] = aux;
        }
    }
}

void ejecutar_GA(int *poblacion, int *fitness, int *seleccionados, int *poblacion_nueva, int n_generaciones, int n_cromosomas, float prob_mut,int kParam)
{
    int  mejor_error_global = INT_MAX;
    int  gen_mejor_global   = -1;
    int *mejor_cromosoma    = malloc(NUM_GENS * sizeof *mejor_cromosoma);
    if (!mejor_cromosoma) {
        perror("malloc mejor_cromosoma");
        exit(EXIT_FAILURE);
    }

    for (int gen = 0; gen < n_generaciones; gen++) {
        /*Evaluar fitness */
    evaluaFormula(poblacion, fitness, n_cromosomas);

        /*Hallar el mejor de la generación actual */
        int mejor_error = INT_MAX;
        int mejor_index   = 0;
        for (int i = 0; i < n_cromosomas; i++) {
            if (fitness[i] < mejor_error) {
                mejor_error = fitness[i];
                mejor_index = i;
            }
        }

        /*Actualizar global si corresponde */
        if (mejor_error < mejor_error_global) {
            mejor_error_global = mejor_error;
            gen_mejor_global = gen;
            memcpy(mejor_cromosoma, &poblacion[mejor_index * NUM_GENS], NUM_GENS * sizeof *mejor_cromosoma);
        }

        /*Selección por torneo */
        seleccionar_padres(poblacion, fitness, seleccionados, n_cromosomas, kParam);

        /*Cruce (implementado por Dario) */
        cruza_one_point(seleccionados, poblacion_nueva, n_cromosomas);

        /*Mutación gen a gen usando tu función mutar */
        for (int i = 0; i < n_cromosomas; i++) {
            for (int j = 0; j < NUM_GENS; j++) {
                poblacion_nueva[i*NUM_GENS + j] =
                    mutar(poblacion_nueva[i*NUM_GENS + j], prob_mut);
            }
        }

        /*Reemplazo: swap de punteros */
        int *tmp = poblacion;
        poblacion = poblacion_nueva;
        poblacion_nueva = tmp;
    }

    /* 8) Imprimir mejor solución global */
    printf("\n=== Mejor solución encontrada en generación %d ===\n", gen_mejor_global + 1);
    printf("\n\n");

    free(mejor_cromosoma);
}

void libMemTaula(int *taula){
    for (int i = 0; i < sizeof(taula); i++){
        free(taula[i]);
    }
}



void libMem(int *poblacio, int *fitness, int *seleccionados, int *poblacion_nueva){
    //libera memoria de la taula y el punter poblacio
    libMemTaula(poblacio);
    free(poblacio);
    //libera memoria de la taula y el punter fitness
    libMemTaula(fitness);
    free(fitness);
    //libera memoria de la taula y el punter seleccionados
    libMemTaula(seleccionados);
    free(seleccionados);
    //libera memoria de la taula y el punter poblacion_nueva
    libMemTaula(poblacion_nueva);
    free(poblacion_nueva);
}

void imprimirContra(int *taula){
    printf("La contrasenya es: ");
    for(int i = 0; i < sizeof(taula); i++){
        printf("%d", taula[i]);
    }
}

int main(){
    
    //variables
    int nGeneracions;
    int nCromosomes;
    float probMutacio;
    int kParam;
    //taules malloc
    insercioParam(nGeneracions, nCromosomes, probMutacio, kParam);
    int *poblacion = malloc(nCromosomes * NUM_GENS * sizeof(int));
    int *fitness = malloc(nCromosomes * NUM_GENS * sizeof(int));
    int *seleccionados = malloc(nCromosomes * NUM_GENS * sizeof(int));
    int *poblacion_nueva= malloc(nCromosomes * NUM_GENS * sizeof *poblacion_nueva);

    if (!poblacion || !fitness || !seleccionados || !poblacion_nueva) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    srand(time(NULL));
    init_poblacion(poblacion, nCromosomes);
    ejecutar_GA(poblacion, fitness, seleccionados, poblacion_nueva, nGeneracions, nCromosomes, probMutacio, kParam);

    evaluaFormula(poblacion, fitness, nCromosomes); /*Mira en el void GA lo que necessito para hacer esta funcion, lo mismo para la funcion cruza_one_point()*/
    imprimirContra(seleccionados);
    libMem(poblacion, fitness, seleccionados, poblacion_nueva);

    free(poblacion_nueva);
    return 0;
}