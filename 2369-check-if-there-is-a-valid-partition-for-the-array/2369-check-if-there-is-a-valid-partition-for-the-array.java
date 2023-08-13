class Solution {
    public boolean validPartition(int[] nums) {
        int len=nums.length;
        int dp[]=new int[len+1];
        
        dp[0]=1;
        if(nums[0]==nums[1]){
            dp[2]=1;
        }
                
        for(int i=2;i<len;i++){
            int ind=i+1;
            if(nums[i]==nums[i-1] && dp[ind-2]==1)
                dp[ind]=dp[ind-2];
            else if(nums[i]==nums[i-1] && nums[i-1]==nums[i-2] && dp[ind-3]==1)
                dp[ind]=dp[ind-3];
            else if(nums[i]==(nums[i-1]+1) && nums[i-1]==(nums[i-2]+1) && dp[ind-3]==1)
                dp[ind]=dp[ind-3];
        }
        
        return dp[len]==1;
    }
}