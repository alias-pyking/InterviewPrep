import java.util.*;
class Solution{
    public static long substrCount(int n,String str) {
        long result = 0;
        int []sameChr = new int[n];

        int [] frequencies = new int[n];;
        for(int i =0; i < n; i++ ) {
            char a = str.charAt(i);
            int j = 0;
            for(j = i + 1; j < n; j++) {
                char b = str.charAt(j);
                if(a == b) {
                    continue;
                } else{
                    break;
                }
            }
            frequencies[i] = j - i;
        }
        for(int i = 0; i < frequencies.length; i++) {
            result += (frequencies[i]*(frequencies[i] + 1) /2);
        }


        for(int j = 1; j < n; j++) {
            if(str.charAt(j) == str.charAt(j - 1)) {
                frequencies[j] = frequencies[j -1];
            }
            if(j > 0 && j < n - 1 && str.charAt(j - 1) == str.charAt(j + 1) && str.charAt(j) != str.charAt(j - 1)) {
                result += Math.min(frequencies[j-1], frequencies[j + 1]);
            }
        }
        return result;

    }
    public static void main(String[] args) {
        
    }
}