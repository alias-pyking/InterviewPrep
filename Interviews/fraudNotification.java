import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
class Solution {


    //notification code 
    static int activityNotifications(int[] expenditure, int d) {
        int []countingSortList = new int[201];
        int medianPostion = -1;
        int end = d;
        int notifications = 0;
        int current = 0;
        if( d % 2 == 0) {
            medianPostion = d/2;
        } else {
            medianPostion = d/2 + 1;
        }
        for(int i = 0; i < end; i++) {
            countingSortList[expenditure[i]]++;
        }
        
        while (end < expenditure.length) {
            double median = getMedian(countingSortList, medianPostion,d);
            if(expenditure[end] >= 2*median) {
                notifications++;
            }
            countingSortList[expenditure[current]]--;
            countingSortList[expenditure[end]]++;
            current++;
            end++;
        }
        return notifications;
    }
    private static double getMedian(int []array,int medianPostion,int d) {
        int counter = 0;
        int left = 0;
        while(counter < medianPostion) {
            counter += array[left];
            left++;
        }
        int right = left;
        left--;
        // odd
        if (counter > medianPostion || d % 2 != 0) {
            return left;
        } else {
            while(array[right] == 0){
                right += 1;
            }
            return ((double)left + right) /2;
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args){

        int n = scanner.nextInt();
        int d = scanner.nextInt();
        int expenditure[] = new int[n];
        for(int i = 0; i < n; i++) {
            expenditure[i] = scanner.nextInt();
        }
        System.out.println(activityNotifications(expenditure, d));
    }
}
