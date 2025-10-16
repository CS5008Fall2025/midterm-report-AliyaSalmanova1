
#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int testFibIterative(){
    int n = 10;
    int* array = (int *)calloc(n, sizeof(int));

    int result = fibonacciIterative(array, n - 1);
    int expectedResult = 55;

    if (expectedResult != result) return 1;

    int expectedArray[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    for (int i = 0; i < 10; i++){
        if (array[i] != expectedArray[i]) return 1;
    }
    return 0;
}

int testfibonacciRecursive(){
    int n = 10;
    int* array = (int *)calloc(n, sizeof(int));

    int result = fibonacciRecursive(array, n - 1);
    int expectedResult = 55;

    if (expectedResult != result) return 1;

    int expectedArray[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    for (int i = 0; i < 10; i++){
        if (array[i] != expectedArray[i]) return 1;
    }
    return 0;
}

int testfibonacciDynamic(){
    int n = 10;
    int* array = (int *)calloc(n, sizeof(int));

    int result = fibonacciRecursiveDynamic(array, n - 1);
    int expectedResult = 55;

    if (expectedResult != result) return 1;

    int expectedArray[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    for (int i = 0; i < 10; i++){
        if (array[i] != expectedArray[i]) return 1;
    }
    return 0;
}

int main(){
    if (testFibIterative() == 1){
        printf("testFibIterative test failed\n");
    }else {
        printf("testFibIterative test passed\n");
    }

    if (testfibonacciRecursive() == 1){
        printf("testfibonacciRecursive test failed\n");
    }else {
        printf("testfibonacciRecursive test passed\n");
    }

    if (testfibonacciDynamic() == 1){
        printf("testfibonacciDynamic test failed");
    }else {
        printf("testfibonacciDynamic test passed\n");
    }
}