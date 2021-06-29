#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Menu.h"

void showMenu(){
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("1. Read CSV file\n");
    printf("2. Exit\n");
    printf("------------------------\n");
    printf("Your choice: ");
}

void showReadMenu(){
    printf("\nWhat do you want to do?\n");
    printf("------------------------\n");
    printf("1. Show family tree info\n");
    printf("2. Export HTML family tree files\n");
    printf("3. Export HTML info files\n");
    printf("4. Export all files\n");
    printf("5. Query family tree\n");
    printf("6. Go back to principal menu\n");
    printf("------------------------\n");
    printf("Your choice: ");
}

void showQueryMenu(){
    printf("\nQuery the family tree!\n\n");
    printf("what do you want to do?\n");
    printf("------------------------\n");
    printf("1. Get first born in the tree\n");
    printf("2. Get last born in the tree\n");
    printf("3. Get number of people born in a region\n");
    printf("4. Get the region with highest number of births\n");
    printf("5. Get the number of people born in a given day ad month\n");
    printf("6. . . . . . \n");
    printf("7. Export query results to HTML file\n");
    printf("8. Go back to previous menu\n");
    printf("------------------------\n");
    printf("Your choice: ");
}

void familyInfo(struct TabPerson* tp){
    printf("\nFamily info\nFirst person born:\n");
    firstBorn(tp);
    printf("Last person born:\n");
    lastBorn(tp);
    printf("First place in birth:\n");
    bestPlace(tp);
}

void firstBorn(struct TabPerson* tp){
    struct Person* p = getYoungPerson(tp);

    printf("Name: %s, ", getName(p));
    printf("Family name: %s\n", getFamilyName(p));
    printf("Birth date: %s, ", getBirthDate(p));
    printf("Birth place: %s\n", getBirthPlace(p));
}

void lastBorn(struct TabPerson* tp){
    struct Person* p = getOldPerson(tp);

    printf("Name: %s, ", getName(p));
    printf("Family name: %s\n", getFamilyName(p));
    printf("Birth date: %s, ", getBirthDate(p));
    printf("Birth place: %s\n", getBirthPlace(p));
}

void nbPeopleInRegion(struct TabPerson* tp, char* word){
    printf("\nNumber of birth for \"%s\": %d\n", word, getBirthForPlace(tp->places, word));
}

void bestPlace(struct TabPerson* tp){
    printf("Best place in birth is %s\n", getBestPlace(tp));
}

void calendar(struct TabPerson* tp, int day, int month){
    showBirthForDate(tp, day, month);
}