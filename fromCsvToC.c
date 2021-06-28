#include "fromCsvToC.h"


struct TabPerson* fromCsvToC(char* fichier){

    struct Person* father, *mother, *new;
    char* name, *fname, *birthPlace, *length, *string;
    unsigned int day, month, ID, motherID, fatherID;
    int years, csvLength;

    struct TabPerson* tp = createEmptyTabPerson();

    FILE* fic = fopen(fichier, "r");

    if(fic != NULL) {

        fgets(length, 255, fic);
        csvLength = atoi(length);       //Je récupère le nombre de personnes contenues dans la liste
        fgets(length, 255, fic);        //Je saute la deuxième ligne du csv

        for (int i = 0; i < (csvLength-1); i++) {

            fscanf(fic, "%d,%d,%d,%s", &ID, &fatherID, &motherID, string);  //Je récupère les infos dans le fichier
            char* separateur = ",/";
            char* dayChar, * monthChar, *yearChar;

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

            new = createPerson(ID, fname, name, day, month, years, birthPlace, tp->tab[fatherID-1], tp->tab[motherID-1]);
            tp->tab[ID-1] = new;                  //Je mets la nouvelle personne dans le tableau de personnes
            tp->length++;
            updateYounger(tp, new);               //Je vérifie si la nouvelle personne est la plus jeune
            updateOlder(tp, new);                 //Je vérifie si la nouvelle personne est la plus vieille

            if (!(isAlreadyPlace(tp->places, birthPlace))) {  //Si le lieu de naissance n'existe pas je l'ajoute
                insertWord(tp, birthPlace);
            } else {
                updateBirthForPlace(tp->places,
                                    birthPlace);  //Sinon j'actualise le nombre de naissance dans le lieu correspondant
            }
            if ((getBirthForPlace(tp->places, birthPlace)) > tp->valBestPlace) {

                tp->valBestPlace = getBirthForPlace(tp->places,
                                                    birthPlace);  //Si le lieu de naissance de la nouvelle personne est le
                tp->bestPlace = birthPlace;                                   //nouveau lieu avec le plus de naissance je l'actualise
            }

            updateCalendar(tp->calendar, new);    //J'actualise les anniversaires dans le calendrier
        }
        return tp;
    }
    return NULL;
}

