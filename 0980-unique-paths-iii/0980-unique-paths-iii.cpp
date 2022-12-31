#define f first
#define s second

class Solution {
public:
    pair<int,int>s,e;
    int r,c,cnt=1,res=0;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int i,int j,vector<vector<int>>& grid){
        return i>=0 && j>=0 && i<r && j<c && (grid[i][j]==0 || grid[i][j]==2 || grid[i][j]==1);
    }
    
    void dfs(int i,int j,vector<vector<int>>& arr){
        if(!valid(i,j,arr))
            return;
        if(arr[i][j]==2){
            if(cnt==0)
                res++;
            return;
        }
        cnt--;
        arr[i][j]+=5;
        dfs(i+dir[0][0],j+dir[0][1],arr);
        dfs(i+dir[1][0],j+dir[1][1],arr);
        dfs(i+dir[2][0],j+dir[2][1],arr);
        dfs(i+dir[3][0],j+dir[3][1],arr);
        cnt++;
        arr[i][j]-=5;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        r=grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    s={i,j};
                if(grid[i][j]==2)
                    e={i,j};
                if(grid[i][j]==0)
                    cnt++;
            }
        }
        
        dfs(s.f,s.s,grid);
        
        return res;
    }
};