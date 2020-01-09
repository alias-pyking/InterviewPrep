import java.util.ArrayList;
import java.util.*;

class MinHeap{
    private int [] items;
    int size = 0;
    public MinHeap(){
        items = new int[10000];
    }
    public boolean isEmpty(){
        return size == 0;
    }
    public int getSize(){
        return size;
    }
    public int getMin(){
        if(size == 0){
            return -1;
        }
        return items[0];
    }
    public void add(int data){
        items[size++] = data;
        int childIndex = size - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            if(items[childIndex] < items[parentIndex]){
                int temp = items[childIndex];
                items[childIndex] = items[parentIndex];
                items[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    public int deleteMin(){
        int ans = items[0];
        int min = 0;
        items[0] = items[--size];
        int parentIndex = 0;
        while(parentIndex < size){
            int leftChildIndex = (2*parentIndex) + 1;
            int rightChildIndex = (2 * parentIndex) + 2;
            if(leftChildIndex < size && rightChildIndex < size){
                if(items[leftChildIndex] > items[rightChildIndex]){
                    min = rightChildIndex;
                } else{
                    min = leftChildIndex;
                }
            }
            if(leftChildIndex < size && rightChildIndex >= size){
                min = leftChildIndex;
            }
            if(items[parentIndex] > items[min]){
                int temp = items[min];
                items[min] = items[parentIndex];
                items[parentIndex] = temp;
                parentIndex = min;
            }
            else{
                break;
            }
        }
        return ans;
    }
    public void printAllElements(){
        for(int i = 0; i < size; i++){
            System.out.print(items[i]+",");
        }
        System.out.println();
    }
    @Override
    


}

class Main {
    public static void main(String[] args) {
        System.out.println("start ");
        MinHeap heap = new MinHeap();
        heap.add(10);
        heap.add(90);
        heap.add(1);
        heap.add(2);
        heap.add(120);
        heap.add(5);
        heap.printAllElements();
        heap.deleteMin();
        heap.printAllElements();
        heap.deleteMin();
        heap.printAllElements();
        heap.deleteMin();
        heap.printAllElements();
    }
}