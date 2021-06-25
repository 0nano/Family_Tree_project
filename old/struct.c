#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "struct.h"

struct CellID* createCellID(struct Person* p){
    struct CellID* cid = malloc(sizeof(struct CellID));
    if(cid == NULL){
        printf("Problème lors de l'allocation de mémoire!\n");
        exit(1);
    }
    cid->ID = p->ID;
    cid->next = NULL;

    return cid;
}

struct ListID* createListID(struct CellID* cid){
    struct ListID* lid = malloc(sizeof(struct ListID));
    if(lid == NULL){
        printf("Problème lors de l'allocation de mémoire!\n");
        exit(1);
    }
    lid->head = cid;
    lid->taille = 1;

    return lid;
}

void addNewID(struct ListID* lid, struct Person* p){
    struct CellID* cid = createCellID(p);

    cid->next = lid->head;
    lid->head = cid;
    lid->taille++;
}

void deleteCellID(struct CellID* cid){
    free(cid);
}

void deleteListID(struct ListID* lid){
    struct CellID* temp = lid->head;
    struct CellID* ntemp = temp->next;
    int taille = lid->taille;

    for (int i = 0; i < taille; i++){
        if(temp != NULL){
            free(temp);
            temp = ntemp;
            ntemp = temp->next;
        }
    }
    
    free(lid);
}