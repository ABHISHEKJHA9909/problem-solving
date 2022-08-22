class Solution {
public:
    
    int numDecodings(string s) {
        int n=s.size();
        
        int dp[n+1];
        fill(dp,dp+n+1,0);
        dp[s.size()]=1;
        if(s[n-1]!='0')
            dp[n-1]=1;
        
        for(int i=s.size()-2;i>=0;--i){
            if(s.substr(i,1)!="0"){
                dp[i]+=dp[i+1];
                if(s.substr(i,2)<"27")
                    dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};