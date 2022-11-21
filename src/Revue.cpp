#include "Revue.h"

Revue::Revue(){}

Revue::Revue(
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
            map<string, string> liste_article_a)

            : Livre(
                titre_a,
                auteur_a,
                status_a,
                type_a,
                nb_medias_a,
                annee_pub_a,
                nb_pages_a,
                collection_a,
                resume_a)
{
    editeur = editeur_a;
    nb_articles = nb_articles_a;
    liste_article = liste_article_a;
}

string Revue::showMedia(bool b)
{
    
    string output;

    string liste_revue_string_true = string("");
    string liste_revue_string_false = string("");

    for (auto article: liste_article) {
        liste_revue_string_true = liste_revue_string_true + string("article n") + article.first + string(" : ") + article.second + string("\n");
        liste_revue_string_false = liste_revue_string_false + article.first + string("[") + article.second + string("]\n");
    }

    if (b){
        output = Livre::showMedia(true)
                + string("Editeur : ") + editeur + string("\n")
                + string("Nombre de d'articles : ") + to_string(nb_articles) + string("\n")
                + liste_revue_string_true;
    }
    else{
        output = Livre::showMedia(false)
        + editeur + string("\n")
        + to_string(nb_articles) + string("\n")
        + liste_revue_string_false;
    }
 

    return output;
}

void Revue::newRevue(int nb_medias){
    string chaine;

    this->newLivre(nb_medias);
    this->type = "Revue";
    this->id = nb_medias;
    cout << "Entrez l'éditeur de la revue :" << endl;
    getline(cin, this->editeur);

    cout << "Entrez le nombre d'articles de la revue :" << endl;
    getline(cin, chaine);
    while(isNumber(chaine) != true){
        cout << colorPrint("RED","enter a number please \n");
        getline(cin, chaine);
    }
    this->nb_articles = stoi(chaine);

    for (int i = 0; i<this->nb_articles; i++) {
        cout << "Entrez le nom de l'article n° :" << to_string(i) << endl;
        getline(cin, chaine);

        if (i<10){
            liste_article["A00" + to_string(i)] = chaine;
        }
        else if ( i < 100){
            liste_article["A0" + to_string(i)] = chaine;
        }
        else{
             liste_article["A" + to_string(i)] = chaine;
        }
        
    }
}

int Revue::searchMedia(string search){
    int found = 0;
    
    found = Livre::searchMedia(search);

    if (editeur.find(search) != string::npos){
        found ++;
    }

    for (auto article: liste_article) {
        if (article.first.find(search) != string::npos){
            found ++;
        } 
        if (article.second.find(search) != string::npos){
            found ++;
        }
    }
    return found ;
}

ostream& operator<<(ostream& os, Revue& revue)
{
    os  << revue.colorPrint("CYAN",revue.showMedia(true));
    return os;
}
