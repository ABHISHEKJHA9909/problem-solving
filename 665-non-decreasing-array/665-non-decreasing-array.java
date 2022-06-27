class Solution {
    public boolean checkPossibility(int[] nums) {
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1]){
                int temp=nums[i+1];
                nums[i+1]=nums[i];
                
                int cnt=0;
                for(int j=0;j<nums.length-1;j++){
                    if(nums[j]>nums[j+1]){
                        cnt++;
                    }
                }
                
                nums[i]=temp;
                nums[i+1]=temp;
                int cnt1=0;
                for(int j=0;j<nums.length-1;j++){
                    if(nums[j]>nums[j+1]){
                        cnt1++;
                    }
                }
                if(cnt==0||cnt1==0)
                    return true;
                return false;
            }
        }
        return true;
    }
}