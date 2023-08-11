class Solution {
    public int singleNumber(int[] nums) {
        int one=0;
        int two=0;
        int three=0;
        
        for(int i=0;i<nums.length;++i){
            int n=nums[i];
            two=two|(one&n);
            one=one^n;
            three=one&two;
            one&=(~three);
            two&=(~three);
        }
        
        return one;
    }
}