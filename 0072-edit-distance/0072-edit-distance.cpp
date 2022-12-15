class Solution {
public:
    int n,m;
    map<vector<int>,int>mm;
    
    int rec(string &s,string &t,int i,int j){
        if(mm.find({i,j})!=mm.end())
            return mm[{i,j}];
        if(i==n)
            return m-j;
        if(j==m)
            return n-i;
        
        if(s[i]==t[j])
            return rec(s,t,i+1,j+1);
        return mm[{i,j}]=1+min(rec(s,t,i+1,j+1),min(rec(s,t,i+1,j),rec(s,t,i,j+1)));
    }
    
    int minDistance(string word1, string word2) {
        n=word1.size() , m=word2.size();
        return rec(word1,word2,0,0);
    }
};