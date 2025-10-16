
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int fibonacciIterative(int n, int* ops){
    //set up prev and curr
    int prev = 0;
    int curr = 1;

    //loop to n
    for (int i = 0; i <= n; i++){

		(*ops)++;
        //curr becomes curr + prev, and prev becomes old curr
        int temp = curr + prev;
        prev = curr;
        curr = temp;
    }

    //should return nth fib
    return prev;
}


int fibonacciRecursive(int n, int* ops){
    
    //base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
        
    //recursive case
    //find prev 2 values through recursive calls and add them
	(*ops)++;
    return fibonacciRecursive(n - 2, ops) 
            + fibonacciRecursive(n - 1, ops);

}

int fibonacciHelperDP(int* array, int n, int* ops){

    //base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    //dynamic programming: if array[n] is not zero, it has already been calculated so return value
    else if (array[n] != 0){
        return array[n];
    }

    //find prev 2 values through recursive calls and add them. assign that to array[n] to save value
    (*ops)++;
    array[n] = fibonacciHelperDP(array, n - 2, ops) 
            + fibonacciHelperDP(array, n - 1, ops);

    //return nth fib
    return array[n];

}


int fibonacciRecursiveDynamic(int n, int* ops){

    //create array of size n filled with 0s
    int* array = (int *)calloc(n + 1, sizeof(int));

    //call helper that returns nth fib
    int nthFibonacci = fibonacciHelperDP(array, n, ops);

    //free array!
    free(array);

    //return fib of n
    return nthFibonacci;
}


