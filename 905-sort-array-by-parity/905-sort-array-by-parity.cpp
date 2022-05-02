class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>=0 && nums[i]&1)i--;
        int j=i-1;
        while(j>=0 && !(nums[j]&1))j--;
        cout<<j<<' '<<i;
        while(j<i && j>=0 && i>=0){
            swap(nums[i],nums[j]);
            j--,i--;
            while(i>=0 && nums[i]&1)i--;
            while(j>=0 && !(nums[j]&1))j--;
        }
        return nums;
    }
};