#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include "string.h"
#include "Media.h"

using namespace std;

class Fichier : public Media
{
protected:
    string fileType;
    int taille;
    string url;

public:
    Fichier();
    
    Fichier(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        string fileType_a,
        int taille_a,
        string url_a);

    string showMedia(bool b); 
    void newFichier(int nb_medias);
    int searchMedia(string search);

    friend ostream& operator<<(ostream& os, Fichier& fichier);
};

#endif