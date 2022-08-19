class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int>>dp(2,vector<int>(n+1,0));
        
        for(int i=0;i<n+1;i++){
            dp[0][i]=i;
        }
        
        for(int i=1;i<2;i++){
            for(int j=1;j<=n;j++){
                
                int minn=INT_MAX;
                for(int k=1;k<=j;k++){
                    minn=min(minn,max(dp[i-1][k-1],dp[i][j-k]));
                }
                dp[i][j]=1+minn;
            }
        }
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<n+1;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        
        return dp[1][n];
    }
};