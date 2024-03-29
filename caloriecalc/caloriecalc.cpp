#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string file = "kaloria.txt";
ofstream FileKi(file, std::ofstream::app);

struct rekord
{
    char nem;
    short int kor;
    float suly;
    short int magassag;
};
rekord person;

float manBmr(float weight, short int height, short int age){
    return ((88.362 + ((13.397 * weight) + (4.799 * height))) - (5.677 * age));
}

float womanBmr(float weight, short int height, short int age){
    return ((655 + ((4.35 * weight) + (4.7 * height))) - (4.7 * age));
}

void kiiras(){
    FileKi.open(file, std::ofstream::app);
    if (person.nem == 'F' or person.nem == 'f')
    {
        FileKi << "Ferfi BMR: " << manBmr(person.suly, person.magassag, person.kor) << " Kcal" <<"\n";
    } else if(person.nem == 'N' or person.nem == 'n'){
        FileKi << "Noi BMR: " << womanBmr(person.suly, person.magassag, person.kor) << " Kcal" <<"\n";
    }
    FileKi.close();
}

void kaloriaszamitas(){
    try
    {
        cout << "Nem(F/N):" << " ";
        if(!(cin >> person.nem) and (typeid(person.nem) == typeid(char))){
            throw runtime_error("Hibas adatformatum a 'Nem' mezoben!, probalja ujra!");
        }
        cout << (person.nem) << " ";
        cout << "Kor:" << " ";
        if(!(cin >> person.kor)){
            throw runtime_error("Hibas adatformatum a 'Kor' mezoben!");    
        }
        cout << "Suly:" << " ";
        if(!(cin >> person.suly)){
            throw runtime_error("Hibas adatformatum a 'Suly' mezoben!");
        }
        cout << "Magassag:"<< " ";
        if(!(cin >> person.magassag)){
            throw runtime_error("Hibas adatformatum a 'Magassag' mezoben!");
        }
        if (islower(person.nem) or isupper(person.nem)){
            manBmr(person.suly, person.magassag, person.kor);
            }
        else if(islower(person.nem) or isupper(person.nem)){
            womanBmr(person.suly, person.magassag, person.kor);
        }
        kiiras();
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
        cout << "Valahol hibas adatot adtal meg, probald ujra!";
    }
}

int main(){
    kiiras();
    kaloriaszamitas();
    return 0;
}