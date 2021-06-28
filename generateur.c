#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "generateur.h"

void generateur(struct Person* p){
    //creation du nom du fichier x = personne_(id de la personne).html
    char t[50];
    sprintf(t, "%d", getID(p));
    char s[50];
    char x[50];
    strcpy(x, "personne_");
    strcpy(s, ".html");
    strcat(x, t);
    strcat(x, s);

    // ouvrir le fichier en écriture
    FILE *fichier = NULL;
    fichier = fopen(x, "w");

    struct Person* f = getFather(p);
    struct Person* m = getMother(p);
    struct Person* Ff = getFather(f);
    struct Person* Mf = getMother(f);
    struct Person* Fm = getFather(m);
    struct Person* Mm = getMother(m);
    

    //ecrit dans le fichier
    fprintf(fichier, "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n<meta charset=\"utf-8\">\n<link href=\"style.css\" rel=\"stylesheet\">\n<title>Projet</title>\n</head>\n<body>\n<header class=\"header-basic-light\">\n<img src=\"logo-isen-yncrea-BD-1.jpg\" alt=\"\">\n<nav>\n<ul>\n<li class=\"deroulant\"><a>Différente Famille &ensp;</a>\n<ul class=\"sous\">\n</ul>\n</li>\n</ul>\n</nav>\n</header>\n" "<div class=\"container\">\n<div class=\"row\">\n<div class=\"tree\">\n<ul>\n<li>\n<a>Nom : %s <br> Prénom : %s <br> date de naissance : %s <br> lieu de naissance : %s <br></a>\n<ul>\n<li>\n<a href=\"#personne_%d.html\">Pather : %s<br></a>\n<ul>\n<li>\n<a href=\"#personne_%d.html\">Grand-Pather : %s<br></a>\n</li>\n<li>\n<a href=\"#personne_%d.html\">Grand-Mother : %s<br></a>\n</li>\n</ul>\n</li>\n<li>\n<a href=\"#personne_%d.html\">Mother : %s<br></a>\n<ul>\n<li>\n<a href=\"#personne_%d.html\">Grand-Pather : %s<br></a>\n</li>\n<li>\n<a href=\"#personne_%d.html\">Grand-Mother : %s<br></a>\n</li>\n</ul>\n</li>\n</ul>\n</li>\n</ul>\n</div>\n</div>\n</div>\n<script src=\"script.js\"></script>\n</body>\n</html>", getFamilyName(p), getName(p), getBirthDate(p), getBirthPlace(p), getID(f), getName(f), getID(Ff), getName(Ff), getID(Mf), getName(Mf), getID(p->mother), getName(m), getID(getFather(m)), getName(Fm), getID(Mm), getName(Mm));

    fclose(fichier);
}

void information(struct TabPerson* tab){
    // creation de la page information general
    FILE *fichier = NULL;
    fichier = fopen("information.html", "w");

    fprintf(fichier, "<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n<meta charset=\"utf-8\">\n<link href=\"style.css\" rel=\"stylesheet\">\n<title>Information</title>\n</head>\n<body>\n<header class=\"header-basic-light\">\n<img src=\"logo-isen-yncrea-BD-1.jpg\" alt=\"\">\n<nav>\n<ul>\n<li class=\"deroulant\"><a>Différente Famille &ensp;</a>\n<ul class=\"sous\">\n<li><a>Information général</a></li>\n</ul>\n</li>\n</ul>\n</nav>\n</header>\n<div class=\"containe\">\n<div class=\"row\">\n<div class=\"tree\">\n<p>Nombre de personne : %d</p><br>\n<p>Age de la personne la plus jeune : %s</p><br>\n<p>Age de la personne la plus agé : %s</p><br>\n<p>Lieu où il y a le plus de naissance : %s</p><br>\n</div>\n</div>\n</div>\n<script src=\"script.js\"></script>\n</body>\n</html>", getTabPLength(tab), getBirthDate(getYoungPerson(tab)), getBirthDate(getOldPerson(tab)), getBestPlace(tab));

    fclose(fichier);
}