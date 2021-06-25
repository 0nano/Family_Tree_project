#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//#include "struct.h"

int main(){

    printf("WELCOME TO THE FAMILY TREE PROJECT!!!\n\n");
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("1. Read CSV file\n");
    printf("2. Exit\n");
    printf("------------------------\n");
    printf("Your choice: ");

    char choice;

    scanf("%c", &choice);

    if (choice == '1'){
        printf("\nRead CSV file\n");
        printf("------------------------\n");
        printf("Enter CSV file name: ");
    }else{
        if(choice == '2'){
            printf("\nGood Bye :)\n");
        }else{
            printf("\nWrong input :( !\n");
        }
    }
    

    return 0;
}