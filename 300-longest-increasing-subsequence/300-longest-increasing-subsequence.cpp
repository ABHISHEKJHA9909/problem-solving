class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int res=1;
        
        for(int j=1;j<n;j++){
            int curr=0;
            for(int i=0;i<j;i++){
                if(nums[i]<nums[j])
                    curr=max(curr,dp[i]);
            }
            dp[j]=max(dp[j],curr+1);
            res=max(res,dp[j]);
        }
        
        return res;
    }
};