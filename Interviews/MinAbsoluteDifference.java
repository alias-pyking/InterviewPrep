import java.util.*;
class Main{
    public static void mergesort(int []arr){
        mergesort(arr,new int[arr.length],0,arr.length - 1);
    }
    private static void mergesort(int []arr,int []temp,int left, int right) {
        if(left >= right) {
            return;
        }
        int mid = (left + right) /2;
        mergesort(arr,temp,left,mid);
        mergesort(arr,temp,mid + 1,right);
        merge(arr,temp,left,right);
    }
    public static int minAbs = Integer.MAX_VALUE;
    private static void merge(int []arr,int []temp,int leftStart, int rightEnd) {
        int leftEnd = (rightEnd + leftStart)/2;
        int rightStart = leftEnd + 1;
        int size = rightEnd - leftStart + 1;
        int left = leftStart;
        int right = rightStart;
        int index = leftStart;
        while(left <= leftEnd && right <= rightEnd) {
            int tempMin = Math.abs(arr[left] - arr[right]);
            if(tempMin < minAbs) {
                minAbs = tempMin;
            }
            if(arr[left] <= arr[right]) {
                temp[index++] = arr[left++];
            } else {
                temp[index++] = arr[right++];
            }
        }
        while(left <= leftEnd) {
            temp[index++] = arr[left++];
        }
        while(right <= rightEnd) {
            temp[index++] = arr[right++];
        }
        System.arraycopy(temp, leftStart, arr, leftStart, size);
    }
    public static void main(String[] args) {
        int []arr = {-59 ,-36, -13, 1, -53, -92, -2 ,-96, -54, 75};
        mergesort(arr); 
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+",");
        }  
        System.out.println();
        System.out.println(minAbs);
    }
}