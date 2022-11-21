#include "Vhs.h"

Vhs::Vhs(){}

Vhs::Vhs(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        string maison_prod_a,
        int duree_a)

        : Media(
            titre_a,
            auteur_a,
            status_a,
            type_a,
            nb_medias_a)
{
    maison_prod = maison_prod_a;
    duree = duree_a;
}

string Vhs::showMedia(bool b)
{
    string output;

    if (b){
        output = Media::showMedia(true)
        + string("Maison production : ") + maison_prod + string("\n")
        + string("Duree : ") + to_string(duree) + string("\n");
    }
    else{
        output = Media::showMedia(false)
        + maison_prod + string("\n")
        + to_string(duree) + string("\n");
    }
    return output;
}

void Vhs::newVhs(int nb_medias){
    string chaine;
    this->newMedia();
    this->type = "Vhs";
    this->id = nb_medias;

    cout << "Entrez la maison de disque de la Vhs :" << endl;
    getline(cin, this->maison_prod);

    cout << "Entrez la duree de la Vhs (int) :" << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->duree = stoi(chaine);
}

int Vhs::searchMedia(string search){
    int found = 0;
    
    found = Media::searchMedia(search);

    if (maison_prod.find(search) != string::npos){
        found ++;
    }
    return found ;
}


ostream& operator<<(ostream& os, Vhs& vhs)
{
    os  <<  vhs.colorPrint("CYAN",vhs.showMedia(true));
    return os;
}