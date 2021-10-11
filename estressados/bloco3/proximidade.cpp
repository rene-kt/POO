#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int briga(vector<int> v)
{
    int contadorBrigas = 0;

    for (int i = 1; i < v.size() - 1; i++)
    {

        if (v[i - 1] >= 30 && v[i] >= 50 && v[i + 1] >= 30)
            contadorBrigas++;
    }

    return contadorBrigas;
}

vector<int> apaziguados(vector<int> v)
{
    vector<int> apaziguados;

    for (int i = 0; i < v.size(); i++)
    {

        if (i == 0)
        {

            if (v[i] >= 80 && v[i + 1] <= 10)
                apaziguados.push_back(i);
        }
        else if (i == v.size() - 1)
        {
            if (v[i] >= 80 && v[i - 1] <= 10)
                apaziguados.push_back(i);
        }
        else
        {

            if (v[i] >= 80 && v[i - 1] <= 10)
            {

                apaziguados.push_back(i);
            }

            if (v[i] >= 80 && v[i + 1] <= 10)
            {
                apaziguados.push_back(i);
            }
        }
    }

    return apaziguados;
}

int main()
{

    apaziguados({1, 90, 82, 2, 90});
    return 0;
}