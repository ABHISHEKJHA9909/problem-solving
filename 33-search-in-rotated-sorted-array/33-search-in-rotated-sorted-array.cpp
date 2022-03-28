class Solution {
public:
    int bs(vector<int>& nums,int i,int j,int target){
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                j=mid-1;
            else
                i=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        
        while(i<j){
            int mid=i+(j-i)/2;
            cout<<i<<' '<<j<<endl;
            if(nums[mid]>nums[j])
                i=mid+1;
            else
                j=mid;
        }
        int idx=bs(nums,0,i-1,target);
        if (idx>=0)
            return idx;
        idx=bs(nums,i,nums.size()-1,target);
        return idx;
    }
};