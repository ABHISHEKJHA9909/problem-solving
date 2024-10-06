class Solution {
    public long countSubarrays(int[] nums, int k) {
        int len=nums.length;
        int max=Integer.MIN_VALUE;
        long res=0;
        
        for(int i=0;i<len;++i){
            max=Math.max(max,nums[i]);
        }
        
        for(int i=0,j=0,total=0,cnt=0;i<len;++i){
            if(nums[i]==max){
                ++cnt;
            }
            
            while(cnt>=k){
                total++;
                if(nums[j]==max){
                    --cnt;
                }
                ++j;
            }
            res+=total;
        }
        
        return res;
        
    }
}