class Solution {
public:
    vector<string>res;
    vector<vector<int>>vis;
    int r,c;
    
    class node{
        public:
        node *next[26];
        int isword=0;
    };
    
    void insert(node* n,string s){
        node* c=n;
        for(char t:s){
            if(c->next[t-'a']==NULL)
                c->next[t-'a']=new node();
            c=c->next[t-'a'];
        }
        c->isword=c->isword+1;
    }
    
    void search(node* n,vector<vector<char>>& arr,int i,int j,string &s){
        if(n->isword){
            while(n->isword){
                res.push_back(s);
                n->isword-=1;
            }
        }
        
        if(i<0||i==r||j<0||j==c||vis[i][j]==1||n->next[arr[i][j]-'a']==NULL)
            return;
        
        s.push_back(arr[i][j]);
        vis[i][j]=1;
        search(n->next[arr[i][j]-'a'],arr,i+1,j,s);
        search(n->next[arr[i][j]-'a'],arr,i-1,j,s);
        search(n->next[arr[i][j]-'a'],arr,i,j+1,s);
        search(n->next[arr[i][j]-'a'],arr,i,j-1,s);
        s.pop_back();
        vis[i][j]=0;
    }
    
    vector<string> findWords(vector<vector<char>>& arr, vector<string>& words) {
        node *n=new node();
        
        for(string &s:words){
            insert(n,s);
        }
        
        r=arr.size(),c=arr[0].size();
        vis=vector<vector<int>>(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                node *c=n;
                string s;
                search(c,arr,i,j,s);
            }
        }
        
        return res;
    }
};