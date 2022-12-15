class Solution {
public:
    
    int minDistance(string s, string t) {
        int n=s.size() , m=t.size();
        if(n==0)
            return m;
        if(m==0)
            return n;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    if(j!=0){
                        dp[i][j]=dp[i][j-1]+((s[i]==t[j])?(dp[i][j-1]==j?0:1):1);
                    }
                    else if(i!=0){
                        dp[i][j]=dp[i-1][j]+((s[i]==t[j])?(dp[i-1][j]==i?0:1):1);
                    }
                    else
                        dp[i][j]=!(s[i]==t[j]);
                    
                }
                else{
                    if(s[i]!=t[j])
                        dp[i][j]=1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    else
                        dp[i][j]=dp[i-1][j-1];
                }
                // cout<<dp[i][j]<<' ';
            }
            // cout<<endl;
        }
        
        return dp[n-1][m-1];
    }
};