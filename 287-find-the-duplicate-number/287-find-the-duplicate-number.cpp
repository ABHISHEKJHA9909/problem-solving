class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int &i:nums){
            int j=abs(i);
            if(nums[j-1]<0)
                return abs(i);
            nums[j-1]=-nums[j-1];
        }
        return -1;
    }
};