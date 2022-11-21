#include "Commande.h"

Commande::Commande(){}


string Commande::colorPrint(string color, string print){

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

void Commande::colorPrintln(string color, string print){

    string output ="";

    if (color == "RED"){
        output =  string("\033[31m") + print + string("\033[0m\n");
    }else if (color == "CYAN"){
        output = string("\033[36m") + print + string("\033[0m\n");
    }else if (color == "GREEN"){
        output = string("\033[32m") + print + string("\033[0m\n"); 
    }

    cout << output;
}

void Commande :: clear()
{
    cout << "\x1B[2J\x1B[H";
}


void Commande :: treatChaine(string chaine, string &cmd, string &argument)
{
    cmd = chaine.substr(0, chaine.find(' '));
    argument ="";

    if (chaine.size() > cmd.size()){
        argument = chaine.substr(cmd.size()+1);
    }
}

void Commande :: welcomeMessage(){

    // Affichage du menu
    clear();                                                                
    
    
    cout << endl;
    colorPrintln("CYAN","==============================================");
    colorPrintln("CYAN","Welcome to Media Vole l'orange du marche");
    cout << endl;
    colorPrintln("CYAN","Please tape \"userconnect\" \"your_id\" to connect you as a client");
    colorPrintln("CYAN","Please tape \"adminconnect\" \"password\"  (default : 1234) to connect you as an admin");
    colorPrintln("CYAN","==============================================");
    
}

void Commande :: selectCmd(){

    cout << "Mediatheque MediAVoleLOrangeDuMarche >>";

    // Détection de la commande
    getline(cin, chaine);
    treatChaine(chaine, cmd, argument);

    MediAVoleLOrangeDuMarche.Reload();

//--------------------------------------------------------------------
    if (cmd == "bye" && currentUser.getType() == "admin") {
        cout << "Save changes before closing ? y/n" << endl;
        getline(cin, chaine);
        if (chaine == "y")
        {
            MediAVoleLOrangeDuMarche.saveToFile("../save_directory/SaveMediatheque.txt");
        }
        currentUser.setType("");
        MediAVoleLOrangeDuMarche.clear(true);
        MediAVoleLOrangeDuMarche.clear(false);
        colorPrintln("GREEN","bye admin !");
        exit(EXIT_SUCCESS);
    }
//--------------------------------------------------------------------
    else if (cmd == "add" && currentUser.getType() == "admin")
    {
        if(MediAVoleLOrangeDuMarche.addMedia(argument)){
            colorPrintln("GREEN","media well add");
        }
        else{
            colorPrintln("RED","type not recognized please try again");
        }
        
    }
//--------------------------------------------------------------------
    else if (cmd == "load" && currentUser.getType() == "admin")
    {
        if (argument != "")
        {
            if (MediAVoleLOrangeDuMarche.loadFromFile(argument.data()))
            {
                colorPrintln("GREEN","file well load");
            }
            else
            {   
                colorPrintln("RED","file fail to open");
            }
        }
        else
        {
            if (MediAVoleLOrangeDuMarche.loadFromFile("../save_directory/Mediatheque.txt"))
            {
                colorPrintln("GREEN","file well load");
            }
            else
            {
                colorPrintln("RED","file fail to open");  
            }
        }
    }
//--------------------------------------------------------------------
    else if (cmd == "save" && currentUser.getType() == "admin")
    {

        if (argument != "")
        {
            if (MediAVoleLOrangeDuMarche.saveToFile(argument.data()))
            {
                colorPrintln("GREEN","file well save");
            }
            else
            {
                colorPrintln("RED","file fail to save");
            }
        }
        else
        {
            if (MediAVoleLOrangeDuMarche.saveToFile("../save_directory/Mediatheque.txt"))
            {
                colorPrintln("GREEN","file well save");
            }
            else
            {
                colorPrintln("RED","file fail to save");
            }
        }
    }
//--------------------------------------------------------------------
    else if (cmd == "delete" && currentUser.getType() == "admin")
    {
        if (argument != ""){
        MediAVoleLOrangeDuMarche.deleteId(argument);     
        }
        else {
            colorPrintln("RED","please enter an ID");
        }
    }            
//--------------------------------------------------------------------
    else if (cmd == "bye" && currentUser.getType() == "client") {
        currentUser.setType("");
        MediAVoleLOrangeDuMarche.clear(true);
        MediAVoleLOrangeDuMarche.clear(false);
        colorPrintln("GREEN","bye " + currentUser.getId() +" !");
        exit(EXIT_SUCCESS);
    } 
//--------------------------------------------------------------------  
    else if (cmd == "search")
    {
        MediAVoleLOrangeDuMarche.searchMedia(argument);
    }
//--------------------------------------------------------------------
    else if (cmd == "list")
    {
        cout <= MediAVoleLOrangeDuMarche;
    }
//--------------------------------------------------------------------
    else if (cmd == "show")
    {
        if (argument != "")
        {
            MediAVoleLOrangeDuMarche.showId(argument);
        }
        else
        {
            cout << MediAVoleLOrangeDuMarche;
        }
    }
//--------------------------------------------------------------------
    else if (cmd == "clear")
    {
        MediAVoleLOrangeDuMarche.clear(true);
    }  

//--------------------------------------------------------------------
    else if (cmd == "reset")
    {
        MediAVoleLOrangeDuMarche.clear(false);
    } 

//--------------------------------------------------------------------
    else if (cmd == "borrow")
    {
        if (argument != "")
        {
            MediAVoleLOrangeDuMarche.borrowMedia(argument,currentUser.getId());
            MediAVoleLOrangeDuMarche.saveToFile("../save_directory/Mediatheque.txt");
        }
        else
        {
            colorPrintln("RED","Please enter a Medai id");
        }
       
    } 
//--------------------------------------------------------------------
    else if (cmd == "return")
    {

        if (argument != "")
        {
            MediAVoleLOrangeDuMarche.returnMedia(argument,currentUser.getId());
            MediAVoleLOrangeDuMarche.saveToFile("../save_directory/Mediatheque.txt");
        }
        else
        {
            colorPrintln("RED","Please enter a Medai id");
        }
    } 
//--------------------------------------------------------------------          
    else if (cmd == "?")
    {
        currentUser.showMan();
    }
//--------------------------------------------------------------------
    else if (cmd == "clean")
    {
        clear();
    }
//--------------------------------------------------------------------
    else
    {
        colorPrintln("RED","Command not found please try again or tape '?' to read the the help");
    }            
}

bool Commande :: treatConnection (){

    cout << "Mediatheque MediAVoleLOrangeDuMarche >>";

    // Détection de la commande
    getline(cin, chaine);
    treatChaine(chaine, cmd, argument);

    if (cmd == "adminconnect")
    {
        if (argument == MediAVoleLOrangeDuMarche.getPassword()){
            colorPrintln("GREEN","Welcome admin !");
            currentUser.setType("admin");
            currentUser.setId("admin");
            return true;
        }
        else {
            colorPrintln("RED","Wrong passeword, try again");
        }
    }
    else if (cmd == "userconnect"){
        if (argument != ""){
            if (MediAVoleLOrangeDuMarche.loadFromFile("../save_directory/Mediatheque.txt"))
            {
                colorPrintln("GREEN","Welcome client :" + argument);
                currentUser.setType("client"); 
                currentUser.setId(argument);
                return true;
            }
            else
            {
                colorPrintln("RED","file fail to open");
            }            
        }
        else{
            colorPrintln("RED","please enter your Id");
        }
    }
    else if (cmd == "bye"){
        MediAVoleLOrangeDuMarche.clear(true);
        MediAVoleLOrangeDuMarche.clear(false);
        colorPrintln("GREEN","bye" + currentUser.getId() + " !");
        exit(EXIT_SUCCESS);
    }
    else if (cmd == "clean")
    {
        clear();
    }
    else
    {
        colorPrintln("GREEN","Command not found please try again");
    }   

    return false;         
}
