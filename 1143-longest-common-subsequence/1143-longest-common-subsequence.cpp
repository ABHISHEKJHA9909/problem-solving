class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size() , m=t.size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0  || j==0){
                    if(s[i]==t[j])
                        dp[i][j]=1;
                    else if(i!=0)
                        dp[i][j]=dp[i-1][j];
                    else if(j!=0)
                        dp[i][j]=dp[i][j-1];
                }
                else{
                    if(s[i]==t[j])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};