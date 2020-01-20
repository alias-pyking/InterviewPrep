import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the triplets function below.
    static long triplets(int[] a, int[] b, int[] c) {
        Arrays.sort(a);
        Arrays.sort(c);
        Set<Integer> aSet = new HashSet<>();
        Set<Integer> cSet = new HashSet<>();
        for(int i = 0; i < a.length; i++) {
            aSet.add(a[i]);
        }
        for(int i = 0; i < c.length; i++) {
            cSet.add(c[i]);
        }
        int []arrayA = new int[aSet.size()];
        int []arrayC = new int[cSet.size()];
        int i = 0;
        for(Integer aInteger : aSet) {
            arrayA[i++] = aInteger;
        }
        i = 0;
        for(Integer cInteger: cSet) {
            arrayC[i++] = cInteger;
        }
        Arrays.sort(arrayA);
        Arrays.sort(arrayC);
        long result = 0;
        Set<Integer> set = new HashSet<>();

        for( i  = 0; i < b.length; i++) {
            set.add(b[i]);
        }

        for(Integer bInteger : set) {
            long a1 = 0;
            long c1 = 0;
            i = 0;
            while( i < arrayA.length) {
                if(arrayA[i] <= bInteger) {
                    a1++;
                    i++;
                } else{
                    break;
                }
            }
            i = 0;
            while(i < arrayC.length) {
                if(arrayC[i] <= bInteger) {
                    c1++;
                    i++;
                } else{
                    break;
                }
            }
            result += a1 * c1;
        }
        return result;
    }
    private static long binarySearch(int []arr,long k) {
        long ans = 0;
        int i  = 0;
        int j =  arr.length - 1;
        if (arr[0] > k) {
            return 0;
        }
        while(i <= j) {
            int mid = (i + j)/2;
            if(arr[mid] == k) {
                int x = mid + 1;
                while(x <= j && arr[mid] == arr[x]) {
                    x++;
                }
                return x;
            }
            if(k < arr[mid]) {
                j =  mid - 1;
                ans = mid + 1;
            }
            if (k > arr[mid]) {
                i = mid + 1;
                ans = mid + 1;
            }
        }
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] lenaLenbLenc = scanner.nextLine().split(" ");

        int lena = Integer.parseInt(lenaLenbLenc[0]);

        int lenb = Integer.parseInt(lenaLenbLenc[1]);

        int lenc = Integer.parseInt(lenaLenbLenc[2]);

        int[] arra = new int[lena];

        String[] arraItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < lena; i++) {
            int arraItem = Integer.parseInt(arraItems[i]);
            arra[i] = arraItem;
        }

        int[] arrb = new int[lenb];

        String[] arrbItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < lenb; i++) {
            int arrbItem = Integer.parseInt(arrbItems[i]);
            arrb[i] = arrbItem;
        }

        int[] arrc = new int[lenc];

        String[] arrcItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < lenc; i++) {
            int arrcItem = Integer.parseInt(arrcItems[i]);
            arrc[i] = arrcItem;
        }

        long ans = triplets(arra, arrb, arrc);

        bufferedWriter.write(String.valueOf(ans));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
