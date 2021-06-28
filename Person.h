#ifndef _PERSON_H
#define _PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "PlacesTree.h"

struct Person {
    unsigned int ID; //identifiant d'une personne donné dans le CSV
    char* familyName; //nom de famille
    char* name; //prenom
    unsigned int day;   //
    unsigned int month; //date de naissance
    int years; //
    char* birthPlace; //lieu de naissance
    struct Person* father;
    struct Person* mother;
};

struct TabPerson {
    struct Person** tab;
    int length;

    int youngPerson;
    struct Person* young; //personne la plus jeune et aussi la racine de la famille
    int oldPerson;
    struct Person* old; //personne la plus vieille de la famille
    struct PlacesTree* places; //liste des lieux de naissances
    char* bestPlace; //lieu avec le plus de naissance
    int valBestPlace; //valeur du lieu avec le plus de naissance
    int** calendar; //calendrier contenant toutes les dates et le nombre d'anniverssaire de chaque jours
};

unsigned int getID(struct Person* p);
char* getFamilyName(struct Person* p);
char* getName(struct Person* p);
char* getBirthDate(struct Person* p);
char* getBirthPlace(struct Person* p);
struct Person* getFather(struct Person* p);
struct Person* getMother(struct Person* p);

void updateCalendar(struct TabPerson* tp, struct Person* p);
void checkBestPlace(struct TabPerson* tp, struct Person* P);

int getTabPLength(struct TabPerson* tp);
struct Person* getYoungPerson(struct TabPerson* tp);
struct Person* getOldPerson(struct TabPerson* tp);
char* getBestPlace(struct TabPerson* tp);
void showBirthForDate(struct TabPerson* tp, int day, int month);

#endif