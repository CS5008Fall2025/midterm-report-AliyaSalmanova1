
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int fibonacciIterative(int* array, int n){
    //set up prev, curr, and malloc array of size n
    int prev = 0;
    int curr = 1;

    //loop to n
    for (int i = 0; i <= n + 1; i++){
        //assign curr to array[i]
        array[i] = curr;
        //curr becomes prev + curr, prev becomes old curr which is now array[i]
        curr += prev;
        prev = array[i];
    }

    //should return array
    return array[n];
}



int fibonacciRecursive(int* array, int n){
    
    //base case
    if (n <= 1) {
        array[n] = 1;
        return 1;
    }
        
    //find prev 2 values through recursive calls and add them. assign that to array[n] 
    //we need a return as function returns an int
    return array[n] = fibonacciRecursive(array, n - 2) 
            + fibonacciRecursive(array, n - 1);

}


int fibonacciRecursiveDynamic(int* array, int n){
    

    //base case
    if (n <= 1) {
        array[n] = 1;
        return 1;
    } 
    //dynamic programming: if array[n] is not zero, it has already been calculated so return value
    else if (array[n] != 0){
        return array[n];
    }
    
    //find prev 2 values through recursive calls and add them. assign that to array[n] 
    //we need a return as function returns an int
    return array[n] = fibonacciRecursiveDynamic(array, n - 2) 
            + fibonacciRecursiveDynamic(array, n - 1);

}
/*
int main(int argc, char** argv){
    //convert 2nd argv (char *) to int
    int n = atoi(argv[1]);
    int* array = (int *)calloc(n, sizeof(int));


    int result = fibonacciIterative(array, n - 1);
    printf("Result: %d\n", result);
    printIntArray(array, n);

    //free! 
    free(array);
}*/