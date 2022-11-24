class Solution {
public:
    int r,c;
    bool vis[10][10];
    
    bool dfs(int i,int j,int k,vector<vector<char>> & arr,string& word){
        if(k==word.size())
            return true;
        if(i<0 || j<0 || i==r || j==c || vis[i][j]==true || arr[i][j]!=word[k])
            return false;
        
        vis[i][j]=true;
        if(dfs(i+1,j,k+1,arr,word) || dfs(i,j+1,k+1,arr,word)||dfs(i-1,j,k+1,arr,word)||dfs(i,j-1,k+1,arr,word))
            return true;
        vis[i][j]=false;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r=board.size(),c=board[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                    if(dfs(i,j,0,board,word))
                       return true;
                }
        }
        return false;
    }
};