#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string file = "kaloria.txt";
ofstream FileKi(file, std::ofstream::app);

struct rekord
{
    char nem;
    short int age;
    float weight;
    short int height;
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
    if (person.nem == 'F' || person.nem == 'f')
    {
        FileKi << "Ferfi BMR: " << manBmr(person.weight, person.height, person.age) << " Kcal" <<"\n";
    } else if(person.nem == 'N' || person.nem == 'n'){
        FileKi << "Noi BMR: " << womanBmr(person.weight, person.height, person.age) << " Kcal" <<"\n";
    }
    FileKi.close();
}

void kaloriaszamitas(){
    try
    {
        cout << "Nem(F/N):" << " ";
        if(!(cin >> person.nem) && (typeid(person.nem) == typeid(char))){
            throw runtime_error("Hibas adatformatum a 'Nem' mezoben!, probalja ujra!");
        }
        //cout << (person.nem) << " ";
        cout << "Kor:" << " ";
        if(!(cin >> person.age)){
            throw runtime_error("Hibas adatformatum a 'Kor' mezoben!");
        }
        cout << "Suly:" << " ";
        if(!(cin >> person.weight)){
            throw runtime_error("Hibas adatformatum a 'Suly' mezoben!");
        }
        cout << "Magassag:"<< " ";
        if(!(cin >> person.height)){
            throw runtime_error("Hibas adatformatum a 'Magassag' mezoben!");
        }
        if (islower(person.nem) || isupper(person.nem)){
            manBmr(person.weight, person.height, person.age);
            }
        else if(islower(person.nem) || isupper(person.nem)){
            womanBmr(person.weight, person.height, person.age);
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