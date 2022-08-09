class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        vector<long long>dp(n,1);
        unordered_map<int,int>m;
        int MOD=1000000007;
        
        for(int i=0;i<n;i++){
            int j=1;
            m[arr[i]]=i+1;
            
            for(;j*j<arr[i];j++){
                if(arr[i]%j==0 && m[j] && m[arr[i]/j]){
                    dp[i]+=2*(dp[m[j]-1]*dp[m[arr[i]/j]-1]);
                    dp[i]%=MOD;
                }
            }
            
            if(j*j==arr[i] && m[j] )
                dp[i]+=dp[m[j]-1]*dp[m[j]-1];
            dp[i]%=MOD;
        }
        
        
        return accumulate(dp.begin(),dp.end(),(long long)0)%MOD;
    }
};