#ifndef CD_H
#define CD_H

#include <iostream>
#include "string.h"
#include "Media.h"

using namespace std;

class Cd : public Media
{
protected:
    string maison_prod;
    int nb_pistes;
    int duree; 

public:
    Cd();
    
    Cd(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        
        string maison_prod_a,
        int nb_pistes_a,
        int duree_a);

    string showMedia(bool b);
    void newCd(int nb_medias);
    int searchMedia(string search);

    friend ostream& operator<<(ostream& os, Cd& cd);

};

#endif