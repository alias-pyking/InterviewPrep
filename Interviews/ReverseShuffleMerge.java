import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the reverseShuffleMerge function below.
    public static int NUMBER_OF_CHARACTERS = 26;
    private static int [] freq = new int[NUMBER_OF_CHARACTERS];
    static String reverseShuffleMerge(String s) {
        int uniqueElement = fillFreq(s);
        for(int i = 0; i < freq.length; i++) {
            freq[i] /= 2;
        }
        int lastIndex = s.length();
        StringBuffer result = new StringBuffer();
        while(uniqueElement > 0) {
            // find the smallest window which has the elements of freq as subsequence
            int []tempFreq = freq.clone();
            int tempuniqueElement = uniqueElement;
            int windowSize = 0;
            for(int i = 0; i < s.length(); i++) {
                char current = s.charAt(i);
                tempFreq[current - 'a']--;
                if(tempFreq[current - 'a'] == 0) tempuniqueElement--;
                if(tempuniqueElement == 0) break;
                windowSize++;
            }
            Character minChar = null;
            for(int i = lastIndex - 1; i >= windowSize; i--) {
                char c = s.charAt(i);
                if(freq[c- 'a'] == 0) {
                    continue;
                }
                if(minChar == null || minChar > c) {
                    minChar = c;
                    lastIndex = i;
                }
            }
            result.append(minChar);
            freq[minChar -'a']--;
            if(freq[minChar -'a'] == 0) {
                uniqueElement--;
            }
        }
        return result.toString();

    }
    private static int fillFreq(String s){
        int uniqueElement = 0;
        for(char c : s.toCharArray()) {

            if(freq[c-'a'] == 0) {
                uniqueElement++;
            }
            freq[c - 'a']++;
        }
        return uniqueElement;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scanner.nextLine();

        String result = reverseShuffleMerge(s);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}