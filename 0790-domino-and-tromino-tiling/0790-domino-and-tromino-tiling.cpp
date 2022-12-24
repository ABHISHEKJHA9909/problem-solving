class Solution {
public:
    int numTilings(int n) {
        int dp[n+10];
        dp[0]=dp[1]=1;
        dp[2]=2,dp[3]=5;
        
        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
            dp[i]%=1000000007;
            int x=0;
            for(int j=i-3;j>=0;j-=2){
                x+=dp[j];
                x%=1000000007;
            }
            for(int j=i-4;j>=0;j-=2){
                x+=dp[j];
                x%=1000000007;
            }
            dp[i]+=(2*x)%1000000007;
            dp[i]%=1000000007;
            // cout<<i<<' '<<x<<' '<<dp[i]<<endl;
        }
        
        return dp[n];
    }
};