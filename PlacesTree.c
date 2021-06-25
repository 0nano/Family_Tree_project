#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "PlacesTree.h"

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
    triePointer->birth = 1;
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

int getBirthForPlace(struct PlacesTree* pt, char* word){
    int n = strlen(word);
    struct PlacesTree* triePointer = pt;

    for (int i = 0; i < n; i++){
        if (getLetters(triePointer)[charToPos(word[i])] == NULL){
            break;
        }else{
            triePointer = getLetters(triePointer)[charToPos(word[i])];
        }
    }

    return triePointer->birth;
}

void upadteBirthForPlace(struct PlacesTree* pt, char* word){
    int n = strlen(word);
    struct PlacesTree* triePointer = pt;

    for (int i = 0; i < n; i++){
        if (getLetters(triePointer)[charToPos(word[i])] == NULL){
            break;
        }else{
            triePointer = getLetters(triePointer)[charToPos(word[i])];
        }
    }

    triePointer->birth++;
}