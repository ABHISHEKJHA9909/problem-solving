class Solution {
public:
    map<pair<int,int>,int>m;
    
    bool rec(string &s1,string &s2,int i,int j,string &s3){
        if(i==s1.size() && j==s2.size() && i+j==s3.size())
            return m[{i,j}]=true;
        
        if(m.find({i,j})!=m.end())
            return m[{i,j}];
        
        if(i<s1.size() && s1[i]==s3[i+j] && rec(s1,s2,i+1,j,s3))
            return m[{i,j}]=true;
        
        if(j<s2.size() && s2[j]==s3[i+j] && rec(s1,s2,i,j+1,s3))
            return m[{i,j}]=true;
        
        return m[{i,j}]=false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        return rec(s1,s2,0,0,s3);
    }
};