class Solution {
    boolean rec(int i,int[] nums){
        if(i==-1)
            return true;
        
        if(i>0 && nums[i]==nums[i-1] && rec(i-2,nums))
            return true;
        else if(i>1 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2] && rec(i-3,nums))
            return true;
        else if(i>1 && nums[i]==(nums[i-1]+1) && nums[i-1]==(nums[i-2]+1) && rec(i-3,nums))
            return true;
        return false;
    }
    
    public boolean validPartition(int[] nums) {
        return rec(nums.length-1,nums);
    }
}