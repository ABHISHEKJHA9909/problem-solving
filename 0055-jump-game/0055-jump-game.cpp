class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0,n=nums.size();
        for(int j=0;i<=j && i<n;i++){
            j=max(j,i+nums[i]);
        }
        return i==n;
    }
};