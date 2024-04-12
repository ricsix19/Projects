#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string file = "menhely.txt";

struct Allat{
    string fajta;
    string nev;
    int kor;
    string szin;
};

vector<Allat> allatv; 

ifstream& operator>>(ifstream &i, Allat& a){
    i >> a.fajta;
    i >> a.nev;
    i >> a.kor;
    i >> a.szin;
    return i;
}

ostream& operator<<(ostream& o, Allat& a){
    o << a.fajta << " " << a.nev << " " << a.kor << " " << a.szin << " " << endl;
    return o;
}

void beolvas(){
    Allat allatolv;
    ifstream inFile(file);

    while (inFile >> allatolv)
    {
        allatv.push_back(allatolv);
    }
    /*
    for(Allat a: allatv){
        cout << a;
    }
    */
    inFile.close();
}

void keres(){
    string keres;
    string faj;
    string maskeres;
    cout << "Milyen allatot keresel(faj,nev,kor,szin) ";
    cin >> keres;

    if(keres == "faj"){
        cin >> faj;
    }
    else{
        cin >> maskeres;
    }
    bool megvan = false;
    switch(keres[0])
    {
        case 'f':
            for(Allat i: allatv){
                if(i.fajta == faj){
                    cout << i;
                    megvan = true;
                }
            }
            break;
        case 'n':
            for(Allat i: allatv){
                if(i.nev == maskeres){
                    cout << i;
                    megvan = true;
                }
            }
            break;
        case 'k':
            for(Allat i: allatv){
                if(to_string(i.kor) == (maskeres)){
                    cout << i;
                    megvan = true;
                }
            }
            break;
        case 's':
            for(Allat i: allatv){
                if(i.szin == maskeres){
                    cout << i;
                    megvan = true;
                }
            }
            break;
    }
}

int main(){
    beolvas();
    keres();
}