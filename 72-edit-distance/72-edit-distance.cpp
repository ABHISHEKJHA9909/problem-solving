class Solution {
public:
    map<pair<int,int>,int>mp;
    
    int rec(string &s,string &t,int i,int j){
        if(j==t.size())
            return s.size()-i;
        if(i==s.size())
            return t.size()-j;
        
        if(mp.find({i,j})!=mp.end())
            return mp[{i,j}];
        
        if(s[i]==t[j])
            return mp[{i,j}]=rec(s,t,i+1,j+1);
        
        int ins=1+rec(s,t,i,j+1);
        int del=1+rec(s,t,i+1,j);
        int rep=1+rec(s,t,i+1,j+1);
        
        return mp[{i,j}]=min(ins,min(del,rep));
    }
    
    int minDistance(string word1, string word2) {
        return rec(word1,word2,0,0);
    }
};