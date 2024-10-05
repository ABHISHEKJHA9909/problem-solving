class Solution {
    public int minOperations(int[] nums, int x) {
        int sum=0;
        int len=nums.length;
        
        for(int i=0;i<len;++i){
            sum+=nums[i];
        }
        
        int need=sum-x;
        
        if(need<0){
            return -1;
        }
        
        int res=Integer.MIN_VALUE;
        
        for(int i=0,j=0,curr=0;i<len;++i){
            curr+=nums[i];
            
            while(curr>need){
                curr-=nums[j];
                ++j;
            }
            
            if(curr==need){
                res=Math.max(res,i-j+1);
            }
        }
        
        return res==Integer.MIN_VALUE?-1:len-res;
    }
}