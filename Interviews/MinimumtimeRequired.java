import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution {

    // Complete the minTime function below.
    static long minTime(long[] machines, long goal) {
        long days = 0;
        long inc = Integer.MAX_VALUE;
        for(int i =0; i < machines.length; i++)  {
            if(inc > machines[i]) {
                inc = machines[i];
            }
        }
        long items = 0;
        days += inc;
        while(days <= 20) {
            items = 0;
            for(int i = 0; i < machines.length; i++) {
                items += days / machines[i];
                if (items >= goal) {
                    return days;
                }
            }
            if(items >= goal) {
                break;
            }
            days += inc;
        }
        return days;

    }
    public static void main(String[] args) throws IOException {
        long []machines = {4, 5, 6};
        System.out.println(minTime(machines, 12));
    }
}
