class Solution {
public:
    unordered_map<int,int>m;
    
    int rec(int i,vector<int>& nums){
        if(i>=nums.size()-1)
            return 0;
        if(m.find(i)!=m.end())
            return m[i];
        int x=1e5;
        
        for(int j=i+1;j<=i+nums[i];j++)
            x=min(x,1+rec(j,nums));
        
        return m[i]=x;
    }
    
    int jump(vector<int>& nums) {
        return rec(0,nums);
    }
};