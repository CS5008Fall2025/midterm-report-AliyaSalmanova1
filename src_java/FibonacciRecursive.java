public class FibonacciRecursive implements FibonacciApproach{

    public int ops;

    FibonacciRecursive(){
        ops = 0;
    }

    public int fibonacci(int n){

        //base cases
        if (n <= 1) return n;


        this.ops++;
        //recursive case
            //find prev 2 values through recursive calls and add them
        return fibonacci(n - 2)
                + fibonacci(n - 1);

    }

    //getter and setter for ops
    public int getOps(){
        return this.ops;
    }
    public void setOps(int ops){
        this.ops = ops;
    }





}
