class Solution {
    boolean rec(int i,int[] nums,Map<Integer,Boolean> m){
        if(i==-1)
            return true;
        
        if(m.get(i)!=null)
            return m.get(i);
        
        m.put(i,true);
        if(i>0 && nums[i]==nums[i-1] && rec(i-2,nums,m))
            return true;
        else if(i>1 && nums[i]==nums[i-1] && nums[i-1]==nums[i-2] && rec(i-3,nums,m))
            return true;
        else if(i>1 && nums[i]==(nums[i-1]+1) && nums[i-1]==(nums[i-2]+1) && rec(i-3,nums,m))
            return true;
        m.put(i,false);
        return false;
    }
    
    public boolean validPartition(int[] nums) {
        Map<Integer,Boolean>m=new HashMap<Integer,Boolean>();
        return rec(nums.length-1,nums,m);
    }
}