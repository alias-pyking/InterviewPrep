import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the sherlockAndAnagrams function below.
    private static ArrayList<String> getAllSubstrings(String str) {
        ArrayList<String> result = new ArrayList<>();
        for(int i = 0; i < str.length(); i++) {
            for(int j = i + 1; j < str.length() + 1; j++) {
                result.add(str.substring(i, j));
            }
        }
        return result;
    }
    private static int[] getCharCounts(String string) {
        int[] charCount = new int[26];
        for(int i = 0; i < string.length(); i++) {
            int code = string.charAt(i) - 'a';
            charCount[code]++;
        }
        return charCount;
    }
    private static boolean isAnagrammatic(String str1, String str2) {
        int []charCount1 = getCharCounts(str1);
        int []charCount2 = getCharCounts(str2);
        int ans = 0;
        for(int i = 0; i< charCount1.length; i++) {
            ans += Math.abs(charCount1[i] - charCount2[i]);
        }
        return ans == 0;
    }
    static int sherlockAndAnagrams(String s) {
        ArrayList<String> subStrings = getAllSubstrings(s);
        int counts = 0;
        int n = subStrings.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n;j++) {
                String a = subStrings.get(i);
                String b = subStrings.get(j);
                if(a.length()== b.length() && isAnagrammatic(a, b)) {
                    counts++;
                }
            }
        }
        return counts;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = sherlockAndAnagrams(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}

