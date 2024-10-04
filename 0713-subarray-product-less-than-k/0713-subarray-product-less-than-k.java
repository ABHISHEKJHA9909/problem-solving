class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int prod=1;
        int len=nums.length;
        int res=0;
        
        for(int i=0,j=0;i<len;++i){
            prod=prod*nums[i];
            
            while(j<=i && prod>=k){
                prod/=nums[j];
                ++j;
            }
            
            res+=(i-j+1);
        }
        
        return res;
    }
}