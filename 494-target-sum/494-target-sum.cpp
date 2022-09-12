class Solution {
public:
    map<pair<int,int>,int>m;
    
    int rec(vector<int>&nums,int i,int target){
        if(i==nums.size())
            return target==0;
        
        if(m.find({i,target})!=m.end())
            return m[{i,target}];
        return m[{i,target}]=rec(nums,i+1,target-nums[i])+rec(nums,i+1,target+nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(nums,0,target);
    }
};