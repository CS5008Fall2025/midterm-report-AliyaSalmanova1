# Midterm p1: Report on Analysis of Fibonacci Algorithm
* **Author**: Aliya Salmanova
* **Semester** Fall 2025
* **Languages Used**: C, Java

## Introduction

For this report, I solved the Nth fibonacci algorithm iteratively, recursively, and with dynamic programming
in C and in Java. The fibonacci sequence is a sequence where every element is the sum of the previous two 
elements, so F(0) = 0, F(1) = 1, and F(n) = F(n - 1) + F(n - 2). All my C source code is in src_c and Java source code
 is in src_java. The main.c and Main.java files prompt the user for N, and compute the Nth fibonacci
using the 3 approaches. The runner.c and Runner.java files print all the runtimes and ops 
for 0...N to csv files, and I used this data to create line graphs that are in the png_folder. 

## Overview and Big O Notation

Pseudocode for iterative approach:
```
function fib_iter(n):
    if n <= 1: return n
    prev = 0
    curr = 1
    for i from 2 to n:
        temp = prev + curr
        prev = curr
        curr = temp
    return prev
```

Time complexity: the T(n) for this algorithm is a(n) + c, as we initially have two constants,
and then have a loop that loops until n. Inside the loop, we have some updates. 
In Big O notation, we don't count constants, so we get O(n).


The space complexity is O(1), as no matter how large or small n is, we always declare the same number of variables.


Pseudocode for recursive approach:
```
function fib_rec(n):
    if n <= 1: return n
    return fib_rec(n-1) + fib_rec(n-2)
```

Let's look at this using the recurrence tree if n is 4: 

n 

(n-1) (n-2) 
(2^1)

(n-2) (n-3) (n-3) (n-4) 
(2^2)

(n-3) 
(2^3)

The T(n) would be on average and worse case is T(n-1) + T(n-2) + O(1). 
We ignore constants, so the big O notation is O(2^n), which is exponential growth. 

Our space complexity would be O(n). This is because the space complexity of a recursive algorithm 
is the space for the data structures used + the depth of the recursion.
This is because we count how many calls are on the call stack, and the amount of calls on the call
stack never goes over n. 
In the case of n = 4, we would get fib(4), fib(3), fib(2), fib(1) on the call stack.
After that, fib(1) gets popped off and fib(0) would be placed on the call stack. 
We never go over 4 functions on the call stack. 

Pseudocode for dynamic programming approach: 

```
memo = array of length n+1 filled with 0s
function fib_memo(n):
    if n <= 1: return n
    if memo[n] != 0: return memo[n]
    memo[n] = fib_memo(n-1) + fib_memo(n-2)
    return memo[n]
```

To show what is happening better I will draw out a tree:
                fib(4)
            fib(3) fib(2) - returns
    fib(2) fib(1) - returns
fib(1) fib(0)

Using memoization, we compute each subproblem once. 
The first time we hit an n, we do O(1) work (a couple checks and an add) and store it. 
Later calls are O(1) cache hits that just return the saved value. 
Since there are n distinct states, the total work is linear, so the big O notation is O(n). 
T(n) = a·n + c = Θ(n). 
The constant term includes the cache hits. 

It also could take O(n) to initialize the array of 0s, depending on the language and what we use, etc.
As we ignore constants, a*n + c is still O(n).

The space complexity would be O(n), as we are declaring an array of size n in order to use memoization.

I noticed that the iterative solution can be counted as dynamic programming with tabulation, as we are 
saving the computations of n-1 and n-2 in variables. 

The most efficient approach in terms of time complexity and space complexity theory is the iterative approach, 
as it has the same time complexity as the recursive dp solution, but less space complexity. However, we will see that 
the iterative solution's runtimes grow slightly more than the recursive dynamic programming implementation in Java.


## Empirical Data & Discussion

For empirical data, I let the recursive function run until n = 50, as I saw that the Java code would give me problems for the recursive function for larger n numbers on my operating system.
The iterative and dynamic programming solutions ran until n = 3000.
I printed out the runtimes and ops to CSVs for both languages (src_c/ops.csv, src_c/times.csv, src_java/ops_java.csv, src_java/times.csv)
and then created line graphs from the data, which can be seen in the png_folder. 

Recursive runtimes (C vs Java): png_folder/recursive_runtimes_c_java.png 
The curve grows like you’d expect for exponential time. Java’s line grows a bit faster than C by my runs.
However, a big contributor to this was the optimization I made during compilation,
using gcc -O3 -march=native -fno-omit-frame-pointer. 

