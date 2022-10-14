class Solution {
public:
    vector<int>arr[105];
    int vis[105];
    
    void dfs(int i){
        
        vis[i]=1;
        for(int j:arr[i]){
            if(vis[j]==0)
                dfs(j);
        }
    }
    
    int findCircleNum(vector<vector<int>>& brr) {
        int n=brr.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i && brr[i][j]==1){
                    arr[i].push_back(j);
                }
            }
        }
        
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    }
};