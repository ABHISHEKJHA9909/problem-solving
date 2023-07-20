class Solution {
public:
    int rec(int i,int target,vector<int>&nums,unordered_map<string,int>& m){
        if(i==nums.size()){
            if(target==0)
                return 1;
            return 0;
        }
        string s=to_string(i)+" "+to_string(target);
        auto it=m.find(s);
        if(it!=m.end())
            return (*it).second;
        int ans=rec(i+1,target-nums[i],nums,m) +rec(i+1,target+nums[i],nums,m);
        m[s]=ans;
        return ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>m;
        
        return rec(0,target,nums,m);
    }
};