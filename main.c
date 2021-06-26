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

    choice = getc(stdin);

    if (choice == '1'){
        printf("\nRead CSV file\n");
        printf("------------------------\n");
        printf("Enter CSV file name: ");
    }else{
        if(choice == '2'){
            printf("\nGood Bye :)\n");
            return 0;
        }else{
            printf("\nWrong input :( !\n");
        }
    }
    
    char filename[50];

    getc(stdin);

    scanf("%s[^\n]", filename);

    printf("\nFile \"%s\" read successfully!\n", filename);

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

    return 0;
}