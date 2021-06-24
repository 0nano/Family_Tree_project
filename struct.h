#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct CellPerson {
    struct Person* p;
    struct CellPerson* next;
};

struct ListPerson {
    struct CellPerson* head;
    int taille;
};

struct CellPlace {
    char* place;
    int birth;
    struct CellPlace* next;
};

struct ListPlace {
    struct CellPlace* head;
    int taille;
};

struct Person {
    char* familyName;
    char* name;
    char* date;
    char* birthPlace;
    struct Person* father;
    struct Person* mother;
    char gender;
    struct ListPerson* children;
};

struct FamilyTree {
    int youngPerson;
    struct Person* young;
    int oldPerson;
    struct Person* old;
    struct ListPlace* Lplace;
    struct CellPlace* bestPlace;
    int valBestPlace;
    int** calendar;
};

struct CellPerson* createCellPerson(struct Person* p);
struct ListPerson* createListPerson(struct CellPerson* p);
void addNewPerson(struct ListPerson* lp, struct Person* p);
void deleteCellPerson(struct CellPerson* p);
void deleteListPerson(struct ListPerson* p);

struct CellPlace* createCellPlace(char* place);
struct ListPerson* createListPlace(struct CellPlace* p);
void addNewPlace(struct ListPerson* lp, char* place);
void upadePlace(struct ListPerson* lp, char* place);
void deleteCellPlace(struct CellPlace* p);
void deleteListPerson(struct ListPlace* p);

struct Person* createPerson(char* fName, char* name, char* date, char* birthPlace, struct Person* father, struct Person* mother);
struct FamilyTree* createFamily(char* fileName);
bool isFamilyTreeEmpty (struct FamilyTree* f);
void addPerson (struct FamilyTree* f, struct Person* p);
struct Person* getOld (struct FamilyTree* f);
struct Person* getYoung (struct FamilyTree* f);
int getBirthForPlace (struct FamilyTree* f, char* place);
char* getBestPlaceInBirth (struct FamilyTree* f);
int numberBirthForDate (struct FamilyTree* f, int day, int month);

void deleteFamilly (struct FamilyTree* f);
