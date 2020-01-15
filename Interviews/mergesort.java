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
    private static void merge(int []arr,int []temp,int leftStart, int rightEnd) {
        int leftEnd = (rightEnd + leftStart)/2;
        int rightStart = leftEnd + 1;
        int size = rightEnd - leftStart + 1;
        int left = leftStart;
        int right = rightStart;
        int index = leftStart;
        while(left <= leftEnd && right <= rightEnd) {
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
        int []arr = {6,3,0,1,14,90,2,4,80};
        mergesort(arr); 
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+",");
        }  
        System.out.println();
    }
}