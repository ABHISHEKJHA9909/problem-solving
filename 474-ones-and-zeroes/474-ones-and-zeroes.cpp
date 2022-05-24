class Solution {
public:
    int dp[101][101];
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(string &s:strs){
            int z=0,o=0;
            for(char &c:s){
                if(c=='0')
                    z++;
                else
                    o++;
            }
            
            for(int i=m;i>=z;i--){
                for(int j=n;j>=o;j--){
                    dp[i][j]=max(dp[i-z][j-o]+1,dp[i][j]);
                }
            }
            
        }
        
        
        return dp[m][n];
    }
};