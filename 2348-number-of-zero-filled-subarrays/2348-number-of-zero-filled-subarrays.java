class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long res=0;
        long len=0;
        
        for(int i:nums){
            if(i==0){
                len++;
            }
            else{
                len=0;
            }
            res+=len;
        }
        
        return res;
    }
}