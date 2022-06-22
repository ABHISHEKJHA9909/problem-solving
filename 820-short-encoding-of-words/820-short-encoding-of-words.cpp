class Solution {
public:
    class node{
        public:
        bool isend=0;
        node *next[26];
    };
    
    int length=0;
    
    int is(string s,node *n){
        for(int i=s.size()-1;i>=0;i--){
            char c=s[i];
            n=n->next[c-'a'];
        }
        if(n->isend){
            n->isend=0;
            return 1;
        }
        return 0;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end());
        reverse(words.begin(),words.end());
        
        node *n=new node();
        for(string &s:words){
            node *curr=n;
            for(int i=s.size()-1;i>=1;i--){
                char c=s[i];
                if(curr->next[c-'a']==NULL)
                    curr->next[c-'a']=new node();
                curr=curr->next[c-'a'];
                curr->isend=0;
            }
            if(curr->next[s[0]-'a']==NULL){
                curr->next[s[0]-'a']=new node();
                curr=curr->next[s[0]-'a'];
                curr->isend=1;
            }
        }
        
        for(string &s:words){
            length+=is(s,n)?s.size()+1:0;
        }
        
        return length;
    }
};