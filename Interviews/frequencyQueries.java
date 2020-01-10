import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Solution {

    // Complete the freqQuery function below.
    static List<Integer> freqQuery(List<List<Integer>> queries) {
        List<Integer> answers = new ArrayList<>();
        Map<Integer,Integer> frequencies = new HashMap<>();
        int cache[] = new int[1000000];
        for(int i = 0; i < queries.size(); i++) {
            int query = queries.get(i).get(0);
            int data = queries.get(i).get(1);
            if(query == 1) {
                // insert the element in the data structure
                if(!frequencies.containsKey(data)) {
                    frequencies.put(data,1);
                    Integer key = frequencies.get(data);
                    cache[key]++;
                } else {
                    Integer key = frequencies.get(data);
                    cache[key]--;
                    frequencies.put(data, frequencies.get(data) + 1);
                    key = frequencies.get(data);
                    cache[key]++;

                    
                }
                continue;
            }
            if(query == 2) {
                if(frequencies.containsKey(data) && frequencies.get(data) > 0) {
                    Integer key = frequencies.get(data);
                    if(cache[key] > 0){
                        cache[key]--;
                    }
                    frequencies.put(data,frequencies.get(data) - 1);   
                    key = frequencies.get(data);
                    cache[key]++;
                }
                continue;
            }
            if(query == 3) {
                if(cache[data]> 0) {
                    answers.add(1);
                }
                else{
                    answers.add(0);
                }
            }
        }
        return answers;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> queries = new ArrayList<>();

        IntStream.range(0, q).forEach(i -> {
            try {
                queries.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<Integer> ans = freqQuery(queries);

        bufferedWriter.write(
            ans.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}

