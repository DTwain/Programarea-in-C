#include <stdio.h>
#include "../Aplicatie/app.h"

void salvare(FILE *file_ptr, Tranzactie tranzactii[], int nr_tranzacii){
    for(int i = 0; i < nr_tranzacii; ++i){
        fprintf(file_ptr, "%s\n", tranzactii[i].data);
        fprintf(file_ptr, "%s\n", tranzactii[i].descriere);
        fprintf(file_ptr, "%f\n", tranzactii[i].suma);
        fprintf(file_ptr, "%s\n", tranzactii[i].tip);
        fprintf(file_ptr, "\n");
    }
}