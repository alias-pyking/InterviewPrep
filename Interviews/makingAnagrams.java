import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the makeAnagram function below.
    static int NUMBER_OF_CHARS = 26;
    private static int [] getCharCount(String str) {
        int []charCount = new int[NUMBER_OF_CHARS];
        for(char c : str.toCharArray()) {
            int code = c-'a';
            charCount[code]++;
        }
        return charCount;
    }
    static int makeAnagram(String a, String b) {
        int [] charCounts1 = getCharCount(a);
        int [] charCounts2 = getCharCount(b);
        int numberOfDeletions = 0;
        for(int i =0; i < charCounts1.length; i++) {
            numberOfDeletions += Math.abs(charCounts1[i] - charCounts2[i]);
        }
        return numberOfDeletions;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

