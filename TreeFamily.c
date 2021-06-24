#include "TreeFamily.h"

struct Person* createPerson(char* fName, char* name, char* date, char* birthPlace, struct Person* father, struct Person* mother){

    struct Person* p = malloc(sizeof(struct Person));
    if(p != NULL){

        p->name = name;
        p->familyName = fName;
        p->date = date;
        p->birthPlace = birthPlace;
        p->father = father;
        p->mother = mother;
    }
}

bool isFamilyTreeEmpty (struct FamilyTree* f){

    if(f->young == NULL){
        return true;
    }
    return false;
}

void addPerson (struct FamilyTree* f, struct Person* p){


}