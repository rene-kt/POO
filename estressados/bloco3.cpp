#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;


//{1, 3, 4, 3, -1, -3, -3} -> {4}
vector<int> sozinhos(vector<int> v)

{
    vector<int> sozinhos;
    int counter = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (abs(v[i]) == abs(v[j]))
                counter++;
        }

        if (counter == 1)
        {

            sozinhos.push_back(abs(v[i]));
            counter = 0;
        }
        else
            counter = 0;
    }

    for (int i = 0; i < sozinhos.size(); i++)
    {
        cout << sozinhos[i] << '\n';
    }

    return sozinhos;
}

int mais_ocorrencias(vector<int> v)
{
    int maiorOcorrencias = 0;
    int counter = 0;

    for (int i = 0; i < v.size(); i++)
    {

        for (int j = 0; j < v.size(); j++)
        {
            if (abs(v[i]) == abs(v[j]))
                counter++;
        }

        if (i == 0)
            maiorOcorrencias = counter;
        else
        {
            if (counter > maiorOcorrencias)
                maiorOcorrencias = counter;
        }

        counter = 0;
    }

    return maiorOcorrencias;
}


int main()
{   
    return 0;
}