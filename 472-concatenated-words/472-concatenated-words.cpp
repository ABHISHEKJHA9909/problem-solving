class Solution {
public:
    static bool comp(string a,string b){
        return a.size()<b.size();
    }
    
    class node{
        public:
        node *next[26];
        bool is=false;
    };
    
    bool find(int i,string s,node *n){
        if(i==s.size())
            return true;
        
        node *curr=n;
        
        for(;i<s.size();i++){
            if(curr->next[s[i]-'a']==NULL)
                return false;
            curr=curr->next[s[i]-'a'];
            if(curr->is && find(i+1,s,n)){
                return true;
            }
        }
        
        return false;
    }
    
    void insert(string word,node *n){
        node *curr=n;
        for(char c:word){
            if(curr->next[c-'a']==NULL)
                curr->next[c-'a']=new node();
            
            curr=curr->next[c-'a'];
        }
        curr->is=true;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        
        node *n=new node();
        vector<string>res;
        
        for(string &s:words){
            if(find(0,s,n))
                res.push_back(s);
            insert(s,n);
        }
        
        return res;
    }
};