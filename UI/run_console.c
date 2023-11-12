#include <stdio.h>
#include <string.h>
#include "../UI/Aplicatie.h"

typedef struct tranzactie{
    char data[11];
    char descriere[100];
    float suma;
    char tip[10];
} Tranzactie;

void meniu(){
    printf("1. Adauga o noua tranzactie\n");
    printf("2. Soldul contului\n");
    printf("3. Afisare tranzactii\n");
    printf("4. Raport care cuprinde venitul si cheltuielile dintr-o perioada\n");
    printf("5. Salvare tranzactii in fisier\n");
}
void comanda(int cmd, Tranzactie tranzactii[], int *nr_tranzactii){
    switch(cmd){
        case 1:
            char data[11];
            char descriere[100];
            float suma;
            char tip[10];
            printf("Introduceti data (dd/mm/yyyy): ");
            scanf("%s", data);
            getc(stdin);

            printf("Introduceti descrierea: ");
            fgets(descriere, 100, stdin);
            getc(stdin);

            printf("Introduceti suma: ");
            scanf("%f", &suma);
            getc(stdin);

            printf("Introduceti tipul (IN / OUT): ");
            scanf("%s", tip);

            if(validare_data(data) && validare_suma(suma) && validare_tip(tip)){
                add_tranzactie(tranzactii, data, descriere, suma, tip);
                nr_tranzactii++;
            }
            else{
                printf("DATE INVALIDE\n");
                comanda(1, tranzactii, &nr_tranzactii);
            }
            break;

        case 2:
            printf("Soldul contului este: %f", sold(tranzactii));
            break;

        case 3:
            printf("Tranzactiile sunt: ");
            output(tranzactii);
            break;

        case 4:
            printf("Raportul este: ");
            char start[11];
            char end[11];
            printf("Introduceti data de inceput (dd/mm/yyyy): ");
            scanf("%s", start);
            getc(stdin);

            printf("Introduceti data de sfarsit (dd/mm/yyyy): ");
            scanf("%s", end);
            getc(stdin);

            if(validare_data(start) && validare_data(end) && (validare_start_mai_mic_decat_end(start, end) || strcmp(start, end) == 0))
            raport_situatie_cont_perioada_a_b(tranzactii, start, end);
            else{
                printf("DATE INVALIDE\n");
                comanda(4, tranzactii, &nr_tranzactii);
            }
            break;
        case 5:
            salvare(tranzactii, nr_tranzactii);
            printf("Tranzactiile au fost salvate in fisier");
            break;
    }
}

void run_console() {
    Tranzactie tranzactii[100];
    int lungime_tranzactii = 0;
    meniu();
    char rep[3] = "da\0";
    while(strcmp(rep, "da") == 0){
        printf("Introduceti comanda: ");
        int cmd;
        scanf("%d", &cmd);
        while( cmd < 1 || cmd > 5){
            printf("Comanda invalida. Introduceti comanda: ");
            scanf("%d", &cmd);
        }
        comanda(cmd, tranzactii, &lungime_tranzactii);


        printf("Doriti sa continuati? (da/nu): ");
        scanf("%s", rep);
    }    
    
}
