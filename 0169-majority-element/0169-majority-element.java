class Solution {
    public int majorityElement(int[] nums) {
        for(int x:nums){
            int cnt=0;
            
            for(int i:nums){
                if(i==x){
                    ++cnt;
                }
            }
            
            if(cnt>((nums.length)/2)){
                return x;
            }
        }
        
        return -1;
    }
}