#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "PlacesTree.h"
#include "Person.h"

unsigned int getID(struct Person* p){
    return p->ID;
}

char* getFamilyName(struct Person* p){
    return p->familyName;
}

char* getName(struct Person* p){
    return p->name;
}

char* getBirthDate(struct Person* p){
    int day = p->day;
    int month = p->month;
    int year = p->years;

    char* date = malloc((11+1)*sizeof(char));

        if(date == NULL){
                printf("Problème lors de l'allocation\n");
                exit(1);
        }

        int indice = 0;

        if(day/10 != 0){
                date[indice] = day/10+48;
                indice++;
        }

        date[indice] = day%10+48;
        indice++;

        date[indice] = '/';
        indice++;

        if(month/10 != 0){
                date[indice] = month/10+48;
                indice++;
        }

        date[indice] = month%10+48;
        indice++;

        date[indice] = '/';
        indice++;

        if(year < 0){
                date[indice] = '-';
                indice++;
        }

        if(year/1000 != 0){
                date[indice] = year/1000+48;
                indice++;
        }
        if(year/100 != 0){
                date[indice] = (year%1000)/100+48;
                indice++;
        }
        if(year/10 != 0){
                date[indice] = (year%100)/10+48;
                indice++;
        }

        date[indice] = year%10+48;
        indice++;

        date[indice] = '\0';

        return date;
}

char* getBirthPlace(struct Person* p){
    return p->birthPlace;
}

struct Person* getFather(struct Person* p){
    return p->father;
}

struct Person* getMother(struct Person* p){
    return p->mother;
}

int getTabPLength(struct TabPerson* tp){
    return tp->length;
}

struct Person* getYoungPerson(struct TabPerson* tp){
    return tp->youngPerson;
}

struct Person* getOldPerson(struct TabPerson* tp){
    return tp->old;
}

char* getBestPlace(struct TabPerson* tp){
    return tp->bestPlace;
}

void showBirthForDate(struct TabPerson* tp, int day, int month){
    printf("Number of Birth for %d/%d : %d\n", day, month, tp->calendar[month][day]);
}