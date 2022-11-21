#include "Fichier.h"

Fichier::Fichier(){}

Fichier::Fichier(
            string titre_a,
            string auteur_a,
            string status_a,
            string type_a,
            int nb_medias_a,
            string fileType_a,
            int taille_a,
            string url_a)

            : Media(
                titre_a,
                auteur_a,
                status_a,
                type_a,
                nb_medias_a)
{
    fileType = fileType_a;
    taille = taille_a;
    url = url_a;
}
string Fichier::showMedia(bool b)
{
    string output;

    if (b){
        output = Media::showMedia(true)
        + string("Type de fichier : ") + fileType + string("\n")
        + string("Taille : ") + to_string(taille) + string("\n")
        + string("URL : ") + url + string("\n");
    }
    else{
        output = Media::showMedia(false)
        + fileType + string("\n")
        + to_string(taille) + string("\n")
        + url + string("\n");
    }

    return output;
}

void Fichier::newFichier(int nb_medias){
    string chaine;
    this->newMedia();
    this->type = "Fichier";
    this->id = nb_medias;

    cout << "Entrez le type de fichier :" << endl;
    getline(cin, this->fileType);

    cout << "Entrez la taille (int) :" << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->taille = stoi(chaine);

    cout << "Entrez le lien de fichier :" << endl;
    getline(cin, this->url);
}

int Fichier::searchMedia(string search){
    int found = 0;
    
    found = Media::searchMedia(search);

    if (fileType.find(search) != string::npos){
        found ++;
    }

    if (url.find(search) != string::npos){
        found ++;
    }
    
    return found ;
}

ostream& operator<<(ostream& os, Fichier& fichier)
{
    os  <<  fichier.colorPrint("CYAN",fichier.showMedia(true));
    return os;
}