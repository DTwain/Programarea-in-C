#include <stdio.h>
#include <string.h> 
#include <assert.h> 
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

void test_add_tranzactii(){
    Tranzactie tranzactii[100];
    int nr_tranzactii = 0;
    add_tranzactie(tranzactii, &nr_tranzactii, "12.12.2012", "datoria", 100, "IN");
    assert(tranzactii[0].suma == 100);
    assert(strcmp(tranzactii[0].data, "12.12.2012") == 0);
    assert(strcmp(tranzactii[0].descriere, "datoria") == 0);
    assert(strcmp(tranzactii[0].tip, "IN") == 0);
    add_tranzactie(tranzactii, &nr_tranzactii, "12.12.2012", "bani de buzunar", 100, "OUT");
    assert(tranzactii[1].suma == 100);
    assert(strcmp(tranzactii[1].data, "12.12.2012") == 0);
    assert(strcmp(tranzactii[1].descriere, "bani de buzunar") == 0);
    assert(strcmp(tranzactii[1].tip, "OUT") == 0);
}
