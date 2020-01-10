import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    private static final int NUMBER_OF_CHARACTERS = 26;
    private static int[] getCharCounts(String str){
        int []charCount = new int[NUMBER_OF_CHARACTERS];
        int len = str.length();
        for(int i = 0; i < len; i++){
            char c = str.charAt(i);
            int offset = (int)'a';
            int code = c - offset;
            charCount[code]++;
        }
        return charCount;
    }
    private static int getNumberOfCharsToBeRemoved(int []charCount1, int []charCount2) {
        int numberOfCharsToBeRemoved = 0;
        for(int i =0 ;i < charCount1.length; i++) {
            numberOfCharsToBeRemoved += Math.abs(charCount1[i] - charCount2[i]);
        }
        return numberOfCharsToBeRemoved/2;
    }
    // Complete the anagram function below.
    static int anagram(String s) {
        if(s.length()%2 != 0){
            return -1;
        }  
        String str1 = s.substring(0, s.length()/2 - 1);
        String str2 = s.substring(s.length()/2, s.length() - 1);
        int []charCount1 = getCharCounts(str1);
        int []charCount2 = getCharCounts(str2);
        return getNumberOfCharsToBeRemoved(charCount1,charCount2);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = anagram(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
