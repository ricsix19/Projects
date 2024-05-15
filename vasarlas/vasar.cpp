#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string file = "vasar.txt";
ifstream FileBe;
map<int, string> vasarlas;

void beolvas(){
    FileBe.open(file);
    int key;
    string value;
    
    while(FileBe >> key >> value){
        vasarlas[key] = value;
    }

    map<int, string>::iterator it = vasarlas.begin();

    while(it != vasarlas.end()){
        int line = it->first;
        string data = it -> second;

        cout << line << " " << data;
        it++;
    }
    
}

int main(){
    beolvas();

    return 0;
}