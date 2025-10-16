public class FibonacciRecursive implements FibonacciApproach{

    public int ops;

    FibonacciRecursive(){
        ops = 0;
    }

    public long fibonacci(int n){

        //base cases
        if (n <= 1) return n;


        this.ops++;

        long left = fibonacci(n - 2);
        long right = + fibonacci(n - 1);
        //recursive case
        //find prev 2 values through recursive calls and add them
        return left + right;

    }

    //getter and setter for ops
    public int getOps(){
        return this.ops;
    }
    public void setOps(int ops){
        this.ops = ops;
    }


}
