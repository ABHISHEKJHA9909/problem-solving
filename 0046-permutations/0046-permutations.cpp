class Solution {
public:
    bool find_next(vector<int>& nums){
        int i=0,n=nums.size()-1;
        
        while(i<n && nums[i]<nums[i+1])
            i++;
        if(i==n)
            return false;
        int j=upper_bound(nums.begin(),nums.begin()+i+1,nums[i+1])-nums.begin();
        // cout<<nums[i+1]<<' '<<j<<endl;
        swap(nums[i+1],nums[j]);
        reverse(nums.begin(),nums.begin()+i+1);
        
        return true;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        res.push_back(nums);
        
        while(find_next(nums)){
            res.push_back(nums);
        }
        
        return res;
    }
};