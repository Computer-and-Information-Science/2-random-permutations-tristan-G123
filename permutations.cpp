// Tristan Gannon

#include "permutations.h"
#include "randint.h"
#include <cstddef>

// A sequential search function, for your convenience.
// Parameters:
//  array - The array of int's to be searched
//  size - The size of the array
//  target - The target value
// Returns:
//  Array index where target is found, or size if target is not found.
// Example:
//  if (search(array, size, x) < size)
//      cout << "x was found in the array\n";
//  else
//      cout << "x was not found in the array\n";
static size_t search (const int array[], size_t size, int target) {
    for (size_t i = 0; i < size; i++)
    if (array[i] == target)
        return i;
    return size;
}

void permutations1 (int array[], size_t size) {
    // TODO: Implement algorithm #1 here
    // for loop which goes through each value in array
    for(size_t i=0;i<size;i++){
        size_t temp=size-1;
        //while loop that repeats until search returns with the value size
        while(temp!=size){
            array[i]=randint(1,size);
            temp=search(array,size,array[i]);
        }
    }
}

void permutations2 (int array[], size_t size) {
    // TODO: Implement algorithm #2 here
    //creates bool array to store used numbers
    bool used[size];
    //for loop to go through entire array
    for(size_t i=0;i<size;i++){
        array[i]=randint(1,size);
        //while loop that uses used to check numbers that aren't used
        while(!used[array[i-1]]){
            array[i]=randint(1,size);
        }
        used[i-1]=true;
    }
}

void permutations3 (int array[], size_t size) {
    // TODO: Implement algorithm #3 here
    //for loop initialising all values as i+1
    for(size_t i=0;i<size;i++){
        array[i]=i+1;
    }
    //for loop swapping values in array[i] with a random value in array from a[0] to a[i]
    for(size_t i=1;i<size;i++){
        size_t temp;
        temp=array[i];
        int rand=randint(0,i);
        array[i]=array[rand];
        array[rand]=temp;
    }
}
