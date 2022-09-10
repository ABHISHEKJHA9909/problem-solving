class Solution {
public:
    int rob(vector<int> nums,int i,int j){
        if(j-i+1==1)
            return nums[i];
        nums[i+1]=max(nums[i],nums[i+1]);
        
        i+=2;
        for(;i<=j;i++){
            nums[i]=max(nums[i]+nums[i-2],nums[i-1]);
        }
        
        return nums[j];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        return max(rob(nums,0,n-2),rob(nums,1,n-1));
    }
};