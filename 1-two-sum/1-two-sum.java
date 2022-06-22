class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        HashMap<Integer,ArrayList<Integer>> m =new HashMap<Integer,ArrayList<Integer>>();
        
        for(int i=0;i<nums.length;i++){
            if(m.containsKey(nums[i])==false){
                m.put(nums[i],new ArrayList<Integer>());
            }
            m.get(nums[i]).add(i);
        }
        
        Arrays.sort(nums);
        int i=0,j=nums.length-1;
        while(i<j){
            if(nums[i]+nums[j]==target){
                if(nums[i]==nums[j]){
                    int arr[]={m.get(nums[i]).get(0),m.get(nums[j]).get(1)};
                    return arr;
                }
                int arr[]={m.get(nums[i]).get(0),m.get(nums[j]).get(0)};
                return arr;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        int arr[]={0};
        return arr;
    }
}