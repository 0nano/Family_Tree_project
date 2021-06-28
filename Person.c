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
        char date[50];

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