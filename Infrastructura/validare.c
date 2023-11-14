#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } bool;

bool validare_data(char data[11]) {
    char componente_data[3][3];
    char copie_data[11];
    strcpy(copie_data, data);
    char *sub_sir = strtok(copie_data, "/");
    int i = 0;
    while(sub_sir != NULL){
        strcpy(componente_data[i], sub_sir);
        i++;
        sub_sir = strtok(NULL, "/");
    }

    if(i != 3)
        return false;

    int zi = atoi(componente_data[0]);
    int luna = atoi(componente_data[1]);
    int an = atoi(componente_data[2]);

    if(zi < 1 || zi > 31)
        return false;
    if(luna < 1 || luna > 12)
        return false;
    if(an < 0) 
        return false;
    bool an_bisect = false;
    if(an % 4 == 0 || an % 400 == 0)
        an_bisect = true;
    if(luna == 2 && an_bisect == 1 && zi > 29)
        return false;
    if(luna == 2 && an_bisect == 0 && zi > 28)
        return false;
    if((luna == 4 || luna == 6 || luna == 9 || luna == 11) && zi > 30)
        return false;
    return true;
    
}

bool validare_suma(float suma){
    if(suma < 0)
        return false;
    return true;
}

bool validare_tip(char tip[10]){
    if(strcmp(strupr(tip), "IN") == 0 || strcmp(strupr(tip), "OUT") == 0)
        return true;
    return false;
}

bool validare_optiune(char optiune[10]){
    /*
    optiunea trebuie sa fie un numar natural din multimea {1, 2, 3, 4, 5, 6}
    */
    if(strcmp(optiune, "1") == 0 || strcmp(optiune, "2") == 0 || strcmp(optiune, "3") == 0 || 
    strcmp(optiune, "4") == 0 || strcmp(optiune, "5") == 0 || strcmp(optiune, "6") == 0 || 
    strcmp(optiune, "1.0") == 0 || strcmp(optiune, "2.0") == 0 || strcmp(optiune, "3.0") == 0 ||
    strcmp(optiune, "4.0") == 0 || strcmp(optiune, "5.0") == 0 || strcmp(optiune, "6.0") == 0 ||
    strcmp(optiune, "1,0") == 0 || strcmp(optiune, "2,0") == 0 || strcmp(optiune, "3,0") == 0 ||
    strcmp(optiune, "4,0") == 0 || strcmp(optiune, "5,0") == 0 || strcmp(optiune, "6,0") == 0)
        return true;
    return false;
}



    
