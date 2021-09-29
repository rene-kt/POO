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


int main() {
    int array[7] = {50, -19, 2, 5, 17, 50, 50};
    std::cout << returnPositionOfTheValueAfterGivenValue(array, 6, 50, 0) << '\n';
    return 0;
}