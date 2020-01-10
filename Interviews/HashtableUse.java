import java.util.*;
class Main{
    public static void main(String []args){
        HashMap<String,Integer> magzineFrequency = new HashMap<>();
        String [] mag = {"two","times","three","is","not","four"};
        String [] note = {"two","times","two","is","four"};
        for(String word : mag) {
            if(!magzineFrequency.containsKey(word)){
                magzineFrequency.put(word,1);
            } else{
                magzineFrequency.put(word, magzineFrequency.get(word) + 1);
            }
        }
        for(Map.Entry<String,Integer> entry : magzineFrequency.entrySet()){
            System.out.println(entry.getKey()+","+entry.getValue());
        }
        System.out.println(magzineFrequency.toString());
    }
}