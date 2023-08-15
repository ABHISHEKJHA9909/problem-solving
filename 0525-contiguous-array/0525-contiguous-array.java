class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer,Integer>m=new HashMap<Integer,Integer>();
        
        int checkPoint=0;
        m.put(checkPoint,-1);
        
        int res=0;
        int n=nums.length;
        
        for(int i=0;i<n;++i){
            if(nums[i]==0)
                --checkPoint;
            else
                ++checkPoint;
            
            if(m.get(checkPoint)!=null){
                res=Math.max(res,i-m.get(checkPoint));
            }
            else{
                m.put(checkPoint,i);
            }
        }
        
        return res;
    }
}