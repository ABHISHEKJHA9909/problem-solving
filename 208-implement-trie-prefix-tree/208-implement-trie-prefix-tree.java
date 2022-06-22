class Trie {
    class node{
        Boolean isend=false;
        node next []=new node[26];
    }
    
    node no=new node();
    
    public Trie() {
        
    }
    
    public void insert(String word) {
        node n=no;
        for(int i=0;i<word.length();i++){
            if(n.next[word.charAt(i)-'a']==null)
                n.next[word.charAt(i)-'a']=new node();
            n=n.next[word.charAt(i)-'a'];
        }
        n.isend=true;
    }
    
    public boolean search(String word) {
        node n=no;
        for(int i=0;i<word.length();i++){
            if(n.next[word.charAt(i)-'a']==null)
                return false;
            n=n.next[word.charAt(i)-'a'];
        }
        return n.isend;
    }
    
    public boolean startsWith(String word) {
        node n=no;
        for(int i=0;i<word.length();i++){
            if(n.next[word.charAt(i)-'a']==null)
                return false;
            n=n.next[word.charAt(i)-'a'];
        }
        return true;
    }
}