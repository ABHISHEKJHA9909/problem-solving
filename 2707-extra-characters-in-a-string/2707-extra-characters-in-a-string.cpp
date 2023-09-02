class Solution {
public:

    int minExtraChar(string s, vector<string>& arr) {
        unordered_set<string>m(arr.begin(),arr.end());
        
        int n=s.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=n;++i){
            dp[i]=dp[i-1]+1;
            for(int len=1;len<=i;++len){
                if(m.find(s.substr(i-len,len))!=m.end()){
                    dp[i]=min(dp[i],dp[i-len]);
                }
            }
        }
        
        
        return dp[s.size()];
    }
};