class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n,-1);
        
        for(long long i=0,sum=0;i<n;i++){
            sum+=nums[i];
            if(i>=2*k){
                res[i-k]=sum/(2*k+1);
                sum-=nums[i-2*k];
            }
        }
        return res;
    }
};