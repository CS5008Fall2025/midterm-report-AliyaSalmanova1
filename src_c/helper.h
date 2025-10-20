
#define _POSIX_C_SOURCE 199309L //for clocks and timers
#include <time.h>

//print every element ofthe array separated by a space
void printIntArray(uint64_t* array, int size){
    for (int i = 0; i < size; i++){
        printf("%llu ", array[i]);
    }
    printf("\n");
}


static inline double ms_between(const struct timespec* a, const struct timespec* b) {
    //we want to print in milliseconds, so multiply seconds by 1000, and divide nanoseconds by 1000000
    //add those
    return (b->tv_sec - a->tv_sec) * 1000.0 +
           (b->tv_nsec - a->tv_nsec) / 1e6;
}

double time_function(uint64_t (*func)(uint64_t, int*), int n, int print, int* ops) {

	//declare two structs, one for initial time, one for end time
    struct timespec t0, t1;
    
    //get initial time, run function, get time after running function
    clock_gettime(CLOCK_MONOTONIC, &t0);
    uint64_t result = func(n, ops);
    clock_gettime(CLOCK_MONOTONIC, &t1);

    if (print == 1){
        printf("Nth fibonacci is: %llu\n", result);
    }

    //calculate difference and return in desired format
    return ms_between(&t0, &t1);
}
