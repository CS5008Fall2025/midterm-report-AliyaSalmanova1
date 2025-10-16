public class Helper {

    public static void printIntArray(int[] array, int size){
        for (int i = 0; i < size; i++){
            System.out.println(array[i] + " ");
        }
        System.out.println("\n");
    }

    public static String time_function(FibonacciApproach fibonacci, int n, int print){
        //get start time, run function, get end time
        long startTime = System.nanoTime();
        long result = fibonacci.fibonacci(n);
        long endTime = System.nanoTime();
        
        //subtract times, and divide by 1000000 to get milliseconds from nanoseconds
        double time_ms = (endTime - startTime) / 1_000_000.0;

        if (print == 1) {
            System.out.println("Result: " + result + "\n");
        }
        
        //format string, return
        return String.format("%.6f", time_ms);


    }
}
