class Solution {
public:
    
    map<pair<int,int>,int>mp;
    
    int rec(string &s,string &t,int i,int j){
        if(i==s.size()||j==t.size())
            return 0;
        if(mp.find({i,j})!=mp.end())
            return mp[{i,j}];
        if(s[i]==t[j])
            return mp[{i,j}]=1+rec(s,t,i+1,j+1);
        return mp[{i,j}]=max(rec(s,t,i+1,j),rec(s,t,i,j+1));
    }
    
    int longestCommonSubsequence(string s, string t) {
        return rec(s,t,0,0);
    }
};