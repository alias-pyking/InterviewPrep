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
        TreeSet<Long> prefix = new TreeSet<>();
        long current = 0;
        long maxSum = 0;
        int n = a.length;
        for(int i = 0; i < n; i++) {
            current = (a[i] % m + current) % m;
            SortedSet<Long> set = prefix.tailSet(current);
            Iterator<Long> itr = set.iterator();
            if(itr.hasNext()) {
                maxSum = Math.max(maxSum,(current - itr.next() + m)  %m);
            }
            maxSum = Math.max(maxSum,current);
            prefix.add(current)
            
        }
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
