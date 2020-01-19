import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the commonChild function below.
    static int commonChild(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        return commonChild(s1,s2,n,m);
    }
    private static int commonChild(String s1, String s2, int n, int m){
        int [][]dp =  new int[n + 1][m + 1];
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if( i == 0 || j == 0){
                    dp[i][j] = 0;
                } else if(s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j]  = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        String s1 = scanner.nextLine();

        String s2 = scanner.nextLine();

        int result = commonChild(s1, s2);
        System.out.println(result);

    }
}
