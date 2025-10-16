import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class Tests {

    FibonacciApproach fibIterative;
    FibonacciApproach fibRecursive;
    FibonacciApproach fibDynamicProgramming;

    @Before
    public void setup(){
        fibIterative = new FibonacciIterative();
        fibRecursive = new FibonacciRecursive();
    }

    @Test
    public void testIterative(){
        assertEquals(0, fibIterative.fibonacci(0));
        assertEquals(1, fibIterative.fibonacci(1));
        assertEquals(832040, fibIterative.fibonacci(30));
    }

    @Test
    public void testRecursive(){
        assertEquals(0, fibRecursive.fibonacci(0));
        assertEquals(1, fibRecursive.fibonacci(1));
        assertEquals(832040, fibRecursive.fibonacci(30));
    }

    @Test
    public void testDP1(){
        fibDynamicProgramming = new FibonacciDP(0);
        assertEquals(0, fibDynamicProgramming.fibonacci(0));

    }

    @Test
    public void testDP2(){
        fibDynamicProgramming = new FibonacciDP(1);
        assertEquals(1, fibDynamicProgramming.fibonacci(1));
    }

    @Test
    public void testDP3(){
        fibDynamicProgramming = new FibonacciDP(30);
        assertEquals(832040, fibDynamicProgramming.fibonacci(30));
    }





}
