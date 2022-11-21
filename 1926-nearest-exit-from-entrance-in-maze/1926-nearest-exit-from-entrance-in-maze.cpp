class Solution {
public:
    int res=INT_MAX,r,c;
    
    void dfs(vector<vector<char>>& maze,int i,int j,int curr){
        
        queue<vector<int>>q;
        q.push({i,j,curr});
        
        while(q.size()){
            i=q.front()[0],j=q.front()[1],curr=q.front()[2]; q.pop();
            
            if(i<0 || i==r || j<0 || j==c){
                if(curr!=1)
                    res=min(res,curr);
                continue;
            }
            if(maze[i][j]!='.')
                continue;
            maze[i][j]='*';
            q.push({i+1,j,curr+1});
            q.push({i,j+1,curr+1});
            q.push({i,j-1,curr+1});
            q.push({i-1,j,curr+1});
        }
        
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        r=maze.size(),c=maze[0].size();
        
        dfs(maze,entrance[0],entrance[1],0);
        
        return res==INT_MAX?-1:res-1;
    }
};