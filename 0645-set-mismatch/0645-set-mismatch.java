class Solution {
    public int[] findErrorNums(int[] nums) {
        
        
        int len=nums.length;
        
        int sum=0;
        
        for(int i:nums){
            sum+=i;
        }
        
        for(int i=0;i<len;i++){
            int abs=Math.abs(nums[i]);
            
            if(nums[abs-1]<0){
                return new int[]{abs,abs+(len*(len+1))/2-sum};
            }
            
            nums[abs-1]*=-1;
        }
        
        return new int[0];
    }
}