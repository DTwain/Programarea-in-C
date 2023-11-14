#include <stdio.h>
#include <string.h>
#include "../Infrastructura/infrastructura.h"
#include "../Aplicatie/app.h"

void meniu(){
    printf("1. Adauga o noua tranzactie\n");
    printf("2. Soldul contului\n");
    printf("3. Afisare tranzactii\n");
    printf("4. Raport care cuprinde venitul si cheltuielile dintr-o perioada\n");
    printf("5. Salvare tranzactii in fisier\n");
    printf("6. Preluare date din fisier\n");
}

void comanda(FILE *file_ptr, int optiune, Tranzactie tranzactii[], int *nr_tranzactii){
    char data[11];
    char descriere[300];
    float suma;
    char tip[10];
    switch(optiune){
        case 1:
            printf("Introduceti data (dd/mm/yyyy): ");
            scanf("%10s", data);
            getc(stdin); // getc citeste un caracter din bufferul de intrare stdin (standard input) si il returneaza
                         // in cazul nostru, dupa ce citim data, in bufferul de intrare ramane caracterul \n (enter)
                         // deci trebuie sa il citim si pe el pentru a putea citi descrierea
                         // altfel, daca nu am citi caracterul \n, la citirea descrierii, fgets va citi \n 
                         // si va considera ca am introdus descrierea

            printf("Introduceti descrierea: ");
            fgets(descriere, 300, stdin);
            descriere[strcspn(descriere, "\n")] = 0; // functia strcspn returneaza indexul primei aparitii a caracterului \n in stringul descriere
                                                    // iar apoi setam caracterul de la indexul respectiv cu \0 pentru a inlocui \n.

            printf("Introduceti suma: ");
            scanf("%f", &suma);
            getc(stdin);

            printf("Introduceti tipul: ");
            scanf("%9s", tip);

            if(validare_data(data) && validare_suma(suma) && validare_tip(tip)){
                add_tranzactie(tranzactii, nr_tranzactii, data, descriere, suma, tip);
                printf("Tranzactie adaugata cu succes!\n\n");
            }
            else{
                printf("DATE INVALIDE\n");
                comanda(file_ptr, 4, tranzactii, nr_tranzactii);
            }
            break;

        case 2:
            printf("Soldul contului este: %f \n", sold(tranzactii, *nr_tranzactii));
            break;

        case 3:
            printf("Tranzactiile sunt: \n");
            afisare_tranzactii(tranzactii, *nr_tranzactii);
            break;

        case 4:
            printf("Raportul este: ");
            char start[11];
            char end[11];
            printf("\nIntroduceti data de inceput (dd/mm/yyyy): ");
            scanf("%s", start);
            getc(stdin);

            printf("\nIntroduceti data de sfarsit (dd/mm/yyyy): ");
            scanf("%s", end);
            getc(stdin);

            if(validare_data(start) && validare_data(end) && (data_in_ordine_cronologica(start, end) || strcmp(start, end) == 0)){
                Inc_Out rezultat_raport;
                rezultat_raport = situatie_cont(tranzactii, *nr_tranzactii, start, end);
                printf("Income: %f\n", rezultat_raport.income);
                printf("Outcome: %f\n", rezultat_raport.outcome);
                printf("\n\n");
            }
            else{
                printf("DATE INVALIDE\n");
                comanda(file_ptr, 4, tranzactii, nr_tranzactii);
            }
            break;

        case 5: 
            salvare(file_ptr, tranzactii, *nr_tranzactii);
            printf("Tranzactiile au fost salvate in fisier.\n");
            break;
        
        case 6:
            getter(file_ptr, tranzactii, nr_tranzactii);
            printf("Tranzactiile au fost preluate din fisier.\n");
            break;
    default:
        printf("Optiune invalida. Asigura-te ca optiunea este un numar natural din multimea {1, 2, 3, 4, 5, 6} \n");
        break;
    }
}

void run() {
    FILE * file_ptr;
    file_ptr = fopen("comanda_de_rulare_si_fisier_tranzactii/tranzactii.txt", "a+"); // a+ = append + read practic deschide fisierul cu a+ pentru a nu sterge continutul
    Tranzactie tranzactii[100];               // Este posibil sa dorim sa luam tranzactiile din fisier ceea ce nu ar fi fost posibil 
    int lungime_tranzactii = 0;               // daca am fi deschis fisierul cu w sau w+.
    meniu();
    char rep[3] = "da\0";
    while(strcmp(rep, "da") == 0){
        printf("\nAsigura-te ca optiunea este un numar natural din multimea {1, 2, 3, 4, 5, 6}!!\nIntroduceti optiunea: ");
        char optiune[10];
        scanf("%s", optiune);
        getc(stdin);
        while(validare_optiune(optiune) == false){
            printf("Optiune invalida. Asigura-te ca optiunea este un numar natural din multimea {1, 2, 3, 4, 5, 6}!!\nIntroduceti optiunea: ");
            scanf("%s", optiune);
            getc(stdin);
        }
        comanda(file_ptr, optiune[0] - '0', tranzactii, &lungime_tranzactii); // optiune[0] - '0' transforma un caracter in cifra corespunzatoare int
        printf("Doriti sa continuati? (da/nu): ");
        scanf("%s", rep);
        printf("\n");
    }    
    return;
}
