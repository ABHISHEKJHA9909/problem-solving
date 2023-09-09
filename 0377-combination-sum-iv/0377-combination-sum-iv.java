class Solution {
    Map<Integer,Integer> m =new HashMap<Integer,Integer>();
    
    private int rec(int[] nums,int target){
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        
        if(m.get(target)!=null)
            return m.get(target);
        
        int res=0;
        
        for(int j=0;j<nums.length;j++){
            res+=rec(nums,target-nums[j]);
        }
        
        m.put(target,res);
        return res;
    }
    
    public int combinationSum4(int[] nums, int target) {
        return rec(nums,target);
    }
}