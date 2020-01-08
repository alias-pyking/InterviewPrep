import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sk = new Scanner(System.in);
        int arr[] = new int[10];
        System.out.println(arr);
        System.out.println(arr + 1);

    }
    public static int[][] subsets( int input[]) {
        int output[][] = new int[1000][20];
        if (input.lenght == 0) {
            output[0][0] = {};
            return output;
        }
        int [][] smallOutput = subsets(input + 1)
    }
}