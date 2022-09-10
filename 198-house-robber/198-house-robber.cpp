class Solution {
public:
    unordered_map<int,int>m;
    
    int rec(vector<int>& nums,int i){
        if(i>=nums.size())
            return 0;
        if(m.find(i)!=m.end())
            return m[i];
        return m[i]=max(nums[i]+rec(nums,i+2),rec(nums,i+1));
    }
    int rob(vector<int>& nums) {
        return rec(nums,0);
    }
};