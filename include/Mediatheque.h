#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include "Media.h"
#include "Mediatheque.h"
#include "Utilisateur.h"
#include "Cd.h"
#include "Dvd.h"
#include "Fichier.h"
#include "Livre.h"
#include "Revue.h"
#include "Vhs.h"

using namespace std;

class Mediatheque
{
    protected:
    vector<Media *> liste_media;
    vector<Media *> liste_media_search;

    int nb_medias = 0;
    string password = "1234";
    int version;
  
    public:
    
    Mediatheque();

    string colorPrint(string color, string print);
    bool addMedia(string type);
    void addMedia(Media *m);
    bool loadFromFile(const char * path);
    bool Reload(void);
    bool saveToFile(const char * path);
    void searchMedia(string search);
    void clear(bool search);
    void borrowMedia(string id_livre, string id_client);
    void returnMedia(string id_livre, string id_client);
    void showId(string id);
    void deleteId(string id);
    Media *findMedia(string id);
    string getPassword(void);
    string showListeMedia(vector<Media *> liste, bool compact);

    //show la liste de media 
    friend ostream& operator<<(ostream& os, Mediatheque& mediatheque);

    //show la liste de media apres recherche
    friend ostream& operator<=(ostream& os, Mediatheque& mediatheque);
  
};

#endif