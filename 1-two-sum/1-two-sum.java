class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> m =new HashMap<Integer,Integer>();
        
        for(int i=0;i<nums.length;i++){
            if(m.containsKey(target-nums[i])){
                int arr[]= {m.get(target-nums[i]),i};
                return arr;
            }
            m.put(nums[i],i);
        }
        int arr[]={0};
        return arr;
    }
}