class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer,Integer>m=new HashMap<Integer,Integer>();
        
        int res=0;
        for(int i:nums){
            if(m.containsKey(i))
                continue;
            
            int left=m.containsKey(i-1)?m.get(i-m.get(i-1)):0;
            int right=m.containsKey(i+1)?m.get(i+m.get(i+1)):0;
            
            m.put(i,left+right+1);
            m.put(i-left,left+right+1);
            m.put(i+right,left+right+1);
            
            res=Math.max(res,left+right+1);
        }
        
        return res;
    }
}