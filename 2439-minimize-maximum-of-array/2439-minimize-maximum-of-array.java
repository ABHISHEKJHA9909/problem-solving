class Solution {
    public int minimizeArrayValue(int[] nums) {
        int n=nums.length;
        
        long sum=0,curr=0;
        
        for(int i=0;i<n;i++){
            long temp=((nums[i]+i)+sum)/(i+1);
            
            if(curr<temp){
                curr=Math.max(curr,temp);
            }
            sum+=nums[i];
        }
        
        
        return (int)curr;
    }
}