import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.Stack;

class Solution {

    // Complete the riddle function below.
    static long[] riddle(long[] arr) {
        Stack<Integer> stack = new Stack<>();
        int n = arr.length;
        long []leftSmaller = new long[n];
        long []rightSmaller = new long[n];
        long []ans = new long[n + 1];
        long len;
        for(int i =0; i < n; i++) {
            leftSmaller[i] = -1;
            rightSmaller[i] = n;
        }
        // leftSmaller contains the index of the element which is less than arr[i] and is to the left of arr[i]
        // Vice versa for rightSmaller
        for(int i = 0; i < n; i++) {
            while(!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            if(!stack.isEmpty()) {
                leftSmaller[i] = stack.peek();
            }
            stack.push(i);
        }
        stack.clear();
        // Debug code
        for(int i = 0; i < leftSmaller.length; i++) {
            System.out.println(i+": "+leftSmaller[i]+", arr[i] :"+arr[i]);
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!stack.isEmpty() && arr[stack.peek()] >= arr[i]){
                stack.pop();
            }
            if(!stack.isEmpty()) {
                rightSmaller[i] = stack.peek();
            }
            stack.push(i);
        }
        Arrays.fill(ans,0);
        for(int i = 0; i < n; i++) {
            len = rightSmaller[i] - leftSmaller[i] - 1;
            ans[(int)len] = Math.max(ans[(int)len], arr[i]);
        }
        for(int i = n -1; i >= 1; i--) {
            ans[i] = Math.max(ans[i],ans[i + 1]);
        }
        
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        long []arr = {3,5,4,7,6,2};
        riddle(arr);
    }
}
