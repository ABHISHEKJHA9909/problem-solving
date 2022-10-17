class Solution {
public:
    int dp[305][15];
    
    int rec(vector<int>& arr,int j,int d){
        if(dp[j][d]!=-1)
            return  dp[j][d];
        
        if(d==0){
            int curr=0;
            for(;j<arr.size();j++)
                curr=max(curr,arr[j]);
            return dp[j][d]=curr;
        }
        
        
        int curr=0,res=1e6;
        int i=j;
        for(;j<arr.size()-d;j++){                                                                                             
            curr=max(curr,arr[j]);
            res=min(res,curr+rec(arr,j+1,d-1));
        }
        
        return dp[i][d]=res;
        
    }
    
    int minDifficulty(vector<int>& arr, int d) {
        if(d>arr.size())
            return -1;
        memset(dp,-1,sizeof(dp));
        return rec(arr,0,d-1);
    }
};