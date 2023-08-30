class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        
        
        int curr_min=INT_MAX;
        long long result=0;
        
        for(int &i:nums){
            if(i<=curr_min){
                curr_min=i;
                continue;
            }
            int curr_div=(i+curr_min-1)/curr_min;
            curr_min=i/curr_div;
            result+=curr_div-1;
        }
        
        return result;
    }
};