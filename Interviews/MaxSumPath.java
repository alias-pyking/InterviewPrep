import java.util.*;
class Solution{
    private static int getMaxSumPath(int n, int m, int [][]matrix) {
        return getMaxSumPath(n, m, matrix, 0,0);
    }
    private static int getMaxSumPath(int n, int m , int [][]matrix, int i, int j) {
        if(i == n - 1 && j == m - 1) {
            return matrix[i][j];
        }
        if(i == n - 1){
            return matrix[i][j] + getMaxSumPath(n, m, matrix,i, j + 1);
        }else if (j == n - 1) {
            return matrix[i][j] + getMaxSumPath(n, m, matrix,i + 1, j);
        } else {
            int t1 = matrix[i][j] + getMaxSumPath(n, m, matrix,i, j + 1);
            int t2 = matrix[i][j] + getMaxSumPath(n, m, matrix,i + 1, j);
            return Math.max(t1, t2);
        }
    }
    public static void main(String []args) {
        int n = 4;
        int m = 4;
        int [][]matrix = {  {1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12},
                            {13,14,15,16}
            };
        int maxSumPath = getMaxSumPath(n,m,matrix);
        System.out.println(maxSumPath);

    }
}