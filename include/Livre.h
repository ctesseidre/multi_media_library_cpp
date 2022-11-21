#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include "string.h"
#include "Media.h"

using namespace std;

class Livre : public Media
{
protected:
    int annee_pub;
    int nb_pages;
    string collection;
    string resume;
   
public:
    Livre();

    Livre(
        string titre_a, 
        string auteur_a, 
        string status_a, 
        string type_a, 
        int nb_medias_a,
        int annee_pub_a,
        int nb_pages_a,
        string collection_a,
        string resume_a);
        
    virtual string showMedia(bool b);    
    void newLivre(int nb_medias);
    virtual int searchMedia(string search);

    friend ostream& operator<<(ostream& os, Livre& livre);

};

#endif