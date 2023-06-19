class Solution {
public:
    int r,c,MOD=1000000007;
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>&arr, int i,int j,int priv){
        if(i<0 || i==r || j<0 || j==c || arr[i][j]<=priv)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int curr=dfs(arr,i+1,j,arr[i][j]);
        curr%=MOD;
            curr+=dfs(arr,i-1,j,arr[i][j]);
        curr%=MOD;
            curr+=dfs(arr,i,j-1,arr[i][j]);
        curr%=MOD;
            curr+=dfs(arr,i,j+1,arr[i][j]);
        return dp[i][j]=(curr+1)%MOD;
    }
    
    int countPaths(vector<vector<int>>& arr) {
        r=arr.size(),c=arr[0].size();
        dp=vector<vector<int>>(r,vector<int>(c,-1));
        
        int res =0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(dp[i][j]==-1)
                    dfs(arr,i,j,INT_MIN);
                
                res+=(dp[i][j]);
                res%=MOD;
            }
        }
        
        return res;
    }
};