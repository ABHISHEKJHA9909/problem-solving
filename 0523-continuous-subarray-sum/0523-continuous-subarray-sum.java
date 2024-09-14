class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int len=nums.length;
        int sum=0;
        
        Map<Integer,Integer>m=new HashMap<>(Map.of(0,-1));
        
        for(int i=0;i<len;i++){
            sum+=nums[i];
            sum%=k;
            if(m.containsKey(sum) && m.get(sum)<(i-1)){
                return true;
            }
            if(!m.containsKey(sum))
                m.put(sum,i);
        }
        
        return false;
    }
}