#include <stdio.h>
#include <string.h>
#include "../Aplicatie/app.h"
#include <assert.h>
float sold(Tranzactie tranzactii[], int nr_tranzactii){
    float sold = 0;
    for (int i = 0; i < nr_tranzactii; ++i)
        if(strcmp(tranzactii[i].tip, "IN") == 0)
            sold += tranzactii[i].suma;
        else
            sold -= tranzactii[i].suma;
    return sold;
}

void test_sold(){
    Tranzactie tranzactii[100];
    int nr_tranzactii = 0;
    add_tranzactie(tranzactii, &nr_tranzactii, "12.12.2012", "datoria", 100, "IN");
    add_tranzactie(tranzactii, &nr_tranzactii, "12.12.2012", "bani de buzunar", 100, "OUT");
    assert(sold(tranzactii, nr_tranzactii) == 0);
    add_tranzactie(tranzactii, &nr_tranzactii, "12.12.2012", "datoria", 100, "IN");
    assert(sold(tranzactii, nr_tranzactii) == 100);
    add_tranzactie(tranzactii, &nr_tranzactii, "12.12.2012", "bani de buzunar", 100, "OUT");
    assert(sold(tranzactii, nr_tranzactii) == 0);
}
