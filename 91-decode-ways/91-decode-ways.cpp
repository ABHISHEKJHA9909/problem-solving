class Solution {
public:
    unordered_map<int,int>m;
    
    int solve(int i,string s){
        if(i>=s.size()){
            return 1;
        }
        if(m.find(i)!=m.end())
            return m[i];
        int res=0;
        if(s[i]!='0')
            res+=solve(i+1,s);
        if(i+1<s.size()){
            string curr=s.substr(i,2);
            if(curr>"09" && curr<"27")
                res+=solve(i+2,s);
        }
        return m[i]=res;
    }
    
    int numDecodings(string s) {
        // cout<<endl;
        return solve(0,s);
    }
};