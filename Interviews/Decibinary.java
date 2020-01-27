import java.util.*;
class Solution{
    private static int db(int deci){
        String dec = ""+deci;
        int n = dec.length();
        int t = n - 1;
        int decimal = 0;

        for(int i = 0; i < n; i++) {
            decimal += (dec.charAt(i) - '0') * Math.pow(2, t);
            t--;
        }
        return decimal;
    }
    
    public static void main(String[] args) {
        System.out.println(db(13));   
    }
}