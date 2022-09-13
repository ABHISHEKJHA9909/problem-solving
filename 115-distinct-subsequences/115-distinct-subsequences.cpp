class Solution {
public:
    map<pair<int,int>,int>mp;
    
    int rec(string &s,string &t,int i,int j){
        if(j==t.size())
            return 1;
        if(i==s.size())
            return 0;
        if(mp.find({i,j})!=mp.end())
            return mp[{i,j}];
        int take=0,nottake=0;
        
        if(s[i]==t[j])
            take=rec(s,t,i+1,j+1);
        nottake=rec(s,t,i+1,j);
        return mp[{i,j}]=take + nottake;
    }
    
    int numDistinct(string s, string t) {
        return rec(s,t,0,0);
    }
    
};