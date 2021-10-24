#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int casais(vector<int> v)
{
    int casais = 0;

    for (int i = 0; i < v.size(); i++)
    {

        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] != 0 && v[j] != 0 && v[i] == v[j] * -1)
            {
                casais++;
                v[i] = 0;
                v[j] = 0;
            }
        }
    }
    return casais;
}

int trios(vector<int> v)
{

    int trios = 0;
    int contador = 1;

    for (int i = 0; i < v.size(); i++)
    {

        for (int j = i + 1; j < v.size(); j++)
        {
            if(abs(v[i]) == abs(v[j])) contador++;

            

            if(contador == 3) {
                
                trios++;
                contador = 0;

            }
        }
    }
    return trios;
}
int main()
{
    cout << trios({1,2,1,2,-1,-2, 2, 1}) << '\n';
    return 0;
}