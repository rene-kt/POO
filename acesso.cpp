#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;


vector<int> inverter_com_copia(vector<int> v){
    vector<int> novo_vector = v;
    reverse(novo_vector.begin(), novo_vector.end());
    return novo_vector;
    
}

void inverter_inplace(vector<int> v){
    return reverse(v.begin(), v.end());
}


int sortear( vector<int> v){
    int random = rand() % v.size() + 1;
    return v[random];
}

void embaralhar(vector<int> v){
    std::random_shuffle(v.begin(), v.end());
}


void ordenar(vector<int> v){

    sort(v.begin(), v.end(), greater <>());

    for(int i =0; i<v.size(); i++){
        cout << v[i] << '\n';
    }

}
int main(){
    ordenar({1,2,3,4,5});
    return 0;
}