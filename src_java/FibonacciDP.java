public class FibonacciDP implements FibonacciApproach{
    public int ops;
    public int[] dpArray;

    FibonacciDP(int n){

        this.dpArray = new int[n + 1];
        ops = 0;
    }

    public int fibonacci(int n){

        //base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        //dynamic programming: if array[n] is not zero, it has already been calculated so return value
        else if (this.dpArray[n] != 0){
            return this.dpArray[n];
        }

        this.ops++;
        //find prev 2 values through recursive calls and add them. assign that to array[n] to save value
        this.dpArray[n] = fibonacci(n - 2)
                + fibonacci(n - 1);

        //return nth fib
        return this.dpArray[n];

    }

    //getter and settera for ops
    public int getOps(){
        return this.ops;
    }
    public void setOps(int ops){
        this.ops = ops;
    }


}
