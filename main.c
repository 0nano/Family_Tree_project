#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "fromCsvToC.h"


int main(){


    struct TabPerson* tp = createEmptyTabPerson();
    tp = fromCsvToC("bd_petite.csv");

    /*printf("Plus jeune personne: %s %s\n", tp->young->name, tp->young->familyName);
    printf("Plus vieille personne: %s %s\n", tp->old->name, tp->old->familyName);
    printf("Plus de naissance: %d\n", tp->valBestPlace);
    printf("Lieu plus de naissance: %s\n", tp->bestPlace);*/


    return 0;
}