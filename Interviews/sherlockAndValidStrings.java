import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the isValid function below.
    private static boolean allSame(List<Integer> arr){
        int first = arr.get(0);
        for(int i =0; i < arr.size(); i++) {
            if(arr.get(i) != first) {
                return false;
            }
        }
        return true;
    }
    static String isValid(String s) {
        if(s.length() == 1) {
            return "YES";
        }
        HashMap<Character,Integer> hashMap = new HashMap<>();
        for(Character c : s.toCharArray()) {
            if(hashMap.containsKey(c)){
                hashMap.put(c,hashMap.get(c) + 1);
            } else{
                hashMap.put(c,1);
            }
        }
        List<Integer> arr = new ArrayList<>();
        for(Character i: hashMap.keySet()) {
            arr.add(hashMap.get(i));
        }
        if(allSame(arr)) {
            return "YES";
        } else {
            int n = arr.size();
            for(int i = 0; i < n; i++) {
                int temp = arr.get(i);
                arr.set(i, temp -1);
                if(allSame(arr)) {
                    return "YES";
                }
                arr.set(i, temp);
            }
        }
        return "NO";

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String s = scanner.nextLine();
        System.out.println(isValid(s));
    }
}