Iterative + DP in C: png_folder/iterative_dp_runtimes_c.png
Both are nice and linear. My iterative version is a bit faster than my DP version in C, 
due to the calloc the C performs for the DP solution. 

Iterative + DP in Java: png_folder/iterative_dp_runtimes_java.png
Also linear. Here my DP was faster than my iterative slightly.


I wrote separate Runner code in C and Java to print out the data to the csv files. These languages both deal with time in different ways,
so it was important to make sure that the time would be measured in the same units, or else our data and comparisons would be incorrect. 
In java I used the System.nanoTime() functions, and in C I used clock_gettime. I made sure both were measured in milliseconds.
I decided to measure the time in milliseconds instead of seconds to be able to better see the curves/lines and the differences between times. 



### Operations Comparison

#### Operations Count

| N    | Iterative | Recursive | Dynamic Programming |
|------|-----------|-----------|---------------------|
| 3    | 4         | 1         | 1                   |
| 4    | 5         | 2         | 2                   |
| 5    | 6         | 4         | 3                   |
| 6    | 7         | 7         | 4                   |
| 7    | 8         | 12        | 5                   |
| 8    | 9         | 20        | 6                   |
| 9    | 10        | 33        | 7                   |
| 10   | 11        | 54        | 8                   |
| 11   | 12        | 88        | 9                   |
| 12   | 13        | 143       | 10                  |
| 13   | 14        | 232       | 11                  |
| 14   | 15        | 376       | 12                  |
| 15   | 16        | 609       | 13                  |
| 16   | 17        | 986       | 14                  |
| 17   | 18        | 1596      | 15                  |
| 18   | 19        | 2583      | 16                  |
| 19   | 20        | 4180      | 17                  |
| 20   | 21        | 6764      | 18                  |
| 21   | 22        | 10945     | 19                  |
| 22   | 23        | 17710     | 20                  |
| 23   | 24        | 28656     | 21                  |
| 24   | 25        | 46367     | 22                  |
| 25   | 26        | 75024     | 23                  |
| 26   | 27        | 121392    | 24                  |
| 27   | 28        | 196417    | 25                  |
| 28   | 29        | 317810    | 26                  |
| 29   | 30        | 514228    | 27                  |
| 30   | 31        | 832039    | 28                  |
| 31   | 32        | 1346268   | 29                  |
| 32   | 33        | 2178308   | 30                  |
| 33   | 34        | 3524577   | 31                  |
| 34   | 35        | 5702886   | 32                  |
| 35   | 36        | 9227464   | 33                  |
| 36   | 37        | 14930351  | 34                  |
| 37   | 38        | 24157816  | 35                  |
| 38   | 39        | 39088168  | 36                  |
| 39   | 40        | 63245985  | 37                  |
| 40   | 41        | 102334154 | 38                  |

The ops table matches the theory. Recursive operations count looks like Fibonacci numbers (aka at
n=40 ops = 102,334,154), while iterative and DP are linear.

The results we get also depends on what we count as an operation, meaning where we are incrementing the operations count.
In the dynamic programming solution, we are not incrementing the operations count when the function is being called for the n
where fib of n has already been calculated and just returning a value from our array. If we were, it would count as more operations.


### Recursive Versions

![](png_folder/recursive_runtimes_c_java.png)

The curve grows like you’d expect from exponential time. Java’s line grows slightly faster than C’s in my runs.


### Iterative and Dynamic Programming Versions

![](png_folder/iterative_dp_runtimes_c.png)


![](png_folder/iterative_dp_runtimes_java.png)

We can see spikes in the runtimes for the earlier N numbers for our Java implementations.
Java first compiles the code into byte-code, then that byte-code is interpreted by the JVM (Java virtual machine).
However, the JVM also runs just-in-time compilation for optimization. The optimization happens over time,
so this is likely why we are getting such results. 

C is fully compiled ahead of time and shows faster runtimes when we use optimization. 


### Speed Comparison Between Languages

As we can see in the line graphs, the recursive version in Java is somewhat more costly than the version in C, and in general 
all the runtimes of the different approaches are more costly than the runtimes in C. 


## Language Analysis

### Language 1: C

Like in the Java implementation, the recursive approach in C proves to be very inefficient in terms of runtime. 
The C implementation of the dynamic programming approach results in worse runtimes than the iterative approach.
The iterative approach's runtimes are surprisingly good. 
The drawbacks of dynamic in programming in this case is that calloc is a costly function, as it takes time for the program
to allocate n amount of memory, and initiate all the elements to 0. The bigger n, the more space the array needs,
and the longer it takes C to allocate that memory. Another drawback for the dynamic programming approach is that, 
for n values that have already been calculated, we still need to recursively call the function again,
and check whether we already have the array[n] value. This takes time and adds on to the callstack.


