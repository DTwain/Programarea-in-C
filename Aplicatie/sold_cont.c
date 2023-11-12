#include <stdio.h>
#include <string.h>
#include "../Aplicatie/app.h"

float sold(Tranzactie tranzactii[], int nr_tranzactii){
    float sold = 0;
    for (int i = 0; i < nr_tranzactii; ++i)
        if(strcmp(tranzactii[i].tip, "IN") == 0)
            sold += tranzactii[i].suma;
        else
            sold -= tranzactii[i].suma;
    return sold;
}