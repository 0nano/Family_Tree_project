#ifndef _PLACESTREE_H
#define _PLACESTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LETTERS 27

struct PlacesTree {
    struct PlacesTree* letters[MAX_LETTERS];
    bool isWord;
    int birth;
};

struct PlacesTree* createEmptyPlacesTree();
void deletePlacesTree(struct PlacesTree* pt);
struct PlacesTree** getLetters(struct PlacesTree* pt);
bool getIsWord(struct PlacesTree* pt);
void addLetter(struct PlacesTree* pt, char c);
void setIsWord(struct PlacesTree* pt, bool newBool);
void upBirth(struct PlacesTree* pt);
int getBirth(struct PlacesTree* pt);
int charToPos(char c);
int getBirthForPlace(struct PlacesTree* pt, char* word);
int updateBirthForPlace(struct PlacesTree* pt, char* word);

#endif