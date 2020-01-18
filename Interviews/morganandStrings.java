import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the morganAndString function below.
    static String morganAndString(String a, String b) {
        int n = a.length();
        int m = b.length();
        int i = 0;
        int j = 0;
        StringBuffer result = new StringBuffer();
        while(i < n && j < m) {
            char a1 = a.charAt(i);
            char b1 = b.charAt(j);
            if(a1 - 'A' <= b1 - 'A') {
                result.append(a1);
                i++;
            } else {
                result.append(b1);
                j++;
            }
        }
        while(i < n) {
            result.append(a.charAt(i));
            i++;
        }
        while(j < m) {
            result.append(b.charAt(j));
            j++;
        }
        return result.toString();

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String a = scanner.nextLine();
        String b = scanner.nextLine();
        System.out.println(morganAndString(a, b));
        scanner.close();
    }
}