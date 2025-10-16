
import java.util.Scanner;

public class Main {


    public static void main(String[] args){

        //variable to be used for while loop
        boolean repeat = true;

        //initiate needed variables to reassign from user input
        int n = 0;
        int chosenFunc = 0;
        int print = 0;

        Scanner scanner = new Scanner(System.in);
        
        //make user input numbers by using try/catch
        while (repeat){
            try{
                System.out.println("Welcome to our fibonacci assignment! Please enter in these arguments one after the other: \n");
                System.out.println("1. Number for the size of array.\n");
                n = scanner.nextInt();
                System.out.println("2. The number 1 to run the iterative approach, 2 for recursive, 3 for recursive with dynamic programming, and 4 for all.\n");
                chosenFunc = scanner.nextInt();
                System.out.println("3. Enter 1 to print, and 0 to not print.\n");
                print = scanner.nextInt();
                repeat = false;

            }catch(Exception e){
                System.out.println("You must enter numbers only.");

            }
        }

        //initiate all fibonacciApproach objects and place in array
        FibonacciApproach fibonacciIterative = new FibonacciIterative();
        FibonacciApproach fibonacciRecursive = new FibonacciIterative();
        FibonacciApproach fibonacciRecursiveDynamic = new FibonacciDP(n);

        FibonacciApproach[] fibonaccis = {fibonacciIterative, fibonacciRecursive, fibonacciRecursiveDynamic};

        String time_taken;

        //if user wants to run all functions, loop through array
        if (chosenFunc == 4){

            for (int i = 0; i < 3; i++){
                FibonacciApproach fibonacci = fibonaccis[i];
                //run time_function passing in current fib function
                time_taken = Helper.time_function(fibonacci, n, 0);
                System.out.println("Time taken: " + time_taken + "\n");

            }
        } else {
            FibonacciApproach fibonacci = fibonaccis[chosenFunc];
            //run time_function passing in fib function
            time_taken = Helper.time_function(fibonacci, n, 0);
            System.out.println("Time taken: " + time_taken + "\n");

        }


    }
}
