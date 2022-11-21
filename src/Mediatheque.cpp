#include "Mediatheque.h"

Mediatheque::Mediatheque()
{
}

bool Mediatheque::addMedia(string type)
{
    nb_medias = liste_media.back()->getId();

    if (type == "Livre")
    {
        Livre *livre = new Livre();
        nb_medias += 1;
        livre->newLivre(nb_medias);
        liste_media.push_back(livre);
    }
    else if (type == "Revue")
    {
        Revue *revue = new Revue();
        nb_medias += 1;
        revue->newRevue(nb_medias);
        liste_media.push_back(revue);
    }
    else if (type == "Cd")
    {
        Cd *cd = new Cd();
        nb_medias += 1;
        cd->newCd(nb_medias);
        liste_media.push_back(cd);
    }
    else if (type == "Vhs")
    {
        Vhs *vhs = new Vhs();
        nb_medias += 1;
        vhs->newVhs(nb_medias);
        liste_media.push_back(vhs);
    }
    else if (type == "Dvd")
    {
        Dvd *dvd = new Dvd();
        nb_medias += 1;
        dvd->newDvd(nb_medias);
        liste_media.push_back(dvd);
    }
    else if (type == "Fichier")
    {
        Fichier *fichier = new Fichier();
        nb_medias += 1;
        fichier->newFichier(nb_medias);
        liste_media.push_back(fichier);
    }
    else {
        return false;
    }

    return true;
}

void Mediatheque::addMedia(Media *m)
{
    liste_media.push_back(m);
}

Media * Mediatheque::findMedia(string id){

    int id_int = stoi(id);
    Media * m = NULL;

    for(int i = 0; i<liste_media.size(); i++)
    {
        if(liste_media.at(i)->getId() == id_int)
        {
            m = liste_media.at(i);
        }
    }
    return m;
}

void Mediatheque::borrowMedia(string id_livre, string id_client)
{
    Media * m = this->findMedia(id_livre);

    if (m != NULL){
        if (m->getStatus() == "DISPONIBLE"){
            m->changeMediaStatus("EMPRUNTE",id_client);
        }
        else{
            cout << colorPrint("RED" ,"You can't boorow Media already borrow") << endl;
        }
    }
    else{
        cout << colorPrint("RED" ,"Wrong id please try a right id ") << endl;
    }    
}

void Mediatheque::returnMedia(string id_livre, string id_client)
{
    Media * m = this->findMedia(id_livre);
    string id_borrower = m->getStatus().substr(m->getStatus().find(':')+1);

    if (m != NULL){
        if (id_borrower == id_client){
            m->changeMediaStatus("DISPONIBLE",id_client);
        }
        else {
            cout <<  colorPrint("RED" , "you can't return a media you do not borrow") << endl;
        }
    }
    else{
        cout <<  colorPrint("RED" ,"Wrong id please try a right id") << endl;
    } 
   
}

bool Mediatheque::Reload(){

    const char *path = "../save_directory/Mediatheque.txt";
    string version;
    bool return_value;

    ifstream myfile(path, ifstream::in);

    if (myfile.is_open())
    {
        getline(myfile, version);
        return_value = true ;
    }
    myfile.close();

    if (stoi(version) != this->version){
        this->clear(false);
        return_value = loadFromFile(path);
    }
    
    return return_value;
}


