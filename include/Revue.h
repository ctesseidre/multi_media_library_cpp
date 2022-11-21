#ifndef REVUE_H
#define REVUE_H

#include <iostream>
#include <map>
#include "string.h"
#include "Livre.h"

using namespace std;

class Revue : public Livre
{
protected:
    string editeur;
    int nb_articles;
    map<string ,string> liste_article;

public:
    Revue();
    
    Revue(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        int annee_pub_a,
        int nb_pages_a,
        string collection_a,
        string resume_a,
        string editeur_a,
        int nb_articles_a,
        map<string, string> liste_article_a);

    string showMedia(bool b);
    void newRevue(int nb_medias);
    int searchMedia(string search);

    friend ostream& operator<<(ostream& os, Revue& revue);

};

#endif