class Solution {
    public int candy(int[] nums) {
        int n=nums.length;
        int res[]=new int[n];
        
        for(int i=0;i<n;i++)res[i]=1;
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])
                res[i]=res[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                res[i]=Math.max(res[i],res[i+1]+1);
        }
        
        int sum=0;
        for(int i:res)sum+=i;
        
        
        // for(int i:nums)System.out.print(i);
        // System.out.println();
        // for(int i:res)System.out.print(i);
        return sum;
    }
}