#include <iostream>
#include <vector>
using namespace std;


// EXISTE method
bool checkIfGivenValueContainsInTheArray(vector<int> array, int value)
{

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == value)
            return true;
    }
    return false;
}

// CONTAR method
int countHowManyTimesValueIsPresentInTheArray(vector<int> array, int value)
{
    int counter = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == value)
            counter++;
    }
    return counter;
}

// PROCURAR method
int returnPositionOfTheValue(vector<int> array, int value)
{

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

// PROCURAR_APOS method

int returnPositionOfTheValueAfterGivenValue(vector<int> array, int value, int initialPosition)
{

    for (int i = initialPosition; i < array.size(); i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

// PROCURAR_MENOR method
int returnSmallestValue(vector<int> array)
{

    int smallestValue = array[0];

    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] < smallestValue)
            smallestValue = array[i];
    }
    return smallestValue;
}

// PROCURAR_MAIOR method
int returnGreatestValue(vector<int> array)
{
    int greatestValue = array[0];

    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] > greatestValue)
            greatestValue = array[i];
    }
    return greatestValue;
}

// PROCURAR_MENOR_POS method
int returnPositionOfTheSmallestValue(vector<int> array)
{

    int smallestValue = returnSmallestValue(array);

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == smallestValue)
            return i;
    }
    return -1;
}
// PROCURAR_MENOR_POS_APOS method
int returnPositionOfTheSmallestValueAfterGivenValue(vector<int> array, int position)
{

    int smallestValue = array[position + 1];

    for (int i = position + 1; i < array.size(); i++)
    {
        if (array[i] < smallestValue)
            smallestValue = array[i];
    }

    return returnPositionOfTheValue(array, smallestValue);
}

// PROCURAR_MELHOR_SE method
int returnPositionOfTheSmallestValueOfAMan(vector<int> array)
{
    int smallestValue = array[0];

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > 0 && array[i] < smallestValue)
            smallestValue = array[i];
    }
    return returnPositionOfTheValue(array, smallestValue);
}

// CALCULAR_STRESS_MEDIO method
int returnAverageStress(vector<int> array)
{

    int sum = 0;

    for (int i = 0; i < array.size(); i++)
    {

        if (array[i] < 0)
            sum += array[i] * -1;
        else
            sum += array[i];
    }
    return (float)sum / array.size();
}
// MAIS_HOMENS_OU_MULHERES method
string itHasMoreMenOrWomen(vector<int> array)
{
    int men = 0;
    int women = 0;

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > 0)
            men++;
        if (array[i] < 0)
            women++;
    }

    if(men>women) return "Men";
    if (women>men) return "Women";
    if (women == men) return "Draw";
    return "";
    
}

// QUAL_METADE_EH_MAIS_ESTRESSADA
string whichPartIsMoreStressed(vector<int> array)
{

    int half_start = 0;
    int half_end = 0;

    if (array.size() % 2 == 0)
    {
        for (int i = 0; i < array.size(); i++)
        {

            if (i < (array.size() / 2))
            {
                if (array[i] < 0)

                    half_start += array[i] * -1;
                else
                    half_start += array[i];
            }

            else

                if (array[i] < 0)
                half_end += array[i] * -1;
            else
                half_end += array[i];
        }

        if(half_start > half_end) return "Half start";
        if(half_start < half_end) return "Half end";
        if (half_start == half_end) return "Draw";
    }
    else
    {
        // removing the last element to make it equal
        for (int i = 0; i < array.size() - 1; i++)
        {

            if (i < (array.size() / 2))
            {
                if (array[i] < 0)
                    half_start += array[i] * -1;
                half_start += array[i];
            }
            else if (array[i] < 0)
                half_end += array[i] * -1;
            else
                half_end += array[i];
        }
       if(half_start > half_end) return "Half start";
        if(half_start < half_end) return "Half end";
        if (half_start == half_end) return "Draw";
    }
    return "";
}

// HOMENS_SAO_MAIS_ESTRESSADOS_QUE_MULHERES method

string menAreMoreStressedThanWomen(vector<int> array){
    int men = 0;
    int sum_men = 0;

    int women = 0;
    int sum_women = 0;
    
    for(int i = 0; i<array.size(); i++){


        if(array [i] < 0){
            women++;
            sum_women += array[i] * -1;
        }
        if(array[i] > 0){
            men++;
            sum_men += array[i];
        }

    }

    float averageMan = sum_men / men;
    float averageWoman = sum_women / women;
    
   
    if(averageMan > averageWoman) return "Man";
    if(averageMan < averageWoman) return "Woman";
    if(averageMan == averageWoman) return "Draw";
    return "";

}

int main()
{
    std::cout << checkIfGivenValueContainsInTheArray({5,6,7,-20,-50, -70, 10}, 10) << '\n';
    return 0;
}