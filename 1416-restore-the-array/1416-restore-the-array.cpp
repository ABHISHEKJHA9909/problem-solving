class Solution {
public:
    unordered_map<int,int>m;
    
    int rec(int i,string& s,int& k){
        if(i==s.size())
            return 1;
        
        
        if(m.find(i)!=m.end())
            return m[i];
        
        long long res=0;
        
        long long z=0;
        int j=i;
        for(;i<s.size();i++){
            z*=10;
            z+=(s[i]-'0');
            if(z>k || z==0)
                break;
            res+=rec(i+1,s,k);
            res%=1000000007;
        }
        
        // cout<<i<<' '<<res<<endl;
        
        return m[j]=res;
    }
    
    int numberOfArrays(string s, int k) {
        return rec(0,s,k);
    }
};