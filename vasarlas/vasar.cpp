#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <string>
using namespace std;

string file = "vasar.txt";
ifstream FileBe;
map<string, float> vasarlas;

void beolvas(){
    FileBe.open(file);
    int row;
    string inData;

    while(FileBe >> inData){
        if(isdigit(inData[0])){
            row++;
        } else{
        vasarlas[inData]++;
        }
    }
    FileBe.close();
}

void szamitas(){
    int seged = 0;
    for(pair<string, float> elemek: vasarlas){
        seged += elemek.second;
    }
    for(pair<string, float> elemek: vasarlas){
        cout << elemek.first << " szazalek:" << ((elemek.second/seged)*100) << "%" <<endl;
    }
    cout <<endl;
}

int main(){
    beolvas();
    szamitas();
    return 0;
}