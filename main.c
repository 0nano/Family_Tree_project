#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Menu.h"

int main(){
    printf("WELCOME TO THE FAMILY TREE PROJECT!!!\n\n");
    
    int good = 0;
    
    do{
        showMenu();

        char choice;

        choice = getc(stdin);

        switch (choice){
            case '1':
                printf("\nRead CSV file\n");
                printf("------------------------\n");
                printf("Enter CSV file name: ");
                good++;
                break;
            case '2':
                printf("\nGood Bye :)\n");
                return 0;
            default:
                printf("\nWrong input :( !\n\n");
                getc(stdin);
                break;
        }
    
        if(good != 0){
            good = 0;

            char filename[50];
    
            getc(stdin);
            scanf("%s[^\n]", filename);
    
            struct TabPerson* tp = NULL;

            if(tp == NULL){
                printf("\nProblème lors de la lecture de la base de donné, soit celle-ci est vide, soit la lecture a eu un problème!\n");
                exit(1);
            }

            printf("\nFile \"%s\" read successfully!\n", filename);
            do{
                showReadMenu();

                char doChoice;
                getc(stdin);
        
                doChoice = getc(stdin);

                switch (doChoice){
                    case '1':
                        good = 1;
                        break;
                    case '2':
                        good = 2;
                        break;
                    case '3':
                        good = 3;
                        break;
                    case '4':
                        good = 4;
                        break;
                    case '5':
                        good = 5;
                        break;
                    case '6':
                        good = 6;
                        break;
                    default:
                        printf("\nWrong input :( !\n");
                        break;
                }
    

                if(good==5){
                    do{
                        showQueryMenu();

                        char doChoice;
                        getc(stdin);
        
                        doChoice = getc(stdin);

                        switch (doChoice){
                            case '1':
                                firstBorn(tp);
                                break;
                            case '2':
                                lastBorn(tp);
                                break;
                            case '3':
                                printf("Enter the place: ");
                                getc(stdin);

                                char lieu[150];
                                scanf("%s[^\n]", lieu);

                                nbPeopleInRegion(tp, lieu);
                                break;
                            case '4':
                                bestPlace(tp);
                                break;
                            case '5':
                                printf("Enter the day: ");
                               getc(stdin);

                                int day, month;
                                scanf("%d", &day);

                                getc(stdin);
                                scanf("%d", &month);

                                calendar(tp, day, month);
                                break;
                            case '6':
                                printf("\nNothing here\n");
                                break;
                            case '7':
                                printf("In construction\n");
                                break;
                            case '8':
                                good = 0;
                                break;
                            default:
                                printf("\nWrong input :( !\n");
                                break;
                        }
                    }while(good!=0);
                    good = 0;
                }

            }while(good==0);
            good = 0;
            getc(stdin);
        }

    }while(good==0);

    return 0;
}