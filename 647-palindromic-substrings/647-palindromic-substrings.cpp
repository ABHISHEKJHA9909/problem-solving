class Solution {
public:
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n=s.size();
        
        int res=n;
        
        for(int l=2;l<=n;l++){
            int i=0,j=l-1;
            while(j<n){
                if(s[i]!=s[j])
                    dp[i][j]=1;
                else if(dp[i+1][j-1]==1)
                    dp[i][j]=1;
                if(dp[i][j]==0)
                    res++;
                j++,i++;
            }
        }
        
        return res;
    }
};