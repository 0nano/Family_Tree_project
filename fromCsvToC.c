#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "fromCsvToC.h"

struct TabPerson* fromCsvToC(char* fichier){

    int length;
    char trash[500];

    struct TabPerson* tp = createEmptyTabPerson();
    FILE* fic = fopen(fichier, "r");

    if(fic != NULL) {

        fscanf(fic, "%d", &length);       //Je récupère le nombre de personnes contenues dans la liste

        updateTab(tp, length);
        fscanf(fic, "%s", trash);        //Je saute la deuxième ligne du csv
        fgetc(fic);

        for (int i = 0; i < length; i++) {
            struct Person *new = NULL;
            char *name = NULL, *fname = NULL, *birthPlace = NULL, *dayChar = NULL, *monthChar = NULL, *yearChar = NULL, *IDChar = NULL, *MIDChar = NULL, *FIDChar = NULL;
            unsigned int day = 0, month= 0, ID= 0, motherID= 0, fatherID= 0;
            char separateur[3] = ",/";
            int years= 0;

            printf("test 0\n");

            int posIni = (int) ftell(fic);
            int ctemp;
            do {
                ctemp = fgetc(fic);
                if(ctemp == '\r' || ctemp == '\n'){
                    break;
                }
            }while(1);

            int taille = (int) ftell(fic) - posIni;
            char* string;

            string = (char*) malloc((taille+1)* sizeof(char));

            fseek(fic, -taille, SEEK_CUR);

            fgets(string, taille, fic);
            int tempctab, tempcent;
            tempctab = fgetc(fic);
            if(tempctab != '\r'){
                fseek(fic, -1, SEEK_CUR);
            }
            tempcent = fgetc(fic);
            if(tempcent != '\n'){
                fseek(fic, -1, SEEK_CUR);
            }

            //fscanf(fic, "%s[^\n]", string);

            string[taille] = '\0';

            printf("\n%s\n", string);

            printf("test 1 \n");//, string[taille]);

            char* strToken = strtok(string, separateur);
            IDChar = strToken;
            strToken = strtok(NULL, separateur);
            FIDChar = strToken;
            strToken = strtok(NULL, separateur);
            MIDChar = strToken;
            strToken = strtok(NULL, separateur);
            fname = strToken;                                        //
            strToken = strtok(NULL, separateur);                    //
            name = strToken;                                       //
            strToken = strtok(NULL, separateur);                    //
            dayChar = strToken;                                     //Je découpe la chaine de caractères "string"
            strToken = strtok(NULL, separateur);                    //pour attribuer les valeurs à chaque variable
            monthChar = strToken;                                   //
            strToken = strtok(NULL, separateur);                    //
            yearChar = strToken;                                    //
            strToken = strtok(NULL, separateur);                    //
            birthPlace = strToken;                                  //

            //printf("test 2 %s %s %s %s %s %s\n", IDChar, FIDChar, MIDChar, dayChar, monthChar, yearChar);
            printf("test 2\n");

            ID = atoi(IDChar);
            fatherID = atoi(FIDChar);
            motherID = atoi(MIDChar);
            day = atoi(dayChar);                                    //
            month = atoi(monthChar);                                //Je mets la date en nombres entiers
            years = atoi(yearChar);                                 //

            printf("test 3 %d %d %d %s %s %d %d %d %s\n", ID, fatherID, motherID, fname, name, (int)day, (int)month, years, birthPlace);

            if(motherID == 0 && fatherID == 0){
                new = createPerson(ID, fname, name, (int)day, (int)month, years, birthPlace, 0, 0);
            }else{
                if(motherID == 0){
                    new = createPerson(ID, fname, name, (int)day, (int)month, years, birthPlace, fatherID, 0);
                }else{
                    if (fatherID == 0){
                        new = createPerson(ID, fname, name, (int)day, (int)month, years, birthPlace, 0, motherID);
                    }else{
                        new = createPerson(ID, fname, name, (int)day, (int)month, years, birthPlace, fatherID, motherID);
                    }
                }
            }

            printf("test 4\n");

            tp->tab[ID-1] = new;                  //Je mets la nouvelle personne dans le tableau de personnes
            updateYounger(tp, new);               //Je vérifie si la nouvelle personne est la plus jeune
            updateOlder(tp, new);                 //Je vérifie si la nouvelle personne est la plus vieille

            printf("test 5\n");

            int tempBirth = updateBirthForPlace(tp->places, birthPlace);

            if (tempBirth > tp->valBestPlace) {
                tp->valBestPlace = tempBirth;  //Si le lieu de naissance de la nouvelle personne est le nouveau lieu avec le plus de naissance je l'actualise
                int birthLength = (int)strlen(birthPlace);
                tp->bestPlace = malloc((birthLength+1)*sizeof(char));
                if(tp->bestPlace == NULL){
                    printf("Problème lors de l'allocation\n");
                    exit(1);
                }
                strcpy(tp->bestPlace, birthPlace);
            }

            printf("test 6\n");

            updateCalendar(tp->calendar, new);    //J'actualise les anniversaires dans le calendrier

            //printf("%d\n", tp->tab[i]->ID);

            /*printf("test\n");
            free(string);
            printf("test\n");*/
        }
        for(int i = 0; i < length; i++){
            updateParents(tp, tp->tab[i]);
        }
        printf("OK\n");
        return tp;
    }
    return NULL;
}

