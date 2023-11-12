#include <stdio.h>
#include <string.h>
#include "../Aplicatie/app.h"
#include "../Infrastructura/infrastructura.h"

Inc_Out situatie_cont(Tranzactie tranzactii[], int nr_tranzactii, char data_start[11], char data_end[11]){
    float income = 0, outcome = 0;
    for(int i = 0; i < nr_tranzactii; ++i){
        if(data_in_ordine_cronologica(data_start, tranzactii[i].data) == true && data_in_ordine_cronologica(tranzactii[i].data, data_end) == true){
            if(strcmp(tranzactii[i].tip, "IN") == 0)
                income += tranzactii[i].suma;
            else
                outcome += tranzactii[i].suma;
        }
    }
    return (Inc_Out){income, outcome};
}

