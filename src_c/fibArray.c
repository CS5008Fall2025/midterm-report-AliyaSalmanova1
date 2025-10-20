
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fibonacci.h"


int main(int argc, char** argv){
    
    //if user enters less than 4 args, prompt them and return 1 so that main reruns
    if (argc < 3){
        printf("Welcome to our fibonacci assignment! Please enter in these arguments one after the other: \n");
        printf("1. Number for the size of array.\n");
        printf("2. The number 1 to run the iterative approach, 2 for recursive, 3 for recursive with dynamic programming.\n");
        return 1;
    }
    //need this to input into strtoul
    //char *endptr;
    //args 1 should be n, arg 2 the func that user wants to run, and arg 3 whether to print or not
    uint64_t n =  strtoul(argv[1], NULL, 0);
    int chosenFunc = atoi(argv[2]);


    //array of fibonacci function definitions for all approaches
    uint64_t (*funcArray[])(uint64_t n, int* ops) = {fibonacciIterative, fibonacciRecursive, fibonacciRecursiveDynamic};
    
    //array of fibonacci function definitions for all approaches
    char* namesOfFunctions[3] = {"Fibonacci iterative", "Fibonacci recursive", "Fibonacci recursive w DP"};


    uint64_t *fibArray = malloc(sizeof(uint64_t) * n);

    int ops = 0;

    for (int i = 0; i <= n; i++){
        fibArray[i] = funcArray[chosenFunc - 1](i + 1, &ops);
    }
    printf("Printing out 1..%llu of the Fibonacci Series with the %s approach.\n", n, namesOfFunctions[chosenFunc - 1]);
    printIntArray(fibArray, n);

}