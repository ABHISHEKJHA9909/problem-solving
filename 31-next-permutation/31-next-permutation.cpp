class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 && nums[i-1]>=nums[i])i--;
        i--;
        cout<<i;
        if(i>=0){
            int j=i;
            int curr =INT_MAX;
            for(int k=i+1;k<nums.size();k++){
                if(nums[k]>nums[i] && nums[k]<curr){
                    j=k;
                    curr=nums[j];
                }
            }
            swap(nums[i],nums[j]);
        }
        
        sort(nums.begin() + i+ 1,nums.end());
    }
};