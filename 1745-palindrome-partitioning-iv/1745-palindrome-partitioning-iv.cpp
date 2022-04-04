class Solution {
public:
    int dp[2005][2005];
    bool checkPartitioning(string s) {
        int n=s.size();
        for(int l=2;l<=n;l++){
            for(int i=0,j=l-1;j<n;i++,j++){
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=1;
            }
        }
        for(int i=0;i<n-2;i++){
            if(dp[0][i]==0){
                for(int j=i+1;j<n-1;j++){
                    if(dp[i+1][j]==0 && dp[j+1][n-1]==0)
                        return 1;
                }
            }
        }
        return 0;
    }
};