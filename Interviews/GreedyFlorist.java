import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the getMinimumCost function below.
    static int getMinimumCost(int k, int[] c) {
        int n = c.length;
        Integer minCost = new Integer(0);
        Integer []arr = new Integer[c.length];
        for(int i = 0; i < c.length; i++) {
            arr[i] = c[i];
        }
        Arrays.sort(arr,Collections.reverseOrder());
        for(int i = 0; i < arr.length; i++) {
            if( i < k) {
                minCost += arr[i];
            } else{
                int temp = i / k;
                minCost += (temp + 1) * arr[i];
            }
        }
        return (int)minCost;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nk = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nk[0]);

        int k = Integer.parseInt(nk[1]);

        int[] c = new int[n];

        String[] cItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int cItem = Integer.parseInt(cItems[i]);
            c[i] = cItem;
        }

        int minimumCost = getMinimumCost(k, c);

        bufferedWriter.write(String.valueOf(minimumCost));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
