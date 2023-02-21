class Solution {
    public int singleNonDuplicate(int[] nums) {
        int i=0,j=nums.length-1;
        
        while(i<j){
            int mid=(i+j)/2;
            
            if(nums[mid]==nums[mid+((mid&1)==0?1:-1)]){
                i=mid+1;
            }
            else{
                j=mid;
            }
        }
        
        return nums[i];
    }
}