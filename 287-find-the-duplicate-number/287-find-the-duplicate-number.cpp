class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]<mid+1)
                j=mid;
            else
                i=mid+1;
        }
        return nums[i];
    }
};