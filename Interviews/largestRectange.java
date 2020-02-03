import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.*;
import java.util.Stack;

class Solution {

    // Complete the largestRectangle function below.
    static long largestRectangle(int[] h) {
        Stack<Integer> indecies = new Stack<>();
        int i = 0;
        long ans = -1;
        while(i < h.length) {
            int currentH = h[i];
            if(indecies.isEmpty()|| h[indecies.peek()] < currentH){
                indecies.push(i);
                continue;
            } else if(currentH < h[indecies.peek()]) {
                int tempP,tempH;
                while(!indecies.isEmpty() && currentH < h[indecies.peek()]) {
                    tempP = indecies.pop();
                    tempH = h[tempP];
                    ans = Math.max(ans,(i - tempP) * tempH);
                }
                indecies.push(i);
            }
            i++;
        }
        while(!indecies.isEmpty()) {
           int tempP = indecies.pop();
           int tempH = h[tempP];
            ans = Math.max(ans,(h.length - tempP) * tempH);
        }
        return ans;
        
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] h = new int[n];

        String[] hItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int hItem = Integer.parseInt(hItems[i]);
            h[i] = hItem;
        }

        long result = largestRectangle(h);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
