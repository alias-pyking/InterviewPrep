import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the runningMedian function below.
     */
     public static void addNumber(int number, PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers){
        if(lowers.size() == 0 || lowers.peek() > number){
            lowers.add(number);
        } else {
            highers.add(number);
        } 
    }
    public static void rebalance(PriorityQueue<Integer> lowers, PriorityQueue<Integer> highers){
        PriorityQueue<Integer> biggerHeap = lowers.size() > highers.size()?lowers:highers;
        PriorityQueue<Integer> smallerHeap = lowers.size() > highers.size()?highers:lowers;
        if(biggerHeap.size() - smallerHeap.size() >= 2){
            smallerHeap.add(biggerHeap.poll());
        } 
    }
    public static double getMedian(PriorityQueue<Integer> lowers, PriorityQueue<Integer>    highers){
        PriorityQueue<Integer> biggerHeap = lowers.size() > highers.size()?lowers:highers;
        PriorityQueue<Integer> smallerHeap = lowers.size() > highers.size()?highers:lowers;
        if(biggerHeap.size() == smallerHeap.size()){
            return ((double)biggerHeap.peek() + smallerHeap.peek()) /2;
        } else {
            return biggerHeap.peek();
        }

    }
    static double[] runningMedian(int[] array) {
        PriorityQueue<Integer> lowers = new PriorityQueue<>(new Comparator<Integer>() {
           public int compare(Integer a, Integer b){
               return -1 * a.compareTo(b);
           }
       }); //max heap
       PriorityQueue<Integer> highers = new PriorityQueue<>(); //min heap
       double [] medians = new double[array.length];
       for(int i = 0 ;i < array.length; i++) {
           int number = array[i];
           addNumber(number, lowers, highers);
           rebalance(lowers,highers);
           medians[i] = getMedian(lowers,highers);
       }
       return medians;

    }
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        
    }
}
