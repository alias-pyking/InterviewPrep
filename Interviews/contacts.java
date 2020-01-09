import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;
public class Solution {

    /*
     * Complete the contacts function below.
     */
    public static class Node{
        private static int NUMBER_OF_CHARACTERS = 26;
        Node[] children = new Node[NUMBER_OF_CHARACTERS];
        int size = 0;
        private static int getIndex(char c){
            return c - 'a';
        }
        private Node getNode(char c){
            return children[getIndex(c)];
        }
        private void setNode(char c, Node node){
            children[getIndex(c)] = node;
        }
        public void add(String s){
            add(s,0);
        }
        private void add(String s, int index){
            size++;
            if(index == s.length()){
                return;
            }
            char current = s.charAt(index);
            Node child = getNode(current);
            if(child == null){
                child = new Node();
                setNode(current, child);
            }
            child.add(s, index +1);

        }
        public int findCount(String s, int index){
            if(s.length() == index){
                return size;
            }
            Node child = getNode(s.charAt(index));
            if(child == null){
                return 0;
            }
            return child.findCount(s, index+1);
        }

    }
    static int[] contacts(String[][] queries) {
        Node trie = new Node();
        ArrayList<Integer> answers = new ArrayList<>();
        for(int i = 0; i < queries.length; i++){
            if(queries[i][0] == "add"){
                trie.add(queries[i][1]);
            }
            else{
                answers.add(trie.findCount(queries[i][1], 0));
            }
        }
        int [] ans = new int[answers.size()];
        int a = 0;
        for(Integer i:answers){
            ans[a++] = i;
        }
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int queriesRows = Integer.parseInt(scanner.nextLine().trim());

        String[][] queries = new String[queriesRows][2];

        for (int queriesRowItr = 0; queriesRowItr < queriesRows; queriesRowItr++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");

            for (int queriesColumnItr = 0; queriesColumnItr < 2; queriesColumnItr++) {
                String queriesItem = queriesRowItems[queriesColumnItr];
                queries[queriesRowItr][queriesColumnItr] = queriesItem;
            }
        }

        int[] result = contacts(queries);

        for (int resultItr = 0; resultItr < result.length; resultItr++) {
            bufferedWriter.write(String.valueOf(result[resultItr]));

            if (resultItr != result.length - 1) {
                bufferedWriter.write("\n");
            }
        }

        bufferedWriter.newLine();

        bufferedWriter.close();
    }
}
