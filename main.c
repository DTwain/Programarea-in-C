#include <stdio.h>
//#include "UI/run_console.c"
#include "Infrastructura/infrastructura.h"
#include "Aplicatie/app.h"

int main(){
    Tranzactie tranzactii[100];
    int nr_tranzactii = 0;
    add_tranzactie(tranzactii, &nr_tranzactii, "12/12/2012", "Cashback", 12.54, "IN");
    printf("%s", tranzactii[0].data);
    printf("\n%s", tranzactii[0].descriere);
    printf("\n%f", tranzactii[0].suma);
    printf("\n%s", tranzactii[0].tip);
    printf("\n%d", nr_tranzactii);
    printf("\n %f", sold(tranzactii, nr_tranzactii));
    add_tranzactie(tranzactii, &nr_tranzactii, "19/02/2020", "Banii pe datorie.", 100, "IN");
    afisare_tranzactii(tranzactii, nr_tranzactii);
    char data_start[11] = "11/12/2012";
    char data_final[11] = "15/12/2052";
    Inc_Out cevaaa = situatie_cont(tranzactii, nr_tranzactii, data_start, data_final);
    printf("\n%f", cevaaa.income);
    printf("\n%f", cevaaa.outcome);

    return 0;
}
