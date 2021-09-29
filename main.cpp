#include <iostream>
using namespace std;

    // 0 for false and 1 for true
    // EXISTE method
    int checkIfGivenValueContainsInTheArray(int arr[], int arr_size, int value){


        for(int i = 0; i<arr_size; i++){
            if(arr[i] == value ) return 1;
        }
        return 0;

    }

    // CONTAR method
    int countHowManyTimesValueIsPresentInTheArray(int arr[], int arr_size, int value){
        int counter = 0;
        for(int i = 0; i<arr_size; i++){
            if(arr[i] == value ) counter++;
        }
        return counter;
    }

    // PROCURAR method
    int returnPositionOfTheValue(int arr[], int arr_size, int value){
        
        for(int i = 0; i<arr_size; i++){
            if(arr[i] == value ) return i;
        }
        return -1;
       
    }

    // PROCURAR_APOS method

     int returnPositionOfTheValueAfterGivenValue(int arr[], int arr_size, int value, int initialPosition){
        
        for(int i = initialPosition; i<arr_size; i++){
            if(arr[i] == value ) return i;
        }
        return -1;
       
    }

    // PROCURAR_MENOR method
     int returnSmallestValue(int arr[], int arr_size){
        
        int smallestValue = arr[0];

        for(int i = 1; i<arr_size; i++){
            if(arr[i] < smallestValue)  smallestValue = arr[i];
            
        }
        return smallestValue;
    }

    // PROCURAR_MAIOR method
    int returnGreatestValue(int arr[], int arr_size){
        int greatestValue = arr[0];

        for(int i = 1; i<arr_size; i++){
            if(arr[i] > greatestValue)  greatestValue = arr[i];
            
        }
        return greatestValue;
    }

    // PROCURAR_MENOR_POS method
     int returnPositionOfTheSmallestValue(int arr[], int arr_size){
        
        int smallestValue = returnSmallestValue(arr, arr_size);

        for(int i =0; i<arr_size; i++){
            if(arr[i] == smallestValue) return i;
        }
        return -1;
    }
    // PROCURAR_MENOR_POS_APOS method
    int returnPositionOfTheSmallestValueAfterGivenValue(int arr[], int arr_size, int position){
        
        int smallestValue = arr[position + 1]; 

        for(int i = position + 1; i<arr_size; i++){
            if(arr[i] < smallestValue) smallestValue = arr[i];
        }

        return returnPositionOfTheValue(arr, arr_size, smallestValue);
    }

    // PROCURAR_MELHOR_SE method
    int returnPositionOfTheSmallestValueOfAMan(int arr[], int arr_size){
        int smallestValue = arr[0];

        for(int i =0; i<arr_size; i++){
            if(arr[i] > 0 && arr[i] < smallestValue) smallestValue = arr[i];
        }
        return returnPositionOfTheValue(arr, arr_size, smallestValue);
    }




int main() {
    int array[7] = {50, -19, -22, 56, 2, 50, 5};
    std::cout << returnPositionOfTheSmallestValueOfAMan(array, 7) << '\n';
    return 0;
}