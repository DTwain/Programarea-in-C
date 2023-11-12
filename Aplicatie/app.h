typedef struct tranzactie{
    char data[11];
    char descriere[100];
    float suma;
    char tip[10];
} Tranzactie;

typedef struct inc_out{
    float income;
    float outcome;
} Inc_Out;

void add_tranzactie(Tranzactie tranzactii[], int *nr_tranzactii, char data[11], char descriere[100], float suma, char tip[10]);
float sold(Tranzactie tranzactii[], int nr_tranzactii);
void afisare_tranzactii(Tranzactie tranzactii[], int nr_tranzactii);
Inc_Out situatie_cont(Tranzactie tranzactii[], int nr_tranzactii, char data_start[11], char data_end[11]);