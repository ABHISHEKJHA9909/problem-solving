class Solution {
public:
    int n;
    long long rec(vector<int>&nums,vector<int>& cost,int x){
        long long curr=0;
        
        for(int i=0;i<n;i++){
            curr+=(long long)abs(x-nums[i])*cost[i];
        }
        
        return curr;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        n=nums.size();
        
        int i=0,j=1e6;
        long long res=LONG_MAX;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            long long midi=rec(nums,cost,mid);
            long long  midii=rec(nums,cost,mid+1);
            
            res=min(res,midi);
            if(midi>midii){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        
        return res;
        
    }
};