bool Mediatheque::loadFromFile(const char *path)
{
    string version = "";
    string vide = "";
    string titre = "";
    string auteur = "";
    string status = "";
    string type = "";
    string id = "";

    ifstream myfile(path, ifstream::in);

    if (myfile.is_open())
    {

        getline(myfile, version);
        this->version = stoi(version);

        while (getline(myfile, vide))
        {
            getline(myfile, titre);
            getline(myfile, auteur);
            getline(myfile, status);
            getline(myfile, type);
            getline(myfile, id);

            if (type == "Livre")
            {
                string annee_pub;
                string nb_pages;
                string collection;
                string resume;

                getline(myfile, annee_pub);
                getline(myfile, nb_pages);
                getline(myfile, collection);
                getline(myfile, resume);

                Livre *livre = new Livre(titre, auteur, status, type, stoi(id), stoi(annee_pub), stoi(nb_pages), collection, resume);
                this->addMedia(livre);
            }
            else if (type == "Revue")
            {
                string annee_pub;
                string nb_pages;
                string collection;
                string resume;
                string editeur;
                string nb_articles;
                map<string, string> liste_article;

                getline(myfile, annee_pub);
                getline(myfile, nb_pages);
                getline(myfile, collection);
                getline(myfile, resume);
                getline(myfile, editeur);
                getline(myfile, nb_articles);

                for (int i = 0; i < stoi(nb_articles); i++)
                {
                    string line;
                    string cle;
                    string article;

                    getline(myfile, line);
                    cle = line.substr(0, 4);
                    article = line.substr(5, line.size() - 6);

                    liste_article[cle] = article;
                }

                Revue *revue = new Revue(titre, auteur, status, type, stoi(id), stoi(annee_pub), stoi(nb_pages), collection, resume, editeur, stoi(nb_articles), liste_article);
                this->addMedia(revue);
            }
            else if (type.substr(0, 2) == "Cd")
            {
                type = type.substr(0, 2);

                string maison_prod;
                string nb_pistes;
                string duree;

                getline(myfile, maison_prod);
                getline(myfile, nb_pistes);
                getline(myfile, duree);

                Cd *cd = new Cd(titre, auteur, status, type, stoi(id), maison_prod, stoi(nb_pistes), stoi(duree));
                this->addMedia(cd);
            }
            else if (type.substr(0, 3) == "Vhs")
            {
                type = type.substr(0, 3);

                string maison_prod;
                string duree;

                getline(myfile, maison_prod);
                getline(myfile, duree);

                Vhs *vhs = new Vhs(titre, auteur, status, type, stoi(id), maison_prod, stoi(duree));
                this->addMedia(vhs);
            }
            else if (type == "Fichier")
            {

                string fileType;
                string taille;
                string url;

                getline(myfile, fileType);
                getline(myfile, taille);
                getline(myfile, url);

                Fichier *fichier = new Fichier(titre, auteur, status, type,stoi(id), fileType, stoi(taille), url);
                this->addMedia(fichier);
            }
            else if (type == "Dvd")
            {
                string maison_prod;
                string duree;
                string nb_pistes;

                getline(myfile, maison_prod);
                getline(myfile, duree);
                getline(myfile, nb_pistes);

                Dvd *dvd = new Dvd(titre, auteur, status, type, stoi(id), maison_prod, stoi(duree), stoi(nb_pistes));
                this->addMedia(dvd);
            }
            else
            {
                cout << colorPrint("RED" ,"type of Media load not recognized") << endl;
                break;
            }
        }

        myfile.close();
    }
    else
    {
        return false;
    }
    return true;
}

// sauvegarfe la liste de media dans le dossier spécifié en argument
// path : chemin du dossier ou sauvegarder la liste de media
bool Mediatheque::saveToFile(const char *path)
{

    string buffer = string("");

    version ++;

    for (int i = 0; i < liste_media.size(); i++)
    {
        buffer = buffer + liste_media.at(i)->showMedia(false);
    }

    ofstream myfile(path, ofstream::out);

    if (myfile.is_open())
    {
        myfile << version << endl;
        myfile << buffer;

        myfile.close();
    }
    else
    {
        return false;
    }
    return true;
}

void Mediatheque::searchMedia(string search)
{

    int nb_found = 0;

    vector<Media *> liste_media_to_search;
    vector<Media *> liste_media_search_temp;

    if (liste_media_search.size() > 0)
    {
        liste_media_to_search = liste_media_search;
    }
    else
    {
        liste_media_to_search = liste_media;
    }

    for (int i = 0; i < liste_media_to_search.size(); i++)
    {
        Media *m = liste_media_to_search.at(i);
        int found = 0;

        if (m->getType() == "Cd")
        {
            Cd *cd = dynamic_cast<Cd *>(m);
            if (cd->searchMedia(search) > 0)
            {
                liste_media_search_temp.push_back(cd);
                nb_found++;
            }
        }
        else if (m->getType() == "Dvd")
        {
            Dvd *dvd = dynamic_cast<Dvd *>(m);
            if (dvd->searchMedia(search) > 0)
            {
                liste_media_search_temp.push_back(dvd);
                nb_found++;
            }
        }
        else if (m->getType() == "Fichier")
        {
            Fichier *fichier = dynamic_cast<Fichier *>(m);
            if (fichier->searchMedia(search) > 0)
            {
                liste_media_search_temp.push_back(fichier);
                nb_found++;
            }
        }
        else if (m->getType() == "Livre")
        {
            Livre *livre = dynamic_cast<Livre *>(m);
            if (livre->searchMedia(search) > 0)
            {
                liste_media_search_temp.push_back(livre);
                nb_found++;
            }
        }
        else if (m->getType() == "Revue")
        {
            Revue *revue = dynamic_cast<Revue *>(m);
            if (revue->searchMedia(search) > 0)
            {
                liste_media_search_temp.push_back(revue);
                nb_found++;
            }
        }
        else if (m->getType() == "Vhs")
        {
            Vhs *vhs = dynamic_cast<Vhs *>(m);
            if (vhs->searchMedia(search) > 0)
            {
                liste_media_search_temp.push_back(vhs);
                nb_found++;
            }
        }
        else
        {
            cout << colorPrint("RED" ,"type search not recognized") << endl;
        }
    }

    if (nb_found > 0)
    {
        liste_media_search = liste_media_search_temp;
    }
    else
    {
        cout << colorPrint("RED" , "\"" + search + "\""
              + " not found in any Media") << endl;
    }
}

