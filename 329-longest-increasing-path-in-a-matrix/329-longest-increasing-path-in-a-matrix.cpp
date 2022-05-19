class Solution {
public:
    int dp[201][201];
    int n,m;
    
    bool is(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    int rec(vector<vector<int>>& arr,int i,int j){
        if(dp[i][j]!=0)
            return dp[i][j];
        int res=1;
        if(is(i+1,j) && arr[i][j]>arr[i+1][j])  res=max(res,1+rec(arr,i+1,j));
        if(is(i-1,j) && arr[i][j]>arr[i-1][j])  res=max(res,1+rec(arr,i-1,j));
        if(is(i,j+1) && arr[i][j]>arr[i][j+1])  res=max(res,1+rec(arr,i,j+1));
        if(is(i,j-1) && arr[i][j]>arr[i][j-1])  res=max(res,1+rec(arr,i,j-1));
        return dp[i][j]=res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& arr) {
        
        n=arr.size(),m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=0;
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,rec(arr,i,j));
            }
        }
        
        return res;
    }
};