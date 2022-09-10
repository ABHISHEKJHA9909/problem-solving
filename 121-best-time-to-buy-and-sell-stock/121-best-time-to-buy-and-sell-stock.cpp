class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mn=arr[0],n=arr.size(),res=0;
        
        for(int i=0;i<n;i++){
            mn=min(mn,arr[i]);
            res=max(res,arr[i]-mn);
        }
        
        return res;
    }
};