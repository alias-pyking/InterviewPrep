import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the abbreviation function below.
    static String abbreviation(String a, String b) {
        char []x = a.toCharArray();
        char []y = b.toCharArray();
        boolean [][]dp = new boolean[x.length + 1][y.length + 1];
        for(int i= 0;i  < x.length; i++) {
            for(int j = 0; j < y.length; j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for(int i = 0; i  < x.length; i++) {
            for(int j = 0; j <= y.length; j++) {
                if(dp[i][j]) {
                    if( j < y.length && (Character.toUpperCase(x[i]) == y[j])) {
                        dp[i + 1][j + 1] = true;
                    }
                    if(!Character.isUpperCase(x[i])) {
                        dp[i + 1][j] = true;
                    }
                }
            }
        }
        return dp[x.length][y.length]?"YES":"NO";
    }
    

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String a = "daBcd";
        String b = "ABC";
        abbreviation(a, b);

    }
}
