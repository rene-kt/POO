#include <iostream>
using namespace std;

// 0 for false and 1 for true
// EXISTE method
int checkIfGivenValueContainsInTheArray(int arr[], int arr_size, int value)
{

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == value)
            return 1;
    }
    return 0;
}

// CONTAR method
int countHowManyTimesValueIsPresentInTheArray(int arr[], int arr_size, int value)
{
    int counter = 0;
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == value)
            counter++;
    }
    return counter;
}

// PROCURAR method
int returnPositionOfTheValue(int arr[], int arr_size, int value)
{

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// PROCURAR_APOS method

int returnPositionOfTheValueAfterGivenValue(int arr[], int arr_size, int value, int initialPosition)
{

    for (int i = initialPosition; i < arr_size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// PROCURAR_MENOR method
int returnSmallestValue(int arr[], int arr_size)
{

    int smallestValue = arr[0];

    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] < smallestValue)
            smallestValue = arr[i];
    }
    return smallestValue;
}

// PROCURAR_MAIOR method
int returnGreatestValue(int arr[], int arr_size)
{
    int greatestValue = arr[0];

    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] > greatestValue)
            greatestValue = arr[i];
    }
    return greatestValue;
}

// PROCURAR_MENOR_POS method
int returnPositionOfTheSmallestValue(int arr[], int arr_size)
{

    int smallestValue = returnSmallestValue(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == smallestValue)
            return i;
    }
    return -1;
}
// PROCURAR_MENOR_POS_APOS method
int returnPositionOfTheSmallestValueAfterGivenValue(int arr[], int arr_size, int position)
{

    int smallestValue = arr[position + 1];

    for (int i = position + 1; i < arr_size; i++)
    {
        if (arr[i] < smallestValue)
            smallestValue = arr[i];
    }

    return returnPositionOfTheValue(arr, arr_size, smallestValue);
}

// PROCURAR_MELHOR_SE method
int returnPositionOfTheSmallestValueOfAMan(int arr[], int arr_size)
{
    int smallestValue = arr[0];

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0 && arr[i] < smallestValue)
            smallestValue = arr[i];
    }
    return returnPositionOfTheValue(arr, arr_size, smallestValue);
}

// CALCULAR_STRESS_MEDIO method
int returnAverageStress(int arr[], int arr_size)
{

    int sum = 0;

    for (int i = 0; i < arr_size; i++)
    {

        if (arr[i] < 0)
            sum += arr[i] * -1;
        else
            sum += arr[i];
    }
    return (float)sum / arr_size;
}
// MAIS_HOMENS_OU_MULHERES method
int itHasMoreMenOrWomen(int arr[], int arr_size)
{
    int men = 0;
    int women = 0;

    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] > 0)
            men++;
        if (arr[i] < 0)
            women++;
    }
    // 0 = men and 1 = women
    return men > women ? 0 : 1;
}

// QUAL_METADE_EH_MAIS_ESTRESSADA
int whichPartIsMoreStressed(int arr[], int arr_size)
{

    int half_start = 0;
    int half_end = 0;

    if (arr_size % 2 == 0)
    {
        for (int i = 0; i < arr_size; i++)
        {

            if (i < (arr_size / 2))
            {
                if (arr[i] < 0)

                    half_start += arr[i] * -1;
                else
                    half_start += arr[i];
            }

            else

                if (arr[i] < 0)
                half_end += arr[i] * -1;
            else
                half_end += arr[i];
        }

        // 0 = half start and 1 = half_end
        return half_start > half_end ? 0 : 1;
    }
    else
    {
        // removing the last element to make it equal
        for (int i = 0; i < arr_size - 1; i++)
        {

            if (i < (arr_size / 2))
            {
                if (arr[i] < 0)
                    half_start += arr[i] * -1;
                half_start += arr[i];
            }
            else if (arr[i] < 0)
                half_end += arr[i] * -1;
            else
                half_end += arr[i];
        }

        // 0 = half start and 1 = half_end
        return half_start > half_end ? 0 : 1;
    }
}

// HOMENS_SAO_MAIS_ESTRESSADOS_QUE_MULHERES method

int menAreMoreStressedThanWomen(int arr[], int arr_size){
    int men = 0;
    int sum_men = 0;

    int women = 0;
    int sum_women = 0;

    for(int i = 0; i<arr_size; i++){


        if(arr [i] < 0){
            women++;
            sum_women += arr[i] * -1;
        }
        if(arr[i] > 0){
            men++;
            sum_men += arr[i];
        }

    }

    // 0 = men and 1 = women
    return (sum_men / men) > (sum_women / women) ? 0 : 1;

}

int main()
{
    int array[6] = {-4, -2, -5, -10, -12, 85};
    std::cout << menAreMoreStressedThanWomen(array, 6) << '\n';
    return 0;
}