class Solution {
public:
    
    int tallestBillboard(vector<int>& nums) {
        int n=nums.size(),sum=5001;
        
        int dp[sum];
        dp[0]=0;
        for(int i=1;i<sum;i++)dp[i]=-100000;
        
        for(int &x:nums){
            int curr[sum];
            for(int i=0;i<sum;i++)curr[i]=dp[i];
            
            for(int i=0;i<sum-x;i++){
                dp[i+x]=max(dp[i+x],curr[i]);
                dp[abs(i-x)]=max(dp[abs(i-x)],curr[i]+min(i,x));
            }
        }
        
        
        return dp[0];
    }
};