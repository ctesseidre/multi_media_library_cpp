#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <iostream>
#include <string.h>
#include "Media.h"
#include "Cd.h"
#include "Dvd.h"
#include "Fichier.h"
#include "Livre.h"
#include "Revue.h"
#include "Vhs.h"

using namespace std;

class Utilisateur
{
    private:

    string type;
    string id;

    public:

    Utilisateur();
    bool showMan();
    void selectCmd();
    string getType();
    string getId();
    void setType(string type_a);
    void setId(string id_a);
};

#endif