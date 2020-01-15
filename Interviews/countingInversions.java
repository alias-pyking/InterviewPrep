import java.util.Scanner;

class Solution{
    private static long inversions = 0;
    public static void mergesort(long []array) {
        mergesort(array,new long[array.length],0,array.length - 1);
    }
    private static void mergesort(long []array,long []temp, int left, int right) {
        if(left >= right) {
            return;
        }
        int mid = (left + right)/2;
        mergesort(array,temp,left,mid);
        mergesort(array,temp,mid + 1,right);
        merge(array,temp,left,right);
    }
    private static void merge(long []array,long []temp, int leftStart, int rightEnd) {
        int leftEnd = (leftStart + rightEnd) /2;
        int rightStart = leftEnd + 1;
        int size = (rightEnd - leftStart + 1);
        int left = leftStart;
        int right = rightStart;
        int index = leftStart;
        while(left <= leftEnd && right <= rightEnd) {
            if(array[left] <= array[right]) {
                temp[index++] = array[left++];
            } else {
                inversions += leftEnd - left + 1;
                temp[index++] = array[right++];
            }
        }
        while(left <= leftEnd) {
            temp[index++] = array[left++];
        }
        while(right <= rightEnd) {
            temp[index++] = array[right++];
        }
        System.arraycopy(temp, leftStart, array, leftStart, size);
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int d = input.nextInt();
        while(d > 0){
            int n = input.nextInt();
            long [] arr =new long[n ];
            for(int i =0; i < arr.length; i++) {
                arr[i] = input.nextLong();
            }
            mergesort(arr);
            System.out.println(inversions);
            inversions = 0;
            d--;
        } 
    }
}