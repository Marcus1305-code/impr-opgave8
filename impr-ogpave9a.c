#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* opgave(char* input);
int main() {
    char* input[] = {"chair", "dairy", "boss", "circus", "fly", "dog", "church", "clue", "dish"};
    for(int i = 0; i < sizeof(input)/sizeof(char*); i++) {
        char* result = opgave(input[i]);
        printf("opredlige navn: %s\n", input[i]);
        printf("nye navn: %s\n", opgave(input[i]));
        free(result);
    }
    return 0;
}
char* opgave(char* input) {
    char* result = (char*)malloc(sizeof(char) * (strlen(input) + 5));
    strcpy(result, input);
    for(int i = 0; input[i] != '\0'; i++) {
        char* o1 = strrchr(input, 'y');
        char* o2 = strrchr(input, 's');
        char* o3 = strrchr(input, "ch");
        char* o3 = strrchr(input, "sh");

        if(o1 != NULL) {
            strcat(result, "ies");
            break;
        } else if (o2 != NULL) {
            strcat(result, "es");
            break;
        } else {
            strcat(result, "s");
            break;
        }
    }
    return result;
}
/*
Opgave A: Flertals navneord
Dette er Kurt Nørmark's opgave 10.3. Du kan skrive dit program i filen opgave-a.c.

Skriv et program som oversætter udvalgte engelske navneord 
fra ental til flertal. Følgende regler skal overholdes:

Hvis et navneord ender i et "y" fjernes "y" og der tilføjes "ies".
Hvis et navneord ender i et "s", "ch" eller "sh" tilføjes et "es".
I alle andre tilfælde tilføjes et "s" til navneordet.

Udskriv hvert navneord i både ental og flertal.

Som altid skal du designe en funktion med et passende navn, 
og med parametre (input og evt. output). Og som altid laver 
vi top-down programmering ved trinvis forfinelse. Ønsker du at 
bruge returværdien af funktionen til noget?

Afprøv dit program på følgende engelske navneord:

chair dairy boss circus fly dog church clue dish
Alloker plads til disse i en passende array af tekststrenge.

Hints: Måske er funktionen strrchr fra string.h nyttig i denne opgave. 
Den søger efter et tegn fra bagenden af strengen. Husk også at du blot kan 
tilgå tegn i en tekststreng med array subscripting operatoren: str[i]. 
Du kan teste om et tegn i din streng svarer til et bestemt tegn: str[i] == 'y'.*/