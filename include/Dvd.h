#ifndef DVD_H
#define DVD_H

#include <iostream>
#include "string.h"
#include "Vhs.h"

using namespace std;

class Dvd : public Vhs
{
protected:
    int nb_pistes;



public:
    Dvd();
    
    Dvd(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        string maison_prod_a,
        int duree_a,
        int nb_pistes_a);

    string showMedia(bool b); 
    void newDvd(int nb_medias);
    int searchMedia(string search);

    friend ostream& operator<<(ostream& os, Dvd& dvd);
};

#endif