class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        
        unordered_map<int,int>dp;
        int res=0;
        
        for(int i=0,curr;i<n;i++){
            res=max(res,dp[arr[i]]=1+dp[arr[i]-d]);
        }
        
        return res;
    }
};