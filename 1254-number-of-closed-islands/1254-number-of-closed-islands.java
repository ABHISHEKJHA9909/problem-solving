class Solution {
    int r,c;
    
    boolean dfs(int i,int j,int[][] grid){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==-2)
            return false;
        if(grid[i][j]==1 || grid[i][j]==-1)
            return true;
        
        grid[i][j]=-1;
        
        if(dfs(i+1,j,grid) && dfs(i,j+1,grid) && dfs(i-1,j,grid) && dfs(i,j-1,grid)){
            return true;
        }
        grid[i][j]=-2;
        return false;
    }
    
    public int closedIsland(int[][] grid) {
        r=grid.length;
        c=grid[0].length;
        
        int res=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0 && dfs(i,j,grid)){
                        res++;
                }
            }
        }
        
        return res;
    }
}