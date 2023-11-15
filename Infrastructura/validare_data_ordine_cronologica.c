#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef  enum{false, true} bool;

char **creaza_componente_data(char data[11]){
    /*
    Functia primeste ca parametru un sir de caractere de forma dd/mm/yyyy
    si returneaza un double pointer 
    */
    char copie_data[11];
    strcpy(copie_data, data);
    char **componente_data = (char**)malloc(3*sizeof(char*));
    for(int i = 0; i < 3; i++)
        componente_data[i] = (char*)malloc(3*sizeof(char));
    char *subsir = strtok(copie_data, "/");
    int i = 0;
    while(subsir != NULL){
        strcpy(componente_data[i], subsir);
        i++;
        subsir = strtok(NULL, "/");
    }
    return componente_data;
}

bool data_in_ordine_cronologica(char data_start[11], char data_end[11]){
    /*
    Functia primeste ca parametri doua siruri de caractere de forma dd/mm/yyyy
    si returneaza true daca data_start este mai mica decat data_end si false in caz contrar
    */
    char **componente_data_start = creaza_componente_data(data_start);
    char **componente_data_end = creaza_componente_data(data_end);
    int zi_start = atoi(componente_data_start[0]);
    int luna_start = atoi(componente_data_start[1]);
    int an_start = atoi(componente_data_start[2]);
    int zi_end = atoi(componente_data_end[0]);
    int luna_end = atoi(componente_data_end[1]);
    int an_end = atoi(componente_data_end[2]);
    if(an_start < an_end)
        return true;
    if(an_start == an_end && luna_start < luna_end)
        return true;
    if(an_start == an_end && luna_start == luna_end && (zi_start < zi_end) || zi_end == zi_start)
        return true;
    return false;
}

void test_data_in_ordine_cronologica(){
    assert(data_in_ordine_cronologica("12/12/2012", "12/12/2012") == true);
    assert(data_in_ordine_cronologica("12/12/2012", "12/12/2013") == true);
    assert(data_in_ordine_cronologica("12/12/2012", "12/11/2012") == false);
    assert(data_in_ordine_cronologica("12/12/2012", "11/12/2012") == false);
    assert(data_in_ordine_cronologica("12/12/2012", "13/12/2012") == true);
    assert(data_in_ordine_cronologica("12/12/2012", "12/13/2012") == true);
    assert(data_in_ordine_cronologica("12/12/2012", "12/12/2011") == false);
}
