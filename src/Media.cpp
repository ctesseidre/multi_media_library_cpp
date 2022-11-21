#include "Media.h"

Media::Media(){}

Media::Media(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int id_a)
{    
    titre = titre_a;
    auteur = auteur_a;
    status = status_a;
    type = type_a;
    id =id_a;
}

bool Media :: isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

string Media::getType(void){
    return type;
}

int Media::getId(void){
    return id;
}

string Media::getStatus(void){
    return status;
}

void Media::newMedia(){
    cout << "Entrez le titre du media : " << endl;
    getline(cin, this->titre);

    cout << "Entrez l'auteur du media : " << endl;
    getline(cin, this->auteur);
    
    this->status = "DISPONIBLE";
}

string Media::showMedia(bool b){
 
    string output;

    if (b){
        output  = string("\n")
                + string("==============================") + string("\n")
                + string("Titre : ") + titre + string("\n")
                + string("Auteur : ") + auteur + string("\n")
                + string("Status : ") + status + string("\n")
                + string("Type : ") + type + string("\n")
                + string("ID : ") + to_string(id) + string("\n");

    }
    else {
        output  = string("\n")
            + titre + string("\n")
            + auteur + string("\n")
            + status + string("\n")
            + type + string("\n")
            + to_string(id) + string("\n");
    }

    return output;
}

int Media::searchMedia(string search){
    int found = 0;

    if (titre.find(search) != string::npos){
        found ++;
    }
    if (auteur.find(search) != string::npos){
        found ++;
    }
    if (status.find(search) != string::npos){
        found ++;
    }
    if (type.find(search) != string::npos){
        found ++;
    }    

    return found;
}

void Media :: changeMediaStatus(string new_status, string id_client){

    if (new_status == "DISPONIBLE"){
        this->status = string("DISPONIBLE");

    }else if (new_status == "EMPRUNTE"){  
        this->status = string("EMPRUNTE ") + string(":") + id_client;

    }
}

string Media::colorPrint(string color, string print){

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

ostream& operator<<(ostream& os, Media& media)
{
    os  << media.colorPrint("CYAN",media.showMedia(true));
    return os;
}