#include "Cd.h"

Cd::Cd(){}

Cd::Cd(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int nb_medias_a,
        string maison_prod_a,
        int nb_pistes_a,
        int duree_a)

        : Media(
            titre_a,
            auteur_a,
            status_a,
            type_a,
            nb_medias_a)
{
    maison_prod = maison_prod_a;
    nb_pistes = nb_pistes_a;
    duree = duree_a;
}

string Cd::showMedia(bool b)
{
    string output;

    if (b){
        output = Media::showMedia(true)
            + string("Maison publication : ") + maison_prod + string("\n")
            + string("Nombre de piste : ") + to_string(nb_pistes) + string("\n")
            + string("Duree : ") + to_string(duree) + string("\n");
    }
    else{
        output = Media::showMedia(false)
        + maison_prod + string("\n")
        + to_string(nb_pistes) + string("\n")
        + to_string(duree) + string("\n");
    
    }

    return output;
}

void Cd::newCd(int nb_medias){
    string chaine;
    this->newMedia();
    this->type = "Cd";
    this->id = nb_medias;

    cout << "Entrez la maison de disque du Cd :" << endl;
    getline(cin, this->maison_prod);

    cout << "Entrez le nombre de pistes du Cd :" << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->nb_pistes = stoi(chaine);

    cout << "Entrez la duree du Cd :" << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
        this->duree = stoi(chaine);   
}

int Cd::searchMedia(string search){
    int found = 0;
    
    found = Media::searchMedia(search);

    if (maison_prod.find(search) != string::npos){
        found ++;
    }
    return found ;
}

ostream& operator<<(ostream& os, Cd& cd)
{
    os  <<  cd.colorPrint("CYAN",cd.showMedia(true));
    return os;
}