#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int quantos_times(vector<int> v)
{
    int quantidadeTimes = 0;
    int contador = 0;

    for (int i = 0; i < v.size() - 1; i++)
    {

        if (v[i] == v[i + 1])
            contador++;
        else if (contador > 0)
        {
            quantidadeTimes++;
            contador = 0;
        }

        if (i == v.size() - 2 && contador > 0)
            quantidadeTimes++;
    }

    return quantidadeTimes;
}

int maior_time(vector<int> v)
{
    int contador = 0;
    int maiorTime = 0;

    for (int i = 0; i < v.size() - 1; i++)
    {

        if (v[i] == v[i + 1])
            contador++;
        if (contador > maiorTime)
            maiorTime = contador;
        if (v[i] != v[i + 1])
            contador = 0;
    }
    return maiorTime + 1;
}

int sozinhos(vector<int> v)
{
    int sozinhos = 0;

    for (int i = 0; i < v.size(); i++)
    {

        if (i == 0)
        {

            if (v[i] != v[i + 1])
                sozinhos++;
        }

        else if(i == v.size() - 1){
            if(v[i] != v[i-1])sozinhos++;
        }

        else if(v[i] != v[i - 1] && v[i] != v[i+1])sozinhos++;
    
    }
    return sozinhos;
}
int main()
{
    cout << sozinhos({1,1,1,1,1}) << '\n';
    return 0;
}