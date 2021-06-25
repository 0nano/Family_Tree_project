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

