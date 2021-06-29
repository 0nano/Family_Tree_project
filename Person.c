
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
    printf("Number of Birth for %d/%d : %d\n", day, month, tp->calendar[month][day]);
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

    if(tp->youngPersonYears < p->years){    //Si l'année de naissance de la nouvelle personne est plus grande que l'ancienne
                                            //plus jeune personne je remplace les infos
        tp->youngPersonDay = p->day;
        tp->youngPersonMonth = p->month;
        tp->youngPersonYears = p->years;
        tp->young = p;
    }
    if(tp->youngPersonYears == p->years){       //Si les années sont égales je compare les mois et remplace si besoin
        if(tp->youngPersonMonth < p->month){

            tp->youngPersonDay = p->day;
            tp->youngPersonMonth = p->month;
            tp->youngPersonYears = p->years;
            tp->young = p;
        }
        if(tp->youngPersonMonth == p->month){   //Si les mois sont égaux je compare les jours et remplace si besoin
            if(tp->youngPersonDay < p->day){

                tp->youngPersonDay = p->day;
                tp->youngPersonMonth = p->month;
                tp->youngPersonYears = p->years;
                tp->young = p;
            }
        }
    }

}

void updateOlder(struct TabPerson* tp, struct Person* p){

    if(tp->oldPersonYears < p->years){    //Si l'année de naissance de la nouvelle personne est plus petite que l'ancienne
                                          //plus vieille personne je remplace les infos
        tp->oldPersonDay = p->day;
        tp->oldPersonMonth = p->month;
        tp->oldPersonYears = p->years;
        tp->old = p;
    }
    if(tp->oldPersonYears == p->years){       //Si les années sont égales je compare les mois et remplace si besoin
        if(tp->oldPersonMonth > p->month){

            tp->oldPersonDay = p->day;
            tp->oldPersonMonth = p->month;
            tp->oldPersonYears = p->years;
            tp->old = p;
        }
        if(tp->oldPersonMonth == p->month){   //Si les mois sont égaux je compare les jour et remplace si besoin
            if(tp->oldPersonDay > p->day){

                tp->oldPersonDay = p->day;
                tp->oldPersonMonth = p->month;
                tp->oldPersonYears = p->years;
                tp->old = p;
            }
        }
    }
}

struct TabPerson* createEmptyTabPerson(){

    struct TabPerson* tp = malloc(sizeof(struct TabPerson));
    if(tp != NULL){

        tp->oldPersonYears = 3000;          //Je mets des valeurs aberrantes pour être sur que le plus vieux et plus jeune
        tp->youngPersonYears = -6000;       //s'actualise(ça ne marchera pas si quelqu'un veut faire l'arbre généalogique de cléôpatre)
        tp->length = 0;
        tp->calendar = malloc(sizeof(int*)*12);
        if(tp->calendar != NULL){
            for (int k = 0; k < 12; k++) {
                tp->calendar[k] = malloc(31 * sizeof(int));
            }
        }
        for(int i = 0; i < 12;i++){         //J'initialise tout le calendrier à 0
            for(int j = 0; j < 31; j++){
                tp->calendar[i][j] = 0;
            }
        }
        tp->valBestPlace = 0;               //J'initialise valBestPlace à 0 pour que bestPlace s'actualise correctement
        return tp;
    }
    return NULL;
}

void updateCalendar(int** calendar, struct Person* p){

    calendar[p->month][p->day]++;
}
