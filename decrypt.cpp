#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encKey = ""; 
string file = "encryptedFile.txt";

ifstream FileBeol;
ofstream FileKi;

bool megtalalva = false;

string XORdecryption(string sor){
    int inkey=0;
    //végig megy a sor elemein
    for(int i=0; i < sor.length();i++){   
        //kulcs elemein végig megy 
        if(inkey == encKey.length()){
            //vissza az elejére
            inkey=0;
        }
        sor[i] = char(sor[i] ^ encKey[inkey]) ;
        // Vissza fejtéshez csak egy második XoR kell
        //sor[i] = char(char(sor[i] ^ encKey[inkey]) ^ encKey[inkey]) ;
        inkey++;
    }
    return sor;
}


bool tores_check(string kulcs){
    ifstream egysor;
    egysor.open("encryptedFile.txt");
    string sor = "";
    getline(egysor, sor);
    XORdecryption(sor);
    if (XORdecryption(sor).substr(0,4) == "Szem")
    {
        cout << kulcs << " Jó!" << XORdecryption(sor);
        return true;
    }
    else{
        return false;
    }
    egysor.close();
}

void beolvas(){
    string sor = "";
    FileBeol.open(file);
    FileKi.open("decryptedFile.txt");
    while(getline(FileBeol, sor))
    {
        FileKi << XORdecryption(sor) << "\n";
    }
    FileBeol.close();
    FileKi.close();
}

void exor_tores(int hossz){
    hossz = 3;
    int kulcs = 0;
    while(!megtalalva && kulcs < 1000){
        kulcs++;
        if(kulcs < 10){
            encKey = "00"+to_string(kulcs);
        } else if(kulcs < 100){
            encKey = "0"+to_string(kulcs);
        }else{
            encKey = to_string(kulcs);
        }
        //cout << kulcs << " ";
        megtalalva = tores_check(encKey);
    }
    beolvas();
}

int main(){
    exor_tores(3);
    beolvas();
    return 0;
}