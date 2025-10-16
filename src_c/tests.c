
#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

//note: I factored the code this way to avoid duplicating a lot of code

//take in fib function, n, expected, and ops
int testFib(uint64_t (*func)(uint64_t, int* ), uint64_t n, uint64_t expected, int ops){

    //find result of calling function, passing in n and ops
    uint64_t result = func(n, &ops);
    
    //check if result is accurate or not
    if (result != expected) return 1;
    return 0;
}


int main(){

    //make array of ns and matching expected results for each element
    enum { amountOfNs = 3 };
    int arrayOfNs[amountOfNs] = {0, 1, 30};
    int expectedResults[amountOfNs] = {0, 1, 832040};


    //array of fibonacci function definitions for all approaches
    uint64_t (*funcArray[])(uint64_t n, int* ops) = {fibonacciIterative, fibonacciRecursive, fibonacciRecursiveDynamic};
    
    //names of fibonacci function definitions for all approaches
    char* namesOfFunctions[3] = {"fibonacci iterative", "fibonacci recursive", "fibonacci recursive w DP"};

    //loop through array of functions
    for (int i = 0; i < 3; i++){
        
        //loop through array of ns
        for (int j = 0; j < amountOfNs; j++){
    
            //find current n and convert to unsigned long int. do same for expected result
            uint64_t currN = (uint64_t)(arrayOfNs[j]);
            uint64_t expectedResult = (uint64_t)(expectedResults[j]);

            int ops = 0;
            //call testFib, passing in current function, curr n, expected result, ops and save result
            int pass_fail = testFib(funcArray[i], currN, expectedResult, ops);

            //print if test passed or failed
            if (pass_fail == 1){
                printf("Failed test for %llu with %s\n", currN, namesOfFunctions[i]);
            }else {
                printf("Passed test for %llu with %s\n", currN, namesOfFunctions[i]);
            }

        }
    }
}


