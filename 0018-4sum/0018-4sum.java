class Solution {
    public List<List<Integer>> fourSum(int[] nums, int t) {
        List<List<Integer>>res=new ArrayList<>();
        Arrays.sort(nums);
        int len=nums.length;
        
        for(int i=0;i<len;++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<len;++j){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                
                int k=j+1;
                int l=len-1;
                long target=t-(0L+nums[i]+nums[j]);
                while(k<l){
                    if(0L+nums[k]+nums[l]==target){
                        res.add(List.of(nums[i],nums[j],nums[k],nums[l]));
                        while(++k<l && nums[k]==nums[k-1]){}
                    }
                    else if(0L+nums[k]+nums[l]<target){
                        ++k;
                    }
                    else{
                        --l;
                    }
                }
            }
        }
        
        return res;
    }
}