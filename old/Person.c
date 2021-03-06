
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "PlacesTree.h"
#include "Person.h"

unsigned int getID(struct Person* p){
    if(p != NULL){
        return p->ID;
    }else{
        return 0;
    }
}

char* getFamilyName(struct Person* p){
    if(p != NULL){
        return p->familyName;
    }else{
        return "Person does'nt find";
    }
}

char* getName(struct Person* p){
    if(p != NULL){
        return p->name;
    }else{
        return "Person does'nt find";
    }
}

char* getBirthDate(struct Person* p){
    if(p != NULL){
        char* date = malloc(50*sizeof(char));

        sprintf(date, "%d/%d/%d", p->day, p->month, p->years);

        return date;
    }else{
        return "Person does'nt find";
    }
}

char* getBirthPlace(struct Person* p){
    if(p != NULL){
        return p->birthPlace;
    }else{
        return "Person does'nt find";
    }
}

struct Person* getFather(struct Person* p){
    if(p != NULL){
        return p->father;
    }else{
        return NULL;
    }
}

struct Person* getMother(struct Person* p){
    if(p != NULL){
        return p->mother;
    }else{
        return NULL;
    }
}

int getTabPLength(struct TabPerson* tp){
    return tp->length;
}

struct Person* getYoungPerson(struct TabPerson* tp){
    return tp->young;
}

struct Person* getOldPerson(struct TabPerson* tp){
    return tp->old;
}

char* getBestPlace(struct TabPerson* tp){
    return tp->bestPlace;
}

void showBirthForDate(struct TabPerson* tp, int day, int month){
    printf("\nNumber of Birth for %d/%d : %d\n", day, month, tp->calendar[month-1][day-1]);
}

struct Person* createPerson(unsigned int ID, char* fname, char* name, int day, int month, int years, char* birthPlace, struct Person* father, struct Person* mother){

    struct Person* p = malloc(sizeof(struct Person));
    if(p != NULL){

        p->ID = ID;
        p->familyName = fname;
        p->name = name;
        p->day = day;
        p->month = month;
        p->years = years;
        p->birthPlace = birthPlace;
        p->father = father;
        p->mother = mother;

        return p;
    }
    return NULL;
}

void updateYounger(struct TabPerson* tp, struct Person* p){
    if(tp->young != NULL){
        if(tp->young->years < p->years){    //Si l'ann??e de naissance de la nouvelle personne est plus grande que l'ancienne
                                        //plus jeune personne je remplace les infos
            tp->young = p;
        }else{
            if(tp->young->years== p->years){       //Si les ann??es sont ??gales je compare les mois et remplace si besoin
                if(tp->young->month < p->month){
                    tp->young = p;
                }else{
                    if(tp->young->month == p->month){   //Si les mois sont ??gaux je compare les jours et remplace si besoin
                        if(tp->young->day < p->day){
                            tp->young = p;
                        }
                    }
                }
            }
        }
    }else{
        tp->young = p;
    }
}

void updateOlder(struct TabPerson* tp, struct Person* p){
    if(tp->old != NULL){
        if(tp->old->years > p->years){    //Si l'ann??e de naissance de la nouvelle personne est plus petite que l'ancienne
                                          //plus vieille personne je remplace les infos
            tp->old = p;
        }else{
            if(tp->old->years == p->years){       //Si les ann??es sont ??gales je compare les mois et remplace si besoin
                if(tp->old->month > p->month){
                    tp->old = p;
                }else{
                    if(tp->old->month == p->month){   //Si les mois sont ??gaux je compare les jour et remplace si besoin
                        if(tp->old->day > p->day){
                            tp->old = p;
                        }
                    }
                }
            }
        }
    }else{
        tp->old = p;
    }
}

struct TabPerson* createEmptyTabPerson(){

    struct TabPerson* tp = malloc(sizeof(struct TabPerson));
    if(tp != NULL){
        tp->tab = NULL;
        tp->length = 0;
        tp->young = NULL;
        tp->old = NULL;
        tp->calendar = malloc(sizeof(int*)*12);
        if(tp->calendar != NULL){
            for (int k = 0; k < 12; k++) {
                tp->calendar[k] = malloc(31 * sizeof(int));
            }
        }
        for(int i = 0; i < 12;i++){         //J'initialise tout le calendrier ?? 0
            for(int j = 0; j < 31; j++){
                tp->calendar[i][j] = 0;
            }
        }
        tp->valBestPlace = 0;               //J'initialise valBestPlace ?? 0 pour que bestPlace s'actualise correctement
        tp->places = createEmptyPlacesTree();
        return tp;
    }
    return NULL;
}

void updateTab(struct TabPerson* tp, int length){
    if(tp != NULL){
        tp->tab = malloc(length*sizeof(struct Person*));
        if (tp->tab == NULL){
            printf("Probl??me lors de l'allocation\n");
            exit(1);
        }

        for (int i = 0; i < length; i++){
            tp->tab[i] = NULL;
        }
    }
}

void updateCalendar(int** calendar, struct Person* p){
    calendar[p->month-1][p->day-1]++;
}
