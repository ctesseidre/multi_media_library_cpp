#ifndef COMMANDE_H
#define COMMANDE_H

#include <iostream>
#include "Mediatheque.h"
#include "Utilisateur.h"

using namespace std;

class Commande
{

    protected :

    Mediatheque MediAVoleLOrangeDuMarche;
    Utilisateur currentUser;

    string chaine;
    string cmd;
    string argument;

    private:   

    public:

    Commande();

    string colorPrint(string color, string print);
    void colorPrintln(string color, string print);

    void clear();

    bool treatConnection();
    void treatChaine(string chaine, string &cmd, string &argument);
    void welcomeMessage();
    void selectCmd();

};

#endif