### Language 2: Java

For the dynamic programming solution, I was concerned about whether the array would be passed as a copy when used as an argument in the helper function.
However, since arrays are stored in the heap in Java, what gets copied is the pointer. So, the array can be mutated in place.

Java is an object-oriented programming language, so I had to think in terms of classes and create objects. To make it possible 
to create an array of the different Fibonacci objects, I had to implement a FibonacciApproach interface and have the Fibonacci 
objects all implement that interface, so that I could later loop through the array of objects and call the fibonacci() method on all of them.
This had me think in a different way than I do in C coding.

However, the implementation of the algorithm itself is nearly identical in both languages. In the dynamic programming one however,
I did not need a helper method in java. I implemented the helper method in c so that the fibonacciRecursiveDynamic() method
would remain with 2 arguments like the other two approaches, and the helper method could take in the array as an extra argument.
This was not necessary in Java as I saved the array of n size as a property of the object. 


### Comparison and Discussion Between Experiences

In general, the languages felt similar for a stand-alone algorithm, not an application. 
The main difference to me was how I handled memory and pointers directly in C, 
and in Java I had to use on classes/interfaces. I researched how an array is stored under the hood,
to make sure that the array would be mutated in place in the dynamic programming solution.

Getting the runners to behave the same took as much work as the algorithms themselves - matching prompts, timing units, and CSV outputs. 
Each language has its own timing and file APIs, so I had to make sure they are behaving the same way. 
Next time I’d drive both from a single script (probably Python) to generate one consistent CSV.

From the runtimes, I learned more about how the JVM actually executes code. 
Java compiles to bytecode at first, then the JVM interprets the bytecode, while also
the JIT-compiles hot methods to native code. 
C is ahead-of-time fully compiled. That helps explain why my C runtimes were generally faster (with optimization, without optimization it would produce slower results than it did).

Also, both languages can zero-initialize arrays (Java by default, and I used calloc in C), so zeroing cost exists in both with different constants.
One interesting result: in Java my DP run won over iterative; in C my iterative beat DP. That’s consistent with constant-factor differences: 
the DP version may pay function-call and array-access costs in C, while in Java the JIT can sometimes smooth those. Either way, both are Θ(n).

These comparisons are nuanced and can change with different optimizations. 
Sometimes one language clearly wins, other times the comparisons are close and the reasons one is faster is a mix of runtime behavior and what is used to compile the program.


## Conclusions / Reflection

The naive recursion solution (without dynamic programming) is elegant but exponential time becomes impractical fast. 
For real-use I’d choose iterative or bottom-up DP, which are both Θ(n) runtime, and with the two-variable version they are O(1) extra space.

The data matched theory - exponential growth for recursion and linear for iterative/DP. 
C was faster in my measurements (after O3 -march=native), while Java improved after JVM warm-up.

If I were to redo this, I’d drive both languages from one runner, as that ensures that the timings are being calculated the same way
and enables more accurate results. 

As a side effect of this assignment, I also learned a few other things, about nanoseconds, what 1e6/1e9 means, and how “ops” definitions affect the charts. 
Also, I initially gave each function two jobs (fill array and return fib of n), but keeping a function focused on one purpose makes timing cleaner and I refactored.

## References

W3schools.com. W3Schools Online Web Tutorials. (n.d.). https://www.w3schools.com/java/java_files_write.asp
Java System nanotime() method. Tutorialspoint. (n.d.). https://www.tutorialspoint.com/java/lang/system_nanotime.htm
Function pointers in C. Tutorialspoint. (n.d.-a). https://www.tutorialspoint.com/cprogramming/c_function_pointers.htm
kartik. (2025, July 23). Nth Fibonacci number. GeeksforGeeks. https://www.geeksforgeeks.org/dsa/program-for-nth-fibonacci-number/ https://www.geeksforgeeks.org/java/compilation-execution-java-program/
Westrelin, R. (2022, August 26). How the JIT compiler boosts Java performance in openjdk. Red Hat Developer. https://developers.redhat.com/articles/2021/06/23/how-jit-compiler-boosts-java-performance-openjdk?utm_source=chatgpt.com#hotspot_s_jit_execution_model
Clock_gettime(3) - linux manual page. (n.d.). https://man7.org/linux/man-pages/man3/clock_gettime.3.html 









