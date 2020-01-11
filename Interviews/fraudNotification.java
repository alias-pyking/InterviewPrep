import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the activityNotifications function below.
    public static void quicksort(int []array){
        quicksort(array,0,array.length - 1);
    }
    private static void quicksort(int[] array, int left, int right) {
        if(left >= right) {
            return;
        }
        int pivot = array[(left + right)/2];
        int index = partition(array,left, right, pivot);
        quicksort(array,left,index - 1);
        quicksort(array,index, right);
    }
    private static int partition(int[] array, int left, int right, int pivot) {
        while(left < right) {
            while(array[left] < pivot) {
                left++;
            }
            while(array[right] > pivot) {
                right--;
            }
            if(left <= right) {
                swap(array,left, right);
                left++;
                right--;
            }
        } 
        return left;
    }
    private static void swap(int []array,int left, int right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
    //notification code 
    static int activityNotifications(int[] expenditure, int d) {
        int i = 0;
        int j = d;
        int notifications = 0;
        int []expd = new int[expenditure.length];
        for(int idx = 0; idx < expenditure.length; idx++) {
            expd[idx] = expenditure[idx];
        }
        double[] medians = getMedians(expenditure,i,j,d);
        for(int idx = 0; idx < medians.length; idx++) {
            System.out.print(medians[idx]+",");
        }
        System.out.println();
        i = 0;
        j = d;
        for( ; j < expenditure.length; j++) {
            double median = medians[i];
            System.out.println(2*median+" , "+expd[j]);
            if(2*median <= expd[j]) {
                notifications++;
            }
            i++;
        }
        return notifications;

    }
    private static double[] getMedians(int []expenditure, int i, int j, int d) {
        int []counts = new int[201];
        for(;i <= j; i++) {
            counts[expenditure[i]]++;
        }
        if(d%2 == 0) {
            
        }
    }
    private static double getMedian(int []array, int i, int j, int d) {
        quicksort(array,i,j);
        if(d % 2 == 0)  {
            return ((double)array[(i+j)/2] + array[(i+j)/2 + 1]) /2;
        }
        else {
            return array[(i+j)/2];
        }
        
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] expenditure = new int[n];

        String[] expenditureItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int expenditureItem = Integer.parseInt(expenditureItems[i]);
            expenditure[i] = expenditureItem;
        }

        int result = activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
