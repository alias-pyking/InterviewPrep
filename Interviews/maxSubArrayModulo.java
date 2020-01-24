import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the maximumSum function below.
    static long maximumSum(long[] a, long m) {
        long []sum = new long[a.length];
        TreeSet<Long> tree = new TreeSet<>();
        sum[0] = a[0];
        sum[0] %= m;
        tree.add(sum[0]);
        long result = sum[0];
        for(int i = 1; i < a.length; i++) {
            sum[i] = (sum[i -1] + a[i]);
            sum[i] %= m;
            Long higher = tree.higher(sum[i]);
            if (higher == null) {
                result = Math.max(result,sum[i]);
            } else{
                result = Math.max((sum[i] - result + m)%m, result);
            }
            tree.add(sum[i]);
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String[] nm = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nm[0]);

            long m = Long.parseLong(nm[1]);

            long[] a = new long[n];

            String[] aItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                long aItem = Long.parseLong(aItems[i]);
                a[i] = aItem;
            }

            long result = maximumSum(a, m);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
