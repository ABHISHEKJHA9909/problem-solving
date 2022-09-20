class node{
    public:
    node *next[26];
    bool is=false;
};

class WordDictionary {
public:
    node *n;
    WordDictionary() {
        n=new node();
    }
    
    void addWord(string word) {
        node* c=n;
        for(char ch:word){
            if(c->next[ch-'a']==NULL)
                c->next[ch-'a']=new node();
            c=c->next[ch-'a'];
        }
        c->is=true;
    }
    
    bool dfs(node* &c,string& word,int i){
        if(i==word.size())
            return c->is;
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(c->next[j]!=NULL && dfs(c->next[j],word,i+1))
                    return true;
            }
            return false;
        }
        return c->next[word[i]-'a']==NULL?false:dfs(c->next[word[i]-'a'],word,i+1);
    }
    
    bool search(string word) {
        node* c=n;
        return dfs(c,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */