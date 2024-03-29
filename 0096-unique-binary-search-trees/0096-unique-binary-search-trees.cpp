class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++){
            int curr=0;
            for(int j=0;j<i;j++){
                curr+=dp[j]*dp[i-1-j];
            }
            dp[i]=curr;
        }
        
        for(int i=1;i<=n;i++)
            cout<<dp[i]<<' ';
        return dp[n];
    }
};