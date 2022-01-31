#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

vector<int> clone(vector<int> v)
{

    vector<int> vec(v.begin(), v.end());
    return vec;
}

vector<int> pegar_homens(vector<int> v)
{
    vector<int> homens;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
            homens.push_back(v[i]);
    }

    return homens;
}

vector<int> pegar_calmos(vector<int> v)
{

    vector<int> calmos;

    for (int i = 0; i < v.size(); i++)
    {
        if (abs(v[i]) < 10)
            calmos.push_back(v[i]);
    }

    return calmos;
}

vector<int> pegar_mulheres_calmas(vector<int> v){
    vector<int> mulheres_calmas;

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] > -10 && v[i] < 0) mulheres_calmas.push_back(v[i]);
    }

    return mulheres_calmas;
}
int main()
{

    return 0;
}