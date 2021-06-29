#ifndef _MENU_H
#define _MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Person.h"

//show differents menus
void showMenu();
void showReadMenu();
void showQueryMenu();

//function for the query menu
void familyInfo(struct TabPerson* tp);
void firstBorn(struct TabPerson* tp);
void lastBorn(struct TabPerson* tp);
void nbPeopleInRegion(struct TabPerson* tp, char* word);
void bestPlace(struct TabPerson* tp);
void calendar(struct TabPerson* tp, int day, int month);

#endif