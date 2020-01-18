import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the isValid function below.
    static String isValid(String s) {
        if(s.length() == 1) {
            return "YES";
        }
        int [] freq = new int[26];
        for(char c : s.toCharArray()) {
            int code = c -'a';
            freq[code]++;
        }
        int []frequencyOfFreq = new int[s.length()];
        for(int i = 0; i < freq.length; i++) {
            frequencyOfFreq[freq[i]]++;
        }
        int maxFrequency = 0;
        int freqDiff = 0;
        int max = 0;
        System.out.println(Arrays.toString(frequencyOfFreq));
        System.out.println(Arrays.toString(freq));
        for(int i = 0; i < frequencyOfFreq.length; i++) {
            if(max < frequencyOfFreq[i] && frequencyOfFreq[i] != 0) {
                max = frequencyOfFreq[i];
                maxFrequency = i;
            }
        }
        
        for(int i =0; i < freq.length; i++) {
            if(freq[i] != maxFrequency  && freq[i] != 0) {
                freqDiff++;
                if(freqDiff > 1) {
                    System.out.println((char)(i +'a'));
                    return "NO";
                }
                if(Math.abs(freq[i] - maxFrequency) > 1){ 
                    System.out.println((char)(i +'a'));
                    return "NO";
                }
            } 
        }
        return "YES";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String s = scanner.nextLine();
        System.out.println(isValid(s));
    }
}
