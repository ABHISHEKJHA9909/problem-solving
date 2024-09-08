class Solution {
    public int arraySign(int[] nums) {
        boolean neg=false;
        boolean zero=false;
        
        for(int i:nums){
            if(i==0){
                zero=true;
            }
            if(i<0){
                neg=!neg;
            }
        }
        
        return zero?0:(neg?-1:1);
    }
}