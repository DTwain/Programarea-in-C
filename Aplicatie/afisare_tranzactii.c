#include <stdio.h>
#include <string.h>
#include "../Aplicatie/app.h"

void afisare_tranzactii(Tranzactie tranzactii[], int nr_tranzactii){
    for(int indx = 0; indx < nr_tranzactii; ++indx){
        printf("\nTranzactia %d:", indx + 1);
        printf("\n  Data:      %s", tranzactii[indx].data);
        printf("\n  Descriere: %s", tranzactii[indx].descriere);

        (tranzactii[indx].suma == (int)tranzactii[indx].suma) ? 
        printf("\n  Suma:      %d", (int)tranzactii[indx].suma): printf("\n  Suma:      %.2f", tranzactii[indx].suma);

        printf("\n  Tip:       %s", tranzactii[indx].tip);
        printf("\n\n");
        printf("--------------------------------------------------");
    }
}