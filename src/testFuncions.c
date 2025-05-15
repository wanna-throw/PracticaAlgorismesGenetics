#include "aux_funcs.h"
#include "ga.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GENS          30
#define NUM_GENERACIONS   100
#define CROMOSOMES        40
#define K                 10
#define PROBABILITAT      0.05


int main(){
    int a, b, c;
    float d;

    int *w = &a;
    int *x = &b;
    int *y = &c;
    float *z = &d;

    
    insercioParam(w, x, z, y);

    return 0;
}
