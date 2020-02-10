class Solution{
    private static int minLength(int []plots, int k) {
        // Find the minimum length contigous subarray with sum k
        int runningSum = 0;
        int i = 0;
        int j = 0;
        int ans = Integer.MAX_VALUE;
        while (i < plots.length && j < plots .length) {
            if(runningSum == k) {
                ans = Math.min(ans, j - i);
                i++;
                j++;
            }
            if(runningSum < k) {
                runningSum += plots[j];
                j++;
            }
            if(runningSum > k) {
                runningSum -= plots[i];
                i++;
            }
            System.out.println("pass");
        }
        return ans;
    }
    public static void main(String []args) {
        int []plots = {1,3,2,1,4,1,3,2,1,1,2};
        System.out.println(minLength(plots, 8));
    }
}