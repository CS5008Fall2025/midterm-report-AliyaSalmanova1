
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

uint64_t fibonacciIterative(uint64_t n, int* ops){
    
    //edge case
    if (n <= 1) return n;
    //set up prev and curr
    uint64_t prev = 0;
    uint64_t curr = 1;

    //loop to n
    for (int i = 0; i < n; i++){

		(*ops)++;
        //curr becomes curr + prev, and prev becomes old curr
        uint64_t temp = curr + prev;
        prev = curr;
        curr = temp;
    }

    //should return nth fib
    return prev;
}



uint64_t fibonacciRecursive(uint64_t n, int* ops){
    
    //base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
        
    //recursive case
    //find prev 2 values through recursive calls and add them
    (*ops)++;
    return fibonacciRecursive(n - 1, ops) + fibonacciRecursive(n - 2, ops);
           
}

uint64_t fibonacciHelperDP(uint64_t* array, uint64_t n, int* ops){
    

    //base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    //dynamic programming: if array[n] is not zero, it has already been calculated so return value
    else if (array[n] != 0){
        return array[n];
    }

    //find prev 2 values through recursive calls and add them. assign that to array[n] to save value
    (*ops)++;
    array[n] = fibonacciHelperDP(array, n - 1, ops) + fibonacciHelperDP(array, n - 2, ops);

    //return nth fib
    return array[n];

}


uint64_t fibonacciRecursiveDynamic(uint64_t n, int* ops){
    //edge case
    if (n <= 1) return n;

    //create array of size n filled with 0s
    uint64_t* array = (uint64_t *)calloc(n + 1, sizeof(uint64_t));

    //call helper that returns nth fib
    uint64_t nthFibonacci = fibonacciHelperDP(array, n, ops);

    //free array!
    free(array);

    //return fib of n
    return nthFibonacci;
}


