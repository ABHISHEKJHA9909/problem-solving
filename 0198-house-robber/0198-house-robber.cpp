class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return nums[0];
        int arr[n][2];
        arr[1][0]=nums[1];
        arr[1][1]=nums[0];
        
        for(int i=2;i<n;i++){
            arr[i][0]=nums[i]+arr[i-1][1];
            arr[i][1]=max(arr[i-1][0],arr[i-1][1]);
        }
        
        return max(arr[n-1][0],arr[n-1][1]);
    }
};