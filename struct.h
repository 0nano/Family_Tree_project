#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LETTERS 27

struct CellID {
    int ID;
    struct CellID* next;
};

struct ListID {
    struct CellID* head;
    int taille;
};

struct PlacesTree {
    struct PlacesTree* letters[MAX_LETTERS];
    bool isWord;
    int birth;
};

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




struct FamilyTree {
    struct ListID* lID; //liste des membres d'une même famille

    struct ListID* children; //liste d'enfants d'une personne utilisé dans le cas où un enfant n'a pas de parenté dans l'arbre hors de ses parents
};

struct CellFamily {
    struct FamilyTree* ft;
    struct CellFamily* next;
};

struct ListFamily {
    struct CellFamily* fhead;
    int taille;
    //redemander aux profs
    int youngPerson;
    struct Person* young; //personne la plus jeune et aussi la racine de la famille
    int oldPerson;
    struct Person* old; //personne la plus vieille de la famille
    //
    struct PlacesTree* places; //liste des lieux de naissances
    char* bestPlace; //lieu avec le plus de naissance
    int valBestPlace; //valeur du lieu avec le plus de naissance
    int** calendar; //calendrier contenant toutes les dates et le nombre d'anniverssaire de chaque jours
};

struct CellID* createCellID(struct Person* p);
struct ListID* createListID(struct CellID* cid);
void addNewID(struct ListID* lid, struct Person* p);
void deleteCellID(struct CellID* cid);
void deleteListID(struct ListID* lid);

struct PlacesTree* createEmptyPlacesTree();
void deletePlacesTree(struct PlacesTree* pt);
struct PlacesTree** getLetters(struct PlacesTree* pt);
bool getIsWord(struct PlacesTree* pt);
void addLetter(struct PlacesTree* pt, char c);
void setIsWord(struct PlacesTree* pt, bool newBool);
void insertWord(struct PlacesTree* pt, char* word);
int charToPos(char c);
int getBirthForPlace(struct PlacesTree* pt, char* word);
void upadteBirthForPlace(struct PlacesTree* pt, char* word);

struct Person* createPerson(char* fName, char* name, char* date, char* birthPlace, struct Person* father, struct Person* mother); //ok
struct FamilyTree* createFamily();
bool isFamilyTreeEmpty (struct FamilyTree* f); //ok
void addPerson (struct FamilyTree* f, struct Person* p); //ok
struct Person* getOld (struct FamilyTree* f); //ok
struct Person* getYoung (struct FamilyTree* f); //ok
int getBirthForPlace (struct FamilyTree* f, char* place); 
char* getBestPlaceInBirth (struct FamilyTree* f); 
int numberBirthForDate (struct FamilyTree* f, int day, int month); //ok

void deleteFamilly (struct FamilyTree* f);
