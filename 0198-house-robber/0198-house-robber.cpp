class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        
        int with=nums[1],without=nums[0],temp;
        
        for(int i=2;i<n;i++){
            temp=with;
            with=nums[i]+without;
            without=max(temp,without);
        }
        
        return max(with,without);
    }
};