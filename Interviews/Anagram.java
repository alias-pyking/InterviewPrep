class Solution{
    private static final int NUMBER_OF_CHARACTERS = 26;
    private static int getDelta(int []array1, int []array2){
        int delta = 0;
        for(int i = 0; i < array1.length; i++) {
            delta += Math.abs(array1[i] - array2[i]);
        }
        return delta;
    }
    private static int getCharCounts(String str){
        int [] charCounts = new int[NUMBER_OF_CHARACTERS];
        for(int i = 0; i < str.length(); i++){
            char c = str.charAt(i);
            int offset = (int)'a';
            int code = c - offset;
            charCounts[code]++;
        }
        return charCounts;
    }
    public static int numberNeeded(String first, String second){
        int []charCount1 = getCharCounts(first);
        int []charCount2 = getCharCounts(second);
        return getDelta(charCount1, charCount2);
    }
    public static void main(String[] args) {
        
    }
}