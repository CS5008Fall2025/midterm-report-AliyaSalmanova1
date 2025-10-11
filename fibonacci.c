
#include <stdio.h>
#include <stdlib.h>

int* fibonacciIterative(int n){
    //set up prev, curr, and malloc array of size n
    int prev = 1;
    int curr = 0;
    int* array = (int *)malloc(n * sizeof(int));

    //loop to n
    for (int i = 0; i < n; i++){
        //assign curr to array[i]
        array[i] = curr;
        //curr becomes prev + curr, prev becomes old curr which is now array[i]
        curr += prev;
        prev = array[i];
    }

    //should return array
    return array;
}

int main(int argc, char** argv){
    //convert 2nd argv (char *) to int
    int n = atoi(argv[1]);

    int* array = fibonacciIterative(n);
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    //free! 
    free(array);
}