string Mediatheque::showListeMedia(vector<Media *> liste, bool compact)
{

    string output = "";

    for (int i = 0; i < liste.size(); i++)
    {
        Media *m = liste.at(i);
        if (compact)
        {
            output = output + m->Media::showMedia(true);
        }
        else
        {

            if (m->getType() == "Cd")
            {
                Cd *cd = dynamic_cast<Cd *>(m);
                output = output + cd->showMedia(true);
            }
            else if (m->getType() == "Dvd")
            {
                Dvd *dvd = dynamic_cast<Dvd *>(m);
                output = output + dvd->showMedia(true);
            }
            else if (m->getType() == "Fichier")
            {
                Fichier *fichier = dynamic_cast<Fichier *>(m);
                output = output + fichier->showMedia(true);
            }
            else if (m->getType() == "Livre")
            {
                Livre *livre = dynamic_cast<Livre *>(m);
                output = output + livre->showMedia(true);
            }
            else if (m->getType() == "Revue")
            {
                Revue *revue = dynamic_cast<Revue *>(m);
                output = output + revue->showMedia(true);
            }
            else if (m->getType() == "Vhs")
            {
                Vhs *vhs = dynamic_cast<Vhs *>(m);
                output = output + vhs->showMedia(true);
            }
            else
            {
                cout << colorPrint("RED","type not recognized") << endl;
            }
        }
    }

    return output;
}

void Mediatheque::clear(bool search)
{
    if (search == true)
    {
        if (liste_media_search.size() > 0)
        {
            liste_media_search.erase(liste_media_search.begin(), liste_media_search.end());
        }
    }
    else
    {
        if (liste_media.size() > 0)
        {
            liste_media.erase(liste_media.begin(), liste_media.end());
        }
    }
}

void Mediatheque::showId(string ID){

    int id = stoi(ID);

    for(int i = 0; i<liste_media.size(); i++)
    {
        if(liste_media.at(i)->getId() == id)
        {
            cout << *liste_media.at(i);
        }
    }
}

void Mediatheque::deleteId(string ID){

    int id = stoi(ID);
    
    for(int i = 0; i<liste_media.size(); i++)
    {
        if(liste_media.at(i)->getId() == id)
        {
            auto elem_to_remove = liste_media.begin() + i;
            liste_media.erase(elem_to_remove);
        }
    }
}

string Mediatheque::getPassword(){
    return password;
}

string Mediatheque::colorPrint(string color, string print){

    string output ="";

    if (color == "RED"){
        output =  string("\033[31m") + print + string("\033[0m");
    }else if (color == "CYAN"){
        output = string("\033[36m") + print + string("\033[0m");
    }else if (color == "GREEN"){
        output = string("\033[32m") + print + string("\033[0m"); 
    }
    return output;
}

// surcharge de l'operateur << pour qu'il affiche le contenu de chaque media de la liste de media
ostream &operator<<(ostream &os, Mediatheque &mediatheque)
{
    os << mediatheque.colorPrint("CYAN",mediatheque.showListeMedia(mediatheque.liste_media, false));
    return os;
}

// surcharge de l'operateur << pour qu'il affiche le contenu de chaque media de la liste de media
ostream &operator<=(ostream &os, Mediatheque &mediatheque)
{
    os << mediatheque.colorPrint("CYAN" ,mediatheque.showListeMedia(mediatheque.liste_media_search, true));
    return os;
}
