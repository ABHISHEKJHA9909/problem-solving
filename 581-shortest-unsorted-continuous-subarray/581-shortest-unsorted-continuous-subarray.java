class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int e=-2,b=-1,mx=nums[0], mn=nums[nums.length-1];
        for(int i=1;i<nums.length;i++){
            mx=Math.max(mx,nums[i]);
            mn=Math.min(mn,nums[nums.length-i-1]);
            if(mx>nums[i])e=i;
            if(mn<nums[nums.length-i-1])b=nums.length-i-1;
        }
        // System.out.println(b + " " +e);
        return e-b+1;
    }
}