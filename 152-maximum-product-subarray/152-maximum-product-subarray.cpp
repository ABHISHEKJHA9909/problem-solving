class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=1,mn=1,res=INT_MIN;
        
        for(int i=0,n=nums.size();i<n;i++){
            if(nums[i]>0){
                mx=max(mx*nums[i],nums[i]);
                mn=mn*nums[i];
                res=max(res,mx);
            }
            else if(nums[i]<0){
                int temp=mx;
                mx=mn*nums[i];
                mn=min(temp*nums[i],nums[i]);
                res=max(res,mx);
            }
            else{
                res=max(res,0);
                mn=mx=1;
            }
        }
        
        return res;
    }
};