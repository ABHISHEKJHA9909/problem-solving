class Solution {
public:
    
    int jump(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1e5);
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+arr[i] && j<n ;j++){
                dp[j]=min(dp[j],1+dp[i]);
            }
        }
        
        return dp[n-1];
    }
};