class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int res=INT_MAX;
        int i=0;
        int j=nums[n-1]-nums[0];
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            int q=0;
            for(int k=0;q<p && k<n-1;k++){
                if(nums[k+1]-nums[k]<=mid){
                    q++;
                    k++;
                }
            }
            
            if(q==p){
                res=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return res;
    }
};