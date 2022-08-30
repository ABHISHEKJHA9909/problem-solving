class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int num=1;
        
        for(int &i:nums){
            if(i>=num && i!=num++)
                return  --num;
        }
        
        return num;
    }
};