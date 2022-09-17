class Solution {
public:
    void dfs(vector<vector<char>>& arr,int i,int j){
        if(i>=0 && i<arr.size() && j>=0 && j<arr[0].size() && arr[i][j]=='1'){
            arr[i][j]='0';
            dfs(arr,i+1,j);
            dfs(arr,i-1,j);
            dfs(arr,i,j+1);
            dfs(arr,i,j-1);
        }
    }
    
    int numIslands(vector<vector<char>>& arr) {
        int res=0;
        
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]=='1'){
                    dfs(arr,i,j);
                    res++;
                }
                
            }
        }
        return res;
    }
};