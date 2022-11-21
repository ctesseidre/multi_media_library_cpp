#ifndef VHS_H
#define VHS_H

#include <iostream>
#include "string.h"
#include "Media.h"

using namespace std;

class Vhs : public Media
{
protected:
    string maison_prod;
    int duree;

public:
    Vhs();
    
    Vhs(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        
        string maison_prod_a,
        int duree_a);

    virtual string showMedia(bool b);
    void newVhs(int nb_medias);
    virtual int searchMedia(string search);

    friend ostream& operator<<(ostream& os, Vhs& vhs);
};

#endif