#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "struct.h"

struct CellID* createCellID(struct Person* p){
    struct CellID* cid = malloc(sizeof(struct CellID));
    if(cid == NULL){
        printf("Problème lors de l'allocation de mémoire!\n");
        exit(1);
    }
    cid->p = p;
    cid->ID = p->ID;
    cid->next = NULL;

    return cid;
}

struct ListID* createListID(struct CellID* cid){
    struct ListID* lid = malloc(sizeof(struct ListID));
    if(lid == NULL){
        printf("Problème lors de l'allocation de mémoire!\n");
        exit(1);
    }
    lid->head = cid;
    lid->taille = 1;

    return lid;
}

void addNewID(struct ListID* lid, struct Person* p){
    struct CellID* cid = createCellID(p);

    cid->next = lid->head;
    lid->head = cid;
    lid->taille++;
}

void deleteCellID(struct CellID* cid){
    free(cid);
}

void deleteListID(struct ListID* lid){
    struct CellID* temp = lid->head;
    struct CellID* ntemp = temp->next;
    int taille = lid->taille;

    for (int i = 0; i < taille; i++){
        if(temp != NULL){
            free(temp);
            temp = ntemp;
            ntemp = temp->next;
        }
    }
    
    free(lid);
}

struct PlacesTree* createEmptyPlacesTree(){
    struct PlacesTree* pt = malloc(sizeof(struct PlacesTree));

    if (pt != NULL) {
        pt->isWord = false;
        for (int i = 0; i < MAX_LETTERS; i++) {
            pt->letters[i] = NULL;
        }
        pt->birth = 0;
    }

    return pt;
}

void deletePlacesTree(struct PlacesTree* pt){
    for (int i = 0; i < MAX_LETTERS; i++){
        if (getLetters(pt)[i] != NULL){
            deleteNodeTrie(getLetters(pt)[i]);
        }
    }
    free(pt);
}

struct PlacesTree** getLetters(struct PlacesTree* pt){
    return pt->letters;
}

bool getIsWord(struct PlacesTree* pt){
    return pt->isWord;
}

void addLetter(struct PlacesTree* pt, char c){
    pt->letters[charToPos(c)] = createEmptyNodeTrie();
}

void setIsWord(struct PlacesTree* pt, bool newBool){
    pt->isWord = newBool;
}

void insertWord(struct PlacesTree* pt, char* word){
    int n = strlen(word);
    struct PlacesTree* triePointer = pt;

    for (int i = 0; i < n; i++){
        if (getLetters(triePointer)[charToPos(word[i])] == NULL){
            addLetter(triePointer, word[i]);
        }
        triePointer = getLetters(triePointer)[charToPos(word[i])];
    }

    setIsWord(triePointer, true);
}

int charToPos(char c){
    if (c >= 'a' && c <= 'z'){
        return c-97;
    }else{
        if(c >= 'A' && c <= 'Z'){
            return c-65;
        }else{
            return 26;
        }
    }
}

struct Person* getYoung (struct FamilyTree* f){
    return f->young;
}