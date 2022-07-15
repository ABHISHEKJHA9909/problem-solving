class Solution {
    int arr[][]=new int[51][51];
    int n=0,m=0;
    
    int dfs(int i,int j){
        if(i<0 || i==n || j<0 || j==m || arr[i][j]==0)
            return 0;
        arr[i][j]=0;
        return 1 + dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1);
    }
    
    public int maxAreaOfIsland(int[][] grid) {
        int res=0;
        n=grid.length;
        m=grid[0].length;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr[i][j]=grid[i][j];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    res=Math.max(res,dfs(i,j));
                }
            }
        }
        
        return res;
    }
}