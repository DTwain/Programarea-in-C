#include <stdio.h>
#include "../Aplicatie/app.h"
#include "../Infrastructura/infrastructura.h"

void getter(FILE *file_ptr, Tranzactie tranzactii[], int *nr_tranzactii){
    char data[11];
    char descriere[100];
    float suma;
    char tip[10];
    while(fscanf(file_ptr, "%10s %99[^\n] %f %9s", data, descriere, &suma, tip) != EOF){
        if(validare_data(data) && validare_suma(suma) && validare_tip(tip))
            add_tranzactie(tranzactii, nr_tranzactii, data, descriere, suma, tip);
    }
}

