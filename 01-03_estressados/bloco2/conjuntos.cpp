#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool oValorEstaContidoNoVetor(vector<int> array, int value)
{

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == value)
            return true;
    }
    return false;
}

vector<int> exclusivos(const vector<int> v)
{
    vector<int> exclusivos;
    int counter = 0;
    for (int i = 0; i < v.size(); i++)
    {

        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
                counter++;
        }
        if (counter == 0)
            exclusivos.push_back(v[i]);
        else
            counter = 0;
    }

    return exclusivos;
}

vector<int> diferentes(const vector<int> v)
{
    vector<int> diferentes;
    int counter = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (find(diferentes.begin(), diferentes.end(), abs(v[i])) == diferentes.end())
            diferentes.push_back(abs(v[i]));
    }
    return diferentes;
}

//{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
vector<int> abandonados(vector<int> v)
{
    vector<int> abandonados;
    int counter = 1;

    for (int i = 0; i < v.size(); i++)
    {

        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
                counter++;
        }
        if (counter > 1)
        {
            abandonados.push_back(v[i]);
        }
        counter = 1;
    }

    return abandonados;
}

int main()
{
    abandonados({1, 3, 4, 3, -1, -2, -2});
    return 0;
}
