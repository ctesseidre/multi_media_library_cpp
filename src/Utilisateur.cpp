#include "Utilisateur.h"

Utilisateur::Utilisateur()
{
    type = "";
}

void Utilisateur::setType(string type_a){
    type = type_a;
}

void Utilisateur::setId(string id_a){
    id = id_a;
}

string Utilisateur::getType(){
    return type;
}

string Utilisateur::getId(){
    return id;
}

bool Utilisateur :: showMan(){
    
    string line;
    string output;
    string path;

    if (type == "admin"){
        path = "../save_directory/man_admin.txt";
    }
    else{
        path = "../save_directory/man_client.txt";
    }

    ifstream myfile(path, ifstream::in);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            output = output + line +" \n";
        }
        myfile.close();
    }
    else
    {
        return false;
    }
    cout << output << endl;
    return true;
}


