import java.util.Map;

class Trie{
    private class TrieNode{
        Map<Character,TrieNode> children;
        boolean endOfWord;
        public TrieNode(){
            children = new HashMap<>();
            endOfWord = false;
        }
    }
    private final TrieNode root;
    public Trie(){
        root = new TrieNode();
    } 
    // ab 
    public void insert(String word){
        TrieNode current = root;
        for(char ch:word.toCharArray()){
            TrieNode node = current.children.get(ch);
            if(node == null){
                node = new TrieNode();
                current.children.put(ch, node);
            }
            current = node;
        }
        current.endOfWord = true;
    }
    public boolean search(String word){
        TrieNode current = root;
        for(char ch:word.toCharArray()){
            TrieNode node = current.children.get(ch);
            if(node == null){
                return false;
            }
            current = node;
        }
        return current.endOfWord;
    }
}