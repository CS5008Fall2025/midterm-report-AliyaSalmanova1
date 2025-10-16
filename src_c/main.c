
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fibonacci.h"


int main(int argc, char** argv){
    
    //if user enters less than 4 args, prompt them and return 1 so that main reruns
    if (argc < 4){
        printf("Welcome to our fibonacci assignment! Please enter in these arguments one after the other: \n");
        printf("1. Number for the size of array.\n");
        printf("2. The number 1 to run the iterative approach, 2 for recursive, 3 for recursive with dynamic programming, and 4 for all.\n");
        printf("3. Enter 1 to print, and 0 to not print.\n");
        return 1;
    }

    //args 1 should be n, arg 2 the func that user wants to run, and arg 3 whether to print or not
    int n = atoi(argv[1]);
    int chosenFunc = atoi(argv[2]);
    int print = atoi(argv[3]);

    //array of fibonacci function definitions for all approaches
    int (*funcArray[])(int n, int* ops) = {fibonacciIterative, fibonacciRecursive, fibonacciRecursiveDynamic};
    

    double time_taken;


    //if user wants to print all functions
    if (chosenFunc == 4){

        //loop through array of function definitions
        for (int i = 0; i < 3; i++){
            
            //declare ops and set to 0
			int ops = 0;
            //run time function passing in current element in funcArray and print out result
            time_taken = time_function(funcArray[i], n, print, &ops);
            printf("Time taken: %f\n", time_taken);
    

        }
    } else {
        //declare ops and set to 0
		int ops = 0;
        //run time function passing in current element in funcArray and print out result
        time_taken = time_function(funcArray[chosenFunc - 1], n, print, & ops);
        printf("Time taken: %f\n", time_taken);
        
    }

}