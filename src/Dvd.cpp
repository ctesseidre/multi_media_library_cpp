#include "Dvd.h"

Dvd::Dvd(){}

Dvd::Dvd(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias,
        string maison_prod_a,
        int duree_a,
        int nb_pistes_a)

        : Vhs(
            titre_a,
            auteur_a,
            status_a,
            type_a,
            nb_medias,
            maison_prod_a,
            duree_a)
{
    nb_pistes = nb_pistes_a;
}

string Dvd::showMedia(bool b)
{
    string output;

    if (b){
        output = Media::showMedia(true)
        + string("Maison de production : ") + maison_prod+ string("\n")
        + string("Duree : ") + to_string(duree) + string("\n")
        + string("Nombre de pistes : ") + to_string(nb_pistes) + string("\n");
    }    
    else{
        output = Media::showMedia(false)
        + maison_prod + string("\n")
        + to_string(duree) + string("\n")
        + to_string(nb_pistes) + string("\n");
    }

    return output;
}

void Dvd::newDvd(int nb_medias){
    string chaine;

    this->newVhs(nb_medias);

    this->type = "Dvd";
    this->id = nb_medias;

    cout << "Entrez le nombre de pistes du Dvd (int) :" << endl;
    getline(cin, chaine);
        while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->nb_pistes = stoi(chaine);
}

int Dvd::searchMedia(string search){
    int found = 0;
    
    found = Vhs::searchMedia(search);

    return found ;
}

ostream& operator<<(ostream& os, Dvd& dvd)
{
    os  <<  dvd.colorPrint("CYAN",dvd.showMedia(true));
    return os;
}