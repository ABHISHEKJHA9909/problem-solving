class Solution {
    public void moveZeroes(int[] nums) {
        int len=nums.length;
        if(len==1){
            return;
        }
        
        for(int i=0,j=0;i<len;++i){
            if(nums[i]!=0){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                ++j;
            }
        }
        
    }
}