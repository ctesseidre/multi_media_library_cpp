#include <iostream>
#include "Commande.h"

int main(int argc, char *argv[])
{
    //declaration objet
    Commande terminal_commande;
    terminal_commande.welcomeMessage();
    bool connection = false ;

    // Interface utilsateur
    do
    {
        connection = terminal_commande.treatConnection();

    }while(connection == false);

    do
    {
        terminal_commande.selectCmd();
    
    }while(1);    

    return 0;
}
