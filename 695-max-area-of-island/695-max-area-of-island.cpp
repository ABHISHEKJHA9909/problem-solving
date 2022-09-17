class Solution {
public:
    int r,c;
    
    int dfs(vector<vector<int>> & arr,int i,int j){
        if(i>=0 && i<r && j>=0 && j<c &&arr[i][j]==1){
            arr[i][j]=0;
            return 1+
                    dfs(arr,i+1,j)+
                    dfs(arr,i-1,j)+
                    dfs(arr,i,j+1)+
                    dfs(arr,i,j-1);
        }
        return 0;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        r=arr.size(),c=arr[0].size();
        int res=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j])
                    res=max(res,dfs(arr,i,j));
            }
        }
        
        return res;
    }
};