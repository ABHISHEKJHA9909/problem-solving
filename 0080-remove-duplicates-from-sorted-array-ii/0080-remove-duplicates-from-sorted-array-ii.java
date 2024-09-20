class Solution {
    public int removeDuplicates(int[] nums) {
        int len=nums.length;
        
        int j=1;
        for(int i=1;i<len;i++){
            if(i<len-1 && nums[i]==nums[i-1] && nums[i]==nums[i+1]){
                continue;
            }
            nums[j++]=nums[i];
        }
        
        return j;
    }
}