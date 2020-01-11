class Main{
    public static void quicksort(int []array){
        quicksort(array,0,array.length - 1);
    }
    private static void quicksort(int[] array, int left, int right) {
        if(left >= right) {
            return;
        }
        int pivot = array[(left + right)/2];
        int index = partition(array,left, right, pivot);
        for(int i =0; i< array.length; i++) {
            System.out.print(array[i]+",");
        }
        System.out.println();
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
    public static void main(String[] args) {
        int []array = {1,4,3,2,9,100,12};
        quicksort(array);
        for(int i =0; i< array.length; i++) {
            System.out.print(array[i]+",");
        }
        System.out.println();
    }
}