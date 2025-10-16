
import java.io.FileWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Runner {

    //names of csv files
    static String timesCsvFile = "src_java/times_java.csv";
    static String opsCsvFile = "src_java/ops_java.csv";

    static void initiateFile(String nameOfFile){
        //try to open file, write names of columns into it, then close
        try{
            FileWriter fileWriter =  new FileWriter(nameOfFile);
            fileWriter.write("N,Iterative,Recursive,Dynamic Programming\n");
            fileWriter.close();
        }catch(IOException e){
            System.out.println("Could not write to files");
        }
    }

    public static void main(String[] args){

        //
        boolean repeat = true;
        int N = -1;
        while (N < 0){
            try{
                System.out.println("Enter desired size of table: ");
                Scanner scanner = new Scanner(System.in);
                int input = scanner.nextInt();
                if (input >= 0) N = input;
            }catch (InputMismatchException e){
                System.out.println("Input cannot be negative!");
            }
        }

        //empty files and write names of columns into them
        initiateFile(timesCsvFile);
        initiateFile(opsCsvFile);

        //initiate all fib objects and make array of them
        FibonacciApproach fibonacciIterative = new FibonacciIterative();
        FibonacciApproach fibonacciRecursive = new FibonacciRecursive();
        FibonacciApproach fibonacciRecursiveDynamic = new FibonacciDP(N);

        FibonacciApproach[] fibonaccis = {fibonacciIterative, fibonacciRecursive, fibonacciRecursiveDynamic};


        try{
            //make filewriters in append mode. second arg being true means append mode
            FileWriter timesFileWriter =  new FileWriter(timesCsvFile, true);
            FileWriter opsFileWriter =  new FileWriter(opsCsvFile, true);

            //loop to N
            for (int n = 0; n <= N; n++){
                //append n into file with ,. will have to convert n to int
                opsFileWriter.write(Integer.toString(n) + ",");
                timesFileWriter.write(Integer.toString(n) + ",");

                //loop through fibonacci objects
                for (int i = 0; i < fibonaccis.length; i++){
                    
                    //curr object
                    FibonacciApproach fibonacci = fibonaccis[i];
                    
                    //reset ops
                    fibonacci.setOps(0);
                    
                    //make recursive function not run and print - after certain n number
                    if (i == 1 && n > 50){
                        opsFileWriter.write("-");
                        timesFileWriter.write("-");

                    }else {
                        //run time function passing in object and receive time
                        String time_taken = Helper.time_function(fibonacci, n, 0);
                        
                        //write time and ops into csv files
                        opsFileWriter.write(Integer.toString(fibonacci.getOps()));
                        timesFileWriter.write(time_taken);

                    }
                    //if not running last function, include comma in files
                    if (i != 2) {
                        opsFileWriter.write(",");
                        timesFileWriter.write(",");
                    }

                }
                //go to next line in csv files
                opsFileWriter.write("\n");
                timesFileWriter.write("\n");

            }

            //close files
            opsFileWriter.close();
            timesFileWriter.close();
        }catch(IOException e){
            System.out.println("Could not append to files");
        }

    }
}
