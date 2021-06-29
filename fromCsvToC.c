#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "fromCsvToC.h"

struct TabPerson* fromCsvToC(char* fichier){
    
    char length[10001];
    
    int csvLength;

    struct TabPerson* tp = createEmptyTabPerson();
    FILE* fic = fopen(fichier, "r");

    if(fic != NULL) {
        fgets(length, 255, fic);
        csvLength = atoi(length);       //Je récupère le nombre de personnes contenues dans la liste
        updateTab(tp, csvLength);
        fgets(length, 255, fic);        //Je saute la deuxième ligne du csv

        for (int i = 0; i < csvLength; i++) {
            struct Person *new;
            char *name, *fname, *birthPlace, string[100000];
            unsigned int day, month, ID, motherID, fatherID;
            int years;

            fscanf(fic, "%d,%d,%d,%[^\n]", &ID, &fatherID, &motherID, string);  //Je récupère les infos dans le fichier
            char separateur[3] = ",/";
            char *dayChar, *monthChar, *yearChar;

            char* strToken = strtok(string, separateur);            //
            name = strToken;                                        //
            strToken = strtok(NULL, separateur);                    //
            fname = strToken;                                       //
            strToken = strtok(NULL, separateur);                    //
            dayChar = strToken;                                     //Je découpe la chaine de caractères "string"
            strToken = strtok(NULL, separateur);                    //pour attribuer les valeurs à chaque variable
            monthChar = strToken;                                   //
            strToken = strtok(NULL, separateur);                    //
            yearChar = strToken;                                    //
            strToken = strtok(NULL, separateur);                    //
            birthPlace = strToken;                                  //
            
            day = atoi(dayChar);                                    //
            month = atoi(monthChar);                                //Je mets la date en nombres entiers
            years = atoi(yearChar);                                 //

            if(motherID == 0 && fatherID == 0){
                new = createPerson(ID, fname, name, day, month, years, birthPlace, NULL, NULL);
            }else{
                if(motherID == 0){
                    new = createPerson(ID, fname, name, day, month, years, birthPlace, tp->tab[fatherID-1], NULL);
                }else{
                    if (fatherID == 0){
                        new = createPerson(ID, fname, name, day, month, years, birthPlace, NULL, tp->tab[motherID-1]);
                    }else{
                        new = createPerson(ID, fname, name, day, month, years, birthPlace, tp->tab[fatherID-1], tp->tab[motherID-1]);
                    }
                }
            }

            tp->tab[ID-1] = new;                  //Je mets la nouvelle personne dans le tableau de personnes
            updateYounger(tp, new);               //Je vérifie si la nouvelle personne est la plus jeune
            updateOlder(tp, new);                 //Je vérifie si la nouvelle personne est la plus vieille
            
            if (!isAlreadyPlace(tp->places, birthPlace)) {  //Si le lieu de naissance n'existe pas je l'ajoute
                insertWord(tp->places, birthPlace);
            } else {
                updateBirthForPlace(tp->places, birthPlace);  //Sinon j'actualise le nombre de naissance dans le lieu correspondant
            }
            if ((getBirthForPlace(tp->places, birthPlace)) > tp->valBestPlace) {
                tp->valBestPlace = getBirthForPlace(tp->places,birthPlace);  //Si le lieu de naissance de la nouvelle personne est le
                tp->bestPlace = birthPlace;                                   //nouveau lieu avec le plus de naissance je l'actualise
            }
            printf("%s\n", tp->bestPlace);

            updateCalendar(tp->calendar, new);    //J'actualise les anniversaires dans le calendrier
            
        }
        printf("OK\n");
        return tp;
    }
    return NULL;
}

