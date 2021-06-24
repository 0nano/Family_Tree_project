#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Person {
    char* familyName;
    char* name;
    char* date;
    char* birthPlace;
    struct Person* father;
    struct Person* mother;
    char gender;
    struct List* children;
}

struct FamilyTree {
    int youngPerson;
    struct Person* young;
    int oldPerson;
    struct Person* old;
    struct List* place;
    int posPlace;
    int valPlace;
    int** calendar;
}

struct Person* createPerson(char* fName, char* name, char* date, char* birthPlace, struct Person* father, struct Person* mother);
struct FamilyTree* createFamily();
bool isFamilyTreeEmpty (struct FamilyTree* f);
void addPerson (struct FamilyTree* f, struct Person* p);
struct Person* getOld (struct FamilyTree* f);
struct Person* getYoung (struct FamilyTree* f);
int getBirthForPlace (struct FamilyTree* f, char* place);
char* getBestPlaceInBirth (struct FamilyTree* f);
int numberBirthForDate (struct FamilyTree* f, int day, int month);

void deleteFamilly (struct FamilyTree* f);
