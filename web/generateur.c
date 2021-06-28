#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "generateur.h"
void generateur(struct Person *p)
{
    //creation du nom du fichier x = personne_(id de la personne).html
    char t[50];
    sprintf(t, "%d", p->ID);
    char s[50];
    char x[50];
    strcpy(x, "personne_");
    strcpy(s, ".html");
    strcat(x, t);
    strcat(x, s);

    // ouvrir le fichier en lecture
    FILE *html5 = NULL;
    html5 = fopen("personne_id.txt", "r");

    // ouvrir le fichier en écriture
    FILE *fichier = NULL;
    fichier = fopen(x, "w");

    //ecrit dans le fichier
    fprintf(fichier, "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n<meta charset=\"utf-8\">\n<link href=\"style.css\" rel=\"stylesheet\">\n<title>Projet</title>\n</head>\n<body>\n<header class=\"header-basic-light\">\n<img src=\"logo-isen-yncrea-BD-1.jpg\" alt=\"\">\n<nav>\n<ul>\n<li class=\"deroulant\"><a>Différente Famille &ensp;</a>\n<ul class=\"sous\">\n<li><a href=\"#\">Information général</a></li>\n</ul>\n</li>\n</ul>\n</nav>\n</header>\n<div class=\"container\">\n<div class=\"row\">\n<div class=\"tree\">\n<ul>\n<li>\n<a>Nom :%s <br> Prénom :%s <br> date de naissance :%d/%d/%d <br> lieu de naissance :%s <br></a>\n<ul>\n<li>\n<a href=\"#personne_%d.html\">Pather : %d<br></a>\n<ul>\n<li>\n<a href=\"#personne_%d.html\">Grand-Pather : %s<br></a>\n</li>\n<li>\n<a href=\"#personne_%d.html\">Grand-Mother : %s<br></a>\n</li>\n</ul>\n</li>\n<li>\n<a href=\"#personne_%d.html\">Mother : %s<br></a>\n<ul>\n<li>\n<a href=\"#personne_%d.html\">Grand-Pather : %s<br></a>\n</li>\n<li>\n<a href=\"#personne_%d.html\">Grand-Mother : %s<br></a>\n</li>\n</ul>\n</li>\n</ul>\n</li>\n</ul>\n</div>\n</div>\n</div>\n<script src=\"script.js\"></script>\n</body>\n</html>", p->familyName, p->name, p->day, p->month, p->years, p->birthPlace, p->father->ID, p->father->name, p->father->father->ID, p->father->father->name, p->father->mother->ID, p->father->mother->name, p->mother->ID, p->mother->name, p->mother->father->ID, p->mother->father->name, p->mother->mother->ID, p->mother->mother->name);

    fclose(fichier);
}
