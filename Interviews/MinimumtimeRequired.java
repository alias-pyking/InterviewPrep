import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.Arrays;

class Solution {

    // Complete the minTime function below.
    static long getItemsProduced(long days, long [] machines,long goal) {
        long items = 0;
        for(int i = 0; i < machines.length; i++) {
            items += days / machines[i];
        }
        return items;
    }
    static long minTime(long[] machines, long goal) {
        long days = 0;
        Arrays.sort(machines);
        
        long left = 1;
        long right = machines[machines.length - 1];
        while(left < right) {
            long mid = (left + right) /2;
            long itemsProduced = getItemsProduced(mid, machines, goal);
            if (itemsProduced < goal) {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return right;

    }
    private static Scanner scanner =  new Scanner(System.in);
    public static void main(String[] args){
        int n = scanner.nextInt();
        long goal = scanner.nextLong();
        long []machines = new long[n];
        for(int i = 0; i < machines.length; i++) {
            machines[i] = scanner.nextLong();
        }
        System.out.println(minTime(machines, goal));

    }
}
