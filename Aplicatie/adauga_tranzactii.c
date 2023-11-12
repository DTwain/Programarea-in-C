#include <stdio.h>
#include <string.h> 
#include "../Aplicatie/app.h"

void add_tranzactie(Tranzactie tranzactii[], int *nr_tranzactii, char data[11], char descriere[100], float suma, char tip[10]){
    Tranzactie tranzactie_noua;
    tranzactie_noua.suma = suma;
    strcpy(tranzactie_noua.data, data);
    strcpy(tranzactie_noua.descriere, descriere);
    strcpy(tranzactie_noua.tip, strupr(tip));
    tranzactii[*nr_tranzactii] = tranzactie_noua;
    *nr_tranzactii += 1;
    
}