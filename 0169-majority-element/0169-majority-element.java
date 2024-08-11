class Solution {
    public int majorityElement(int[] nums) {
        
        int cnt=1;
        int res=(int)1e9 +1;
        for(int x:nums){
            if(x==res){
                ++cnt;
            }
            else{
                --cnt;
            }
            if(cnt==0){
                res=x;
                cnt=1;
            }
            
        }
        
        return res;
    }
}