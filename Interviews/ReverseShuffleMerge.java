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
    private static int [] required = new int[NUMBER_OF_CHARACTERS];
    static String reverseShuffleMerge(String s) {
        StringBuffer stringBuffer = new StringBuffer();
        fillFreq(s);
        fillRequired();
        int n = s.length() - 1;
        int len = s.length() / 2;
        for(int i = n; i >= 0; i--) {
            char c = s.charAt(i);
            int code = c - 'a';
            if(required[code] > 0) {
                if(freq[code] <= required[code]) {
                    stringBuffer.append(c);
                    required[code]--;
                } else if(isPrority(code)) {
                    stringBuffer.append(c);
                    required[code]--;
                }
                freq[code]--;
                
            }
        }
        return stringBuffer.toString();
    }
    private static void fillFreq(String s){
        for(char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
    }
    private static void fillRequired() {
        for (int i = 0; i < required.length; i++) {
            required[i] = freq[i]/2;
        }
    }
    private static boolean isPrority(int code) {
        int sum = 0;
        if(required[code] > 0) {
            for(int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
                if(i == code){
                    break;
                }
                sum += required[i];
            }
            if(sum == 0) {
                return true;
            } else{
                return false;
            }
        }
        return false;
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
