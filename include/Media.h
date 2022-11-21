#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <cctype>
#include <fstream> 
#include <string.h>

using namespace std;

class Media
{

    protected :

    string titre;
    string auteur;
    string status;
    string type;
    int id;

    private:   

    public:

    Media();

    Media(
        string titre_a,
        string auteur_a,
        string status_a,
        string type_a,
        int id_a);


    bool isNumber(const string& str);
    string getType();
    int getId(); 
    string getStatus();
    void newMedia();
    virtual string showMedia(bool b);
    string colorPrint(string color, string print);
    virtual int searchMedia(string search);
    void changeMediaStatus(string new_status,string id_client);

    friend ostream& operator<<(ostream& os, Media& media);
};

#endif