


public class FibonacciIterative implements FibonacciApproach{

    public int ops;

    FibonacciIterative(){
        ops = 0;
    }
    public int fibonacci(int n){
        //set up prev and curr
        int prev = 0;
        int curr = 1;

        //loop to n
        for (int i = 0; i < n; i++){

            this.ops++;
            //curr becomes curr + prev, and prev becomes old curr
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }

        //should return nth fib
        return prev;
    }

    //getter and setter for ops
    public int getOps(){
        return this.ops;
    }
    public void setOps(int ops){
        this.ops = ops;
    }






}

