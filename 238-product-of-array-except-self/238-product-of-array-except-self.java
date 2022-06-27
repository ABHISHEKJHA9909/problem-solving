class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n=nums.length;
        long mul=1,zr=0;
        for(int i:nums){
            if(i==0)
                zr++;
            else
                mul*=i;
        }
        
        int res[]=new int[n];
        
        if(zr<2){
            if(zr==0){
                for(int i=0;i<n;i++){
                    res[i]=(int)(mul/nums[i]);
                }
            }
            else{
                for(int i=0;i<n;i++){
                    if(nums[i]==0)
                        res[i]=(int)mul;
                    else
                        res[i]=0;
                }
            }
        }
        
        return res;
    }
}