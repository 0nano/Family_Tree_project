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
    char* place; //lieu de naissance
    int birth; //nombre de naissance du lieu
    struct CellPlace* next;
};

struct ListPlace {
    struct CellPlace* head;
    int taille;
};

struct Person {
    char* familyName; //nom de famille
    char* name; //prenom
    char* date; //date de naissance
    char* birthPlace; //lieu de naissance
    struct Person* father;
    struct Person* mother;
    char gender;
    struct ListPerson* children; //liste d'enfants d'une personne utilisé dans le cas où un enfant n'a pas de parenté dans l'arbre hors de ses parents
};

struct FamilyTree {
    int youngPerson;
    struct Person* young; //personne la plus jeune et aussi la racine de la famille
    int oldPerson;
    struct Person* old; //personne la plus vieille de la famille
    struct ListPlace* Lplace; //liste des lieux de naissances
    struct CellPlace* bestPlace; //lieu avec le plus de naissance
    int valBestPlace; //valeur du lieu avec le plus de naissance
    int** calendar; //calendrier contenant toutes les dates et le nombre d'anniverssaire de chacune
};

struct CellPerson* createCellPerson(struct Person* p);
struct ListPerson* createListPerson(struct CellPerson* cp);
void addNewPerson(struct ListPerson* lp, struct Person* p);
void deleteCellPerson(struct CellPerson* cp);
void deleteListPerson(struct ListPerson* lp);

struct CellPlace* createCellPlace(char* place);
struct ListPlace* createListPlace(struct CellPlace* cpl);
void addNewPlace(struct ListPlace* lpl, char* place);
void upadePlace(struct ListPlace* lpl, char* place); //cas où l'on rappel un lieu deja existant + vérification avec valeur de bestPlace dans FamilyTree
void deleteCellPlace(struct CellPlace* cpl);
void deleteListPerson(struct ListPlace* lpl);

struct Person* createPerson(char* fName, char* name, char* date, char* birthPlace, struct Person* father, struct Person* mother); //ok
struct FamilyTree* createFamily(char* fileName);
bool isFamilyTreeEmpty (struct FamilyTree* f); //ok
void addPerson (struct FamilyTree* f, struct Person* p); //ok
struct Person* getOld (struct FamilyTree* f); //ok
struct Person* getYoung (struct FamilyTree* f); //ok
int getBirthForPlace (struct FamilyTree* f, char* place); //ok
char* getBestPlaceInBirth (struct FamilyTree* f); //ok
int numberBirthForDate (struct FamilyTree* f, int day, int month); //ok

void deleteFamilly (struct FamilyTree* f);
