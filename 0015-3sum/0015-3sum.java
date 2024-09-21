class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int len=nums.length;
        List<List<Integer>> res=new ArrayList<>();
        
        for(int i=0;i<len;++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            int j=i+1;
            int k=len-1;
            int target=-nums[i];
            
            while(j<k){
                if(nums[j]+nums[k]==target){
                    res.add(List.of(nums[i],nums[j],nums[k]));
                    while(++j<k && nums[j]==nums[j-1]){}
                }
                else if(nums[j]+nums[k]<target){
                    ++j;
                }
                else{
                    --k;
                }
            }
        }
        
        return res;
    }
}