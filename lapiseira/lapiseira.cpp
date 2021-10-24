#include <iostream>

using namespace std;

class Grafite {
     float calibre;
     string dureza;
     int tamanho;

     public: 


    Grafite(float, string, int); 

    Grafite::Grafite(float c, string d, int t) { 
        calibre = c;
        dureza = d;
        tamanho = t;
    }

    void toString(Grafite grafite){
        cout << grafite.calibre << '\n';
        cout << grafite.dureza << '\n';
        cout << grafite.tamanho << '\n';
    }

}; 


int main(){

}