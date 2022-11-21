#include "Livre.h"

Livre::Livre(){}

Livre::Livre(
            string titre_a,
            string auteur_a,
            string status_a,
            string type_a,
            int nb_medias_a,
            int annee_pub_a,
            int nb_pages_a,
            string collection_a,
            string resume_a)

            : Media(
                titre_a,
                auteur_a,
                status_a,
                type_a,
                nb_medias_a)
{
    annee_pub = annee_pub_a;
    nb_pages = nb_pages_a;
    collection = collection_a;
    resume = resume_a;
}

string Livre::showMedia(bool b)
{
    string output;

    if (b){
        output = Media::showMedia(true)
                + string("Annee publication : ") + to_string(annee_pub) + string("\n")
                + string("Nombre de page : ") + to_string(nb_pages) + string("\n")
                + string("Collection : ") + collection + string("\n")
                + string("Resume : ") + resume + string("\n");
    }
    else{
        output = Media::showMedia(false)
        + to_string(annee_pub) + string("\n")
        + to_string(nb_pages) + string("\n")
        + collection + string("\n")
        + resume + string("\n");

    }
 

    return output;
}

void Livre::newLivre(int nb_medias){
    string chaine;
    this->newMedia();
    this->type = "Livre";
    this->id = nb_medias;

    cout << "Entrez l'année de publication du livre : " << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->annee_pub = stoi(chaine);

    cout << "Entrez le nombre de pages du livre : " << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->nb_pages = stoi(chaine);

    cout << "Entrez la collection du livre : " << endl;
    getline(cin, this->collection);

    cout << "Entrez le résumé du livre : " << endl;
    getline(cin, this->resume);
}

int Livre::searchMedia(string search){
    int found = 0;
    
    found = Media::searchMedia(search);

    if (collection.find(search) != string::npos){
        found ++;
    }

    if (resume.find(search) != string::npos){
        found ++;
    }

    return found ;
}

ostream& operator<<(ostream& os, Livre& livre)
{
    os  <<  livre.colorPrint("CYAN",livre.showMedia(true));
    return os;
}