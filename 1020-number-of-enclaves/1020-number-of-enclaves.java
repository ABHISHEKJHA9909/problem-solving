class Solution {
    int r,c;
    
    void dfs(int i,int j,int[][] grid){
        if(i<0||i==r||j<0||j==c||grid[i][j]==0)
            return;
        
        grid[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
    }
    
    public int numEnclaves(int[][] grid) {
        r=grid.length;c=grid[0].length;
        
        for(int j=0;j<c;j++){
            dfs(0,j,grid);
            dfs(r-1,j,grid);
        }
        
        for(int i=0;i<r;i++){
            dfs(i,0,grid);
            dfs(i,c-1,grid);
        }
        
        
        int res=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    ++res;
            }
        }
        
        return res;
    }
}